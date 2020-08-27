#include <iostream>

using namespace std;

int main()
{
  long long t;
  cin >> t;
  
  for (long long i = 1; i <= t; ++i) {
    long long n_sq = i*i;
    long long n_two = n_sq * (n_sq - 1) / 2;
    long long n_doattack = 4 * (i - 1) * (i - 2);
    // https://math.stackexchange.com/questions/3266257/number-of-ways-two-knights-can-be-placed-such-that-they-dont-attack
    cout << n_two - n_doattack << '\n'; // n_donotattack
  }

  return 0;
}
