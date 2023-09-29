const int numPins = 3;  // Number of pins to control
const int outputPins[] = {9, 10, 11};  // The pins you want to control
int periods[numPins][4] = {
  {1000, 500, 2000, 1000},  // Time periods in milliseconds for pin 9
  {500, 1000, 500, 2000},  // Time periods in milliseconds for pin 10
  {2000, 2000, 2000, 2000}   // Time periods in milliseconds for pin 11
};
bool onOff[numPins][4] = {
  {true, false, true, false},  // On/off states for pin 9
  {true, true, false, false},  // On/off states for pin 10
  {true, false, true, false}   // On/off states for pin 11
};

int numSteps = sizeof(periods[0]) / sizeof(periods[0][0]);
unsigned long previousMillis[numPins];
int step[numPins] = {0};

void setup() {
  for (int i = 0; i < numPins; i++) {
    pinMode(outputPins[i], OUTPUT);
    previousMillis[i] = 0;
  }
}

void loop() {
  for (int i = 0; i < numPins; i++) {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis[i] >= periods[i][step[i]]) {
      previousMillis[i] = currentMillis;
      digitalWrite(outputPins[i], onOff[i][step[i]] ? HIGH : LOW);
      step[i] = (step[i] + 1) % numSteps; // Move to the next step, wrap around if needed
    }
  }
}