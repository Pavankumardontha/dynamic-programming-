class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int ans = 0;
        if(n==0 or n==1)
            return ans;
        for(int i=0;i<n-1;i++)
        {
            if(prices[i]<prices[i+1])
                ans = ans + prices[i+1]-prices[i];
            
        }
        return ans;
        
    }
};
