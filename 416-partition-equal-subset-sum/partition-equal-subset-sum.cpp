class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for (int i=0;i<n;i++){
            sum+=nums[i];
        }
        if (sum%2==1){
          return false;
        }
        int target=sum/2;
        vector<int>dp(target+1,-1);
        dp[target]=target;
        for (int i=1;i<n;i++){
            vector<int>temp(target+1,-1);
            for (int j=0;j<=target;j++){
                if (dp[j]==0){
                    return true;
                }
                if (dp[j]!=-1){
                    int val=j;
                    temp[val]=val;
                    int left=val-nums[i-1];
                    if (left>=0){
                        temp[left]=left;
                    }
                }
            }
            dp=temp;
        }
        for (int i=0;i<=target;i++){
            if (dp[i]==0){return true;}
            if (dp[i]!=-1){
            if (i==nums[n-1]){
             return true;
            }
            }
        }
        return false;
    }
};