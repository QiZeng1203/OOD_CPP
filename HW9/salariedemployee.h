#pragma once
#include <iostream>
#include <fstream>

#include <iomanip>      // std::setprecisio
using namespace std;

#include <stdexcept> //Without this catch will NOT work on Linux
#include <vector>
#include <string>

#include "employee.h"

class salariedemployee : public employee {
public:
    salariedemployee(const string& f, const string& l, const string& s, const string& w, int salary);
    ~salariedemployee();
    salariedemployee(const salariedemployee& s);
    salariedemployee& operator=(const salariedemployee& s);
    virtual ostream& print(ostream& o) const;

private:
    string* _w;
    int _salary;
};

