/*
先找状态转移方程
dp[i] = max{dp[i], dp[j] + 1} if nums[i] % nums[j] when 0 <= j < i
dp[i]至i处的最长子序列的长度，parent[i]为最长子序列中索引i元素的前一个元素的索引
mx为最长子序列长度，mx_idx为最长子序列末尾元素的索引
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0), parent(nums.size(), 0), res;
        int mx = 1, mx_idx = 0;//mx至少为1
        
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = 1;
            parent[i] = -1;
        }
        
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (mx < dp[i]) {
                        mx = dp[i];
                        mx_idx = i;
                    }
                }
            }
        }
        for (int i = 0; i < mx; ++i) {
            res.push_back(nums[mx_idx]);
            mx_idx = parent[mx_idx];
        }
        return res;
    }
};
