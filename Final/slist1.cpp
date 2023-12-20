/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
Filename: slist1.cpp
-----------------------------------------------------------------*/

#include "slist1.h"
//NOTHING CAN BE ADDED HERE

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
slist1::slist1() :first_(nullptr), last_(nullptr), n_(0) {}

//slist1::~slist1() {
//    while(first_ != nullptr) {
//        std::unique_ptr<node> temp = std::move(first_);
//        first_ = std::move(temp->getNext());
//    }
//}

void slist1::append(T data) {
    std::unique_ptr<node> newNode = std::make_unique<node>(data);
    if(!first_) {
        first_ = std::move(newNode);
        last_ = first_.get();
    }
    else {
        last_->getNext() = std::move(newNode);
        last_ = last_->getNext().get();
    }
    n_++;
}

void slist1::prepend(T data) {
    std::unique_ptr<node> newNode = std::make_unique<node>(data);
    if(!first_) {
        first_ = std::move(newNode);
        last_ = first_.get();
    }
    else {
        newNode->getNext() = std::move(first_);
        first_ = std::move(newNode);
    }
    n_++;
}

int slist1::size() {
    return n_;
}

bool slist1::find(T data) {
    node* temp = first_.get();
    while(temp) {
        if(temp->getData() == data) {
            return true;
        }
        temp = temp->getNext().get();
    }
    return false;
}

bool slist1::remove(T data) {
    if(!first_) {
        return false;
    }
    if(first_->getData() == data) {
        first_ = std::move(first_->getNext());
        n_--;
        return true;
    }
    node* temp = first_.get();
    while(temp->getNext()) {
        if(temp->getNext()->getData() == data) {
            temp->getNext() = std::move(temp->getNext()->getNext());
            n_--;
            return true;
        }
        temp = temp->getNext().get();
    }
    return false;
}


// Copy constructor
slist1::slist1(const slist1& s) {
    if(s.first_) {
        first_ = std::make_unique<node>(s.first_->getData());
        last_ = first_.get();
        node* temp = s.first_->getNext().get();
        while(temp) {
            last_->getNext() = std::make_unique<node>(temp->getData());
            last_ = last_->getNext().get();
            temp = temp->getNext().get();
        }
        n_ = s.n_;
    }
}

// Overloaded assignment operator
slist1& slist1::operator=(const slist1& s) {
    // Perform deep copy
    if (this != &s) {
        first_ = nullptr;
        last_ = nullptr;
        n_ = 0;

        if(s.first_) {
            first_ = std::make_unique<node>(s.first_->getData());
            last_ = first_.get();
            node* temp = s.first_->getNext().get();
            while(temp) {
                last_->getNext() = std::make_unique<node>(temp->getData());
                last_ = last_->getNext().get();
                temp = temp->getNext().get();
            }
            n_ = s.n_;
        }
    }
    return *this;
}

ostream& operator<<(ostream& o, slist1& s) {
    node* temp = s.first_.get();
    while(temp) {
        o << temp->getData() << "->";
        temp = temp->getNext().get();
    }
    return o;
}

const T* slist1::operator[](int i) const {
    if (i < 0 || i >= n_) {
        return nullptr;
    }

    node* temp = first_.get();
    for (int j = 0; j < i; j++) {
        temp = temp->getNext().get();
    }

    return &(temp->getData());
}

bool slist1::operator==(const slist1& s) const {
    if (n_ != s.n_) {
        return false;
    }
    node* temp1 = first_.get();
    node* temp2 = s.first_.get();

    while (temp1 && temp2) {
        if (temp1->getData() != temp2->getData()) {
            return false;
        }
        temp1 = temp1->getNext().get();
        temp2 = temp2->getNext().get();
    }

    return !temp1 && !temp2;
}

bool slist1::operator!=(const slist1& s) const {
    return !(*this == s);
}

bool operator!(const slist1& s) {
    return s.n_ == 0;
}

slist1::operator bool() {
    return first_ != nullptr;
}

