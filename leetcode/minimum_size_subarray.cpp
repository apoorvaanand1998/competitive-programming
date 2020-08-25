class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ans = numeric_limits<int>::max();
        
        vector<int> sums(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i-1] + nums[i-1];
        }
        
        for (auto i = sums.begin()+1; i != sums.end(); ++i) {
            int to_find = s + *(i-1);
            auto found = lower_bound(sums.begin(), sums.end(), to_find);
            if (found != sums.end()) {
                ans = min(ans, (static_cast<int>(distance(i, found)))+1);
            }    
        }
        
        return (ans != numeric_limits<int>::max()) ? ans : 0;
    }
};
