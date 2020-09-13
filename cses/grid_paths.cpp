#include <iostream>

using namespace std;

string path;
int nop;
bool chosen[7][7];

bool can_go(int x, int y)
{
  return ((x >= 0) && (y >= 0) && (x < 7) && (y < 7) &&
	  !chosen[x][y]);
}

void backtrack(int x, int y, int counter)
{
  if ((x == 0) && (y == 6)) {
    if (counter == 48) {
      ++nop;
      return;
    }
    return;
  }
  chosen[x][y] = 1;
  //cout << x << ' ' << y << '\n';
  char c = path[counter];

  if ((c == '?') || (c == 'D')) {
    if (y+1 < 7 && !chosen[x][y+1]) {
      if (!(!can_go(x, y+2) && can_go(x-1, y+1) && can_go(x+1, y+1)))
	backtrack(x, y+1, counter+1);
    }
  }

  if ((c == '?') || (c == 'U')) {
    if (y-1 >= 0 && !chosen[x][y-1]) {
      if (!(!can_go(x, y-2) && can_go(x-1, y-1) && can_go(x+1, y-1)))
	backtrack(x, y-1, counter+1);
    }
  }

  if ((c == '?') || (c == 'L')) {
    if (x-1 >=0 && !chosen[x-1][y]) {
      if (!(!can_go(x-2, y) && can_go(x-1, y+1) && can_go(x-1, y-1)))
	backtrack(x-1, y, counter+1);
    }
  }

  if ((c == '?') || (c == 'R')) {
    if (x+1 < 7 && !chosen[x+1][y]) {
      if (!(!can_go(x+2, y) && can_go(x+1, y+1) && can_go(x+1, y-1)))
	backtrack(x+1, y, counter+1);
    }
  }
  chosen[x][y] = 0;
}
    
int main()
{
  cin >> path;
  backtrack(0, 0, 0);
  cout << nop;
}
