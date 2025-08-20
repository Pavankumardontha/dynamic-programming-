int solve(int i, int j, int start, int end, vector<int>& cuts, int& n)
{
    // we cannot make this into DP since start and end range will be very high.
    // we need a way to calculate the difference between start and end. we will see this in the updated version
    if(i==j)
    {
        return end-start;
    }
    else if(i>j)
    return 0;
    else
    {
        long long int ans = INT_MAX;
        long long int temp_ans;
        for(int ind=i;ind<=j;ind++)
        {
            temp_ans = end-start + solve(i,ind-1,start,cuts[ind],cuts,n) + solve(ind+1,j,cuts[ind],end,cuts,n);
            ans = min(ans,temp_ans);
        }
        return ans;
    } 
}

int dp[101][101];
// updated version
int solve1(int i, int j, vector<int>& cuts, int& size, int& n)
{
    // size represents size of the cuts array and n represents the range
    /*
    so whenever we cut we want to calculate the length of the available stick with us by not using start and end 
    but we using only the indices (i,j). Will this be possible ? 
    Lets say we have a stick of n=7 and cuts = [1,3,4,5]

    (0,3) initial lenth = 7 
    if we cut at position cuts[0]=1, we need to calculate 
    1) the cost for cutting the stick 
    How can we calculate this cost=7 in our case ?

    lets say we cut at index ind, then the range of cuts split would be [i,ind-1] [ind+1,j]
    and the cost to cut = cuts[j+1]-cuts[i-1] if j+1<n and i-1>=0.
    if i-1<0 => we take the starting point as 0
    and if j+1>=size of cuts array then we take the ending point as n (here is the length
    of the stick in the starting position and not the size of cuts array. DO NOT CONFUSE BETWEEN
    THESE !!
    we can then obtain the range of the stick and then 
    */
    int start,end;
    if(i-1<0)
    start=0;
    else
    start=cuts[i-1];
    if(j+1>=size)
    end=n;
    else
    end=cuts[j+1];
    if(i==j)
    {
        return dp[i][j] = end-start;
    }
    else if(i>j)
    return 0;
    else if(dp[i][j]!=-1)
    return dp[i][j];
    else
    {
        long long int ans = INT_MAX;
        long long int temp_ans;
        for(int ind=i;ind<=j;ind++)
        {
            temp_ans = end-start + solve1(i,ind-1,cuts,size,n) + solve1(ind+1,j,cuts,size,n);
            ans = min(ans,temp_ans);
        }
        return dp[i][j] = ans;
    } 
}
