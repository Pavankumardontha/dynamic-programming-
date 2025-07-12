int dp[1001][1001];
bool solve(int i, int j, string s, int n)
{
    if(i>=j)
    return true;
    if(dp[i][j]!=-1)
    return dp[i][j];

    bool ans = false;
    if(s[i]==s[j])
    ans = solve(i+1,j-1,s,n);
    return dp[i][j]=ans;
}

class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.length();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            dp[i][j]=-1;
        }
        bool is_palindrome;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                // is the substring s(i,j) a palindrome or not
                is_palindrome = solve(i,j,s,n);
                if(is_palindrome)
                count++; 
            }
        }
        return count;
    }
};
