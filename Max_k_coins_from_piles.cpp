int k;
int solve(vector<vector<int>>& piles , vector<int> &indexes, int coins_picked)
{
    /*indexes[i] stores the number of elements already picked up from ith pile*/
    /* How do we convert this into DP ?? */
    if(coins_picked == k)
    return 0;
    /* we can pick any coin from the remaining */
    int ans  = 0;
    for(int i=0;i<indexes.size();i++)
    {
        if(piles[i].size()==indexes[i])
        continue;
        else
        {
            indexes[i]++;
            int temp_ans = piles[i][indexes[i]-1] + solve(piles,indexes,coins_picked+1);
            ans = max(ans,temp_ans);
            indexes[i]--;
        }
    }
    return ans;
}
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k1) 
    {
        k=k1;
        int n = piles.size();
        vector<int> indexes(n,0);
        int ans = solve(piles,indexes,0);
        return ans;
    }
};


/* DP Solution */
int dp[2001][2001];
int prefix_sum[2001][2001]; // to store prefix sum
int n;
int k;
int solve(vector<vector<int>>& piles, int current_index , int coins_picked)
{
    /* from current pile we can pick at most min(current_pile_size , k-coins_picked) and move to the next 
    pile or we might not pick even a single from our current pile and move to the next pile */
    if(coins_picked == k or current_index==n)
    return 0;
    if(dp[current_index][coins_picked]!=-1)
    return dp[current_index][coins_picked];

    int current_pile_size = piles[current_index].size();
    int remaining_coins = k - coins_picked;
    int max_elements_that_can_be_picked = min(current_pile_size,remaining_coins); 
    // max no of elements that can be picked from current pile
    int ans1 = INT_MIN;
    int ans2 = INT_MIN; // not taking any coin from current pile 
    for(int i=0;i<max_elements_that_can_be_picked;i++)
    {
        int temp_ans = prefix_sum[current_index][i] + solve(piles,current_index+1,coins_picked+i+1);
        ans1 = max(ans1,temp_ans);
    }
    ans2 = solve(piles,current_index+1,coins_picked);
    int ans = max(ans1,ans2);
    return dp[current_index][coins_picked] = ans;
}
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k1) 
    {
        /*
        from each pile , we can pick any number of coins. From the first pile , we can pick either 0 or n 
        coins where n is the size of the pile. This is the case for all the piles. Note that when we pick
        lets say i coins from a pile , then we need to pick remaining k-i coins from the rest of the piles
        and the sum of all the i coins will add up into our answer. To calculate this sum of i elements 
        quickly we use prefix sum.
        */
        n = piles.size();
        k = k1;
        for(int i=0;i<n;i++)
        {
            prefix_sum[i][0]=piles[i][0];
            for(int j=1;j<piles[i].size();j++)
            prefix_sum[i][j] = piles[i][j] + prefix_sum[i][j-1];
        }
        memset(dp,-1,sizeof(dp));
        int current_index = 0; // current pile index
        int coins_picked = 0; // initially we have no coins to pick
        int ans = solve(piles,current_index,coins_picked);
        return ans;
    }
};




