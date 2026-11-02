class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        vector<long long>storel(n,0);
        vector<long long>storer(n,0);
        sort(nums.begin(),nums.end());
        int l=nums[0];
        storel[0]=0;
        for (int i=1;i<n;i++){
              storel[i]=storel[i-1]+(i*(nums[i]-l));
               l=nums[i];
        }
        storer[n-1]=0;
        int r=nums[n-1];
        int cnt=1;
        for (int i=n-2;i>=0;i--){
            storer[i]=storer[i+1]+(cnt*(r-nums[i]));
            cnt++;
            r=nums[i];
        }
        long long mini=INT_MAX;
        for (int i=0;i<n;i++){
            mini=min((storel[i]+storer[i]),mini);

        }
        return mini;
    }
};