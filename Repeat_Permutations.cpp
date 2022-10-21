#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// MODEL :- Repetition in taking of elements allowed + Permutations 

int coins[1001],n,sum;
int solve(int current_sum,vector<int> choices)
{
    if(current_sum == sum)
    {
        for(int i=0;i<choices.size();i++)
        cout<<choices[i]<<" ";
        cout<<endl;
        return 1;
    }
    if(current_sum > sum)
    return 0;
    
    int ans  = 0;
    for(int i=0;i<n;i++)
    {
        choices.push_back(coins[i]); 
        ans = ans + solve(current_sum + coins[i],choices);
        choices.pop_back();
    }
    return ans;
}

int main() 
{
    cin>>n>>sum;
    for(int i=0;i<n;i++)
    cin>>coins[i];
    vector<int> choices; // to store answers
    cout<<"combinations possible :"<<endl;
    int ans = solve(0,choices);
    cout<<"total combintions:"<<ans<<endl;
	return 0;
}

/*
test case : 
3 9
2 3 5

output:
combinations possible :
2 2 2 3 
2 2 3 2 
2 2 5 
2 3 2 2 
2 5 2 
3 2 2 2 
3 3 3 
5 2 2 
total combintions:8
*/
