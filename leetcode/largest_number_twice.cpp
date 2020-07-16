// https://leetcode.com/problems/largest-number-at-least-twice-of-others/

int dominantIndex(vector<int>& nums) {
  int max_e = -1;
  int max_i = -1;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] > max_e) {
      max_e = nums[i];
      max_i = i;
    }
  }
  for (int i = 0; i < nums.size(); ++i) {
    if ((nums[i]*2 > max_e) && (i != max_i))
      return -1;
  }
  return max_i;
}
