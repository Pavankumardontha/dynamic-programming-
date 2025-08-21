int is_palindrome[2001][2001]; // to check whether the substring s(i,j) is a palindrome or not
int dp[2001];
bool isPalindrome(int i, int j, string& s, int& n)
{
    if(is_palindrome[i][j]!=-1)
    return is_palindrome[i][j];
    while(i<j)
    {
        if(s[i]==s[j])
        {
            // since s[i]==s[j] we need to check whether s(i+1,j-1) is a palindrome or not for the substring s(i,j) to be a palindrome
            return is_palindrome[i][j] = isPalindrome(i+1,j-1,s,n);
        }
        return is_palindrome[i][j]=false;
    }
    return is_palindrome[i][j]=true;
}

int solve(int i,string& s, int& n)
{
    if(i==n)
    return dp[i] = 0;
    else if(dp[i]!=-1)
    return dp[i];
    else
    {
        // take different lengths substring starting from index i. Check if they are palindromes or not
        int ans = 3001; // since n<=2000 we are just choosing some random max number >=2000 to compare results
        for(int len=1;len<=n-i;len++)
        {
            // the substring will start at index i and end at index j=i+len-1
            // check the substring s(i,i+len-1) is a palindrome or not in O(1) time using the is_palindrome matrix. If it a palindrome , put a partition and move forward
            if(is_palindrome[i][i+len-1])
            ans = min(ans, 1+solve(i+len,s,n));
        }
        return dp[i] = ans;
    }
}

class Solution {
public:
    int minCut(string s) 
    {
        // for each (i,j) subsring in s, find if s(i,j) is a substring or not.
        // s(i,j) = substring of s starting from index i and ending at index j
        int n = s.length();
        int i = 0;
        memset(dp,-1,sizeof(dp));
        memset(is_palindrome,-1,sizeof(is_palindrome));
        /*
        we will first construct the is_palindrome matrix so answer whether the substring s(i,j)
        is a palindrome or not */
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                isPalindrome(i,j,s,n);
            }
        }

        return solve(0,s,n)-1;
        
    }
};
