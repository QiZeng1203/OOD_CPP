/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: L0006.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
6. Zigzag Conversion
https://leetcode.com/problems/zigzag-conversion/
---------------------------------------------------------------- - */

/*----------------------------------------------------------------
NO  includes here
CUT AND PASTE whole file in Leetcode
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
WRITE CLASS L0006
-----------------------------------------------------------------*/
/*----------------------------------------------------------------
Declaration of L0006 class
-----------------------------------------------------------------*/
class L0006 {
public:
  //WRITE CODE
  L0006(const string& s, const int r, string& ans, bool show);

private:
  //inputs
  const string& s_; 
  const int r_;
  string& ans_;
  bool show_;
  //all private routines
  void alg_();
};


/*----------------------------------------------------------------
Time: THETA(n)
Space O(n*r)
-----------------------------------------------------------------*/
L0006::L0006(const string& s, const int r, string& ans, bool show):s_(s), r_(r),ans_(ans), show_(show) {
    alg_();
}
void L0006::alg_() {
		//WRITE CODE
        if(show_) {
            cout << "---------------------------------------------------" << endl;
            cout << s_ << endl;
            cout << "num rows = " << r_ << endl;
        }
        vector<string> resultRow(r_);
        int i = 0;
        while(i < s_.length()) {
            for(int row = 0; row < r_ && i < s_.length(); row++, i++) {
                resultRow[row].push_back(s_[i]);
                if(show_) cout << row;
            }
            for(int row = r_-2; row > 0 && i < s_.length(); row--, i++) {
                resultRow[row].push_back(s_[i]);
                if(show_) cout << row;
            }
        }
        if(show_) cout << endl;
        for(const string& str : resultRow) {
            if(show_) cout << str << endl;
            ans_ += str;
        }
        if(show_) cout << ans_ << endl;
}

/*----------------------------------------------------------------
Leetcode interface
NPTHING CAN BE CHANGED BELOW
This procedure must be at the end
-----------------------------------------------------------------*/
class Solution {
public:
		string convert(string s, int numRows) {
				string ans;
				bool show = false;
    L0006 a(s, numRows, ans, show);
    return ans;
  }
};

