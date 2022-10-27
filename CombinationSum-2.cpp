/*
This is very very important model. Here the input array can contain duplicate elements and due to this , some of the combinations will repeat. We 
need to eliminate these repeating combinations and should only output unique combinations. Here are the possible combinations of all problems 

Given an input array and a target value , the possible type of problems that we face are listed below.
      Array              restriction       output 
1) distinct elements + taken only once + Combinations ( combination sum - 3 )
2) Distinct elements + taken any times + Combinations ( coin combinations - 2 , combination sum - 1 )
3) Distinct elements + taken only once + Permutations  
4) Distinct elements + taken any times + Permutations ( combination sum - 4 , coin combinations - 1 )
5) Repetition of elements + taken only once + Combinations ( combination sum - 2 )
6) Repetition of elements + taken any times + Combinations 
7) Repetition of elements + taken only once + Permutations
8) Repetition of elements + taken any times + Permutations
*/

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
