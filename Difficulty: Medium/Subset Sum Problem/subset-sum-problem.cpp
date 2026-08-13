class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
     vector<vector<int>> dp(n,vector<int>(sum+1,-1));
     dp[0][sum]=sum;
     for (int i=1;i<n;i++){
         for (int j=0;j<=sum;j++){
             if (dp[i-1][j]==0){
                 return true;
             }
             if (dp[i-1][j]!=-1){
                 int val=dp[i-1][j];
                 dp[i][val]=val;
                 
                 int left=val-arr[i-1];
                 if (left>=0){
                 dp[i][left]=left;
                 }
             }
         }
     }
     for (int i=0;i<=sum;i++){
         if (dp[n-1][i]==0){
             return true;
         }
         if (dp[n-1][i]!=-1){
             if (dp[n-1][i]==arr[n-1]){
                 return true;
             }
         }
     }
     return false;
        
    }
};