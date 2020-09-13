#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

vector<ll> sa { 0 };
vector<ll> sb { 0 };

void subset_sum(vector<ll>& v, vector<ll>& s, ll i)
{
  if (i == static_cast<ll>(v.size()))
    return;
  ll k = s.size();
  for (ll j = 0; j < k; ++j) {
    s.push_back(v[i]+s[j]);
  }
  subset_sum(v, s, i+1);
}

ll no_of_ways(vector<ll>& sa, vector<ll>& sb, ll x)
{
  ll now = 0;
  
  for (auto e : sa) {
    if (e > x) continue;
    auto to_find = x - e;

    if (binary_search(sb.begin(), sb.end(), to_find))
      now += distance(lower_bound(sb.begin(), sb.end(), to_find),
		      upper_bound(sb.begin(), sb.end(), to_find));
  }
  return now;
} 
    
int main()
{
  ll n, a, b;
  ll x, t;
  
  cin >> n >> x;
  a = n/2;
  b = n - a;

  vector<ll> va;
  while (a--) {
    cin >> t;
    va.push_back(t);
  }

  vector<ll> vb;
  while (b--) {
    cin >> t;
    vb.push_back(t);
  }

  subset_sum(va, sa, 0);
  subset_sum(vb, sb, 0);

  sort(sb.begin(), sb.end());

  cout << no_of_ways(sa, sb, x);
}
