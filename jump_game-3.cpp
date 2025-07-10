// DP approach
int dp[50001];
bool vis[50001];
int solve(int i,vector<int>& arr, int& n)
{
    vis[i]=true;
    if(i==n)
    return false;
    if(arr[i]==0)
    return dp[i] = 1;
    // you can jump to the front or to the back
    bool ans1 = false;
    bool ans2 = false;
    if(i+arr[i]<=n and vis[i+arr[i]]==false)
    ans1 = solve(i+arr[i],arr,n);
    if(i-arr[i]>=0 and vis[i-arr[i]]==false)
    ans2 = solve(i-arr[i],arr,n);
    return dp[i] = ans1 or ans2;
}

class Solution {
public:
    bool canReach(vector<int>& arr, int start) 
    {
        /*
        dp[i]=1 we can reach an index ind where arr[ind]==0 from i
        dp[i]=0 we cannot reach an index ind where arr[ind]=0 from i
        dp[i]=-1 this subproblem/state is not solved yet
        */
        int n = arr.size();
        for(int i=0;i<=n;i++)
        dp[i]=-1;
        for(int i=0;i<=n;i++)
        vis[i]=false;
        return solve(start,arr,n);
    }
};



// BFS approach 
class Solution {
public:
    bool canReach(vector<int>& a, int start) 
    {
        int n = a.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(start);
        vis[start]=true;
        while(!q.empty())
        {
            int ind = q.front();
            q.pop();
            if(a[ind]==0)
            return true;
            // ind might have 2 children that is ind-a[ind] and ind+a[ind]
            if(ind-a[ind]>=0 and vis[ind-a[ind]]==false)
            {
                q.push(ind-a[ind]);
                vis[ind-a[ind]]=true;
            }
            if(ind+a[ind]<n and vis[ind+a[ind]]==false)
            {
                q.push(ind+a[ind]);
                vis[ind+a[ind]]=true;
            }
        }
        return false;
    }
};
