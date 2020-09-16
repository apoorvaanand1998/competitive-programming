#include <iostream>
#include <ctype.h>
#include <algorithm>

using namespace std;

class Solution {
public:
  void reverse_and_place(string& s, int begin, int end, int& recent)
  {
    reverse(s.begin()+begin, s.begin()+end+1);
  
    for (int i = end; i >= begin; --i) {
      s[--recent] = s[i];
    }
    if (recent != 0) s[--recent] = ' ';
  }
    
  string reverseWords(string s) {
    int last_char = -1;
    int recent = s.size();
    
    bool inside_word = 0;
    // put the starts and ends of each word inside
    for (int i = s.size()-1; i >= 0; --i) {
      if (isspace(s[i]) && inside_word) {
	inside_word = 0;
	reverse_and_place(s, i+1, last_char, recent);
      } else if (!isspace(s[i]) && !inside_word) {
	inside_word = 1;
	last_char = i;
      }   
          
      if ((i == 0) && !isspace(s[i])) {
	reverse_and_place(s, 0, last_char, recent);
      }
    }
    if (last_char == -1) return "";
    reverse(s.begin(), s.end());
    s[s.size()-recent-1] == ' ' ? s.resize(s.size()-recent-1) : s.resize(s.size()-recent);
    return s;
  }
};
