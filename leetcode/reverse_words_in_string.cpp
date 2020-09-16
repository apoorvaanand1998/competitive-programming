#include <iostream>
#include <ctype.h>
#include <vector>

using namespace std;

string reverseWords(string s) {
  vector<int> starts { };
  vector<int> ends { };
        
  bool inside_word = 0;
  // put the starts and ends of each word inside
  for (int i = s.size()-1; i >= 0; --i) {
    if ((i == 0) && !isspace(s[i])) {
      starts.push_back(i);
    } else if (isspace(s[i]) && inside_word) {
      inside_word = 0;
      starts.push_back(i+1);
    } else if (!isspace(s[i]) && !inside_word) {
      inside_word = 1;
      ends.push_back(i);
    }   
  }

  string sol = "";
  for (int i = 0; i < static_cast<int>(starts.size()); ++i) {
    cout << starts[i] << ' ' << ends[i] << '\n';
    for (int j = starts[i]; j <= ends[i]; ++j) {
      sol += s[j];
    }
    if (i != static_cast<int>(starts.size()-1)) sol += ' ';
  }
  return sol;
}

int main()
{
  string s = "a good   example";
  cout << reverseWords(s);
}
