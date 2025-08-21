int is_palindrome[2001][2001];
bool isPalindrome(int i, int j, string& s)
{
    if(i>=j)
    return is_palindrome[i][j]=1;
    else if(is_palindrome[i][j]!=-1)
    return is_palindrome[i][j];
    else
    {
        if(s[i]==s[j])
        return is_palindrome[i][j] = isPalindrome(i+1,j-1,s);
        return is_palindrome[i][j] = false;
    }
}
int dp[2001][5];

bool solve(int i, int partitions, string& s, int& n)
{
    if(i==n)
    {
        if(partitions==3)
        return dp[i][partitions] = true;
        return dp[i][partitions] = false;
    }
    else if(partitions>3)
    return dp[i][partitions]=false;
    else if(dp[i][partitions]!=-1)
    return dp[i][partitions];
    else
    {
        for(int len=1;len<=n-i;len++)
        {
            if(is_palindrome[i][i+len-1])
            {
                bool ans = solve(i+len,partitions+1,s,n);
                if(ans==true)
                return dp[i][partitions] = ans;
            }
        }
        return dp[i][partitions] = false;
    }
}

class Solution {
public:
    bool checkPartitioning(string s) 
    {
        memset(dp,-1,sizeof(dp));
        memset(is_palindrome,-1,sizeof(is_palindrome));
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)
                is_palindrome[i][j]=1;
                else
                isPalindrome(i,j,s);
            }
        }
        return solve(0,0,s,n);
    }
};
