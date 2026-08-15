class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
       int sum=0;
       int n = arr.size();
       for (int i=0;i<n;i++){
           sum+=arr[i];
       }
        if ((sum%2==0&&diff%2==1)||(sum%2==1&&diff%2==0)){
            return 0;
        }
        int k=(sum+1)/2;
        if (sum%2==1){
            int left=diff-1;
            left=left/2;
            k=k+left;
        }
        else{
            int left=diff;
            left=left/2;
            k=k+left;
        }
        vector<int>dp(k+1,0);
        dp[0]=1;
        if (arr[0]==0){
            dp[0]=2;
        }
        else{
            dp[arr[0]]=1;
        }
        for (int i=1;i<n;i++){
            vector<int> curr(k+1,0);
            for (int j=0;j<=k;j++){
                int nottake=dp[j];
                int take=0;
                if (arr[i]<=j){
                    take=dp[j-arr[i]];
                }
                curr[j]=take+nottake;
            }
            dp=curr;
        }
        return dp[k];
    }
};