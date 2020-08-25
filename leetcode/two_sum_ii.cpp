#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size()-1;
        
        vector<int> res;
        while (low < high) {
            int l = numbers[low];
            int h = numbers[high];
	    cout << l + h << '\n';
            if ((l+h) == target) {
                res = { low+1, high+1 };
                return res;
            }
            else if ((l+h) > target) {
                --high;
            }
            else {
                ++low;
            }
        }
        return res;
}

int main()
{
  vector<int> i = { 2, 7, 11, 15 };
  int t = 9;

  for (auto e : twoSum(i, t)) {
    cout << e << ' ';
  }
}
