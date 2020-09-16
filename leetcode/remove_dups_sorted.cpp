class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int recent = 1;
        int prev = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != prev) {
                prev = nums[i];
                nums[recent++] = prev;
            }
        }
        return recent;
    }
};
