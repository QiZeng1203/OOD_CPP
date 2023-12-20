/*----------------------------------------------------------------
Copyright (c) 2019 Author: Jagadeesh Vasudevamurthy
file:ninetyninepointerbased.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
compute string- pointer version
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine.h"


/*----------------------------------------------------------------
compute strings pointer based

YOU GET 
n
and you have to generate pointer to string a and pointer to string b

if n = 90
a points to string ninety
b points to empty string
bool is true

if n = 1
a points to string 0ne
b points to empty string
bool is false
----------------------------------------------------------------*/
bool ninetynine::compute_string_(int n, const string** a, const string** b) {
  bool plural = true;
  //WRITE CODE
    int num1 = n/10;
    int num2 = n%10;

    *a = &(tens[num1]);
    *b = &(units[num2]);

    if(num1 == 1 && num2 != 0) {
        n -= 10;
        *a = &(tens[0]);
        *b = &(teens[n]);
    }
    if(n == 0) {
        *a = &(zero);
    }

  if(n == 1) {
      plural = false;
  }
  return plural;
}


/*----------------------------------------------------------------
compute strings using Pointers
*----------------------------------------------------------------*/
void ninetynine::stanzaPointer_(int n) {
  const string* a = nullptr ;
  const string* b = nullptr ;
  const string* c = nullptr ;
  const string* d = nullptr ;
 
  //WRITE CODE 
  //MUST CALL compute_string_
  //MUST CALL PRINT which prints a stanza
  bool x = compute_string_(n, &a, &b);
  bool y = compute_string_(n-1, &c, &d);

  print_( *a, *b, x, *c, *d, y);
}

//EOF

