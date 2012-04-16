/*
 * SimpleRL
 *
 * A simple roguelike that lets an @ walk around a fixed map. Feel free
 * to implement random map generation, item, combat, magic & time
 * systems and a winning condition in the 2k/32k/1k you have available :)
 * 
 * My Arduino appears as /dev/ttyACM0 under Linux and I connect to it
 * with:
 *
 *   $ screen /dev/ttyACM0 115200
 *
 * You may have to ensure that you have read & write permissions to the
 * Arduino tty device or access it as root.
 *
 * TeraTerm, PuTTY and minicom are other programs you can use to connect
 * a terminal to your Arduino.
 */

#include <BasicTerm.h>

BasicTerm term(&Serial);

#define MAP_COLS    10
#define MAP_ROWS    10

uint8_t dungeon[] = "####  ####"
                    "#  ####  #"
                    "#        #"
                    "##      ##"
                    " #      # "
                    " #      # "
                    "##      ##"
                    "#        #"
                    "#  ####  #"
                    "####  ####";

struct mob {
    uint8_t y;
    uint8_t x;
    uint8_t rep;
} player = { 1, 1, '@' };

void setup(void) {
    Serial.begin(115200);
    term.init();
    term.cls();
    term.show_cursor(false);
    draw_map();
    draw_mob();
}

void loop(void) {
    int16_t key;

    key = term.get_key();

    if(key != -1) {
        term.position(player.y, player.x);
        term.write(' ');

        switch(key) {
            case BT_KEY_DOWN:
            case 'j':
                map_move(player.y + 1, player.x);
                break;

            case BT_KEY_UP:
            case 'k':
                map_move(player.y - 1, player.x);
                break;

            case BT_KEY_LEFT:
            case 'h':
                map_move(player.y, player.x - 1);
                break;

            case BT_KEY_RIGHT:
            case 'l':
                map_move(player.y, player.x + 1);
                break;

            case 'y':
                map_move(player.y - 1, player.x - 1);
                break;

            case 'n':
                map_move(player.y + 1, player.x + 1);
                break;

            case 'u':
                map_move(player.y - 1, player.x + 1);
                break;

            case 'b':
                map_move(player.y + 1, player.x - 1);
                break;

        }

        draw_mob();
    }
}

void draw_map(void) {
    uint8_t x = 0;
    uint8_t y = 0;

    term.cls();
    for(y; y < MAP_ROWS; y++) {
        term.position(y, 0);
        for(x = 0; x < MAP_COLS; x++) {
            term.write(dungeon[y * MAP_COLS + x]);
        }
        x = 0;
    }
}

void draw_mob(void) {
    term.position(player.y, player.x);
    term.write(player.rep);
}

void map_move(uint8_t y, uint8_t x) {
    if(dungeon[(y) * MAP_COLS + (x)] == ' ') {
        player.y = y;
        player.x = x;
    }
}
