#include <iostream>
#include <cstdlib>

using namespace std;

using ll = long long;

int main()
{
  ll t;
  cin >> t;

  while (t--) {
    ll a, b;
    cin >> a >> b;

    if (((a+b) % 3 != 0) || (max(a, b) > 2*min(a, b)))
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
    
