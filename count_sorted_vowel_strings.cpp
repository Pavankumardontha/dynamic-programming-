/*
s = ['a','e','i','o','u]
dp[i][j] = no. of strings in sorted order with length i and starting character as s[j]

dp[1][0]=1
dp[1][1]=1
dp[1][2]=1
dp[1][3]=1
dp[1][4]=1

dp[2][0]=5 (dp[1][0]+dp[1][1]+dp[1][2]+dp[1][3]+dp[1][4])
dp[2][1]=4 (dp[1][1]+dp[1][2]+dp[1][3]+dp[1][4])
.
.
.

dp[3][0] = (dp[2][0]+dp[2][1]....dp[2][4]) = 15
dp[3][1] = (dp[2][1]+dp[2][2]+dp[2][3]+dp[2][4]) = 10
dp[3][2] = (dp[2][2]+dp[2][3]+dp[2][3]) = 6
dp[3][3] = 3
dp[3][4] = 1

dp[n][i] = dp[n-1][i] + dp[n-1][i+1] + . . dp[n-1][4]
*/
class Solution {
public:
    int countVowelStrings(int n) 
    {
        if(n==1)
        return 5;
        else
        {
            int dp[n+1][5];
            dp[1][0]=1;dp[1][1]=1;dp[1][2]=1;dp[1][3]=1;dp[1][4]=1;
            for(int i=2;i<=n;i++)
            {
                dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4];
                dp[i][1] = dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4];
                dp[i][2] = dp[i-1][2] + dp[i-1][3] + dp[i-1][4];
                dp[i][3] = dp[i-1][3] + dp[i-1][4];
                dp[i][4] = dp[i-1][4];
            }
            return dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4];
        }
        return 0;
    }
};
