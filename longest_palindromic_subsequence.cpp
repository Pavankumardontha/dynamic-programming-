int dp[1001][1001];
int solve(int i, int j, string& s1, string& s2, int& n1, int& n2)
{
    if(i==n1 or j==n2)
    return 0;
    if(dp[i][j] != -1)
    return dp[i][j];
    int ans1 = 0;
    int ans2 = 0;
    if(s1[i]==s2[j])
    return dp[i][j] = 1 + solve(i+1,j+1,s1,s2,n1,n2);
    else
    {
        ans1 = solve(i+1,j,s1,s2,n1,n2);
        ans2 = solve(i,j+1,s1,s2,n1,n2);
        return dp[i][j] = max(ans1,ans2);
    }
}
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        /*
        find the longest common subsequence between the string and the reverse of the string
        s1 = "bbbab"
        s2 = "babbb"
        longest common subsequence = 4 which is the length of longest palindrome subsequence
        */
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n1 = s1.length();
        int n2 = s2.length();
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            dp[i][j]=-1;
        }
        return solve(0,0,s1,s2,n1,n2);
    }
};
