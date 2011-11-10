/*
 * BasicTerm.h
 * Provides basic ANSI/VT220 terminal control over a serial interface
 * Copyright 2011 Trannie Carter <borys@nottwo.org>
 * Licensed for use under the terms of the GNU Lesser General Public License v3
 */

#ifndef BASICTERM_H
#define BASICTERM_H

#include <Arduino.h>

class BasicTerm {

    private: 
        Stream *serial;

    public:
        BasicTerm(Stream *);
        void init(void);
        void cls(void);
        void position(uint8_t, uint8_t);
        void print(uint8_t);
        void print(char *);
        void show_cursor(boolean);
};

#endif
