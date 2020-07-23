#include <bits/stdc++.h>

using namespace std;

bool right(int m, int n, int& x, int& y,
	   const vector<vector<int>>& inp,
	   vector<int>& sol) {
  bool entered = 0;
  for (int i = 0; i < n; ++i) {
    entered = 1;
    sol.push_back(inp[x][y++]);
  }
  if (entered) {
    --y;
    ++x;
  }
  return entered;
}

bool down(int m, int n, int& x, int& y,
	  const vector<vector<int>>& inp,
	  vector<int>& sol) {
  bool entered = 0;
  for (int i = 0; i < m-1; ++i) {
    entered = 1;
    sol.push_back(inp[x++][y]);
  }
  if (entered) {
    --x;
    --y;
  }
  return entered;
}

bool left(int m, int n, int& x, int& y,
	  const vector<vector<int>>& inp,
	  vector<int>& sol) {
  bool entered = 0;
  for (int i = 0; i < n-1; ++i) {
    entered = 1;
    sol.push_back(inp[x][y--]);
  }
  if (entered) {
    ++y;
    --x;
  }
  return entered;
}

bool up(int m, int n, int& x, int& y,
	const vector<vector<int>>& inp,
	vector<int>& sol) {
  bool entered = 0;
  for (int i = 0; i < m-2; ++i) {
    entered = 1;
    sol.push_back(inp[x--][y]);
  }
  if (entered) {
    ++x;
    ++y;
  }
  return entered;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  vector<int> sol;
  
  int m = matrix.size();
  if (m == 0) return sol;
  int n = matrix[0].size();
  if (n == 0) return sol;

  int x = 0;
  int y = 0;

  while (true) {
    if (!(right(m, n, x, y, matrix, sol))) {
      break;
    }
    if (!(down(m, n, x, y, matrix, sol))) {
      break;
    }
    if (!(left(m, n, x, y, matrix, sol))) {
      break;
    }
    if (!(up(m, n, x, y, matrix, sol))) {
      break;
    }
    m -= 2;
    n -= 2;
  }
  return sol;
}

int main()
{
  vector<vector<int>> m = { { 1, 2, 3 },
			    { 4, 5, 6 },
			    { 7, 8, 9 } };
  
  for (auto e : spiralOrder(m)) {
    cout << e << ' ';
  }
}
      
  
  
