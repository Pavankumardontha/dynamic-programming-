int n,sum;
vector<vector<int>> ans;
vector<int> a;
unordered_map<int,int> mp;
void solve(int start, int current_sum , vector<int> choices)
{
    if(current_sum == sum)
    {
        ans.push_back(choices);
        return;
    }
    if(start == n or current_sum > sum)
        return;
    
    for(int i=start; i<n; i++)
    {
        if(i>start and a[i]==a[i-1])
            continue;
        choices.push_back(a[i]);
        solve(i+1,current_sum+a[i],choices);
        choices.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        n = candidates.size();
        sum = target;
        ans.clear();
        a.clear();
        for(int i=0;i<n;i++)
        a.push_back(candidates[i]);
        sort(a.begin(),a.end());
        vector<int> choices;
        solve(0,0,choices);
        return ans;
        
        
    }
};
