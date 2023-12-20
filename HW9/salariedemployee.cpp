#include "salariedemployee.h"

salariedemployee::salariedemployee(const string& f, const string& l, const string& s, const string& w, int salary):employee(f, l, s),_w(new string(w)), _salary(salary) {
    if(employee::getShow()) {
        cout << "In salariedemployee::salariedemployee constructor " << f << " " << l << " " << s << " " << w << " " << salary << endl;
    }
}

salariedemployee::~salariedemployee() {
    if(employee::getShow()) {
        cout << "In salariedemployee::~salariedemployee distructor " << getFirst() << " " << getLast() << " " << getSSN() << " " << *_w << " " << _salary << endl;
    }
    delete _w;
}

salariedemployee::salariedemployee(const salariedemployee& s) : employee(s), _w(new string(*(s._w))), _salary(s._salary) {
    if(employee::getShow()) {
        cout << "In salariedemployee copy constructor " << s.getFirst() << " " << s.getLast() << " " << s.getSSN() << " " << *_w << " " << _salary << endl;
    }
}

salariedemployee& salariedemployee::operator=(const salariedemployee& s) {
    if (this != &s) {
        employee::operator=(s); // Call base class assignment operator
        delete _w;
        _w = new string(*(s._w));
        _salary = s._salary;
    }
    if(employee::getShow()) {
        cout << "In salariedemployee equal constructor " << s.getFirst() << " " << s.getLast() << " " << s.getSSN() << " " << *_w << " " << _salary << endl;
    }

    return *this;
}


ostream& salariedemployee::print(ostream& o) const {
    this->employee::print(o);
    o << " " << *_w << " " << _salary;
    return o;
}

