/*
 * BasicTerm.h
 * Provides basic ANSI/VT220 terminal control over a serial interface
 * Copyright 2011 Trannie Carter <borys@nottwo.org>
 * Licensed for use under the terms of the GNU Lesser General Public License v3
 */

#ifndef BASICTERM_H
#define BASICTERM_H

#include <Arduino.h>

class BasicTerm : public Stream {

#define BT_NORMAL    0
#define BT_BOLD      1
#define BT_UNDERLINE 2
#define BT_BLINK     4
#define BT_REVERSE   8

#define BT_BLACK     0
#define BT_RED       1
#define BT_GREEN     2
#define BT_YELLOW    3
#define BT_BLUE      4
#define BT_MAGENTA   5
#define BT_CYAN      6
#define BT_WHITE     7

#define BT_KEY_UNKNOWN      0401
#define BT_KEY_DOWN         0402
#define BT_KEY_UP           0403
#define BT_KEY_LEFT         0404
#define BT_KEY_RIGHT        0405
#define BT_KEY_F0           0410
#define BT_KEY_F(n)         (BT_KEY_F0 + (n))

#define BT_ALTCHAR          0x80
#define BT_START_ALTCHAR    (F("\x1b(0"))
#define BT_END_ALTCHAR      (F("\x1b(B"))
#define BT_ACS(c)           (BT_ALTCHAR | (c))
#define BT_ULCORNER         BT_ACS('l')
#define BT_LLCORNER         BT_ACS('m')
#define BT_URCORNER         BT_ACS('k')
#define BT_LRCORNER         BT_ACS('j')
#define BT_LTEE             BT_ACS('t')
#define BT_RTEE             BT_ACS('u')
#define BT_BTEE             BT_ACS('v')
#define BT_TTEE             BT_ACS('w')
#define BT_HLINE            BT_ACS('q')
#define BT_VLINE            BT_ACS('x')
#define BT_PLUS             BT_ACS('n')
#define BT_S1               BT_ACS('o')
#define BT_S3               BT_ACS('p')
#define BT_S7               BT_ACS('r')
#define BT_S9               BT_ACS('s')
#define BT_DIAMOND          BT_ACS('`')
#define BT_CKBOARD          BT_ACS('a')
#define BT_DEGREE           BT_ACS('f')
#define BT_PLMINUS          BT_ACS('g')
#define BT_BULLET           BT_ACS('~')
#define BT_LEQUAL           BT_ACS('y')
#define BT_GEQUAL           BT_ACS('z')
#define BT_NEQUAL           BT_ACS('|')
#define BT_POUNDS           BT_ACS('}')

    private: 
        Stream *serial;

    public:
        BasicTerm(Stream *);
        void init(void);
        void cls(void);
        void position(uint8_t, uint8_t);
        void show_cursor(boolean);
        void set_attribute(uint8_t);
        void set_color(uint8_t, uint8_t);
        int16_t get_key(void);

        virtual int available(void);
        virtual int peek(void);
        virtual int read(void);
        virtual void flush(void);
        virtual size_t write(uint8_t);

        using Print::write;
};

#endif
