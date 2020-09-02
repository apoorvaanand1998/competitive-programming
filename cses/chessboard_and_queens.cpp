#include <iostream>

using namespace std;

bool col[8] { };
bool l_diag[15] { };
bool r_diag[15] { };
bool reserved[8][8] { };
int counter { 0 };

void count(int y)
{
  if (y == 8) {
    ++counter;
    return;
  }
  for (int x = 0; x < 8; ++x) {
    if (col[x] || r_diag[x+y] || l_diag[x-y+7] || reserved[y][x])
      continue;
    col[x] = r_diag[x+y] = l_diag[x-y+7] = true;
    count(y+1);
    col[x] = r_diag[x+y] = l_diag[x-y+7] = false;
  }
}

int main()
{
  char c;
  for (int y = 0; y < 8; ++y) {
    for (int x = 0; x < 8; ++x) {
      cin >> c;
      if (c == '*')
	reserved[y][x] = true;
    }
  }
  count(0);
  cout << counter << '\n';
}
