int dp[1001][1001];
bool solve(int i, int j, string& s, int& n)
{
    if(i>=j)
    return true;
    if(dp[i][j]!=-1)
    return dp[i][j];
    bool ans = false;
    if(s[i]==s[j])
    ans = solve(i+1,j-1,s,n);
    return dp[i][j] = ans;
}
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        // dp[i][j] = true if the substring s[i,j] is a palindrome
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            dp[i][j]=-1;
        }
        int ans = 0;
        bool is_palindrome;
        int len;
        string longestPalindromicSubstring;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                is_palindrome = solve(i,j,s,n);
                len = j-i+1;
                if(is_palindrome and len>ans)
                {
                    ans = len;
                    longestPalindromicSubstring = s.substr(i,len);
                }
            }
        }
        return longestPalindromicSubstring;
    }
};
