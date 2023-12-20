/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
Filename: slist1.h
-----------------------------------------------------------------*/
#pragma once


/*----------------------------------------------------------------
Basic include files
-----------------------------------------------------------------*/
#include <iostream>
#include <fstream>

#include <iomanip>      // std::setprecision
using namespace std;

#ifdef _WIN32
#include <cassert>
#else
#include <assert.h>
#endif

/*----------------------------------------------------------------
Must use T. if we want we change to double : #define T double
-----------------------------------------------------------------*/
#define T int 

/*----------------------------------------------------------------
All forward declaration
-----------------------------------------------------------------*/
class node;
class slist1;

/*----------------------------------------------------------------
class Node
-----------------------------------------------------------------*/
class node {
public:
  //Write all public functions below
  node(T data) : data_(data), next_(nullptr) {};

  T& getData() {
      return data_;
  }
  unique_ptr<node>& getNext() {
      return next_;
  }

private:
  T  data_;
  std::unique_ptr<node> next_; //MUST USE. YOU CANNOT CHANGE THIS
  //YOU CANNOT ADD ANY DATA MEMBERS
  //You can have any number of private functions here
};

/*----------------------------------------------------------------
class slist
-----------------------------------------------------------------*/
class slist1 {
public:
  //Write all public functions below
  slist1();
  slist1(const slist1& s);
  //~slist1();

  slist1& operator=(const slist1& s);
  friend ostream& operator<<(ostream& o, slist1& s);
  const T* operator[](int i) const;
  bool operator==(const slist1& s) const;
  bool operator!=(const slist1& s) const;
  friend bool operator!(const slist1& s);
  explicit operator bool();

  void append(T data);
  void prepend(T data);
  int size();
  bool find(T data);
  bool remove(T data);
  
private:
  std::unique_ptr<node> first_; //MUST USE. YOU CANNOT CHANGE THIS
  //YOU CAN ADD ANY OTHER DATA MEMBERS
  //For full grade both append and prepend MUST be O(1)
  //std::unique_ptr<node> last_;
  node* last_;
  int n_;
  
  //You can have any number of private functions here

};


