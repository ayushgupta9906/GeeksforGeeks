//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
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

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<pair<int, int>> l(n), r(n);
        l[0] = {arr[0], arr[0]};
        r[n - 1] = {arr[n - 1], arr[n - 1]};
        for(int i = 1; i < n; i++) {
            l[i] = {min(l[i - 1].first, arr[i]), max(l[i - 1].second, arr[i])};
            r[n - i - 1] = {min(r[n - i].first, arr[n - i - 1]), max(r[n - i].second, arr[n - i - 1])};
        }
        int j = 0;
        int ans = r[k].second - r[k].first;
        for(int i = k + 1; i < n; i++) {
            int minn = min(l[j].first, r[i].first);
            int maxx = max(l[j].second, r[i].second);
            ans = min(ans, maxx - minn);
            j++;
        }
        ans = min(ans, l[n - k - 1].second - l[n - k - 1].first);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends