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
     
        if (dp[ind][abs(k)]!=-1){
            return dp[ind][abs(k)];
      
     }
       int same=findsum(arr,k-arr[ind],ind-1,dp);
       int diff=findsum(arr,k+arr[ind],ind-1,dp);

      
       dp[ind][abs(k)]=same+diff;
    
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