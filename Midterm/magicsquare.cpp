/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: magicsquare.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has magicsquare class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "magicsquare.h"

//Constructor
magicsquare::magicsquare(const int n):n_(n) {
    cout << "In Constructor " <<  n << endl;
    _alloc();
    _generateMagicSquare();
}

//Copy Constructor
magicsquare::magicsquare(magicsquare& matrix):n_(matrix.n_) {
    if(magicsquare::show) {
        cout << "In Copy Constructor " << matrix.n_ << endl;
    }
    _alloc();
    _copy(matrix);
}

//Equal Operator
magicsquare& magicsquare::operator=(magicsquare& matrix) {
    if(magicsquare::show) {
        cout << "In Equal Operator " << matrix.n_ << endl;
    }

    if(this != &matrix) {
        _release();
        _alloc();
        _copy(matrix);
    }
    return *this;
}

int magicsquare::getRC(int r, int c) {
    return matrix_->at(r)->at(c);
}


//Distructor
magicsquare::~magicsquare() {
    if(magicsquare::show) {
        cout << "In Distructor " << n_ <<endl;
    }
    _release();
}

void magicsquare::_alloc() {
    matrix_ = new vector<vector<int>*>;
    for(int i = 0; i < n_; i++) {
        vector<int>* row = new vector<int>(n_);
        matrix_->push_back(row);
    }
}

void magicsquare::_release() {
    for(vector<int>* row : *matrix_) {
        delete row;
    }
    delete matrix_;
}

void magicsquare::_copy(magicsquare& matrix) {
    for(int i = 0; i < n_; i++) {
        for(int j = 0; j < n_; j++) {
            int value = matrix.getRC(i, j);
            matrix_->at(i)->at(j) = value;
        }
    }
}

void magicsquare::_generateMagicSquare() {
    int row = 0;
    int col = n_/2;
    int value = 1;
    while(value <= n_ * n_) {
        matrix_->at(row)->at(col) = value;
        row--;
        col--;
        if(row < 0) {
            row = n_ - 1;
        }
        if(col < 0) {
            col = n_ - 1;
        }
        if(matrix_->at(row)->at(col) != 0) {
            row += 2;
            col ++;
            if(row >= n_) {
                row = 1;
            }
            if(col >= n_) {
                col = 0;
            }
        }
        value ++;
    }
}

//print matrix
ostream& operator<<(ostream& o, magicsquare& matrix) {
    if(magicsquare::show) {
        int sum  = 0;
        for(int i = 0; i < matrix.n_; i++) {
            sum += matrix.getRC(0, i);
        }
        cout << "magic square for n = " << matrix.n_ << ", sum = " << sum << endl;

        if(matrix.n_ <= 9) {
            for(int i = 0; i < matrix.n_; i++) {
                for(int j = 0; j < matrix.n_; j++) {
                    o << matrix.getRC(i, j) << ' ';
                }
                o << endl;
            }
        }
        cout << "--------------------------";
    }
    return o;
}


/*----------------------------------------------------------------
space for static
-----------------------------------------------------------------*/
bool magicsquare::show = false;
