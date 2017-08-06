/*
给一个整数数组，调整每个数的大小，使得相邻的两个数的差小于一个给定的整数target，调整每个数的代价为调整前后的差的绝对值，
求调整代价之和最小是多少。
样例: 
对于数组[1, 4, 2, 3]和target=1，最小的调整方案是调整为[2, 3, 2, 3]，调整代价之和是2。返回2。
注意: 
你可以假设数组中每个整数都是正整数，且小于等于100。

分析：
一般这种题，每个位置上都有很多种可能，基本上就是动态规划了，又因为每个位置最多100，于是可以枚举每个位置的数值。
i表示数组第i个元素，j从0到100进行遍历。dp[i][j]表示第i个元素变成j的最小调整代价。
  ——————————————————j
  |      0 1 2 3 4 
  |  1   1 0 1 2 3
  |  4   4 3 
  |  2    
  |  3 
  i
表格大致如上表所示，且每一行只与其上一行有关。返回最后一行的最小值。
本题的思想其实是遍历，依靠动态规划完成实现。及每个元素i在[0,100]取值时的最小调整代价，对于每个元素只关心截至前一个元素i-1时的代价，
状态转移方程为①。
*/
int MinAdjustmentCost(vector<int> A, int target) {  
        // write your code here  
        if(A.size()<2)  
            return 0;  
        vector<vector<int>> dp(A.size(),vector<int>(101,0));  
        for(int i=0;i<101;i++)  
            dp[0][i] = abs(A[0]-i);  
        for(int i=1;i<A.size();i++)  
        {  
            for(int j=0;j<101;j++)  
            {  
                dp[i][j] = INT_MAX;  
                int diff = abs(j-A[i]);  
                int upper = min(j+target,100);  
                int lower = max(j-target,0);  
                for(int k=lower;k<=upper;k++)  //如果第i个元素j,则第i-1个元素只能取lower->upper之间的值
                {  
                    dp[i][j] = min(dp[i][j],dp[i-1][k]+diff);  //状态转移方程①
                }  
            }  
        }  
        int ret = INT_MAX;  
        for(int i=0;i<101;i++)  
            ret = min(ret,dp[A.size()-1][i]);  
        return ret;  
          
    } 
