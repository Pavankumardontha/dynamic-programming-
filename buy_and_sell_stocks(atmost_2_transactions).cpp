int dp[100001][2][2];

int solve(vector<int> &p,int current_day,bool has_stock,int transactions)
{
    if(current_day == p.size() || transactions >= 2)
        return 0;
    if(dp[current_day][has_stock][transactions]!=-1)
        return dp[current_day][has_stock][transactions];
    /*
    on any day , you can either 
    a) have a stock 
        - sell the stock , increase the transactions count and move forward
        - dont sell the stock and just move forward
    b) dont have a stock
        - buy one stock and move forward 
        - dont buy stock and move forward
    */
    int ans1 = 0;
    int ans2 = 0;
    if(has_stock)
    {
        ans1 = p[current_day] + solve(p,current_day+1,false,transactions+1); // sell the stock and move forward
        ans2 = solve(p,current_day+1,true,transactions); // dont sell the stock and move forward
    }
    else
    {
        ans1 = -p[current_day] + solve(p,current_day+1,true,transactions); // buy stock and move forward
        ans2 = solve(p,current_day+1,false,transactions); // dont buy stock and move forward
    }
    return dp[current_day][has_stock][transactions] = max(ans1,ans2);
}
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        memset(dp,-1,sizeof(dp));
        int ans = solve(prices,0,0,0);
        return ans;
    }
};
