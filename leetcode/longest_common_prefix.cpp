#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  if (strs.size() == 0) return "";
  int pos;
        
  for (pos = 0; pos < strs[0].size(); ++pos) {
    int flag = 1;
            
    for (; flag < strs.size(); ++flag) {
      if (strs[0][pos] != strs[flag][pos]) {
	break;
      }
    }
            
    if (flag != strs.size()) {
      break;
    }
  }
  return strs[0].substr(0, pos);
}

int main()
{
  vector<string> strs = { "flower", "flow", "flight" };
  cout << longestCommonPrefix(strs);
  return 0;
}
