/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: String2Data.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
You cannot include any library here
-----------------------------------------------------------------*/
#include "String2Data.h"

/*----------------------------------------------------------------
WRITE CODE
-----------------------------------------------------------------*/
String2Data::String2Data(const string& str):str_(str) {}

int String2Data::string_2_bool(bool& isbool) {
    if(str_ == "true") {
        isbool = true;
        return 1;
    }
    else if(str_ == "false") {
        isbool = true;
        return 0;
    }
    else {
        isbool = false;
    }
    return 0;
}

long String2Data::string_2_long(bool& islong) {
    long value = 0;
    bool isNegative = false;
    int start = 0;
    if(str_[0] == '-') {
        isNegative = true;
        start = 1;
    }

    for(int i = start; i < str_.size(); i++) {
        if(str_[i] >= '0' && str_[i] <= '9') {
            value = value * 10 + (str_[i] - '0');
        }
        else {
            islong = false;
            return 0l;
        }
    }

    if(isNegative) {
        value = -value;
    }

    islong = true;
    return value;
}

double String2Data::string_2_double(bool& isdouble) {
    double value = 0.0;
    bool isNegative = false;
    bool isDecimal = false;
    int start = 0;
    double decimal = 1.0;

    if(str_[0] == '-') {
        isNegative = true;
        start = 1;
    }

    for(int i = start; i < str_.size(); i++) {
        if(str_[i] >= '0' && str_[i] <= '9') {
            value = value * 10 + (str_[i] - '0');
            if(isDecimal) {
                decimal *= 0.1;
            }
        }
        else if(str_[i] == '.' && !isDecimal) {
            isDecimal = true;
        }
        else {
            isdouble = false;
            return 0.0;
        }
    }

    if(isNegative) {
        value = -value;
    }

    value = value * decimal;
    isdouble = true;
    return value;
}