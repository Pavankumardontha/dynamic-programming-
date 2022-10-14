string f;
int n;
int l;
int left_over_ones[1001];
int dp[1001][1001];
int solve(int current_index,int used_carpets)
{
    /*
    At any given point of time our current_index can be 
    1) black
        a) cover it with carpet and move forward
        b) do not cover it with carpet and move forward
    2) white
        a) cover it with carpet and move forward
        b) do not cover it with carpet and move forward
    */
    if(current_index>=f.length())
        return 0;
    
    if(used_carpets == n)
        return dp[current_index][used_carpets] = left_over_ones[current_index];
    if(dp[current_index][used_carpets]!=-1)
        return dp[current_index][used_carpets];
    int ans1 = INT_MAX;
    int ans2 = INT_MAX;
    if(f[current_index]=='0')
    {
        // current tile is black
        ans1 = solve(current_index+l,used_carpets+1); // cover with carpet
        ans2 = solve(current_index+1,used_carpets); // do not cover with carpet
    }
    else
    {
        // current tile is white
        ans1 = solve(current_index+l,used_carpets+1); // cover the carpet
        ans2 = 1 + solve(current_index+1,used_carpets); // do not cover the carpet
    }
    return dp[current_index][used_carpets] = min(ans1,ans2);
}

class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) 
    {
        f = floor;
        n = numCarpets;
        l = carpetLen;
        int sum = 0;
        memset(dp,-1,sizeof(dp));
        
        // left_over_ones[i] tells the number of 1's present from index [i,n-1] of string f.
        for(int i=f.length()-1;i>=0;i--)
        {
            if(f[i]=='1')
                sum = sum + 1;
            left_over_ones[i]=sum;
        }
        int ans = solve(0,0);
        return ans;
    }
};
