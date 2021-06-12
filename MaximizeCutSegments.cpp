class Solution
{
    public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        /* this is similar to Number of coins problem.there it was minimum and here 
        its maximum. Thats the only difference*/
        
        int dp[n+1]; //n acts like sum here
        dp[0]=0;
        for(int i=1;i<=n;i++)
        dp[i]=INT_MIN;
        
        /*lets push x,y, and z into a vector and try to sort them. We will follow the 
        same steps as done in the Number of coins(minimum denomicatoins of coins to 
        make a sum) problem */
        vector<int> a;
        a.push_back(x);
        a.push_back(y);
        a.push_back(z);
        sort(a.begin(),a.end());
        for(int j=1;j<=n;j++)
        {
            for(int i=0;i<3;i++)
            {
                if(j-a[i]>=0)
                {
                    if(dp[j-a[i]]!=INT_MIN)
                    dp[j] = max(dp[j],1+dp[j-a[i]]);
                }
            }
        }
        if(dp[n]==INT_MIN)
        return 0;
        else
        return dp[n];
    }
};
