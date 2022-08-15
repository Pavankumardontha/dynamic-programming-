string s1,s2;
int n1,n2;

int solve(int i, int j)
{
    /* there exists 2 cases if (i<n1 and j<n2)
    1) if s1[i] == s2[j] :- just move forward
    2) if s1[i] != s2[j] 
        - delete character from s1 
        - delete character from s2
    */
    if(i==n1)
    {
        /* delete all remaining characters from s2 */
        return n2-j;
    }
    if(j==n2)
    {
        /* delete all remaning characters from s1*/
        return n1-i;
    }
    int ans1 = INT_MAX;
    int ans2 = INT_MAX;
    if(s1[i]==s2[j])
        ans1 = solve(i+1,j+1);
    else
    {
        ans1 = 1 + solve(i+1,j); // delete s1[i]
        ans2 = 1 + solve(i,j+1); // delete s2[j]
    }
    return min(ans1,ans2);
}


class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        s1 = word1;
        s2 = word2;
        n1 = word1.length();
        n2 = word2.length();
        int ans = solve(0,0);
        return ans;
    }
};
