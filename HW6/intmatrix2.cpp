/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: intmatrix2.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has intmatrix2 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
NOTHING CAM BE ADDED except intmatrix2.h
-----------------------------------------------------------------*/
#include "intmatrix2.h"

/*----------------------------------------------------------------
Definition of routines of intmatrix2 class
-----------------------------------------------------------------*/
intmatrix2::intmatrix2():row_(0), col_(0), value_(0){}

intmatrix2::intmatrix2(int row, int col):row_(row), col_(col), value_(0) {
    matrix_ = vector<vector<int>> (row_, vector<int>(col_, value_));
}

intmatrix2::intmatrix2(int row, int col, int value):row_(row), col_(col), value_(value) {
    matrix_ = vector<vector<int>> (row_, vector<int>(col_, value_));
}

intmatrix2::intmatrix2(const string& str) {
    if(str.empty()) {
        col_ = 0;
        row_ = 0;
        return;
    }

    string newStr; // process the string, remove the extra space
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == ' ' && str[i+1] == '|') {
            continue;
        }
        if(str[i] == ' ' && (str[i-1] >= '0' && str[i-1] <= '9')) {
            newStr += str[i];
        }
        else if(str[i] == '|') {
            newStr += str[i];
        }
        else if(str[i] >= '0' && str[i] <= '9') {
            newStr += str[i];
        }
    }
    while(!newStr.empty() && newStr.back() == ' ') {
        newStr.pop_back();
    }

    string cleanedStr;
    for(int i = 0; i < newStr.size(); i++) {
        if(newStr[i] == ' ' && newStr[i+1] == '|') {
            continue;
        }
        else {
            cleanedStr += newStr[i];
        }
    }

    int value = 0;
    vector<int> rowVector;
    for(char i : cleanedStr) {
        if(i >= '0' && i <= '9') {
            value = value * 10 + (i - '0');
        }
        else if(i == ' ') {
            rowVector.push_back(value);
            value = 0;
        }
        else if(i == '|' ) {
            rowVector.push_back(value);
            value = 0;
            matrix_.push_back(rowVector);
            rowVector.clear();
        }
    }

    if(value != 0 || (value == 0 && cleanedStr.back() == '0')){ // deal with the last value
        rowVector.push_back(value);
        matrix_.push_back(rowVector);
    }

    col_ = matrix_[0].size();
    row_ = matrix_.size();
    value_ = 0;

    for(int i= 1; i < matrix_.size(); i++) {
        if(matrix_[i].size() != matrix_[0].size()) {
            col_ = 0;
            row_ = 0;
            matrix_.clear();
            break;
        }
    }

}

int intmatrix2::getRow() {
    return row_;
}

int intmatrix2::getCol() {
    return col_;
}

vector<vector<int>>& intmatrix2::getMatrix() {
    return matrix_;
}

void intmatrix2::setRow(int row) {
    row_ = row;
}

void intmatrix2::setCol(int col) {
    col_ = col;
}

void intmatrix2::setMatrix(vector<vector<int>>& matrix) {
    matrix_ = matrix;
}

intmatrix2 intmatrix2::add(intmatrix2& matrix) {
    if(matrix.getCol() != this->getCol() || matrix.getRow() != this->getRow()) {
        intmatrix2 sum;
        return sum;
    }

    intmatrix2 sum(matrix.getRow(), matrix.getCol());
    for(int i = 0; i < matrix.getRow(); i++) {
        for(int j = 0; j < matrix.getCol(); j++) {
            sum.getMatrix()[i][j] = matrix.getMatrix()[i][j] + this->getMatrix()[i][j];
        }
    }
    return sum;
}

intmatrix2 intmatrix2::mult(intmatrix2& matrix) {
    if(this->getCol() == 1 && this->getRow() == 1) {
        intmatrix2 product(matrix.getRow(), matrix.getCol());
        for(int i = 0; i < matrix.getRow(); i++) {
            for (int j = 0; j < matrix.getCol(); j++) {
                product.getMatrix()[i][j] = matrix.getMatrix()[i][j] * this->getMatrix()[0][0];
            }
        }
        return product;
    }
    else if(matrix.getCol() == 1 && matrix.getRow() == 1 ) {
        intmatrix2 product(this->getRow(), this->getCol());
        for(int i = 0; i < this->getRow(); i++) {
            for (int j = 0; j < this->getCol(); j++) {
                product.getMatrix()[i][j] = matrix.getMatrix()[0][0] * this->getMatrix()[i][j];
            }
        }
        return product;
    }
    else if (this->getCol() != matrix.getRow())
        //intmatrix2 product;
        return {};

    else {
        intmatrix2 product(this->getRow(), matrix.getCol());
        for (int i = 0; i < this->getRow(); i++) {
            for (int j = 0; j < matrix.getCol(); j++) {
                for (int k = 0; k < this->getCol(); k++) {
                    product.getMatrix()[i][j] += this->getMatrix()[i][k] * matrix.getMatrix()[k][j];
                }
            }
        }
        return product;
    }
}

bool intmatrix2::isEqual(intmatrix2& matrix) {
    if(matrix.getCol() != this->getCol() || matrix.getRow() != this->getRow()) {
        return false;
    }
    for(int i = 0; i < matrix.getRow(); i++) {
        for(int j = 0; j < matrix.getCol(); j++) {
            if(matrix.getMatrix()[i][j] != this->getMatrix()[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// print matrix
ostream& operator<<(ostream& o, intmatrix2& matrix) {
    if(matrix.getRow() == 0 || matrix.getCol() == 0) {
        o << "Empty Matrix" << endl;
    }
    else {
        if(intmatrix2::_show) {
            for (int i = 0; i < matrix.row_; ++i) {
                for (int j = 0; j < matrix.col_; ++j) {
                    o << matrix.matrix_[i][j] << ' ';
                }
                o << endl;
            }
        }
    }
    return o;
}

bool operator!(intmatrix2& matrix) {
    return matrix.getMatrix().empty();
}

/*----------------------------------------------------------------
Space allocation of static must be in CPP file
-----------------------------------------------------------------*/
bool intmatrix2::_show = false ;

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/


//EOF

