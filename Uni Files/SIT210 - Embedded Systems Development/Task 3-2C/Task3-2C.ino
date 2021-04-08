// =======================================================================
// Application:      IFTTT Trigger
// Purpose:          Task 3-2C - Create IFTTT Trigger 
// Author:           Justin Bland
// Date:             08/04/2021
// Status            In Development 
// Revisions         08/04/2021 - Create File 
// =======================================================================

// USEFUL INFORMATION ====================================================
// - CODE FORMATTING:
//      Line Length:    75 Characters +~5% if needed 
// =======================================================================

int LDR = A2;
int value;


void setup() {
    pinMode(LDR, INPUT);
    Serial.begin(9600);
}

void loop() {
    value = analogRead(LDR);
    if (value > 2500)
    {
        Particle.publish("Light", "Detected High", PRIVATE);
    }
    else if (value < 2500 && value > 1200)
    {
        Particle.publish("Light", "Detected Low", PRIVATE);
    }
    else
    {
        Particle.publish("Light", "Not Detected", PRIVATE);
    }
delay(5000);
}
