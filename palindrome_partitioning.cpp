vector<vector<string>> ans;
bool isPalindrome(string s)
{
    int n = s.length();
    int i = 0;
    int j = n-1;
    while(i<j)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
        return false;
    }
    return true;
}
void solve(int i, vector<string>& temp, string &s, int& n)
{
    if(i==n)
    {
        ans.push_back(temp);
        return;
    }
    else
    {
        string sub_string; // substring starting from index i
        for(int len=1;len<=n-i;len++)
        {
            // obtain different lengths substrings starting from index i 
            // check if the substring obtained is palindrome or not.
            // if its a palindrome , add into temp and start a new partition moving forward.
            sub_string = s.substr(i,len); // current partition sub string
            if(isPalindrome(sub_string))
            {
                temp.push_back(sub_string);
                solve(i+len,temp,s,n);
                temp.pop_back();
            }
        }
    }
}


class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        ans.clear();
        int n = s.length();
        vector<string> temp;
        solve(0,temp,s,n);
        return ans;
    }
};
