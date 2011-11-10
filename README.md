BasicTerm
=========

BasicTerm is an Arduino library providing basic ANSI/VT220 terminal
control over (typically) a serial connection.

The canonical version of BasicTerm is available on
[GitHub](http://github.com/nottwo/BasicTerm).

Features
--------

* terminal initialization
* clearing the screen
* arbitrary positioning of the cursor
* outputting characters and strings
* showing and hiding the cursor

Dependencies
------------

BasicTerm uses the F macro introduced in Arduino 1.0 to store constant
strings in program flash memory and so will not work with prior versions
of Arduino.

It should be possible to use BasicTerm with Arduino 022 in combination
with Mikal Hart's [Flash library](http://arduiniana.org/libraries/flash)
with the accompanying modifications to the Print class.

Installation
------------

Cloning the BasicTerm repository or copying the BasicTerm directory into
~/sketchbook/libraries and restarting the Arduino IDE should be
sufficient to make BasicTerm available in the Sketch | Import Library
menu.

License
-------

BasicTerm is licensed under the terms of the GNU Lesser
General Public License v3.

Author
------
Trannie Carter <borys@nottwo.org>

Future development
------------------

* attributes
* control sequence (function, arrow keys) reading
