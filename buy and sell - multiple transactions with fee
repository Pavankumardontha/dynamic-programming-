#include<bits/stdc++.h>
int dp[50001][2];
int solve(int day,bool flag,vector<int>&p , int fee)
{
    if(day==p.size())
        return 0;
    
    if(dp[day][flag]!=-1)
    return dp[day][flag];
    else
    {
        /* we have 2 possibilities.We can have a stock or we have to buy one.*/
        if(flag==1)
        {
    /*we have stock and we can sell it or we can just move without selling on this day.*/
            return dp[day][flag]= max(p[day]-fee+solve(day+1,0,p,fee),solve(day+1,1,p,fee));
        }
        else
        {
    /* we dont have a stock now.So we can either buy one or just move on to the next day.*/
            return dp[day][flag] = max(-p[day]+solve(day+1,1,p,fee),solve(day+1,0,p,fee));
            
        }
    }
}

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
/* on each day,you have 2 options: you can either have a stock to sell or you dont have a stock and you want to buy one.so on each day,you either buy if you dint have or sell if you have.

1)
if you have a stock: you can sell on current day or just move on without selling to the next day

2) if you dont have a stock,you can buy on current day or you can just move on without buying to the next day

flag = 0 means we dont have any stock.
flag = 1 meand we have a stock to sell.
initially we are at day 1 without any stocks.So we will start the recursion from this point of 
time.
*/
        
        
        if(prices.size()==0)
            return 0;
        
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,prices,fee);
        return ans;
};
