int dp[1001][1001];
int solve(int i, int j, string& s1, string& s2, int &n1, int &n2)
{
    if(i==n1 or j==n2)
    return 0;
    if(dp[i][j] != -1)
    return dp[i][j];
    int ans = 0;
    if(s1[i]==s2[j])
    {
        ans = max(ans, 1 + solve(i+1,j+1,s1,s2,n1,n2));
    }
    else
    {
        ans = max(ans,solve(i+1,j,s1,s2,n1,n2));
        ans = max(ans,solve(i,j+1,s1,s2,n1,n2));
    }
    return dp[i][j] = ans;

}
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) 
    {
        int n1 = s1.length();
        int n2 = s2.length();
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            dp[i][j]=-1;
        }
        int ans =  solve(0,0,s1,s2,n1,n2);

        // Printing the longest common subsequence
        /*
        if s1[i] == s2[j] then dp[i][j] = 1 + dp[i+1][j+1]
        if s1[i] != s2[j] then dp[i][j] = max(dp[i+1][j],dp[i][j+1]) 
        */
        string longestCommonSubsequence="";
        int len = 0; // current length of longestCommonSubsequence string
        int i=0;
        int j=0;
        while(len<ans)
        {
            if(s1[i] == s2[j])
            {
                longestCommonSubsequence += s1[i];
                i = i+1;
                j = j+1;
                len++;
            }
            else
            {
                if(dp[i+1][j]>dp[i][j+1])
                i=i+1;
                else
                j=j+1;
            }
        }
        cout<<longestCommonSubsequence<<endl;
        return ans;
    }
};
