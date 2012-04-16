/*
 * StatusMonitor
 *
 * Displays formatted, dynamic, real-time Arduino status information
 * using BasicTerm.
 *
 * It responds to the following input commands:
 * ' '  (space):  Toggle LED
 * '\f' (Ctrl-L): Redraw screen
 */

#include <BasicTerm.h>

BasicTerm term(&Serial);

#define LED 13

uint32_t now;
uint32_t last;

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

#define DIGITAL_ROW 3
#define ANALOG_ROW  7

void loop(void) {
    uint8_t i = 0;
    uint16_t key;

    last = now;
    now  = millis();

    term.position(0, 0);
    term.set_attribute(BT_NORMAL);
    term.set_attribute(BT_BOLD);
    term.print(F("Arduino Status Monitor\t"));

    term.set_attribute(BT_NORMAL);
    term.print(F("Current millis: "));
    term.print(now);
    term.print(F("\tmillis since last loop: "));
    term.set_attribute(BT_UNDERLINE);
    term.print(now - last);
    term.set_attribute(BT_NORMAL);

    term.position(1, 0);
    term.print(F("LED "));
    term.set_color(BT_GREEN, BT_BLACK);
    if(digitalRead(LED) == HIGH) {
        term.set_attribute(BT_BOLD | BT_UNDERLINE);
        term.print(F("ON "));
    } else {
        term.print(F("OFF"));
    }
    term.set_attribute(BT_NORMAL);

    term.position(DIGITAL_ROW, 0);
    term.print(F("Digital Readings"));

    for(i = 0; i <= 13; i++) {
        term.position(DIGITAL_ROW + 1, (i)*6);
        term.set_attribute(BT_NORMAL);
        term.print("DIN");
        term.print(i);
        term.set_color(BT_RED, BT_BLACK);
        term.position(DIGITAL_ROW + 2, (i)*6);
        term.print(digitalRead(i));
    }

    term.set_attribute(BT_NORMAL);
    term.position(ANALOG_ROW, 0);
    term.print(F("Analog Readings"));

    for(i = A0; i <= A5; i++) {
        term.position(ANALOG_ROW + 1, (i-A0)*6);
        term.set_attribute(BT_NORMAL);
        term.print(F("AIN"));
        term.print(i - A0);
        term.set_color(BT_MAGENTA, BT_BLACK);
        term.position(ANALOG_ROW + 2, (i-A0)*6);
        term.print(analogRead(i));
    }

    key = term.get_key();
    switch(key) {
        case ' ':
            /* Spacebar: toggle LED */
            digitalWrite(LED, !digitalRead(LED));
            break;
        case '\f':
            /* Ctrl-L: redraw screen */
            term.cls();
            break;
    }
}
