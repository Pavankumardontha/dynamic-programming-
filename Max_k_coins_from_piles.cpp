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
