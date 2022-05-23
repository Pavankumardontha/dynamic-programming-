
// NOTE :- This problem can be solved recursively but it CANNOT be optimised using dp since it does not have overlapping subproblems !!!

int solve(vector<int> &prices, int n, int current_day ,bool has_stock,int holding_stock_price)
{
    /* NOTE :- you can buy or/and sell on each day. This statement has alot of meaning. This means out of buying and selling , you can do both , nothing
    or anyone !!! 
    On any day , we can either
    1) Have a stock
        - sell this stock , dont buy any stock move forward 
        - sell this stock , buy a stock and move forward
        - dont sell and move forward
    2) Doesnt have a stock
        - buy one stock and move forward 
        - buy and sell on the same day and move forward(this will not impact the profit in anyway). This is just like do not buy and move forward
        - Do not buy and just move forward
    */
    if(current_day==n)
        return 0;
    int ans1 = 0;
    int ans2 = 0;
    int ans3 = 0;
    if(has_stock)
    {
        if(prices[current_day]>holding_stock_price)
        {
            ans1 = prices[current_day] - holding_stock_price + solve(prices,n,current_day+1,false,0);// sell the stock, do not buy and move forward
            ans2 = prices[current_day] - holding_stock_price + solve(prices,n,current_day+1,true,prices[current_day]); // sell the holding stock and buy another stock and move forward.
        }
        ans3 = solve(prices,n,current_day+1,has_stock,holding_stock_price);// dont sell and move forward 
    }
    else
    {
        ans1 = solve(prices,n,current_day+1,true,prices[current_day]);// buy one stock and move forward
        ans2 = solve(prices,n,current_day+1,has_stock,0);// Do not buy and just move forward 
    }
    return max(ans1,ans2);
}

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {  
        int ans = solve(prices,prices.size(),0,false,0);
        return ans;
    }
};
