//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<long long> smallerSum(int n, vector<int> &arr)
    {
        // Code here
        map<int, long long> m;
        for (int i = 0; i < n; i++)
            m[arr[i]]++;
        long long sum = 0;
        vector<long long> ans;
        for (auto i : m)
        {
            long long temp = sum;
            sum += (long long)(i.first * i.second);
            m[i.first] = temp;
            ;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            ans.push_back(m[arr[i]]);
        }
        return ans;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<long long> ans = ob.smallerSum(n, arr);
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
            {
                cout << ans[i] << " ";
            }
            else
            {
                cout << ans[i] << endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends