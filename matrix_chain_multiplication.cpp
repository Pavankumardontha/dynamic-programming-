/*
Given 2 matrices A,B of size 2*3 and 3*2 lets analyse how many 
multiplication operations we need to do to generate each element 
in the matrix C = A*B

to generate the element at (0,0) of C, we need to 
multiple the entire first row of A with the entire first column of B
->No. of elements in first row of A = 3(a1,a2,a3)
->No. of elements in the first col of B = 3(b1,b2,b3)
= element at (0,0) = a1*b1 + a2*b2 + a3*b3
-> So we need to do a total of 3 multiplication operations to
generate element at (0,0) in C.
In C , we will have a total of 4 elements and each element 
requires 3 operations so the total no. of operations = 4*3=12


Now , if A is n1*m1 and B is n2*m2 , for multiplying A and B
we require m1=n2. 
No. of operations to generate the entire product matrix C = A*B
= Total no. of elements in C * no. of multiplications to get each element
= (n1*m2)*m1 = (n1*m2)*n2 (since m1=n2 for multiplication to be possible)

-> in the quetion we have given all matrices and their orders. We need to 
find the minimum operations required to find the resultant matrix C.

lets say we are given C = (A*B*C*D*E*F).
Lets analyse the grouping options in this case, we can group in any of the following options
1) (A)*(BCDEF)
2) (AB)*(CDEF)
3) (ABC)*(DEF)
4) (ABCD)*(EF)
5) (ABCDE)*(F)

And again each possibility will have a chain of possibilities. We need to
calculate the minimum operations in call the cases.

In each case , we will have a left resultant matrix and a right resultant matrix.
If we multiple both , we get the final resultant matrix.
The no. of operations to generate final resultant matrix = No of operations
to construct left resultant (=l1) + No. of operations to construct the right
resultant(r1) + no. of operations to combine the left and the right resultant
No. of operations = l1 + r1 + operations to combine left and right resultants.
*/

int dp[101][101];
int solve(int i, int j, vector<int>& arr)
{
    if(i==j)
    {
        // In this case, we only have one element which do not require any operations
        return 0;
    }
    if(dp[i][j]!=-1)
    return dp[i][j];
    else
    {
        /* 
        we can split anywhere in the range [i,j] 
        [i,j] = [i,i] + [i+1,j]
        [i,j] = [i,i+1] + [i+2,j]
        .
        .
        We will calculate the operations required in each case and then return the minimum of them
        */
        int minimum_operations=INT_MAX;
        int total_operations = 0;
        int multiply_operations = 0;
        int left_operations = 0;
        int right_operations = 0;
        for(int ind=i;ind<j;ind++)
        {
            /*
            ind is the index at which we split
            [i,j] = [i,ind] + [ind+1,j] 
            left_resultant = [i,ind]
            right_resultant = [ind+1,j]
            */
            left_operations = solve(i,ind,arr);
            right_operations = solve(ind+1,j,arr);
            /*
            order of left resultant = arr[i]*arr[ind+1]
            order of rigth resultant = arr[ind+1]*arr[j+1]
            total multiplication operations to combine = arr[i]*arr[ind+1]*arr[j+1]
            */
            multiply_operations =  arr[i]*arr[ind+1]*arr[j+1];// multiplication operations to combine left and right resultants
            total_operations = left_operations + right_operations + multiply_operations;
            minimum_operations = min(minimum_operations,total_operations);
        }
        return dp[i][j] = minimum_operations;
    }
}
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) 
    {
        int n = arr.size();
        int i = 0;
        int j = n-2;
        memset(dp,-1,sizeof(dp));
        return solve(i,j,arr);
    }
};
