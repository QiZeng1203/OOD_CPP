#include "basepluscommissionemployee.h"

basepluscommissionemployee::basepluscommissionemployee(const string& f, const string& l, const string& s, const string& who, int salary, const string& where, int baseSalary):commissionemployee(f, l, s, who, salary),_where(new string(where)), _baseSalary(baseSalary) {
    if(employee::getShow()) {
        cout << "In basepluscommissionemployee::basepluscommissionemployee constructor " << f << " " << l << " " << s << " " << who << " " << salary << " " << where << " " << baseSalary << endl;
    }
}

basepluscommissionemployee::~basepluscommissionemployee() {
    if(employee::getShow()) {
        cout << "In basepluscommissionemployee::~basepluscommissionemployee distructor " << getFirst() << " " << getLast() << " " << getSSN() << " " << getWho() << " " << getSalary() << " " << *_where << " " << _baseSalary << endl;
    }
    delete _where;
}

basepluscommissionemployee::basepluscommissionemployee(const basepluscommissionemployee& b) : commissionemployee(b), _where(new string(*(b._where))), _baseSalary(b._baseSalary) {
    if(employee::getShow()) {
        cout << "In basepluscommissionemployee copy constructor " << b.getFirst() << " " << b.getLast() << " " << b.getSSN() << " " << b.getWho() << " " << b.getSalary() << " " << *_where << " " << _baseSalary << endl;
    }
}

basepluscommissionemployee& basepluscommissionemployee::operator=(const basepluscommissionemployee& b) {
    if (this != &b) {
        commissionemployee::operator=(b); // Call base class assignment operator
        //cout << *s._w << " " << s._salary << endl;
        delete _where;
        _where = new string(*(b._where));
        _baseSalary = b._baseSalary;
    }
    if(employee::getShow()) {
        cout << "In basepluscommissionemployee equal constructor " << b.getFirst() << " " << b.getLast() << " " << b.getSSN() << " " << b.getWho() << " " << b.getSalary() << " " << *_where << " " << _baseSalary << endl;
    }

    return *this;
}

ostream& operator<<(ostream& o, const basepluscommissionemployee& c) {
    c.print(o);
    return o;
}

ostream& basepluscommissionemployee::print(ostream& o) const {
    this->commissionemployee::print(o);
    o << " " << *_where << " " << _baseSalary;
    return o;
}
