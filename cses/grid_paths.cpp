#include <iostream>

using namespace std;

string path;
bool chosen[7][7] { };
int nPaths { 0 };

bool can_choose(int, int, int);
void search(int, int, int, int);
int left(int);
int right(int);

bool can_choose(int i, int x, int y)
{
  if (i == 0) // down
    return (((y+1) < 7) && (!chosen[x][y+1]));
  else if (i == 1) // up
    return (((y-1) > -1) && (!chosen[x][y-1]));
  else if (i == 2) // left
    return (((x-1) > -1) && (!chosen[x-1][y]));
  else
    return (((x+1) < 7) && (!chosen[x+1][y]));
}

int left(int i)
{
  if (i == 0) return 3;
  if (i == 1) return 2;
  if (i == 2) return 0;
  else return 1;
}

int right(int i)
{
  if (i == 0) return 2;
  if (i == 1) return 3;
  if (i == 2) return 1;
  else return 0;
}

void search(int x, int y, int count, int prev)
{
  if ((x == 0) && (y == 6)) {
    if (count == 48) {
      ++nPaths;
      return;
    }
    return;
  } else if (!can_choose(prev, x, y) &&
	     can_choose(left(prev), x, y) &&
	     can_choose(right(prev), x, y)) { // optimisation 4 prune page 53
    return;
  } else {
    char c = path[count];
    if ((c == 'D') || (c == '?')) {
      if (can_choose(0, x, y)) {
        chosen[x][y+1] = true;
	search(x, y+1, count+1, 0);
	chosen[x][y+1] = false;
      }
    }
    if ((c == 'U') || (c == '?')){
      if (can_choose(1, x, y)) {
	chosen[x][y-1] = true;
	search(x, y-1, count+1, 1);
	chosen[x][y-1] = false;
      }
    }
    if ((c == 'L') || (c == '?')) {
      if (can_choose(2, x, y)) {
	chosen[x-1][y] = true;
	search(x-1, y, count+1, 2);
	chosen[x-1][y] = false;
      }
    }
    if ((c == 'R') || (c == '?')) {
      if (can_choose(3, x, y)) {
        chosen[x+1][y] = true;
	search(x+1, y, count+1, 3);
	chosen[x+1][y] = false;
      }
    }
  } 
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> path;
  chosen[0][0] = true;
  search(0, 0, 0, 0);
  cout << nPaths << '\n';
}
