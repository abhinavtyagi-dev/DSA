class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int n=arr.size(); 
        int sum=0; 
        for (int i=0;i<n;i++){ 
            sum+=arr[i]; 
        } 
        
        int target=sum/2; 
        vector<bool> dp(target+1,0); 
        dp[0]=1; 
        
        if (arr[0]<=target){ 
            dp[arr[0]]=1; 
        } 
        
        for (int i=1;i<n;i++){ 
            vector<bool> curr(target+1,0); 
            curr[0]=1; 
            
            for (int j=1;j<=target;j++){ 
                bool nottake=dp[j]; 
                bool take=false; 
                
                if (arr[i]<=j){ 
                    take=dp[j-arr[i]]; 
                } 
                
                curr[j]=take||nottake; 
            } 
            
            dp=curr; 
        } 
        
        int maxi=INT_MIN; 
        
        for (int i=0;i<=target;i++){ 
            if (dp[i]){ 
                maxi=i; 
            } 
        } 
        int other=sum-maxi;
        return abs(maxi-other); 
    }
};