#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
  k %= nums.size();
  int nMoved = 0;
  int curr = 0;
  int to = (curr + k) % nums.size();
  int start = to;
  int temp = nums[curr];
  while (nMoved < nums.size()) {
    swap(nums[to], temp);
    ++nMoved;
    curr = to;
    to = (curr + k) % nums.size();
            
    if (to == start) {
      to = ++start;
      temp = nums[(to - k) % nums.size()];
    }
  }
}

int main()
{
  vector<int> nums = { -1, -100, 3, 99 };
  rotate(nums, 2);

  for (auto e : nums)
    cout << e << ' ';

}
