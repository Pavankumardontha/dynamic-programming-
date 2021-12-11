// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
class Solution{
public:
    int maximumPath(int N, vector<vector<int>> a)
    {
        // minCost(m, n) = min (minCost(m-1, n-1), minCost(m-1, n), minCost(m, n-1)) + cost[m][n]
        int n = N;
        int m = N;
        
        int dp[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            dp[i][j] = INT_MAX;
        }
        dp[0][0] = a[0][0];
        //initializing first row cost. The only way to reach any cell on the first row is via left
        for(int i=1;i<m;i++)
        dp[0][i] = dp[0][i-1] + a[0][i];
        
        //initialising first col cost. The only way to reach any cell on the first cell is via up 
        for(int i=1;i<n;i++)
        dp[i][0] = dp[i-1][0] + a[i][0];
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                int top = dp[i-1][j];
                int right = dp[i][j-1];
                int top_left_corner = dp[i-1][j-1];
                //these are the only 3 ways to reach (i,j)
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + a[i][j]; 
            }
        }
        return dp[n-1][m-1];
        
    }
};
