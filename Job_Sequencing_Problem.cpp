//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    bool static cmp(Job a, Job b)
    {
        if (a.profit == b.profit)
            return a.dead < b.dead;
        return a.profit < b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        sort(arr, arr + n, cmp);

        int deadmax = arr[n - 1].dead;

        int avail[1000000] = {0};
        int count = 0;
        int profit = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int d = arr[i].dead;

            for (int j = d; j > 0; j--)
            {
                if (avail[j] == 0)
                {

                    avail[j] = 1;
                    count++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }

        return {count, profit};
    }
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends