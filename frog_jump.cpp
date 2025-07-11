unordered_map<long long int,int> mp;
int dp[2001][2001];
bool solve(int current_ind, int last_jump, vector<int>& stones, int n)
{
    if(current_ind==n-1)
    return true;
    if(dp[current_ind][last_jump] != -1)
    return dp[current_ind][last_jump];
    bool ans = false;
    // find all the possibilities from the current state
    if(current_ind == 0) // then we only have one jump option as given in the question
    {
        // find if 1 is present or not
        if(mp.find(1)!=mp.end())
        ans = ans || solve(1,1,stones,n);
        return dp[current_ind][last_jump] = ans;
    }
    else
    {
        int k;
        long long int next = stones[current_ind] + last_jump - 1;
        if(mp.find(next) != mp.end())
        {
            k = mp[next];
            if(k!=current_ind)
            ans = ans || solve(k,last_jump-1,stones,n);
        }
        next = stones[current_ind] + last_jump;
        if(mp.find(next) != mp.end())
        {
            k = mp[next];
            ans = ans || solve(k,last_jump,stones,n);
        }
        next = stones[current_ind] + last_jump + 1;
        if(mp.find(next) != mp.end())
        {
            k = mp[next];
            ans = ans || solve(k,last_jump+1,stones,n);
        }
        return dp[current_ind][last_jump] = ans;
    }
}
class Solution {
public:
    bool canCross(vector<int>& stones) 
    {
        mp.clear();
        int n = stones.size();
        for(int i=0;i<n;i++)
        mp[stones[i]]=i;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            dp[i][j]=-1;
        }
        return solve(0,0,stones,n);
    }
};
