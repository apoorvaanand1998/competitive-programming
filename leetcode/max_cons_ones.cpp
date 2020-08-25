class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter = 0;
        int m = 0;
        for (auto e : nums) {
            if (e == 0) {
                counter = 0;
            }
            else {
                ++counter;
                if (counter > m)
                    m = counter;
            }
        }
        return m;
    }
};
