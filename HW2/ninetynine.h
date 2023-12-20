/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: ninetynine.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ninetynine class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ninetynine_H
#define ninetynine_H

#include "../util/util.h"

/*----------------------------------------------------------------
Declaration of ninetynine class
-----------------------------------------------------------------*/
class ninetynine{
private:
  const int MAX = 99 ;
  //WRITE ALL PRIVATE FUNCTIONS HERE
  //WRITE ALL STRING INITIALIZATIONS HERE
  void print_(const string& a,  const string& b, bool x, const string& c, const string& d, bool y);
  bool compute_string_(int n, const string** a, const string** b);
  void stanzaPointer_(int n);
  bool compute_string_(int n, string& a, string& b);
  void stanzaReference_(int n);

  const string zero = "Zero ";
  const string units[10] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
  const string teens[10] = {"", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
  const string tens[10] = {"", "Ten  ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};

public:
  //NOTHING CAN BE ADDED IN PUBLIC
  void run();
};

#endif

