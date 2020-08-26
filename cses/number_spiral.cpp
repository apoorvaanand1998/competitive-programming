#include <iostream>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, x, y, me, d, layer;

  cin >> t;

  while (t--) {
    cin >> x >> y;
    
    layer = max(x, y);
    me = layer*(layer-1) + 1;

    if (x == y)
      cout << me << '\n';
    else if (x > y) {
      d = x - y;
      
      if (layer % 2 == 0)
	cout << me + d << '\n';
      else
	cout << me - d << '\n';
    }
    else {
      d = y - x;

      if (layer % 2 == 0)
	cout << me - d << '\n';
      else
	cout << me + d << '\n';
    }
  }
  return 0;
}
