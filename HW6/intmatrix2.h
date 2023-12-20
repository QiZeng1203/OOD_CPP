/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: intmatrix2.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has intmatrix2  class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#pragma once

/*----------------------------------------------------------------
NOTHING CAM BE ADDED except ../util/util.h
-----------------------------------------------------------------*/
#include "../util/util.h"


/*----------------------------------------------------------------
Declaration of intmatrix2 class
-----------------------------------------------------------------*/
class intmatrix2 {
public:
  //WRITE CODE.
  //CANNOT DECLARE ANY GLOBAL VARIABLE
  intmatrix2();
  intmatrix2(int row, int col);
  intmatrix2(int row, int col, int value);
  intmatrix2(const string& str);

  int getRow();
  void setRow(int row);
  int getCol();
  void setCol(int col);
  vector<vector<int>>& getMatrix();
  void setMatrix(vector<vector<int>>& matrix);


  intmatrix2 add(intmatrix2& matrix);
  intmatrix2 mult(intmatrix2& matrix);
  bool isEqual(intmatrix2& matrix);

  friend ostream& operator<<(ostream& o, intmatrix2& matrix);
  friend bool operator!(intmatrix2& matrix);


  //USE this as is. I will explain when I show
  static void makeShowOn() {_show = true;}
  static void makeShowOff() {_show = false;}
  static bool show() {return _show ;} 

private:
  static bool _show ; //MUST USE THIS
  //WRITE CODE BELOW
  //use xxx_ so that we know all variables are private
  //const string& str_;
  int row_;
  int col_;
  int value_;
  vector<vector<int>> matrix_;
};





//EOF

