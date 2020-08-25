#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;

  cin >> s;

  long long curr_len, max_len;
  curr_len = max_len = 0;
  char p = s[0];
  
  for (char c : s) {
    if (c == p) {
      ++curr_len;
    }
    else {
      curr_len = 1;
      p = c;
    }
    max_len = max(curr_len, max_len);	  
  }

  cout << max_len;
  return 0;
}
