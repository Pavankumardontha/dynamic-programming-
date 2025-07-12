int dp[1001][1001];
int solve(int i, int j, string& s1, string& s2, int& n)
{
    if(i==n or j==n)
    return 0;
    if(dp[i][j] != -1)
    return dp[i][j];
    int ans = 0;
    if(s1[i]==s2[j])
    ans = max(ans,1+solve(i+1,j+1,s1,s2,n));
    else
    {
        ans = max(ans,solve(i+1,j,s1,s2,n));
        ans = max(ans,solve(i,j+1,s1,s2,n));
    }
    return dp[i][j]=ans;
}
class Solution {
public:
    int minInsertions(string s) {
        /*
        we can definitely make any given string a palindrome by adding reverse of a strong
        at the end. 
        ex : s = "abs" => reverse of s = "sba"
        add both which gives => (abs+sba) = abssba
        So we can always add a reverse of a string to it to make it a palindrome
        This gives us the maximum no. of insertions which we can do to make a given 
        string palindrome.
        To find minimum operations , we find the longest palindromice subsequence in the
        given string. We should not disturb these since they form a palindrome.
        We need to insert the matching characters for the rest of the elements which are
        not a part of this longest palindromic subsequence. 
        So minimum insertions = length of string - length of longest palindromic subsequence
        Ex : mbadm
        longest palindrome subsequence = mdm (it can be 'mbm' also but we take any one)
        m (b) (a) d m -> characters in the bracket do not have a match so we add insert matching characters
        a (b) (a) d (b) m -> insertion 1
        a (b) (a) d (a) (b) m -> insertion 2
        So we require 2 minimum insertions to make the above string a palindrome.
        */
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            dp[i][j]=-1;
        }
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int longestPalindromicLength = solve(0,0,s1,s2,n);
        return n - longestPalindromicLength;
    }
};
