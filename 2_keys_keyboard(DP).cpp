int n;
long long int dp[1001][1001][2];
long long int solve(int current_count,int paste_count,int previous_choice)
{
    /*
    In each step you can either copy or paste depending on the previous choice
    if previous step is 
    1) copy(0) 
        a) we can only paste in the current step
    2) paste(1)
        a) we can paste again in the current step
        b) we can copy in the current step
    */
    if(current_count == n)
        return 0;
    if(current_count>n)
        return INT_MAX;
    if(dp[current_count][paste_count][previous_choice]!=-1)
        return dp[current_count][paste_count][previous_choice];
    long long int ans1 = INT_MAX;
    long long int ans2 = INT_MAX;
    if(previous_choice)
    {
        // previous choice is paste
        ans1 = 1 + solve(current_count+paste_count,paste_count,1);
        ans2 = 1 + solve(current_count,current_count,0);
    }
    else
    {
        // previous choice is copy
        ans1 = 1 + solve(current_count+paste_count,paste_count,1);
    }
    dp[current_count][paste_count][previous_choice] = min(ans1,ans2);
    return dp[current_count][paste_count][previous_choice];
}
class Solution {
public:
    int minSteps(int n1) 
    {
        n = n1;
        memset(dp,-1,sizeof(dp));
        /* first choice is always copy since we have nothing to paste
            0 - copy 
            1 - paste
        */
        if(n==1)
            return 0;
        // take the first choice of copy
        long long int ans = 1 + solve(1,1,0);
        return ans;
    }
};
