#include <iostream>

using namespace std;

using ll = long long;

ll count_zeroes(ll fact)
{
  ll count5;
  count5 = 0;

  for (ll i = 5; fact / i > 0; i *= 5)
    count5 += fact / i;
  
  return count5;
}
   
int main()
{
  ll n;
  cin >> n;

  cout << count_zeroes(n);
  return 0;
}

  
