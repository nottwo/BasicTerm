/*
 * StatusMonitor
 *
 * Displays formatted, dynamic, real-time Arduino status information
 * using BasicTerm.
 *
 * It responds to the following input commands:
 * ' '  (space):  Toggle LED
 * '' (Ctrl-L): Redraw screen
 */

#include <BasicTerm.h>

BasicTerm term(&Serial);

#define LED 13

int16_t now;
int16_t last;

void setup(void) {
    Serial.begin(9600);

    pinMode(LED, OUTPUT);

    uint8_t i;

    for(i = A0; i <= A5; i++) {
        pinMode(i, INPUT);
    }

    for(i = 2; i <= 12; i++) {
        pinMode(i, INPUT);
    }

    digitalWrite(LED, LOW);

    term.init();
    term.cls();
    term.show_cursor(false);

    now = millis();

}

#define DIGITAL_ROW 4
#define ANALOG_ROW  9

void loop(void) {
    uint8_t i = 0;
    uint16_t key;

    last = now;
    now  = millis();

    term.position(1, 1);
    term.print("Arduino Status Monitor   ");

    term.print("Current millis: ");
    term.print(now);
    term.print("  millis since last loop: ");
    term.print(now - last);

    term.position(2, 1);
    term.print("LED ");
    if(digitalRead(LED) == HIGH) {
        term.print( "ON" );
    } else {
        term.print( "OFF" );
    }

    term.position(DIGITAL_ROW, 1);
    term.print("Digital Readings");

    for(i = 0; i <= 13; i++) {
        term.position(DIGITAL_ROW + 1, (i)*6 + 1);
        term.print("DIN");
        term.print(i);
        term.position(DIGITAL_ROW + 2, (i)*6 + 1);
        term.print(digitalRead(i));
    }

    term.position(ANALOG_ROW, 1);
    term.print("Analog Readings");

    for(i = A0; i <= A5; i++) {
        term.position(ANALOG_ROW + 1, (i-A0)*6 + 1);
        term.print("AIN");
        term.print(i - A0);
        term.position(ANALOG_ROW + 2, (i-A0)*6 + 1);
        term.print(analogRead(i));
    }

    key = term.get_key();
    switch(key) {
        case ' ':
            /* Spacebar: toggle LED */
            digitalWrite(LED, !digitalRead(LED));
            break;
        case '':
            /* Ctrl-L: redraw screen */
            term.cls();
            break;
    }
}
