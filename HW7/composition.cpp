/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: composition.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
only includes here
-----------------------------------------------------------------*/
#include "composition.h"

mstring::mstring(const char* s) {
    if (SHOW) {
        cout << "in mstring constructor " << s << endl;
    }
    _allocate(s);
}

mstring::~mstring() {
    if(SHOW) {
        cout << "in mstring destructor " << *s_ << endl;
    }
    _free();
}

mstring::mstring(const mstring& rhs) {
    if(SHOW) {
        cout << "in mstring copy constructor " << *rhs.s_ << endl;
    }
    _allocate(rhs.s_->c_str());
}

mstring& mstring::operator=(const mstring& rhs) {
    if(SHOW) {
        cout << "in mstring equal constructor " << rhs << endl;
    }
    if(this != &rhs) {
        _free();
        _allocate(rhs.s_->c_str());
    }
    return *this;
}

ostream& operator<<(ostream& o, const mstring& rhs) {
    if(rhs) {
        o << *rhs.s_;
    }
    return o;
}

mstring::operator bool() const{
    return s_ != nullptr;
}

void mstring::_allocate(const char* s) {
    #ifdef RAWPOINTER
        s_ = new string(s);
    #endif
    #ifdef UNIQUEPOINTER
        s_ = make_unique<string>(s);
    #endif

}
void mstring::_free() {
#ifdef RAWPOINTER
    delete s_;
#endif
#ifdef UNIQUEPOINTER
    s_.reset();
#endif
}

//ssn
ssn::ssn(const string& s, const string& n, const string& c):ssn_(mstring(s.c_str())), name_(mstring(n.c_str())), country_(mstring(c.c_str())){
    if(SHOW) {
        cout << "in ssn constructor " << endl;
    }
}

ssn::~ssn() {
    if(SHOW) {
        cout << "in ssn destructor " << endl;
    }
}

ostream& operator<<(ostream& o, const ssn& r) {
    if(r.name_) {
        o << r.name_ << " ";
    }
    if(r.ssn_) {
        o << r.ssn_ << " ";
    }
    o << r.country_;
    return o;
}

//name
name::name(const string& f, const string& l, const string& m, const string& t):fname_(mstring(f.c_str())), lname_(mstring(l.c_str())), mname_(mstring(m.c_str())), title_(mstring(t.c_str())) {
    if(SHOW) {
        cout << "in name constructor " << endl;
    }
}

name::~name() {
    if(SHOW) {
        cout << "in name destructor " << endl;
    }
}

ostream& operator<<(ostream& o, const name& r) {
    if(r.title_) {
        o << r.title_ << " ";
    }
    if(r.fname_) {
        o << r.fname_ << " ";
    }
    if(r.mname_) {
        o << r.mname_ << " ";
    }
    o << r.lname_;
    return o;
}

//dob
dob::dob(const int m, const int d, const int y) : month_(m), day_(d), year_(y) {
    if(SHOW) {
        cout << "in dob constructor " << endl;
    }
}

dob::~dob() {
    if(SHOW) {
        cout << "in dob destructor " << endl;
    }
}

ostream& operator<<(ostream& o, const dob& r) {
    o << r.month_ << "/" << r.day_ << "/" << r.year_;
    return o;
}

//person
person::person(const ssn& s, const name& n, const dob& d, const mstring& p, bool l):ssn_(s), name_(n), _dob(d), _currentp_lace_of_residence(p), _isalive(l) {
    if(SHOW) {
        cout << "in person constructor " << endl;
    }
}

person::~person() {
    if(SHOW) {
        cout << "in person destructor " << endl;
    }
}

ostream& operator<<(ostream& o, const person& r) {
    o << r.ssn_ << " " << r.name_ << " " << r._dob << " " << r._currentp_lace_of_residence;
    if(!r._isalive) {
        o << " Dead ";
    }
    return o;
}

//graduate
ostream& operator<<(ostream& o, const graduate& r) {
    o << r.p_ << " " << r.degree_awarded_ << " " << r.year_;
    return o;
}

//list_of_graduates class
ostream& operator<<(ostream& o, const list_of_graduates& r) {
    for (int i = 0; i < r.size_; i++) {
        o << *r.list_[i] << endl;
    }
    return o;
}












