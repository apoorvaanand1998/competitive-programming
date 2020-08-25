#include <iostream>

using namespace std;

int main()
{
  long long n, curr;

  cin >> n;

  if ((n < 4) && (n != 1)) {
    cout << "NO SOLUTION";
  } else {
    curr = n - 1;

    while (curr > 0) {
      cout << curr << " ";
      curr -= 2;
    }

    curr = n;

    while (curr > 0) {
      cout << curr << " ";
      curr -= 2;
    }
  }
  return 0;
}
