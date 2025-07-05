/* Dijkstra's approach */
bool isValid(int i, int j, int n, int m)
{
    if(i<0 or j<0 or i>=n or j>=m)
    return false;
    return true;
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int dis[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            dis[i][j]=INT_MAX;
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        dis[0][0]=grid[0][0];
        pair<int,pair<int,int>> temp;
        int x,y;
        while(!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            x = temp.second.first;
            y = temp.second.second;
            if(isValid(x+1,y,n,m) and dis[x+1][y] > dis[x][y] + grid[x+1][y])
            {
                dis[x+1][y] = dis[x][y] + grid[x+1][y];
                pq.push({dis[x+1][y],{x+1,y}});
            }
            if(isValid(x,y+1,n,m) and dis[x][y+1] > dis[x][y] + grid[x][y+1])
            {
                dis[x][y+1] = dis[x][y] + grid[x][y+1];
                pq.push({dis[x][y+1],{x,y+1}});
            }
        }
        return dis[n-1][m-1];
    }
};



/* DP approach */
int dp[201][201];
bool isValid(int i, int j, int n, int m)
{
    if(i<0 or j<0 or i>=n or j>=m)
    return false;
    return true;
}

int solve(int i, int j, vector<vector<int>>& grid, int n, int m)
{
    // dp[i][j] minimum path from (i,j) to (n-1,m-1)
    if(i==n-1 and j==m-1)
    return dp[i][j] = grid[i][j];
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans1 = INT_MAX;
    int ans2 = INT_MAX;
    if(isValid(i,j+1,n,m))
    ans1 = grid[i][j] + solve(i,j+1,grid,n,m);
    if(isValid(i+1,j,n,m))
    ans2 = grid[i][j] + solve(i+1,j,grid,n,m);
    return dp[i][j]=min(ans1,ans2);
}
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            dp[i][j]=-1;
        }
        return solve(0,0,grid,n,m);
    }
};
