string s;
int dp[2001],n;

bool IsPalindrome(string s1)
{
    string temp = s1;
    reverse(temp.begin(),temp.end());
    return temp == s1;
}

int solve(int index)
{
    if(index == n)
    return 0;
    int left_over_length = n - index; // left over length including character at position index
    if(dp[index]!=INT_MAX)
    return dp[index]; 
    // if the substring starting at index = index is totally palindrome we need not do any cut
    if(IsPalindrome(s.substr(index,left_over_length)))
    return dp[index] = 0;
    for(int i=1;i<=left_over_length;i++)
    {
        string temp = s.substr(index,i);
        if(IsPalindrome(temp))
        dp[index] = min(dp[index],1 + solve(index+i));
    }
    return dp[index];

}

class Solution {
public:
    int minCut(string s1) 
    {
        s = s1;
        n = s.length();
        for(int i=0;i<=n;i++)
        dp[i] = INT_MAX;
        // memset(dp,INT_MAX,sizeof(dp));
        int ans = solve(0);
        return ans;
    }
};
