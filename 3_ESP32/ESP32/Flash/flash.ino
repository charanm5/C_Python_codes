#include <SPI.h>

#define FLASH_CS   5

#define TRIG_PIN   25
#define ECHO_PIN   26

#define FLASH_SIZE   0x400000
#define SECTOR_SIZE  0x1000

uint32_t currentAddress = 0;

//------------------------------------------------
void flashWriteEnable()
{
    digitalWrite(FLASH_CS, LOW);
    SPI.transfer(0x06);
    digitalWrite(FLASH_CS, HIGH);
}

//------------------------------------------------
uint8_t flashReadStatus()
{
    digitalWrite(FLASH_CS, LOW);

    SPI.transfer(0x05);

    uint8_t status = SPI.transfer(0);

    digitalWrite(FLASH_CS, HIGH);

    return status;
}

//------------------------------------------------
void flashWaitBusy()
{
    while(flashReadStatus() & 0x01)
    {
        delay(1);
    }
}

//------------------------------------------------
void flashReadID()
{
    digitalWrite(FLASH_CS, LOW);

    SPI.transfer(0x9F);

    uint8_t mfg = SPI.transfer(0);
    uint8_t type = SPI.transfer(0);
    uint8_t cap = SPI.transfer(0);

    digitalWrite(FLASH_CS, HIGH);

    Serial.print("Manufacturer ID : 0x");
    Serial.println(mfg,HEX);

    Serial.print("Memory Type     : 0x");
    Serial.println(type,HEX);

    Serial.print("Capacity ID     : 0x");
    Serial.println(cap,HEX);
}

//------------------------------------------------
void flashSectorErase(uint32_t addr)
{
    flashWriteEnable();

    digitalWrite(FLASH_CS, LOW);

    SPI.transfer(0x20);

    SPI.transfer((addr >> 16) & 0xFF);
    SPI.transfer((addr >> 8) & 0xFF);
    SPI.transfer(addr & 0xFF);

    digitalWrite(FLASH_CS, HIGH);

    flashWaitBusy();
}

//------------------------------------------------
void flashPageProgram(uint32_t addr, uint8_t *data, uint16_t len)
{
    flashWriteEnable();

    digitalWrite(FLASH_CS, LOW);

    SPI.transfer(0x02);

    SPI.transfer((addr >> 16) & 0xFF);
    SPI.transfer((addr >> 8) & 0xFF);
    SPI.transfer(addr & 0xFF);

    for(int i=0;i<len;i++)
    {
        SPI.transfer(data[i]);
    }

    digitalWrite(FLASH_CS, HIGH);

    flashWaitBusy();
}

//------------------------------------------------
void flashRead(uint32_t addr, uint8_t *buffer, uint16_t len)
{
    digitalWrite(FLASH_CS, LOW);

    SPI.transfer(0x03);

    SPI.transfer((addr >> 16) & 0xFF);
    SPI.transfer((addr >> 8) & 0xFF);
    SPI.transfer(addr & 0xFF);

    for(int i=0;i<len;i++)
    {
        buffer[i] = SPI.transfer(0);
    }

    digitalWrite(FLASH_CS, HIGH);
}

//------------------------------------------------
void findNextFreeLocation()
{
    uint8_t value;

    currentAddress = 0;

    while(currentAddress < FLASH_SIZE)
    {
        flashRead(currentAddress,&value,1);

        if(value == 0xFF)
        {
            break;
        }

        currentAddress++;
    }

    Serial.print("Next Free Address : 0x");
    Serial.println(currentAddress,HEX);
}

//------------------------------------------------
uint8_t readDistance()
{
    digitalWrite(TRIG_PIN,LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN,HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG_PIN,LOW);

    long duration = pulseIn(ECHO_PIN,HIGH);

    uint8_t distance =
        (uint8_t)(duration * 0.0343 / 2);

    return distance;
}

//------------------------------------------------
void setup()
{
    Serial.begin(115200);

    SPI.begin(18,19,23,5);

    pinMode(FLASH_CS,OUTPUT);
    digitalWrite(FLASH_CS,HIGH);

    pinMode(TRIG_PIN,OUTPUT);
    pinMode(ECHO_PIN,INPUT);

    delay(100);

    flashReadID();

    findNextFreeLocation();
}

//------------------------------------------------
void loop()
{
    if(currentAddress >= FLASH_SIZE)
    {
        Serial.println("FLASH FULL");

        while(1);
    }

    if((currentAddress % SECTOR_SIZE) == 0)
    {
        uint8_t value;

        flashRead(currentAddress,&value,1);

        if(value == 0xFF)
        {
            Serial.print("Erasing Sector : 0x");
            Serial.println(currentAddress,HEX);

            flashSectorErase(currentAddress);
        }
    }

    uint8_t distance = readDistance();

    flashPageProgram(currentAddress, &distance, 1);

    uint8_t verify;

    flashRead(currentAddress, &verify, 1);

    Serial.print("Address : 0x");
    Serial.print(currentAddress,HEX);

    Serial.print("  Distance : ");
    Serial.print(distance);

    Serial.print("  Verify : ");
    Serial.println(verify);

    currentAddress++;

    delay(1000);
}