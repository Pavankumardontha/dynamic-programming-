string s1,s2;
int n1,n2;
int solve(int i, int j)
{
    /*
    There exists 2 cases if (i<n1 and j<n2)
    a) s1[i] == s[j] :- In this case , we just move forward 
    b) s1[i] !=s2[j] 
        - Replace s1[i] with s2[j]
        - Delete s1[i] 
        - Insert character s2[j] in s1 at location i-1
    */
    if(i==n1)
    {
        /* all insertions into s1 */
        return n2-j;
    }
    if(j==n2)
    {
        /* all deletions from s1 */
        return n1-i;
    }
    int ans1 = INT_MAX;
    int ans2 = INT_MAX;
    int ans3 = INT_MAX;
    if(s1[i]==s2[j])
        ans1 = solve(i+1,j+1);
    else
    {
        ans1 = 1 + solve(i+1,j+1); // replace
        ans2 = 1 + solve(i+1,j); // delete 
        ans3 = 1 + solve(i,j+1); // insert
    }
    return min(ans1,min(ans2,ans3));
}


class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        s1 = word1;
        s2 = word2;
        n1 = s1.length();
        n2 = s2.length();
        int ans = solve(0,0);
        return ans;
        
    }
};
