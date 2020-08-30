#include <iostream>

using namespace std;

using ll = long long;

int main()
{
  string s;
  cin >> s;

  ll freq[26] { };
  for (char& c : s) {
    freq[c - 'A'] += 1;
  }

  bool no_sol = false;
  string sol(s.size(), '*');

  if (s.size() % 2 == 0) {
    ll offset = 0;
    
    for (ll i = 0; i < 26; ++i) {
      if (freq[i] == 0)
	continue;
      if (freq[i] % 2 != 0) {
	cout << "NO SOLUTION\n";
	no_sol = true;
	break;
      }
      else {
	fill(sol.begin()+offset, sol.begin()+offset+freq[i]/2, i+'A');
	fill(sol.end()-offset-freq[i]/2, sol.end()-offset, i+'A');
	offset += freq[i]/2;
      }
    }
  }
  else {
    ll offset = 0;
    int single_count = 0;

    for (ll i = 0; i < 26; ++i) {
      if (freq[i] == 0)
	continue;
      if ((freq[i] % 2 != 0) && (single_count > 1)) {
	cout << "NO SOLUTION\n";
	no_sol = true;
	break;
      }
      else {
	ll e = freq[i];

	if (e % 2 == 1) {
	  ++single_count;
	  sol[sol.size()/2] = i+'A';
	  --freq[i];
	  --i;
	}
	else {
	  fill(sol.begin()+offset, sol.begin()+offset+e/2, i+'A');
	  fill(sol.end()-offset-e/2, sol.end()-offset, i+'A');
	  offset += e/2;
	}
      }
    }
  }
  if (!no_sol)
    cout << sol << '\n';
  return 0;
}
	
