#define BUTTON_PIN 2

void setup()
{
    Serial.begin(115200);

    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
    int state = digitalRead(BUTTON_PIN);

    if(state)
      Serial.println("Button Not Pressed");
    else
      Serial.println("Button pressed");

    delay(1000);
}