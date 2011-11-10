/*
 * RandomSnow
 *
 * Demonstration of BasicTerm library
 */

#include <BasicTerm.h>

BasicTerm term(&Serial);

void setup(void) {
    Serial.begin(9600);

    term.init();

    term.cls();
    term.show_cursor(false);

}

void loop(void) {
    uint8_t row = random(1, 24);
    uint8_t col = random(1, 80);

    term.position(row, col);
    term.print("*");

    if(millis() % 255 == 0) {
        term.cls();
    }
}
