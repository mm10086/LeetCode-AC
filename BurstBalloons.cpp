/*
1、先定义状态dp[i][j]表示打爆区间[i,j]中的所有气球能得到的最多金币
2、找状态转移方程dp[i][j] = max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]) (i ≤ k ≤ j)
    k代表区间[i, j]中最后打爆的气球
3、设计递推，求解dp[i][j]
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() , 0));
        //外层循环采用区间[i, j]长度len递增的形式，保证递推式始终成立
        for (int len = 1; len <= n; ++len) {
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) {
                    dp[left][right] = max(dp[left][right], nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
                }
            }
        }
        return dp[1][n];
    }
};
