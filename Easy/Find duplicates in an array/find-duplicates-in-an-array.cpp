//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
      unordered_set<int>v;vector<int> u;
      unordered_set<int>m;
      for(int i =0;i<n;i++){
          int c = arr[i];
          if(v.count(c) == 0)
             v.insert(c);
            else if(m.count(c) ==0){
                m.insert(c);
                u.push_back(c);
            }
      }

if(u.size() ==0)
        u.push_back(-1);
    else
        sort(u.begin(),u.end());
        return u;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends