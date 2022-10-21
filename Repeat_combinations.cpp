/* 
Problem : Given an array of coins of size n and a sum k , find the no. of DISTINCT ORDERED ways you can make sum equals k using the elements of coins 
array. You are allowed to take each element multiple times. ( CSES Coins Combination - 2 )
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/* MODEL :- Repetition in taking of elements allowed + Combinations */

int coins[101],n,sum;
int solve(int i, int current_sum, vector<int> choices)
{
    if(current_sum == sum)
    {
        for(int i=0;i<choices.size();i++)
        cout<<choices[i]<<" ";
        cout<<endl;
        return 1;
    }
    if(i==n or current_sum > sum)
    return 0;
    // do not take and move forward
    int ans1 = solve(i+1,current_sum,choices); 
    
    // take and stay in the same position
    choices.push_back(coins[i]); // push the taken element
    int ans2 = solve(i,current_sum+coins[i],choices); // take and dont move
    choices.pop_back(); // pop the taken element
    return ans1 + ans2;
}

int main()
{
    cin>>n>>sum;
    for(int i=0;i<n;i++)
    cin>>coins[i];
    vector<int> choices;
    cout<<"combinations possible :"<<endl;
    int ans = solve(0,0,choices);
    cout<<"total combintions:"<<ans<<endl;
    
}

/*
test case : 
3 9
2 3 5  

output : 
combinations possible :
3 3 3 
2 2 5 
2 2 2 3 
total combintions:3
*/
