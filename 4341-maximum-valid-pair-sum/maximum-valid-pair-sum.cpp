class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        vector<int> store;
        int maxi=INT_MIN;
        int n=nums.size();
        for (int i=0;i<nums.size();i++){
               maxi=max(maxi,nums[i]);
                       store.push_back(maxi);
        }
         maxi=INT_MIN;
        for (int i=0;i<n;i++){
             if (i-k>=0){
                maxi=max(maxi,nums[i]+store[i-k]);
             }
        }
        return maxi;

    }
};