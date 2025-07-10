int dp[301];
bool solve(int current_ind, string &s, int& n, vector<string>& wordDict, int& m)
{
    if(current_ind == n)
    return true;
    if(dp[current_ind] != -1)
    return dp[current_ind];
    bool ans = false;
    string s1;
    int n1;
    for(int i=0;i<m;i++)
    {
        s1 = wordDict[i];
        n1 = s1.length();
        if(s1 == s.substr(current_ind,n1))
        ans = ans or solve(current_ind+n1,s,n,wordDict,m);
    }
    return dp[current_ind] = ans;
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.length();
        int m = wordDict.size();
        for(int i=0;i<=n;i++)
        dp[i]=-1;
        return solve(0,s,n,wordDict,m);
    }
};
