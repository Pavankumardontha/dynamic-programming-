int n,sum,a[31];
vector<vector<int>> ans;

void solve(int i , int current_sum, vector<int> choices)
{
    if(current_sum == sum)
    {
        ans.push_back(choices);
        return;
    }
    if(current_sum > sum or i==n)
        return ;
    
    // do not take current element and move forward
    solve(i+1,current_sum,choices);
    // take current element and stay back
    choices.push_back(a[i]);
    solve(i,current_sum + a[i], choices);
    choices.pop_back();
    return;
    
}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sum = target;
        n = candidates.size();
        for(int i=0;i<n;i++)
            a[i]=candidates[i];
        ans.clear();
        vector<int> choices;
        solve(0,0,choices);
        return ans;
    }
};
