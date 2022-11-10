
string s;
int n;
int dp[2002][4];
bool IsPalindrome(string s1)
{
    string temp = s1;
    reverse(temp.begin(),temp.end());
    return temp == s1;
}
bool solve(int index, int splits)
{
    if(index == n)
    {
        if(splits == 3)
        return true;
        else
        return false;
    }
    if(splits == 3)
    return false;
    if(dp[index][splits]!=-1)
    return dp[index][splits];
    int left_over_length = n - index;
    for(int i=1;i<=left_over_length;i++)
    {
        string temp = s.substr(index,i);
        if(IsPalindrome(temp))
        {
            if(solve(index+i,splits+1))
            return dp[index][splits] = true;
        }
    }
    return dp[index][splits]=false;
}

class Solution {
public:
    bool checkPartitioning(string s1) 
    {
        s = s1;
        n = s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};
