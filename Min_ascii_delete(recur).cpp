string s1,s2;
int n1,n2;

int solve(int i, int j)
{
    /* there exists 2 cases if (i<n1 and j<n2)
    1) if s1[i] == s2[j] :- just move forward
    2) if s1[i] != s2[j] 
        - delete character from s1 and add ascii value of s1 to the answer
        - delete character from s2 and add ascii value of s2 to the answer
    */
    if(i==n1)
    {
        /*delete all characters from s2*/
        int sum = 0;
        while(j<n2)
        {
            sum = sum + int(s2[j]);
            j++;
        }
        return sum;
    }
    if(j==n2)
    {
        /*delete all characters from s1*/
        int sum = 0;
        while(i<n1)
        {
            sum = sum + int(s1[i]);
            i++;
        }
        return sum;
    }
    int ans1 = INT_MAX;
    int ans2 = INT_MAX;
    if(s1[i]==s2[j])
        ans1 = solve(i+1,j+1);
    else
    {
        ans1 = int(s1[i]) + solve(i+1,j); // delete s1[i]
        ans2 = int(s2[j]) + solve(i,j+1); // delete s2[j]
    }
    return min(ans1,ans2);
}

class Solution {
public:
    int minimumDeleteSum(string w1, string w2) 
    {
        s1 = w1;
        s2 = w2;
        n1 = w1.length();
        n2 = w2.length();
        int ans = solve(0,0);
        return ans;
    }
};
