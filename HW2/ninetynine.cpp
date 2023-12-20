/*----------------------------------------------------------------
Copyright (c) 2019 Author: Jagadeesh Vasudevamurthy
file: ninetynine.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ninetynine class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine.h"

/*----------------------------------------------------------------
Ninety nine bottles of beer on the wall,
Ninety nine bottles of beer,
Take one down, pass it around,
Ninety eight bottles of beer on the wall.

One bottle of beer on the wall,
One bottle of beer,
Take one down, pass it around,
Zero bottle of beer on the wall.
(91)
a = Ninety   
b = one   
bool true
(90)
c = Ninety   
d = ""
bool true 

YOU GET a,b, bool
YOU GER c,d, bool

PRINT ONE STANZA HERE
----------------------------------------------------------------*/
void ninetynine::print_( const string& a,  const string& b, bool x, const string& c, const string& d, bool y) {
    string bottle1 = x ? "bottles" : "bottle";
    string bottle2 = y ? "bottles" : "bottle";
    cout << a << b << bottle1 << " of beer on the wall," << endl;
    cout << a << b << bottle1 << " of beer," << endl;
    cout << "Take one down, pass it around," << endl;
    cout << c << d << bottle2 << " of beer on the wall." << endl;
    cout << endl;
}

/*----------------------------------------------------------------
NOTHING CAN BE CHANGED BELOW
*----------------------------------------------------------------*/
void ninetynine::run() {
  cout << "REFERENCE BASED SONG\n" ;
  for (int i = MAX; i > 0; --i) {
    stanzaReference_(i);
  }
  cout << "POINTER BASED SONG\n" ;
  for (int i = MAX; i > 0; --i) {
    stanzaPointer_(i) ;
  }
}

//EOF