#include<bits/stdc++.h>
#include <iostream>
using namespace std;

/*dp[i][j] = Probability of getting j heads in i moves.
dp[1][1] = P(H)
dp[1][0] = 1-P(H)
*/

int LCS(string s1,string s2,int i,int j)
{
    if(i==s1.length() || j==s2.length())
    return 0;
    else
    {
        if(s1[i]==s2[j])
        return 1 + LCS(s1,s2,i+1,j+1);
        else
        {
            /* move s1 forward keeping s2 at same index */
            int ans1 = LCS(s1,s2,i+1,j);
            /* move s2 forward keeping s1 at the same index*/
            int ans2 = LCS(s1,s2,i,j+1);
            /* return max of the both */
            return max(ans1,ans2);
        }
    }
}


int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int ans = LCS(s1,s2,0,0);
    cout<<ans<<endl;
}
