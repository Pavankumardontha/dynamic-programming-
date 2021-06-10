#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*we have n1 horses(indistinguishable) and n2 footmen(indistinguishable).Lets get the no. of 
arrangements possible.Before that we will write down the no. of arrangements for n1 = 2 
and n2 = 3 . we will represent n1 by 0 and n2 by 1 
n1(0) = 2 
n2(1) = 3 
5C3 = 5C2 = 5!/(2!*3!) = 10 
Note that n1 and n2 are indistinguishable among themselves !!!! 
*/

int get1(int n1,int n2)
{
    if(n1==0 || n2==0)
    return 1;
    else
    {
        int ans1 = 0;
        int ans2 = 0;
        if(n1>0)
        ans1 = get1(n1-1,n2);
        if(n2>0)
        ans2 = get1(n1,n2-1);
        int res = ans1 + ans2;
        return res;
    }
}

/*Lets now put a restriction saying that we want not more than k1 horsemen to be continuous 
and not more than k2 footmen to be continuous.
*/
int k1_limit;
int k2_limit;
//once we keep 1 object, the limit of other object becomes maximum
int get2(int n1,int k1,int n2,int k2)
{
    if(n1==0 || n2==0)
    return 1;
    else
    {
        int ans1 = 0;
        int ans2 = 0;
        if(n1>0 && k1>0)
        ans1 = get2(n1-1,n2,k1-1,k2_limit);
        if(n2>0 && k2>0)
        ans2 = get2(n1,n2-1,k1_limit,k2-1);
        int ans = ans1 + ans2;
        return ans;
    }
}

/* lets now convert the above function into dynamic programming. We have 4 variables 
which are changing and hence the dp table is 4 dimentional. 
max value of n1,n2 = 100
max value of k1,k2 = 10 
hence the dp table is dp[101][101][11][11]
*/

/*
test case solving :- 
1)(n1,n2,k1_limit,k2_limit) = (2,3,1,2);k1_limit = 1 and k2_limit = 2 
(2,3,1,2) = (1,3,0,2) + (2,2,1,1) 
(1,3,0,2) = (1,2,1,2) = (0,2,0,2) + (1,1,1,1) = 1 + 1 = 2  
(2,2,1,1) = (1,2,0,2) + (2,1,1,0)
(1,2,0,2) = (1,1,1,1) = (0,1,0,1) + (1,0,1,0) = 2  
(2,1,1,0) = 1 
total = 5 
But lets solve the case which is 
2) (n1,n2,k1,k2)=(2,1,1,10) which should give answer as 1
(2 1 1 10) = (2,0,1,9) + (1,1,0,10)
(2,0,1,9) = (1,0,0,9) = 0 (this returns 0.So there are also cases which return 0 when n1+n2!=0 but k1==0 and k2==0) 
(1,1,0,10) = (1,0,1,9) + (0,0,0,10) = 1(this returns 1 since both n1==0 and n2==0 and so n1+n2=0)
*/
long long int dp[101][101][11][11]; //initialise this to -1 in the main function 
long long int m = 1e8;
int get(int n1,int n2,int k1,int k2)
{
    if(n1+n2==0) //here 
    return 1;
    else if(dp[n1][n2][k1][k2]!=-1)
    return dp[n1][n2][k1][k2];
    else
    {
        long long int ans1 = 0;
        long long int ans2 = 0;
        if(n1>0 && k1>0)
        ans1 = get(n1-1,n2,k1-1,k2_limit);
        if(n2>0 && k2>0)
        ans2 = get(n1,n2-1,k1_limit,k2-1);
        dp[n1][n2][k1][k2] = (ans1%m + ans2%m)%m;
        return dp[n1][n2][k1][k2];
    }
}

int main()
{
    int n1,n2;
    cin>>n1>>n2>>k1_limit>>k2_limit;
    memset(dp,-1,sizeof(dp));
    int ans = get(n1,n2,k1_limit,k2_limit);
    cout<<ans<<endl;
}
