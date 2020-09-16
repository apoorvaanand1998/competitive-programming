class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int recent = 0;
        for (auto e : nums) {
            if (e != 0)
                nums[recent++] = e;
        }
        for (int i = recent; i < nums.size(); ++i)
            nums[i] = 0;
    }
};
