#include <iostream>

using namespace std;

int main()
{
  long long n, c, p, turn = 0;

  cin >> n >> p;

  while (--n) {
    cin >> c;

    if (c < p) {
      turn += p - c;
    }
    else {
      p = c;
    }
  }

  cout << turn;
  return 0;
}
    
