#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows) {
  if (numRows == 0) {
    vector<vector<int>> sol;
    return sol;
  }
  if ((numRows == 1) || (numRows == 2)) {
    vector<vector<int>> sol;
    for (int i = 1; i <= numRows; ++i) {
      vector<int> curr(i, 1);
      sol.push_back(curr);
    }
    return sol;
  }
  else {
    vector<vector<int>> sol;
    for (int i = 1; i <= numRows; ++i) {
      vector<int> curr(i, 1);
      sol.push_back(curr);
    }
    for (int x = 2; x < numRows; ++x) {
      for (int y = 1; y <= sol[x].size() - 2; ++y) {
	sol[x][y] = sol[x-1][y-1] + sol[x-1][y];
      }
    }
    return sol;
  }
}

int main()
{
  for (auto e : generate(5)) {
    for (auto el : e) {
      cout << el << ' ';
    }
    cout << '\n';
  }
}
