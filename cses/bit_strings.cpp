#include <iostream>

using namespace std;

int main()
{
  long long m = 1e9 + 7;
  long long n, sol = 1;
  cin >> n;

  for (long long i = 1; i <= n; ++i) {
    sol *= 2;
    sol %= m;
  }

  cout << sol;
  return 0;
}
  
