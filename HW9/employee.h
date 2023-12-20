#pragma once
#include <iostream>
#include <fstream>

#include <iomanip>      // std::setprecisio
using namespace std;

#include <stdexcept> //Without this catch will NOT work on Linux
#include <vector>
#include <string>


class employee {
public:
    employee(const string& f, const string& l, const string& s);
    virtual ~employee();
    employee(const employee& e);
    employee& operator=(const employee& e);
    friend ostream& operator<<(ostream& o, const employee& e);
    virtual ostream& print(ostream& o) const;

    string getFirst() const;
    string getLast() const;
    string getSSN() const;
    bool getShow();

    static void setShow(bool show);

private:
    string* _f;
    string* _l;
    string* _s;
    static bool _show;
};
