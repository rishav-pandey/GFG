//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends
class Solution
{
public:
    long long solve(int n, vector<int> &A, vector<int> &B)
    {
        // code here
        long long s1 = 0;
        long long s2 = 0;
        int o1;
        int o2 = 0;
        vector<int> odd;
        vector<int> even;
        vector<int> odd2;
        vector<int> even2;

        for (int i = 0; i < n; i++)
        {
            s1 += A[i];
            s2 += B[i];
            if (abs(B[i]) % 2 == 1)
            {
                o2++;
                odd2.push_back(B[i]);
            }
            else if (abs(B[i]) % 2 == 0)
            {
                even2.push_back(B[i]);
            }
            if (abs(A[i]) % 2 == 1)
            {
                o1++;
                odd.push_back(A[i]);
            }
            else if (abs(A[i]) % 2 == 0)
            {
                even.push_back(A[i]);
            }
        }
        if (s1 != s2 || o1 != o2)
        {
            return -1;
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        sort(odd2.begin(), odd2.end());
        sort(even2.begin(), even2.end());
        long long ans = 0;

        for (int i = 0; i < odd.size(); i++)
        {
            ans += (abs(odd[i] - odd2[i]) / 2);
        }
        for (int i = 0; i < even.size(); i++)
        {
            ans += (abs(even[i] - even2[i]) / 2);
        }
        ans /= 2;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        vector<int> A(N);
        Array::input(A, N);

        vector<int> B(N);
        Array::input(B, N);

        Solution obj;
        long long res = obj.solve(N, A, B);

        cout << res << endl;
    }
}

// } Driver Code Ends