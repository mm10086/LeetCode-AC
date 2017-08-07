/*题目描述
Edit Distance
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
     a) Insert a character
     b) Delete a character
     c) Replace a character
*/
/*分析
根据以往的经验，对于字符串相关的题目十有八九都是用动态规划Dynamic Programming来解，这道题也不例外。
定义状态：这道题我们需要维护一个二维的数组dp，其中dp[i][j]表示从word1的前i个字符转换到word2的前j个字符所需要的步骤。
          那我们可以先给这个二维数组dp的第一行第一列赋值，这个很简单，因为第一行和第一列对应的总有一个字符串是空串，
          于是转换步骤完全是另一个字符串的长度。【求解dp[i][j]时，dp[s][t],s<=i && t<=j已知】
状态转移方程：(1)显然如果word1[i]==word2[j], 那么dp[i][j] = dp[i-1][j-1]。
            (2)如果word1[i]!=word2[j],那么可以分别对于word1中最后一个字母进行分析（word1前面的字母已经在的dp[s][t]中分析过了）：
            删除：dp[i][j] = dp[i - 1][j] + 1
            插入：dp[i][j] = dp[i][j - 1] + 1
            替换：dp[i][j] = dp[i - 1][j - 1] + 1
            最终取上面3个当中最小值

*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int dp[n1 + 1][n2 + 1];
        for (int i = 0; i <= n1; ++i) dp[i][0] = i;
        for (int i = 0; i <= n2; ++i) dp[0][i] = i;
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
};
