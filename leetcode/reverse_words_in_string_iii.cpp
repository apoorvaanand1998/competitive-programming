#include <iostream>
#include <ctype.h>
#include <vector>
#include <algorithm>

using namespace std;

string reverseWords(string s) {
      int last_char;

      bool inside_word = 0;
      // put the starts and ends of each word inside
      for (int i = s.size()-1; i >= 0; --i) {
        if (isspace(s[i]) && inside_word) {
          inside_word = 0;
          reverse(s.begin()+i+1, s.begin()+last_char+1);
        } else if (!isspace(s[i]) && !inside_word) {
          inside_word = 1;
          last_char = i;
        }

	if ((i == 0) && !isspace(s[i])) {
          reverse(s.begin()+i, s.begin()+last_char+1);
        }
      }
      return s;
}

int main()
{
  string s = "a good   example";
  cout << reverseWords(s);
}
