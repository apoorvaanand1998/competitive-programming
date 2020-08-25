#include <iostream>

using namespace std;

int main()
{
  long long n, curr, sum, c_sum = 0;

  cin >> n;

  sum = n*(n+1)/2;
  
  while (--n) {
    cin >> curr;
    c_sum += curr;
  }

  cout << sum - c_sum;
  return 0;
}
