/*
 * BasicTerm.cpp
 * Provides basic ANSI/VT220 terminal control over a serial interface
 * Copyright 2011 Trannie Carter <borys@nottwo.org>
 * Licensed for use under the terms of the GNU Lesser General Public License v3
 */

#include "BasicTerm.h"

BasicTerm::BasicTerm(Stream *ser) {
    serial = ser;
}

void BasicTerm::init(void) {
   serial->print(F("\x1b\x63")); 
}

void BasicTerm::cls(void) {
    serial->print(F("\x1b[2J"));
}

void BasicTerm::position(uint8_t row, uint8_t col) {
    serial->print(F("\x1b["));
    serial->print((uint8_t)row);
    serial->print(F(";"));
    serial->print((uint8_t)col);
    serial->print(F("H"));
}

void BasicTerm::print(uint8_t c) {
    serial->print(c);
}

void BasicTerm::print(char *s) {
    serial->print(s);
}

void BasicTerm::show_cursor(boolean show) {
    if(show) {
        serial->print(F("\x1b[?25h"));
    } else {
        serial->print(F("\x1b[?25l"));
    }
}

int16_t BasicTerm::get_key(void) {
    return serial->read();
}

void BasicTerm::set_attribute(uint8_t attr) {
    if(attr & BT_REVERSE) {
        serial->print(F("\x1b[7m"));
    }
    if(attr & BT_UNDERLINE) {
        serial->print(F("\x1b[4m"));
    }
    if(attr & BT_BOLD) {
        serial->print(F("\x1b[1m"));
    }
    if(attr & BT_BLINK) {
        serial->print(F("\x1b[5m"));
    }
    if(attr == BT_NORMAL) {
        serial->print(F("\x1b[0m"));
    }
}
