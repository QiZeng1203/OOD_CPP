#include "commissionemployee.h"

commissionemployee::commissionemployee(const string& f, const string& l, const string& s, const string& w, int salary):employee(f, l, s),_w(new string(w)), _salary(salary) {
    if(employee::getShow()) {
        cout << "In commissionemployee::commissionemployee constructor " << f << " " << l << " " << s << " " << w << " " << salary << endl;
    }
}

commissionemployee::~commissionemployee() {
    if(employee::getShow()) {
        cout << "In commissionemployee::~commissionemployee distructor " << getFirst() << " " << getLast() << " " << getSSN() << " " << *_w << " " << _salary << endl;
    }
    delete _w;
}

commissionemployee::commissionemployee(const commissionemployee& s) : employee(s), _w(new string(*(s._w))), _salary(s._salary) {
    if(employee::getShow()) {
        cout << "In commissionemployee copy constructor " << s.getFirst() << " " << s.getLast() << " " << s.getSSN() << " " << *_w << " " << _salary << endl;
    }
}

commissionemployee& commissionemployee::operator=(const commissionemployee& c) {
    if (this != &c) {
        employee::operator=(c); // Call base class assignment operator
        //cout << *s._w << " " << s._salary << endl;
        delete _w;
        _w = new string(*(c._w));
        _salary = c._salary;
    }
    if(employee::getShow()) {
        cout << "In commissionemployee equal constructor " << c.getFirst() << " " << c.getLast() << " " << c.getSSN() << " " << *_w << " " << _salary << endl;
    }

    return *this;
}

ostream& operator<<(ostream& o, const commissionemployee& c) {
    c.print(o);
    return o;
}

ostream& commissionemployee::print(ostream& o) const {
    this->employee::print(o);
    o << " " << *_w << " " << _salary;
    return o;
}

string commissionemployee::getWho() const {
    return *_w;
}

int commissionemployee::getSalary() const {
    return _salary;
}