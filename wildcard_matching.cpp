/*
The entirety of p must match s, so if you have p=*a*b and s=adceb, you ask, "is 
there some value X and some value Y such that XaYb = adceb?" It is a mathematical 
fact that the answer is yes.
*/

int dp[2001][2001];
bool solve(int i, int j, string& s, string& p, int& n1, int& n2)
{
    if(i==n1 and j==n2)
    return true;
    if(j==n2)
    return false;
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(s[i]==p[j] or p[j]=='?')
    return dp[i][j]=solve(i+1,j+1,s,p,n1,n2);
    if(p[j]=='*')
    {
        // try all possibilities
        bool ans = false;
        for(int ind=i;ind<=n1;ind++)
        {
            // we can match with 0 or 1 or 2 or 3... characters of s
            ans = solve(ind,j+1,s,p,n1,n2);
            dp[ind][j+1]=ans;
            if(ans==true)
            return true;
        }
    }
    return dp[i][j] = false;
}

class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int n1 = s.length();
        int n2 = p.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,p,n1,n2);
    }
};
