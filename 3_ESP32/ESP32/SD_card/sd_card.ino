#include <SPI.h>
#include <SD.h>

#define SD_CS 5

#define TRIG_PIN 25
#define ECHO_PIN 26

float readDistance()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH, 30000);

    if(duration == 0)
        return -1;

    return duration * 0.0343 / 2.0;
}

void printOldData()
{
    File file = SD.open("/distance.csv");

    if(file)
    {
        Serial.println("\n===== OLD DATA =====");

        while(file.available())
        {
            Serial.write(file.read());
        }

        file.close();

        Serial.println("\n====================");
    }
}

void setup()
{
    Serial.begin(115200);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    SPI.begin(18,19,23,SD_CS);

    if(!SD.begin(SD_CS))
    {
        Serial.println("SD Card Mount Failed");
        while(1);
    }

    Serial.println("SD Card Mounted");

    if(SD.exists("/distance.csv"))
    {
        printOldData();
    }
    else
    {
        File file = SD.open("/distance.csv", FILE_WRITE);

        if(file)
        {
            file.println("Distance(cm)");
            file.close();
        }
    }
}

void loop()
{
    float distance = readDistance();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    File file = SD.open("/distance.csv", FILE_APPEND);

    if(file)
    {
        file.println(distance);
        file.close();

        Serial.println("Saved");
    }
    else
    {
        Serial.println("Write Failed");
    }

    delay(5000);
}