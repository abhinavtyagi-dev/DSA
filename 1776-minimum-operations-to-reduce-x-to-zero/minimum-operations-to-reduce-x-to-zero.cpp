class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<long long,int>mpp;
        long long sum=0;
        mpp[0]=nums.size();
        for (int i=nums.size()-1;i>=0;i--){
              sum+=nums[i];
              mpp[sum]=i;
        }
        sum=0;
       int ans=INT_MAX;
        for (int i=0;i<nums.size();i++){
            if (sum>x){
                break;
            }
            if (mpp.find(x-sum)!=mpp.end()){
                 if (mpp[x-sum]>=i){
                    int var=i+nums.size()-mpp[x-sum];
                        ans=min(ans,var);
                 }
               
            }
              sum+=nums[i];
        }
        if (ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};