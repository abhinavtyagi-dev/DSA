class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>steps(1e4,0);
       
        int maxind=0;
        for (int i=0;i<nums.size();i++){
            if (maxind>=nums.size()-1){
                break;
            }
            if (i+nums[i]>maxind){
                maxind=i+nums[i];
                int j=1;
                int st=0;
                while (steps[j]!=0){
                    if (i<=steps[j]){
                        st=j;
                        
                        break;
                    }
                    j++;
                    
                }
                steps[st+1]=maxind;
            }
        }
        for (int i=0;i<steps.size();i++){
            if (steps[i]>=maxind){
                return i;
            }
        }
        return -1;
    }
};