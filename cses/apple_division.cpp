#include <iostream>
#include <vector>
#include <limits>

using namespace std;

using ll = long long;

vector<ll> p;
ll group1 = 0;
ll group2 = 0;
ll min_diff = numeric_limits<long long>::max();

void upd(void)
{
  ll diff = abs(group1 - group2);
  if (diff < min_diff) {
    min_diff = diff;
  }
}

void search(int i, int n)
{
  if (i == n) {
    upd();
  } else {
    group1 += p[i];
    group2 -= p[i];
    search(i+1, n);
    group1 -= p[i];
    group2 += p[i];
    search(i+1, n);
  }
}

int main()
{
  int n;
  cin >> n;
  
  ll c;
  while (n--) {
    cin >> c;
    group2 += c;
    p.push_back(c);
  }
  
  search(0, p.size());
  cout << min_diff;
}
