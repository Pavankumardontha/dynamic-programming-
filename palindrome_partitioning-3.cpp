/* we will first calculate the no. of changes required for s(i,j) to make it a palindrome using 2d matrix */
int changes_required[101][101];
int changesToMakePalindrome(int i, int j, string& s)
{
    // this returns minimum changes to make in substring s(i,j) to make it a palindrome
    if(i==j or i>j)
    return changes_required[i][j] = 0;
    else if(changes_required[i][j]!=-1)
    return changes_required[i][j];
    else
    {
        if(s[i]==s[j])
        return changes_required[i][j] = changesToMakePalindrome(i+1,j-1,s);
        return changes_required[i][j] = 1 + changesToMakePalindrome(i+1,j-1,s);
    }
}

int dp[101][101];
int solve(int i, int partitions, string& s, int& n, int& k)
{
    if(i==n)
    {
        if(partitions==k)
        return dp[i][partitions] = 0;
        else
        return dp[i][partitions] = 205; // some random value greater than maximum possible answer value
    }
    else if(dp[i][partitions]!=-1)
    return dp[i][partitions];
    else
    {
        /*
        by taking the current character , form substrings of different lengths calculate the 
        no. of changes needed to make it a palindrome using changes_required vector.
        Add it to the answer and move forward by incrementing the partitions.
        */
        int ans = 205; // some random value greater than maximum possible answer value
        for(int len=1;len<=n-i;len++)
        ans = min(ans, changes_required[i][i+len-1] + solve(i+len,partitions+1,s,n,k));
        return dp[i][partitions] = ans;
    }
}

class Solution {
public:
    int palindromePartition(string s, int k) 
    {
        int n = s.length();
        memset(changes_required,-1,sizeof(changes_required));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                changesToMakePalindrome(i,j,s);
            }
        }
        return solve(0,0,s,n,k);
    }
};
