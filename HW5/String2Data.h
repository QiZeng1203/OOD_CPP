/*----------------------------------------------------------------
All includes here
YOU CANNOT INCLUDE ANY OTHER FILES
-----------------------------------------------------------------*/
#pragma once
#include "util.h"

/*----------------------------------------------------------------
Declaration of String2Data class
-----------------------------------------------------------------*/
class String2Data {
public:
  enum DATATYPE { BOOL = 0, LONG, DOUBLE, STRING };
  void static test_conversion();
  //WRITE CODE
  String2Data(const string& str);

  int string_2_bool(bool& isbool);
  long string_2_long(bool& islong);
  double string_2_double(bool& isdouble);

  
private:
  //CANNOT ADD ANYTHING
  const string& str_;
};

//EOF

