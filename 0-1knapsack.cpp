/*take and not take case(same like subsequence but here we have restriction of maximum weight taken)*/

int dp[1001][1001]; //dimensions : max items * max weight of knapsack
int C; //max capacity 
int n; //no. of items
vector<int> v; //value of each item 
vector<int> w; //weight of each item 
/*
cur_item - current item 
cur_weight - current weight
*/
int solve(int cur_item,int cur_weight)
{
    if(cur_item==n)
    return 0;
    if(dp[cur_item][cur_weight]!=-1)
    return dp[cur_item][cur_weight];
    else
    {
        int ans1 = 0; //take but check weight condition before taking.We can only take when the weight condition gets satisfied.
        int ans2 = 0; //dont take (no condition to check as it can be done in any situation)
        
        //max of (take + dont take)
        if(cur_weight + w[cur_item]<=C)
        ans1 = max(v[cur_item] + solve(cur_item+1,cur_weight+w[cur_item],solve(cur_item+1,cur_weight);
        else
        ans2 = solve(cur_item+1,cur_weight); //only dont take 
        
        //return the maximum of the above 2 cases
        dp[cur_item][cur_weight] = max(ans1,ans2);
        return dp[cur_item][cur_weight];
    }
}

class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n1) 
    { 
       n = n1;
       C = W;
       v.clear();
       w.clear();
       memset(dp,-1,sizeof(dp));
       for(int i=0;i<n;i++)
       v.push_back(val[i]);
       for(int i=0;i<n;i++)
       w.push_back(wt[i]);
       int ans = solve(0,0); //we can also start from solve(0,C) and change the conditions accordingly. !!
       return ans;
    }
};
