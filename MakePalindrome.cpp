//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool makePalindrome(int n, vector<string> &arr)
    {
        map<string, int> s;
        for (int i = 0; i < n; i++)
        {
            s[arr[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            string str = arr[i];
            reverse(str.begin(), str.end());
            if (s[arr[i]] != s[str])
            {
                if (arr[i] != str)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        if (ob.makePalindrome(n, arr))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
// } Driver Code Ends