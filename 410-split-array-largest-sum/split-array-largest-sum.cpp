class Solution {
public:
int split(int mid,vector<int>nums){
    int cnt=0;
    int sum=0;
    for (int i=0;i<nums.size();i++){
        sum+=nums[i];
        if (sum>mid){
            cnt++;
            sum=nums[i];
        }
    }
    if(sum!=0){
        cnt++;
    }
    return cnt;
}
    int splitArray(vector<int>& nums, int k) {
        int maxi=INT_MIN,sum=0; 
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(nums[i],maxi);
        }
        int s=maxi,e=sum; // phle me glti ye kr rha tha ki s ko minimum le rha tha but socho ek bat agr 
// minimum leloge to jo agr mid kbhi vhan aaya to har element usse bda hoga to array split kaise hoga //fir
        int ans=-1;
        while (s<=e){
            int mid=s+(e-s)/2;
            if (split(mid,nums)<=k){
              ans=mid;
              e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};