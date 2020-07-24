#include <bits/stdc++.h>

using namespace std;

string addBinary(string a, string b)
{
  int i, j, carry = 0;
  string sol = "";
  
  for (i = a.size()-1, j = b.size()-1; (i >= 0) && (j >= 0); --i, --j) {
    if ((a[i] == '1') && (b[j] == '1')) {
      if (carry) {
	sol += "1";
	carry = 1;
      }
      else {
	sol += "0";
	carry = 1;
      }
    }
    else if ((a[i] == '1') || (b[j] == '1')) {
      if (carry) {
	sol += "0";
	carry = 1;
      }
      else {
	sol += "1";
	carry = 0;
      }
    }
    else {
      if (carry) {
	sol += "1";
	carry = 0;
      }
      else {
	sol += "0";
      }
    }
  }

  int k;
  string rest;
  
  if (i >= 0) {
    k = i;
    rest = a;
  }
  else if (j >= 0) {
    k = j;
    rest = b;
  }

  for (; k >= 0; --k) {
    if (rest[k] == '1') {
      if (carry) {
	sol += "0";
	carry = 1;
      }
      else {
	sol += "1";
      }
    }
    else {
      if (carry) {
	sol += "1";
	carry = 0;
      }
      else {
	sol += "0";
      }
    }
  }
  if (carry) sol += "1";
  
  reverse(sol.begin(), sol.end());
  return sol;
}

int main()
{
  cout << addBinary("11", "1");
}
      

  
