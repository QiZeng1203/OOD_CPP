/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: composition.h
-----------------------------------------------------------------*/


/*----------------------------------------------------------------
RUN TWICE. OUTPUT MUST BE SAME
-----------------------------------------------------------------*/
//#define RAWPOINTER
#define UNIQUEPOINTER


#pragma once
/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include <iostream>
#include <fstream>

#include <iomanip>      // std::setprecisio
using namespace std;

#ifdef _WIN32
#include <cassert>
#include <ctime>
#else
#include <assert.h>
#include <time.h>
#endif

/*----------------------------------------------------------------
Basic defines here 
-----------------------------------------------------------------*/
static const int SHOW = 1;

/*----------------------------------------------------------------
mstring class
-----------------------------------------------------------------*/
class mstring{
public:
  mstring(const char* s);
  ~mstring();
  mstring(const mstring& rhs);
  mstring& operator=(const mstring& rhs);
  friend ostream& operator<<(ostream& o, const mstring& rhs);
  operator bool() const;
  
private:
  //data
#ifdef RAWPOINTER
  string* s_;
#endif
#ifdef UNIQUEPOINTER   
  unique_ptr<string> s_;
#endif
  void _allocate(const char* s);
  void _free();
 
};

/*----------------------------------------------------------------
SSN class
-----------------------------------------------------------------*/
class ssn{
public:
    ssn(const string& s, const string& n = "", const string& c = "");
    ~ssn();
    friend ostream& operator<<(ostream& o, const ssn& r);

private:
  //data
  mstring ssn_ ; //2156789PQ
  mstring name_ ; //SSN/Pan etc
  mstring country_ ; //Country issued
};

/*----------------------------------------------------------------
name class
-----------------------------------------------------------------*/
class name{
public:
    name(const string& f, const string& l = "", const string& m = "", const string& t = "");
    ~name();
    friend ostream& operator<<(ostream& o, const name& r);

private:
  mstring fname_;
  mstring lname_ ;
  mstring mname_ ;
  mstring title_ ;
};

/*----------------------------------------------------------------
date of birth class
-----------------------------------------------------------------*/
class dob{
public:
    dob(const int m, const int d, const int y);
    ~dob();
    friend ostream& operator<<(ostream& o, const dob& r);

private:
  //data
  unsigned int month_ ;
  unsigned int day_ ;
  unsigned int year_ ;
};


/*----------------------------------------------------------------
person class
-----------------------------------------------------------------*/
class person{
public:
    person(const ssn& s, const name& n, const dob& d, const mstring& p, bool l = true);
    ~person();
    friend ostream& operator<<(ostream& o, const person& r);
  
private:
  //data
  ssn ssn_ ;
  name name_ ;
  dob _dob ;
  mstring _currentp_lace_of_residence ;
  bool _isalive ;
};

/*----------------------------------------------------------------
graduate class
-----------------------------------------------------------------*/
class graduate{
public:
  graduate(const person& p, const mstring& m, int y):p_(p),degree_awarded_(m),year_(y){
    if (SHOW) {
      cout << "in graduate constructor " << endl ;
    }
  }
  ~graduate() {
    if (SHOW) {
      cout << "in graduate disstructor " << endl ;
    }
  }
  friend ostream& operator<<(ostream& o, const graduate& r);
  
private:
  person p_ ;
  mstring degree_awarded_ ;
  int year_ ;
};

/*----------------------------------------------------------------
graduate class
-----------------------------------------------------------------*/
class list_of_graduates{
public:
  list_of_graduates(int maxsize = 50):maxsize_(maxsize),size_(0),list_(nullptr) {
    if (SHOW) {
      cout << "in list_of_graduates constructor " << endl ;
    }
    //WRITE CODE
    list_ = new graduate*[maxsize_];
  }
  ~list_of_graduates() {
    if (SHOW) {
        cout << "in list_of_graduates destructor " << endl;
    }
    //WRITE CODE
    for(int i = 0; i < size_; i++) {
        delete list_[i];
    }
    delete [] list_;
    list_ = 0;
    size_ = 0;
  }
 
  void append(const graduate& g) {
    //WRITE CODE
    assert(size_ < maxsize_);
    graduate* t = new graduate(g);
    list_[size_++] = t;;
  }
  //WRITE cout
  friend ostream& operator<<(ostream& o, const list_of_graduates& r);

private:
  int maxsize_ ;
  int size_ ;
  graduate** list_ ;
};

//EOF

