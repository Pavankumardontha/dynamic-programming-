/* Applying DIJKSTRA's approach */
bool isValid(int i, int j, int n, int m)
{
    if(i<0 or j<0 or i>=n or j>=m)
    return false;
    return true;
}

class Solution {
  public:
    int maximumPath(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        int dis[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            dis[i][j]=INT_MIN; // since we want to find the maximum path
        }
        
        priority_queue<pair<int,pair<int,int>>> pq; // max heap sorted by first element
        for(int j=0;j<m;j++)
        {
            dis[0][j]=mat[0][j]; // initialise the first row with mat values
            // push them into the priority queue
            pq.push({dis[0][j],{0,j}});
        }
        pair<int,pair<int,int>> temp;
        int x,y;
        while(!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            x = temp.second.first;
            y = temp.second.second;
            if(isValid(x+1,y-1,n,m) and dis[x+1][y-1] < dis[x][y] + mat[x+1][y-1])
            {
                dis[x+1][y-1] = dis[x][y] + mat[x+1][y-1];
                pq.push({dis[x+1][y-1],{x+1,y-1}});
            }
            if(isValid(x+1,y,n,m) and dis[x+1][y] < dis[x][y] + mat[x+1][y])
            {
                dis[x+1][y] = dis[x][y] + mat[x+1][y];
                pq.push({dis[x+1][y],{x+1,y}});
            }
            if(isValid(x+1,y+1,n,m) and dis[x+1][y+1] < dis[x][y] + mat[x+1][y+1])
            {
                dis[x+1][y+1] = dis[x][y] + mat[x+1][y+1];
                pq.push({dis[x+1][y+1],{x+1,y+1}});
            }
        }
        int ans = INT_MIN;
        for(int j=0;j<m;j++)
        {
            ans = max(ans,dis[n-1][j]);
        }
        return ans;
    }
};


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/
// DP approach
int dp[501][501];
bool isValid(int i, int j, int n, int m)
{
    if(i<0 or j<0 or i>=n or j>=m)
    return false;
    return true;
}

int solve(int i, int j, vector<vector<int>>& grid, int& n, int& m)
{
    if(i==n-1) // we have reached the last row
    return grid[i][j];
    // we can move right , down , diagonal
    // solve(i,j) find the maximum distance starting from (i,j) to reach the last row
    if(dp[i][j] != -1)
    return dp[i][j];
    int down = INT_MIN;
    int right = INT_MIN;
    int diagonal = INT_MIN;
    if(isValid(i+1,j-1,n,m))
    diagonal =  solve(i+1,j-1,grid,n,m);
    if(isValid(i+1,j,n,m))
    down = solve(i+1,j,grid,n,m);
    if(isValid(i+1,j+1,n,m))
    right = solve(i+1,j+1,grid,n,m);
    return dp[i][j] = grid[i][j] + max(down,max(right,diagonal));
}

class Solution {
  public:
    int maximumPath(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            dp[i][j]=-1;
        }
        int ans = INT_MIN;
        for(int j=0;j<m;j++)
        {
            ans = max(ans,solve(0,j,mat,n,m));
        }
        return ans;
    }
};





