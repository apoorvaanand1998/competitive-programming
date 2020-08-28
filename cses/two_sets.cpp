#include <iostream>
#include <vector>

using namespace std;

int main()
{
  long long n;
  cin >> n;

  double s = n*(n+1)/2;
  double hs = s / 2;

  if ((hs != static_cast<long long>(hs)) || (n == 1) || (n == 2))
    cout << "NO" << '\n';
  else {
    cout << "YES" << '\n';

    long long lhs = static_cast<long long>(hs);
    vector<long long> left, right;
    bool s[n+1] { };
    
    for (long long i = n; i >= 1; --i) {
      if ((lhs <= n) && (!(s[lhs]))) {
	right.push_back(lhs);
	s[lhs] = true;
	break;
      }
      if (!(s[i])) {
	right.push_back(i);
	s[i] = true;
	lhs -= i;
      }
    }

    for (long long i = 1; i <= n; ++i)
      if (!(s[i])) 
	left.push_back(i);

    cout << right.size() << '\n';
    for (auto e : right)
      cout << e << ' ';

    cout << '\n' << left.size() << '\n';
    for (auto e : left)
      cout << e << ' ';
  }
  return 0;
}

    
    
