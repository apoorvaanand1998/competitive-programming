class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, pos = 0;
        
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[pos++] = nums[i];
            }
        }
        return pos;
    }
};
