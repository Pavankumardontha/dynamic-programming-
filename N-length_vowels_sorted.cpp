/*
Given an integer N, the task is to count all possible strings of length N consisting of vowels {a, e, i, o, u} that can be formed such that each string is sorted 
in lexicographical order.
Input: N = 2
Output: 15
Explanation: The strings of length 2 which are sorted in lexicographical order are [“aa”, “ae”, “ai”, “ao”, “au”, “ee”, “ei”, “eo”, “eu”, “ii”, “io”, “iu”, “oo”,
“ou”, “uu”].
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int dp[1001][6];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=5;j++)
        dp[i][j]=0;
    }
    //dp[i][j] = count of length i strings containing first 'j' vowels in lexographical order
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            if(i==1)
            dp[i][j] = dp[i][j-1]+1;
            else
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    cout<<dp[n][5]<<endl;
}
