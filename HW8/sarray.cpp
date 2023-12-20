/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
file: sarray.cpp
-----------------------------------------------------------------*/

#include "sarray.h"

bool Sarray::show = false;
unsigned long long Sarray::num_allocated = 0;
unsigned long long Sarray::num_freed = 0;

Sarray::Sarray(unsigned int size):size_(size), ptr_(nullptr){
    alloc_(size_);
}

Sarray::~Sarray() {
    free_();
}

Sarray::Sarray(const Sarray &rhs) {
    if(rhs.show) {
        cout << "calling copy constructor of size " << rhs.size_ << endl;
    }
    copy_(rhs);
}

Sarray& Sarray::operator = (const Sarray& rhs) { //const
    if(rhs.show) {
        cout << "calling equal operator size " << rhs.size_ << endl;
    }
    if(this != &rhs) {
        free_();
        copy_(rhs);
    }
    return *this;
}

#ifdef MOVE
Sarray::Sarray(Sarray&& rhs) {
    if(rhs.show) {
        cout << "calling move constructor of size " << rhs.size_ << endl;
    }
    move_(rhs);
}

Sarray& Sarray::operator = (Sarray&& rhs) {
    if(rhs.show) {
        cout << "calling move equal operator size " << rhs.size_ << endl;
    }
    if(this != &rhs) {
        free_();
        move_(rhs);
    }
    return *this;
}
#endif

void Swap(Sarray& a, Sarray& b) {
    if(0) {
        Sarray t(a);
        a = b;
        b = t;
    }
    else {
        Sarray t = std::move(a);
        a = std::move(b);
        b = std::move(t);
    }
}

void Sarray::alloc_(unsigned n) {
    if(n) {
        ptr_ = new T[n];
    }
    if(show) {
        cout << "Allocating array of size " << n << endl;
    }
    num_allocated = num_allocated + size_;
}

void Sarray::free_() {
    num_freed = num_freed + size_;
    if(show) {
        if(ptr_) {
            cout << "Freeing array of size " << size_ << endl;
        }
        else {
            cout << "Nothing freed, Array was taken by move/equal operator " << endl;
        }
    }
    delete[] ptr_;
}

void Sarray::copy_(const Sarray& rhs) {
    size_ = rhs.size_;
    alloc_(rhs.size_);
}

void Sarray::move_(Sarray& rhs) {
    size_ = rhs.size_;
    ptr_ = rhs.ptr_;
    rhs.ptr_ = nullptr;
    rhs.size_ = 0;
}



