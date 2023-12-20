#pragma once
#include <iostream>
#include <fstream>

#include <iomanip>      // std::setprecisio
using namespace std;

#include <stdexcept> //Without this catch will NOT work on Linux
#include <vector>
#include <string>

#include "employee.h"

class commissionemployee : public employee {
public:
    commissionemployee(const string& f, const string& l, const string& s, const string& w, int salary);
    ~commissionemployee();
    commissionemployee(const commissionemployee& c);
    commissionemployee& operator=(const commissionemployee& c);
    friend ostream& operator<<(ostream& o, const commissionemployee& c);
    virtual ostream& print(ostream& o) const;

    string getWho() const;
    int getSalary() const;

private:
    string* _w;
    int _salary;
};
