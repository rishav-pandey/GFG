//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c)
    {
        vector<vector<int>> ans(n, vector<int>(m, -1));
        vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (c[i][j] == 'W')
                {
                    q.push({{i, j}, 0});
                    ans[i][j] = 0;
                }
                else if (c[i][j] == 'N')
                {
                    ans[i][j] = 0;
                }
            }
        }
        while (!q.empty())
        {
            int x = q.front().first.first, y = q.front().first.second, d = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny] == -1)
                {
                    if (c[nx][ny] == '.')
                    {
                        q.push({{nx, ny}, d + 2});
                        ans[nx][ny] = 0;
                    }
                    else if (c[nx][ny] == 'H')
                    {
                        q.push({{nx, ny}, d + 2});
                        ans[nx][ny] = d + 2;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (c[i][j] == '.')
                {
                    ans[i][j] = 0;
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> c(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res = ob.chefAndWells(n, m, c);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
}
// } Driver Code Ends