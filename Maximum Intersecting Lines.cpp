//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxIntersections(vector<vector<int>> lines, int N)
    {
        // Code here
        vector<int> start(N), end(N);
        for (int i = 0; i < N; i++)
        {
            start[i] = lines[i][0];
            end[i] = lines[i][1];
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int ans = INT_MIN, intersection = 0, i = 0, j = 0;

        while (i < N && j < N)
        {
            if (start[i] <= end[j])
            {
                intersection++;
                ans = max(ans, intersection);
                i++;
            }
            else
            {
                intersection--;
                j++;
            }
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
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < N; i++)
            {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends