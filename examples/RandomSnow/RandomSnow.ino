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
    uint8_t row = random(0, 23);
    uint8_t col = random(0, 79);

    term.position(row, col);

    term.set_attribute(random(0, BT_BOLD | BT_UNDERLINE | BT_BLINK | BT_REVERSE));
    term.set_color(random(BT_BLACK, BT_WHITE), random(BT_BLACK, BT_WHITE));

    term.print("*");
    if(millis() % 255 == 0) {
        term.set_attribute(BT_NORMAL);
        term.cls();
    }
}
