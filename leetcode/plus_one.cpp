// https://leetcode.com/problems/plus-one/

vector<int> plusOne(vector<int>& digits) {
  vector<int> result(digits);
  int carry = 0;
  int lsb = result[result.size()-1] + 1;
  result[result.size()-1] = lsb % 10;
  if (lsb > 9)
    carry = 1;
  int idx = result.size() - 2;
  while (carry) {
    if (idx == -1) {
      result.insert(result.begin(), 1);
      break;
    }
    int curr = result[idx] + 1;
    result[idx] = curr % 10;
    carry = (curr > 9) ? 1 : 0;
    --idx;
  }
  return result;
}
