#include "employee.h"

bool employee::_show = true;

employee::employee(const string& f, const string& l, const string& s):_f(new string(f)),_l(new string(l)), _s(new string(s)) {
    if(_show) {
        cout << "In employee::employee constructor " << *_f << " " << *_l << " " << *_s << endl;
    }
}

employee::~employee() {
    if (_show) {
        cout << "In employee::~employee distructor " << *_f << " " << *_l << " " << *_s << endl;
    }
    delete _f;
    delete _l;
    delete _s;
}

employee::employee(const employee& e) : _f(new string(*(e._f))), _l(new string(*(e._l))), _s(new string(*(e._s))) {
    if(_show) {
        cout << "In employee copy constructor " << *_f << " " << *_l << " " << *_s << endl;
    }
}

employee& employee::operator=(const employee& e) {
    if (this != &e) {
        delete _f;
        delete _l;
        delete _s;

        _f = new string(*(e._f));
        _l = new string(*(e._l));
        _s = new string(*(e._s));
    }
    if(_show) {
        cout << "In employee equal constructor " << e << endl;
        //cout << "In employee equal constructor " <<  *_f << " " << *_l << " " << *_s << endl;
    }
    return *this;
}

ostream& operator<<(ostream& o, const employee& e) {
    return e.print(o);
    //o << *e._f << " " << *e._l << " " << *e._s;
}

ostream& employee::print(ostream& o) const {
    if(_show) {
        o << *_f << " " << *_l << " " << *_s;
    }
    return o;
}

string employee::getFirst() const {
    return *_f;
}

string employee::getLast() const {
    return *_l;
}

string employee::getSSN() const {
    return *_s;
}

void employee::setShow(bool show) {
    _show = show;
}

bool employee::getShow() {
    return _show;
}



