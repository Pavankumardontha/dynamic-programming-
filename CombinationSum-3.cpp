int sum,max_count,a[9];
vector<vector<int>> ans;
void solve(int i, int current_sum, int count, vector<int> choices)
{
    if(current_sum == sum and count==max_count)
    {
        ans.push_back(choices);
        return;
    }
    if(i==9 or current_sum > sum or count>=max_count)
        return;
    // do not take and move forward
    solve(i+1, current_sum, count, choices);
    // take and move forward
    choices.push_back(a[i]);
    solve(i+1,current_sum  + a[i], count + 1 , choices);
    choices.pop_back();
    
}
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        ans.clear();
        sum = n;
        max_count = k;
        for(int i=0;i<9;i++)
            a[i] = i+1;
        int max_ans = 9*k;
        if(n>max_ans)
            return ans;
        vector<int> choices;
        solve(0,0,0,choices);
        return ans;
        
    }
};
