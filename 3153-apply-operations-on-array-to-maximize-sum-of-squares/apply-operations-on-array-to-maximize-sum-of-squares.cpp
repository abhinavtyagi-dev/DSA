class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> freq(32,0);
        int n=nums.size();
        int mod=1e9+7;
        for (int i=0;i<n;i++){
            for (int j = 0; j <= 30; j++) {
            if ((nums[i] >> j) & 1) {
            freq[j]++;
       }
    }
        }
     long long ans=0;
     for (int i=0;i<k;i++){

        long long x=0;
        for (int i=0;i<=30;i++){
            if (freq[i]>0){
           x+=1LL<<i;
           freq[i]--;
            }
        }
     ans = (ans + (x * x) % mod) % mod;
     }
     
     return ans;
    }
};