/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: prime.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has prime class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "prime.h"

/*----------------------------------------------------------------
Definition of routines of prime class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Space allocation of static must be in CPP file
-----------------------------------------------------------------*/
unsigned long long  prime::kount = 0ll;

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
prime::prime(vector<int>& v, const string& algname, int n): v_(v), algname_(algname), n_(n) {
    if(algname_ == "upto_n_minus_1") {
        upto_n_minus_1_();
    }
    else if(algname_ == "upto_n_by_2") {
        upto_n_by_2_();
    }
    else if(algname_ == "sqrt_of_n") {
        sqrt_of_n_();
    }
}

prime::~prime() {

}
//upto_n_minus_1
void prime::upto_n_minus_1_() {
    v_.push_back(2);
    for(int i = 3; i <= n_; i = i+2) {
        incr_kount();
        if(is_prime_upto_n_minus_1_(i)) {
            v_.push_back(i);
        }
    }
}

bool prime::is_prime_upto_n_minus_1_(int n) {
    for(int i = 2; i < n; i++) {
        incr_kount();
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

// upto_n_by_2
void prime::upto_n_by_2_() {
    v_.push_back(2);
    for(int i = 3; i <= n_; i = i+2) {
        incr_kount();
        if(is_prime_upto_n_by_2_(i)) {
            v_.push_back(i);
        }
    }
}

bool prime::is_prime_upto_n_by_2_(int n) {
    for(int i = 2; i < n/2; i++) {
        incr_kount();
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

// sqrt_of_n
void prime::sqrt_of_n_() {
    v_.push_back(2);
    for(int i = 3; i <= n_; i = i+2) {
        incr_kount();
        if(is_prime_sqrt_of_n_(i)) {
            v_.push_back(i);
        }
    }
}

bool prime::is_prime_sqrt_of_n_(int n) {
    for(int i = 2; (i * i) <= n; i++) {
        incr_kount();
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

//EOF

