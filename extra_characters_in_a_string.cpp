int dp[51];
int solve(int current_ind, string& s, int n, vector<string>& dictionary, int& m)
{
    if(current_ind==n)
    return 0;
    if(dp[current_ind]!=-1)
    return dp[current_ind];
    string s1;
    int n1;
    int ans = 55; // some max value
    // we will explore all the possibilities for the string to be broken from the current_ind 
    for(int i=0;i<m;i++)
    {
        s1 = dictionary[i];
        n1 = s1.length();
        if(s1 == s.substr(current_ind,n1))
        ans = min(ans,solve(current_ind+n1,s,n,dictionary,m));
    }
    // consider the character at current_ind as extra and move forward
    ans = min(ans, 1 + solve(current_ind+1,s,n,dictionary,m));
    return dp[current_ind] = ans; 
}

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        int m = dictionary.size();
        for(int i=0;i<=n;i++)
        dp[i]=-1;
        return solve(0,s,n,dictionary,m);
    }
};
