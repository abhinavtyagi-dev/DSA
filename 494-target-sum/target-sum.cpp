class Solution {
public:
   
int findsum(vector<int>& arr,int k,int ind){
      
       if (ind==-1){
           if (k==0){
               return 1;
           }
           else{
            return 0;
           }
       }
     
       int same=findsum(arr,k-arr[ind],ind-1);
       int diff=findsum(arr,k+arr[ind],ind-1);

      
       return same+diff;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
         int ans=findsum(nums,target,n-1);
         return ans;
    }
};