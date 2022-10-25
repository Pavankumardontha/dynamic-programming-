/* recursive approach */
int p[1001];
int n;
int solve(int len)
{
    if(len==0)
    return 0;
    int ans1=0;
    int ans2=0;
    /*
    if we have a rod of length i we can 
    1) either sell the entire rod of length i or 
    2) We can try all possible cuts
    */
    ans1 = p[len];
    for(int i=1;i<=len;i++)
    ans2 = max(ans2,p[i]+solve(len-i));
    
    return max(ans1,ans2);
}

class Solution{
  public:
    int cutRod(int price[], int N) 
    {
        n=N;
        for(int i=1;i<=n;i++)
        p[i]=price[i-1];
        int ans = solve(N);
        return ans;
    }
};
