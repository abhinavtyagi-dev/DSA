class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for (int i=0;i<n;i++){
            int cnt1=1;
            map<int,int>vis;
            map<int,int>mpp;
            for (int j=i;j<n;j++){
               if (vis.find(nums[j])==vis.end()){
                  vis[nums[j]]++;
                  mpp[nums[j]]=cnt1;
                  cnt1++;
                  }
                  else {
                    if (mpp.find(nums[j])==mpp.end()){
                        break;
                    }
                  }
                  mpp[nums[j]]--;
                  if (mpp[nums[j]]==0){
                    mpp.erase(nums[j]);
                  }
                  if (mpp.size()==0){
                    cnt++;
                  }

            }
        }
        return cnt;
    }
};