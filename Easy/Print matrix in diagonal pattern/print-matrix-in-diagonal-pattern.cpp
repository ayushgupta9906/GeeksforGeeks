//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         int n = mat.size();
         vector<int> ans;
         bool direction = true;
         for(int sum = 0; sum <= 2*n-2; sum++)
         {
             vector<int> temp;
             for(int i = 0; i < n; i++)
             {
                 int j = sum - i;
                 if(j >= 0 && j < n)
                 {
                     temp.push_back(mat[i][j]);
                 }
             }
             if(direction)
             {
                 reverse(temp.begin(), temp.end());
             }
             ans.insert(ans.end(), temp.begin(), temp.end());
             direction = !direction;
         }
         
         return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends