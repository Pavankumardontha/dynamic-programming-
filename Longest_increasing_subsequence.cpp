int a[3000];
int n;
int dp[2600][2600];
int solve(int index,int previous_index)
{
    /*
    at any given index , 
    a) you can either take the element and move forward (we need to check a condition before taking)
    b) you can skip the element and move forward
    */
    if(index == n)
    return 0;
    if(dp[index][previous_index+1]!=-1) // very important
    return dp[index][previous_index+1];
    int ans1 = INT_MIN;
    int ans2 = INT_MIN;
    if(previous_index == -1)
    {
        // we did not take any elements and the array is empty
        ans1 = 1 + solve(index+1,index);
    }
    else
    {
        // we have few elements and take the current element if it is greater than the previous element
        if(a[index]>a[previous_index])
        ans1 = 1 + solve(index+1,index);
    }
    ans2 = solve(index+1,previous_index);
    return dp[index][previous_index+1] = max(ans1,ans2);

}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        a[i]=nums[i];
        int ans = solve(0,-1);
        return ans;

    }
};

/*------------------------------------------------SOLUTION - 2-----------------------------------------------------------------------------------------*/
#include<iostream>
using namespace std;
vector<int> a,b;
//a is to store the input and b is to store the LIS
int main()
 {
	int t,n,k;
	cin>>t;
	vector<int>:: iterator it;//to find the lower bound
	while(t--)
	{
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        cin>>k;
	        a.push_back(k);
	    }
	//we have our array ready.
	for(int i=0;i<a.size();i++)
	{
	    if(i==0)
	    b.push_back(a[i]);
	    else
	    {
	        //here we have 2 cases.One is insertion and the other is replacement in the LIS array
	        k=b.size()-1;//finding the last element index of b.
	        if(b[k]<a[i])//insertion into the LIS array
	        b.push_back(a[i]);
	        else
	        {
	            //replacement case.
	         it=lower_bound(b.begin(),b.end(),a[i]);
/*we have to apply lower bound on the LIS array and not on
array a.LIS array will always be sorted.We apply lower and
upper bound mostly for sorted arrays.*/
	         k=it-b.begin();//this gives the position index of the lower bound of a[i];
	         b[k]=a[i];
	        }
	    }
	}
	cout<<b.size()<<endl;
	a.clear();
	b.clear();
	
}
}


/* here we will also do this problem in traditional dynamic programming way. Time complexity is O(N^(2)) which is more than the previous case.*/
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int lis[n];
    for(int i=0;i<n;i++)
    lis[i]=1;
    
    int ans=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i] && lis[j]+1>lis[i])
            {
                lis[i]=lis[j]+1;
                ans=max(ans,lis[i]);
            }
        }
    }
    cout<<ans<<endl;
}
