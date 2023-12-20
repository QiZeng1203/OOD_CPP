/*----------------------------------------------------------------
Copyleft (c) 2023 Author: Jagadeesh Vasudevamurthy
file: p2.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has p2 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
YOU CANNOT INCLUDE ANY OTHER FILES
-----------------------------------------------------------------*/
#include "p2.h"

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/


//EOF
int p2::d1(int n, char c) {
    cout << "-------------- n = " << n << "\n";
    for(int col = 0; col < 2 * n - 1; col++) { //print the header number
        cout << col % 10;
    }
    cout << "\n";
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = n-i; j > 0; j--) {
            cout << " ";
        }
        for(int k = 0; k < i; k++) {
            cout << c << " ";
            sum ++;
        }
        cout << "\n";
    }
    cout << "N = " << n << " Number of * = " << sum << "\n";
    return sum;
}

int p2::d2(int n, char c) {
    cout << "-------------- n = " << n << "\n";
    for(int col = 0; col < 2 * n - 1; col++) { //print the header number
        cout << col % 10;
    }
    cout << "\n";
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        for(int k = n-i; k > 0; k--) {
            cout << c << " ";
            sum ++;
        }
        cout << "\n";
    }
    cout << "N = " << n << " Number of * = " << sum << "\n";
    return sum;
}

int p2::d3(int n, char c) {
    cout << "-------------- n = " << n << "\n";
    for(int col = 0; col < n; col++) { //print the header number
        cout << col % 10;
    }
    cout << "\n";
    int sum = 0;
    for(int i = 0; i < n/2+1; i++) {
        for(int j = n/2-i; j > 0; j--) {
            cout << " ";
        }
        cout << c;
        sum ++;
        if(i > 0) {
            for(int k = 0; k < 2 * i - 1; k++) {
                cout << " ";
            }
            cout << c;
            sum ++;
        }
        cout << "\n";
    }
    for(int i = n/2+1; i < n; i++) {
        for(int j = 0; j < i-n/2; j ++) {
            cout << " ";
        }
        cout << c;
        sum ++;
        if(i < n-1) {
            for(int k = 2 * (n-i) - 3; k > 0; k--) {
                cout << " ";
            }
            cout << c;
            sum ++;
        }
        cout << "\n";
    }
    cout << "N = " << n << " Number of * = " << sum << "\n";
    return sum;
}

int p2::d4(int n, char c) {
    cout << "-------------- n = " << n << "\n";
    for(int col = 0; col < n; col++) { //print the header number
        cout << col % 10;
    }
    cout << "\n";
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << c;
            sum ++;
        }
        cout << "\n";
    }
    for(int i = 1; i < n; i++) {
        for(int j = n-i-1; j >= 0; j--) {
            cout << c;
            sum++;
        }
        cout << "\n";
    }
    return sum;
}

int p2::d5(int n, char c) {
    cout << "-------------- n = " << n << "\n";
    for(int col = 0; col < n; col++) { //print the header number
        cout << col % 10;
    }
    cout << "\n";
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int k = n-i; k > 0; k--) {
            cout << " ";
        }
        for(int j = 0; j < i; j++) {
            cout << c;
            sum ++;
        }
        cout << "\n";
    }
    for(int i = 1; i < n; i++) {
        for(int k = 1; k <= i; k ++) {
            cout << " ";
        }
        for(int j = n-i-1; j >= 0; j--) {
            cout << c;
            sum++;
        }
        cout << "\n";
    }
    return sum;
}

int p2::d6(int n, char c) {
    cout << "-------------- n = " << n << "\n";
    for(int col = 0; col < 2 * n - 1; col++) { //print the header number
        cout << col % 10;
    }
    cout << "\n";
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            cout << " ";
        }
        for(int k = n-i; k > 0; k--) {
            cout << c << " ";
            sum ++;
        }
        cout << "\n";
    }
    for(int i = 1; i <= n; i++) {
        for(int j = n-i; j > 0; j--) {
            cout << " ";
        }
        for(int k = 0; k < i; k++) {
            cout << c << " ";
            sum ++;
        }
        cout << "\n";
    }
    cout << "N = " << n << " Number of * = " << sum << "\n";
    return sum;
}