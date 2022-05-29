int dp[1001][2][101];

int solve(vector<int> &p,int k, int current_day, bool has_stock , int transactions)
{
    if(current_day == p.size() || transactions >= k)
        return 0;
    if(dp[current_day][has_stock][transactions]!=-1)
        return dp[current_day][has_stock][transactions];
    /*On any day , you can either 
    a) have a stock 
        - sell stock and move forward 
        - dont sell and move forward
    b) do not have a stock
        - buy stock and move forward
        - dont buy and move forward
    */
    int ans1 = 0;
    int ans2 = 0;
    if(has_stock)
    {
        ans1 = p[current_day] + solve(p,k,current_day+1,false,transactions+1);
        ans2 = solve(p,k,current_day+1,true,transactions);
    }
    else
    {
        ans1 = -p[current_day] + solve(p,k,current_day+1,true,transactions);
        ans2 = solve(p,k,current_day+1,false,transactions);
    }
    return dp[current_day][has_stock][transactions]=max(ans1,ans2);
}

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        memset(dp,-1,sizeof(dp));
        int ans = solve(prices,k,0,0,0);
        return ans;   
    }
};
