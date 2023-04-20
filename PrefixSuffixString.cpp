//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int prefixSuffixString(vector<string> &s1, vector<string> s2)
    {
        unordered_set<string> st;
        for (int i = 0; i < s1.size(); i++)
        {
            string t1;
            string t2 = s1[i];
            int n = s1[i].size();

            for (int j = 0; j < n; j++)
            {
                t1.push_back(s1[i][j]);
                t2.erase(0, 1);
                st.insert(t1);
                st.insert(t2);
            }
        }
        int ans = 0;

        for (int j = 0; j < s2.size(); j++)
        {
            if (st.find(s2[j]) != st.end())
            {
                ans++;
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
    for (int i = 0; i < t; i++)
    {
        string str1, str2, newline;
        if (i == 0)
            getline(cin, newline);
        getline(cin, str1);
        getline(cin, str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1, s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while (ss1 >> str)
        {
            s1.push_back(str);
        }
        while (ss2 >> str)
        {
            s2.push_back(str);
        }
        Solution ob;
        cout << ob.prefixSuffixString(s1, s2) << endl;
    }
}
// } Driver Code Ends