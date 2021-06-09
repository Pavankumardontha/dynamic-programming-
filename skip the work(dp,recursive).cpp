//solution-1 :dp solution 
class Solution
{
  public:
    int minAmount(int a[] , int n)
    {
/*dp[i] = minimum time to complete i tasks including i. This including i is very very 
important here as we always add a[i] to minimum of dp[i-1] and dp[i-2]. Understand this 
relation very very carefully.*/
        int ans;
        int dp[n];
        dp[0] = a[0]; 
        dp[1] = a[1];
        for(int i=2;i<n;i++)
        dp[i] = a[i]+min(dp[i-1],dp[i-2]);
        ans = min(dp[n-1],dp[n-2]);
        return ans;
    }
};


//solution-2 : recursive solution 
int cal(int a[],int n,int i, int pre,int sum)
{
    /*
    1) if previous element is taken,then you have 2 possibilities , either to take 
    the current element or not to 
    2) if previous element is not taken then we have to definitely take this element 
    and move forward. 
    */
    if(i==n)
    return sum;
    else
    {
        if(pre==1)
        {
            //take 
            int ans1 = cal(a,n,i+1,1,sum+a[i]);
            
            // dont take 
            int ans2 = cal(a,n,i+1,0,sum);
            
            //return minimum of both 
            return min(ans1,ans2);
        }
        else
        {
            //only take 
            return cal(a,n,i+1,1,sum+a[i]);
        }
        
    }
    
}

class Solution
{
  public:
    int minAmount(int a[] , int n)
    {
        int ans = cal(a,n,0,1,0);
        return ans;
    }
};

    
