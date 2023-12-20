/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
file: sarray.h
-----------------------------------------------------------------*/
#pragma once

#include "../util/util.h"

#define T int

//MUST Attach two outputs with and without move
#define MOVE


class Sarray {
public:
		Sarray(unsigned size = 0);
        ~Sarray();
        Sarray(const Sarray& rhs);
        Sarray& operator = (const Sarray& rhs);

#ifdef MOVE
		//WRITE CODE
        Sarray(Sarray&& rhs);
        Sarray& operator = (Sarray&& rhs);
#endif

		friend void Swap(Sarray& a, Sarray& b);

		static bool show;
		static unsigned long long num_allocated;
		static unsigned long long num_freed;


private:
		unsigned size_;
		T* ptr_;

		//private funcions
        void alloc_(unsigned n);
        void free_();
        void copy_(const Sarray& rhs);
        void move_(Sarray& rhs);
};



