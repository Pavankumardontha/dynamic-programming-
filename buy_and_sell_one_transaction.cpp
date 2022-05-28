int maxProfit(vector<int>& prices) 
    {
/*We will try to the stock on each day and calculate the profit.Lets say we are at ith index and we want to sell the stock on this day.To sell
the stock on this day,we need to buy a stock from [0,1,2,..i-1].Since we are looking for maximum profit,we will buy the stock which has the minimum price 
in days [0,1,2,..i-1]. 
*/
        int n = prices.size();
        if(n==1)
            return 0;
        else
        {
            int minimum = prices[0];
            int ans = 0;
            for(int i=1;i<n;i++)
            {
                ans = max(ans,prices[i]-minimum);
                minimum = min(minimum,prices[i]);
            }
            return ans;
        }
    }
