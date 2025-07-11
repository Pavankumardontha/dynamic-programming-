int dp[71][71][71];
bool isValid(int i,int j, int n, int m)
{
    if(i>=n or i<0 or j>=m or j<0)
    return false;
    return true;
}

int solve(int i, int j1, int j2, vector<vector<int>> & grid, int& n, int& m)
{
    // (i1,j1) -> position of robot 1
    // (i2,j2) -> position of robot 2
    /*
    both the robots will be in the same row when same no. of steps are taken by both the robots 
    since always the robots move to the next row in each step so instead of using i1 and i2 for seperately tagging 
    the rows of each robot. We can use a only a single variable i.
    */
    if(i==n-1)
    {
        // we have reached the final row. Now we need to check whether both the robots are at the same cell. 
        // if they are at the same cell we return the current value only once. If they are at different cells, we return the 
        // sum of both the cell values
        if(j1==j2)
        return grid[i][j1];
        else
        return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)
    return dp[i][j1][j2];

    // explore all possible paths.
    /*
    robot-1 can move in 3 directions and robot-2 can also move in 3 directions. So in total there are 9 combinations of moments
    robot-1 (i+1,j1) -> robot-2 (i+1,j2) , (i+1,j2-1) , (i+1,j2+1) 
    robot-1 (i+1,j1-1) -> robot-2 (i+1,j2) , (i+1,j2-1) , (i+1,j2+1) 
    robot-2 (i+1,j1+1) -> robot-2 (i+1,j2) , (i+1,j2-1) , (i+1,j2+1) 
    We can only explore a combination of indices if both the routes taken by robot-1 and robot-2 are valid.
    */
    int ans = 0;
    int sum = 0; // sum of current cheery values of robot1 and robot2
    if(j1==j2)
    sum = grid[i][j1];
    else
    sum = grid[i][j1] + grid[i][j2];

    if(isValid(i+1,j1,n,m) and isValid(i+1,j2,n,m))
    ans = max(ans, sum + solve(i+1,j1,j2,grid,n,m));
    if(isValid(i+1,j1,n,m) and isValid(i+1,j2-1,n,m))
    ans = max(ans, sum + solve(i+1,j1,j2-1,grid,n,m));
    if(isValid(i+1,j1,n,m) and isValid(i+1,j2+1,n,m))
    ans = max(ans, sum + solve(i+1,j1,j2+1,grid,n,m));

    if(isValid(i+1,j1-1,n,m) and isValid(i+1,j2,n,m))
    ans = max(ans, sum + solve(i+1,j1-1,j2,grid,n,m));
    if(isValid(i+1,j1-1,n,m) and isValid(i+1,j2-1,n,m))
    ans = max(ans, sum + solve(i+1,j1-1,j2-1,grid,n,m));
    if(isValid(i+1,j1-1,n,m) and isValid(i+1,j2+1,n,m))
    ans = max(ans, sum + solve(i+1,j1-1,j2+1,grid,n,m));

    if(isValid(i+1,j1+1,n,m) and isValid(i+1,j2,n,m))
    ans = max(ans, sum + solve(i+1,j1+1,j2,grid,n,m));
    if(isValid(i+1,j1+1,n,m) and isValid(i+1,j2-1,n,m))
    ans = max(ans, sum + solve(i+1,j1+1,j2-1,grid,n,m));
    if(isValid(i+1,j1+1,n,m) and isValid(i+1,j2+1,n,m))
    ans = max(ans, sum + solve(i+1,j1+1,j2+1,grid,n,m));
    
    return dp[i][j1][j2] = ans;
}
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        // try to write the recurrance for both at once
        // at each step we try to add the cherrys obtained by 2 robots
        // both the robots will be in the same row always
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=m;k++)
                dp[i][j][k]=-1;
            }
        }
        return solve(0,0,m-1,grid,n,m);
    }
};
