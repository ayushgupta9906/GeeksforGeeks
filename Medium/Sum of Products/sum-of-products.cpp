//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long nums[]) {
        vector<int>cnt(32,0);
        for(int j=0;j<32;j++){
          for(int i=n-1;i>=0;i--){
                if(nums[i]&(1<<j)) cnt[j]++;
            }
        }
        long long int ans=0;
        for(int j=0;j<32;j++){
            long long val=0;
            for(int i=0;i<n-1;i++) {
                if(nums[i]&(1<<j)){ cnt[j]--;
                if(cnt[j]>0)
                   val+=(1LL<<j)*cnt[j];
                }
            }
            ans+=val;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends