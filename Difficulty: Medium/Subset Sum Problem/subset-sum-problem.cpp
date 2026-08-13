class Solution {
  public:
    bool findsum(vector<int>& arr,int ind,int target, vector<vector<int>>&dp){
        if (target==0){
            return true;
        }
        if (ind==0){
            if (arr[ind]==target){
                return true;
            }
            else{
                dp[ind][target]=0;
                return false;
            }
        }
            if (dp[ind][target]!=-1){
            return dp[ind][target];
        } 
        
        bool nottake=findsum(arr,ind-1,target,dp);
        if (nottake){
        return true;
    }
    bool take=false;
    if (target>=arr[ind]){
        take=findsum(arr,ind-1,target-arr[ind],dp);
    }
    if (take){
        return true;
    }
    dp [ind][target]=(nottake||take);
    return (nottake||take);
        }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        bool ans=findsum(arr,n-1,sum,dp);
        return ans;
    }
};