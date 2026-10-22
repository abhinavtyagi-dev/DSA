class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> store;
        bool flag=true;
          int n=nums.size();
        for (int i=1;i<n;i++){
            if (nums[i]<nums[i-1]){
                flag=false;
                break;
            }
        }
        if (flag){
            return 0;
        }
      
        for (int i=0;i<n;i++){
            store.push_back(nums[i]);
        }
         for (int i=0;i<n;i++){
            store.push_back(nums[i]);
        }
        int lind=-1;
        int stind=0;
        int len=1;
        // proper decreasing
        for (int i=1;i<2*n-1;i++){
             if (store[i]<store[i-1]){
                len++;
               }
             else{
                stind=i;
                len=1;
             }
             if (len==n){
                lind=stind;
                break;
             }
        }
        int cnt1=INT_MAX;;
        if (lind==n-1){
          cnt1=2;
        }
        else{
            if (lind!=-1){
            cnt1=min(lind+1,n-lind+1);
            }
            }
      // increasing
               lind=-1;
         stind=0;
         len=1;
       
        for (int i=1;i<2*n-1;i++){
             if (store[i]>store[i-1]){
                len++;

             }
             else{
                stind=i;
                len=1;
             }
             if (len==n){
                lind=stind;
                break;
             }
        }
        int cnt2=INT_MAX;
        if (lind!=-1){
        cnt2=min(lind,n-lind+2);
        }
        if (cnt1==INT_MAX&&cnt2==INT_MAX){
            return -1;
        }
       return min(cnt1,cnt2);
    }
};