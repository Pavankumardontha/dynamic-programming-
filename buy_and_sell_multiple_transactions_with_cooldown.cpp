int dp[5001][2];

int solve(vector<int> &p,int current_day,bool has_stock)
{
    if(current_day>=p.size())
        return 0;
    if(dp[current_day][has_stock]!=-1)
        return dp[current_day][has_stock];
    int ans1 = 0;
    int ans2 = 0;
    /*
    on any day, you can either 
    a) have a stock
        - sell the stock and move forward
        - dont sell and move forward
    b) dont have a stock 
        - buy stock and move forward
        - dont buy and move forward
    */
    if(has_stock)
    {
        ans1 = p[current_day] + solve(p,current_day+2,false); // sell stock and move forward
        ans2 = solve(p,current_day+1,true); // dont sell and move forward
    }
    else
    {
        ans1 = -p[current_day] + solve(p,current_day+1,true);
        ans2 = solve(p,current_day+1,false);
    }
    return dp[current_day][has_stock]=max(ans1,ans2);
}
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        memset(dp,-1,sizeof(dp));
        int ans = solve(prices,0,0);
        return ans;
    }
};
