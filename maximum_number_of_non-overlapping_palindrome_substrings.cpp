int is_palindrome[2001][2001]; // used to tell if s(i,j) substring is palindrome or not
int dp[2001];

bool isPalindrome(int i, int j, string& s, int& n)
{
    if(is_palindrome[i][j]!=-1)
    return is_palindrome[i][j];
    while(i<j)
    {
        if(s[i]==s[j])
        return is_palindrome[i][j] = isPalindrome(i+1,j-1,s,n);
        return is_palindrome[i][j] = false;
    }
    return is_palindrome[i][j] = true;
}

int solve(int i, string& s, int& n, int& k)
{
    if(i==n)
    return 0;
    else if(dp[i]!=-1)
    return dp[i];
    else
    { 
        // check if any palindrome of length atleast k starts from the current index character.
        // if it starts , take the palindrome and move forward
        // if no palindrome starts with the current index of atleast length k , then just move forward
        int ans1 = INT_MIN;
        for(int len=k;len<=n-i;len++)
        {
            if(is_palindrome[i][i+len-1])
            ans1 = max(ans1,1+solve(i+len,s,n,k));
        } 
        // do not take current character and search
        int ans2 = solve(i+1,s,n,k);
        return dp[i] = max(ans1,ans2);
    }
}
class Solution {
public:
    int maxPalindromes(string s, int k) 
    {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        memset(is_palindrome,-1,sizeof(is_palindrome));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)
                is_palindrome[i][j]=1;
                else
                isPalindrome(i,j,s,n);
            }
        }
        return solve(0,s,n,k);
    }
};
