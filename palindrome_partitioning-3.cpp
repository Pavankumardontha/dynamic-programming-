int n;
int k;
string s;
int dp[103][103];
int MinCharacters(string temp)
{
    int n1 = temp.length();
    int ans = 0;
    for(int i=0;i<n1/2;i++)
    {
        if(temp[i]!=temp[n1-i-1])
        ans++;
    }
    // if it is palindrome then it returns 0
    return ans;
}
int solve(int index, int splits)
{
    if(index == n)
    {
        if(splits == k)
        return 0;
        else
        return 1e8;
    }
    if(splits > k)
    return 1e8;
    if(dp[index][splits]!=-1)
    return dp[index][splits];
    int left_over_length =  n - index;
    int ans = 1e8;
    for(int i=1;i<=left_over_length;i++)
    {
        string temp = s.substr(index,i);
        int min_characters = MinCharacters(temp);
        ans = min(ans,min_characters + solve(index+i,splits+1));
    }
    return dp[index][splits]=ans;
}

class Solution {
public:
    int palindromePartition(string s1, int k1) 
    {
        s = s1;
        n = s.length();
        k = k1;
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0);
        return ans;
    }
};
