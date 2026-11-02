class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        vector<long long>storel(n,0);
        
        sort(nums.begin(),nums.end());
        int l=nums[0];
        storel[0]=0;
        for (int i=1;i<n;i++){
              storel[i]=storel[i-1]+(i*(nums[i]-l));
               l=nums[i];
        }
         long long mini=INT_MAX;
         int l1=nums[n-1];
         long long lstore=0;
         mini=min(0+storel[n-1],mini);
         int cnt=1;
         for (int i=n-2;i>=0;i--){
            long long total=lstore+(1ll*cnt*(l1-nums[i]));
            mini=min((total+storel[i]),mini);
            lstore=total;
            cnt++;
            l1=nums[i];
         }
        return mini;
    }
};