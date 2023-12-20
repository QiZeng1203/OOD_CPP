#pragma once
#include <iostream>
#include <fstream>

#include <iomanip>      // std::setprecisio
using namespace std;

#include <stdexcept> //Without this catch will NOT work on Linux
#include <vector>
#include <string>

#include "commissionemployee.h"

class basepluscommissionemployee : public commissionemployee {
public:
    basepluscommissionemployee(const string& f, const string& l, const string& s, const string& who, int salary, const string& where, int baseSalary);
    ~basepluscommissionemployee();
    basepluscommissionemployee(const basepluscommissionemployee& b);
    basepluscommissionemployee& operator=(const basepluscommissionemployee& b);
    friend ostream& operator<<(ostream& o, const basepluscommissionemployee& b);
    virtual ostream& print(ostream& o) const;

private:
    string* _where;
    int _baseSalary;
};