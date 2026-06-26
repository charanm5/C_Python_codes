#include <SPI.h>

#define CS_PIN 5

SPIClass spi(VSPI);


#define CMD_JEDEC_ID  0x9F
#define CMD_WRITE_EN   0x06
#define CMD_READ_DATA  0x03
#define CMD_PAGE_PROG  0x02
#define CMD_SECTOR_ER  0x20
#define CMD_READ_STAT  0x05

void writeEnable() {
  digitalWrite(CS_PIN, LOW);
  spi.transfer(CMD_WRITE_EN);
  digitalWrite(CS_PIN, HIGH);
}

void waitBusy() {
  digitalWrite(CS_PIN, LOW);
  spi.transfer(CMD_READ_STAT);
  while (spi.transfer(0x00) & 0x01);
  digitalWrite(CS_PIN, HIGH);
}

void readID() {
  digitalWrite(CS_PIN, LOW);
  spi.transfer(CMD_JEDEC_ID);

  byte mfg = spi.transfer(0);
  byte mem = spi.transfer(0);
  byte cap = spi.transfer(0);

  digitalWrite(CS_PIN, HIGH);

  Serial.print("JEDEC ID: ");
  Serial.print(mfg, HEX); Serial.print(" ");
  Serial.print(mem, HEX); Serial.print(" ");
  Serial.println(cap, HEX);
}

void eraseSector(uint32_t addr) {
  writeEnable();

  digitalWrite(CS_PIN, LOW);
  spi.transfer(CMD_SECTOR_ER);
  spi.transfer((addr >> 16) & 0xFF);
  spi.transfer((addr >> 8) & 0xFF);
  spi.transfer(addr & 0xFF);
  digitalWrite(CS_PIN, HIGH);

  waitBusy();
}

void writePage(uint32_t addr, const char* data, int len) {
  writeEnable();

  digitalWrite(CS_PIN, LOW);
  spi.transfer(CMD_PAGE_PROG);
  spi.transfer((addr >> 16) & 0xFF);
  spi.transfer((addr >> 8) & 0xFF);
  spi.transfer(addr & 0xFF);

  for (int i = 0; i < len; i++) {
    spi.transfer(data[i]);
  }

  digitalWrite(CS_PIN, HIGH);

  waitBusy();
  Serial.println("Write to a page finished");
}

void readData(uint32_t addr, uint8_t* buf, int len) {
  digitalWrite(CS_PIN, LOW);
  spi.transfer(CMD_READ_DATA);

  spi.transfer((addr >> 16) & 0xFF);
  spi.transfer((addr >> 8) & 0xFF);
  spi.transfer(addr & 0xFF);

  for (int i = 0; i < len; i++) {
    buf[i] = spi.transfer(0);
  }

  digitalWrite(CS_PIN, HIGH);
}

void setup() {
    Serial.begin(115200);

    delay(5000);

  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);
  spi.begin(18, 19, 23, CS_PIN);

  readID();

  const char msg[] = "Hello";
  uint32_t addr = 0x000000;

  Serial.println("Erasing sector...");
  eraseSector(addr);

  Serial.println("Writing...");
  writePage(addr, msg, sizeof(msg));

  Serial.println("Reading...");
  char buf[50];
  readData(addr, (uint8_t*)buf, sizeof(msg));

  Serial.print("Data: ");
  Serial.println(buf);

}

void loop() {

}