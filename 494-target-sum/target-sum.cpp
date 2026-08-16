class Solution {
public:
   
int findsum(vector<int>& arr,int k,int ind,vector<vector<int>>&dp){
      
       if (ind==-1){
           if (k==0){
               return 1;
           }
           else{
            return 0;
           }
       }
     if (k>=0){
        if (dp[ind][k]!=-1){
            return dp[ind][k];
        }
     }
       int same=findsum(arr,k-arr[ind],ind-1,dp);
       int diff=findsum(arr,k+arr[ind],ind-1,dp);

       if (k>=0){
       dp[ind][k]=same+diff;
     }
       return same+diff;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2001,-1));
        target=abs(target);
         int ans=findsum(nums,target,n-1,dp);
         return ans;
    }
};