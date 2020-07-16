// https://leetcode.com/problems/find-pivot-index/
#include <bits/stdc++.h>

using namespace std;

int pivotIndex(vector<int>& nums)
{
  if (nums.size() == 0) return -1;
  if (nums.size() == 1) return 0;

  int idx = 0;
  long long l_sum = 0;
  long long r_sum = 0;

  // initialize r_sum
  for (int i = 1; i < nums.size(); ++i) {
    r_sum += nums[i];
  }

  while (true) {
    if (l_sum == r_sum) {
      return idx;
    }
    else if (idx >= static_cast<int>(nums.size())) {
      return -1;
    }
    else {
      ++idx;
      l_sum += nums[idx-1];
      r_sum -= nums[idx];
    }   
  }
}
    
int main()
{
  vector<int> nums = { 1, 7, 3, 6, 5, 6 };
  pivotIndex(nums);
}
