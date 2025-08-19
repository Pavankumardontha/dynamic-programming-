int dp[101][101][2];
// dp[i][j][0] = No. of ways for the expression s(i,j) to be evaluated to true.
// dp[i][j][1] = No. of ways for the expression s(i,j) to be evaluated to false.
int solve(int i, int j, bool expected_boolean, string &s, int& n)
{
    // returns no. of ways for the string s(i,j) to be evaluated to be excepted boolean
    /*
    for example solve(0,6,true,s,n) will return the no. of ways for the arithmetic expression
    s(0,6) to be true
    Similarly solve(0,6,false,s,n) returns the no. of ways for the arithmetic expression s(0,6) to be false
    */
    if(i==j)
    {
        if(s[i]=='T')
        {
            if(expected_boolean == true)
            return 1;
            else
            return 0;
        }
        else
        {
            if(expected_boolean == false)
            return 1;
            else
            return 0;
        }
    }
    if(dp[i][j][expected_boolean]!=-1)
    return dp[i][j][expected_boolean];
    int count = 0;
    int ans;
    int ind=i;
    while(ind<j)
    {
        if(s[ind+1]=='&')
        {
            /*
            if we split the expression e into e1 and e2, then the expresion e can be 
            evaluated to true only if both e1 and e2 are true
            */
            if(expected_boolean == true)
            ans = solve(i,ind,true,s,n)*solve(ind+2,j,true,s,n);
            else
            {
                int ans1 = solve(i,ind,false,s,n)*solve(ind+2,j,true,s,n); //F*T
                int ans2 = solve(i,ind,true,s,n)*solve(ind+2,j,false,s,n); //T*F
                int ans3 = solve(i,ind,false,s,n)*solve(ind+2,j,false,s,n); // F*F
                ans = ans1 + ans2 + ans3;
            }
        }
        else if(s[ind+1]=='|')
        {
            if(expected_boolean == true)
            {
                int ans1 = solve(i,ind,true,s,n)*solve(ind+2,j,false,s,n);
                int ans2 = solve(i,ind,false,s,n)*solve(ind+2,j,true,s,n);
                int ans3 = solve(i,ind,true,s,n)*solve(ind+2,j,true,s,n);
                ans = ans1 + ans2 + ans3;
            }
            else
            {
                // false only if both are false
                ans = solve(i,ind,false,s,n)*solve(ind+2,j,false,s,n);
            }
        }
        else
        {
            if(expected_boolean == true)
            {
                int ans1 = solve(i,ind,true,s,n)*solve(ind+2,j,false,s,n);
                int ans2 = solve(i,ind,false,s,n)*solve(ind+2,j,true,s,n);
                ans = ans1 + ans2;
            }
            else
            {
                int ans1 = solve(i,ind,true,s,n)*solve(ind+2,j,true,s,n);
                int ans2 = solve(i,ind,false,s,n)*solve(ind+2,j,false,s,n);
                ans = ans1 + ans2;
            }
        }
        count += ans;
        ind = ind + 2;
    }
    return dp[i][j][expected_boolean] = count;
}
/*
T|T&F^T = 
0123456
splits:- 
1) (0,0) | (2,6) ind=0
2) (0,2) & (4,6) ind=2
3) (0,4) & (6,6) ind=4
-> if the operation is & then 
total no. of ways to evaluate to true = (no. of ways for left half to be true)*(no. of ways for right half to be true)
Again each one can be seperately split recursively
-> Similar conditions follow for & and ^ operations
*/
class Solution {
  public:
    int countWays(string &s) 
    {
        int i = 0;
        int n = s.length();
        int j = n-1;
        memset(dp,-1,sizeof(dp));
        return solve(i,j,true,s,n);
    }
};
