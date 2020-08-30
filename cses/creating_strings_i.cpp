#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  vector<string> poss;
  string s;
  cin >> s;

  sort(s.begin(), s.end());

  do {
    poss.push_back(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << poss.size() << '\n';

  for (string& p : poss)
    cout << p << '\n';

  return 0;
}
