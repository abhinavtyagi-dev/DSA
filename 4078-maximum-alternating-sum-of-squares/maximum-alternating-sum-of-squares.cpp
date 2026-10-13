class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end(),greater<int>());
        long long sum=0;
        if (nums.size()%2==0){
            int i=0,e=nums.size()-1;
            while (i<e){
                sum+=(nums[i]*nums[i])-(nums[e]*nums[e]);
                i++,e--;
            }

        }
        else{
            int i=0,e=nums.size()-1;
            while (i<=e){
                if (i!=e){
                   sum+=1LL*((1LL*nums[i]*nums[i])-(1LL*nums[e]*nums[e]));
                }
                else{
                    sum+=nums[i]*nums[i];
                }
                i++,e--;
            }
        }
        return sum;
    }
};