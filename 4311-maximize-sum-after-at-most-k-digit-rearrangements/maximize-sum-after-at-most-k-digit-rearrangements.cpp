class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<pair<int,pair<int,int>>> store;
        int n=nums.size();
        for (int i=0;i<n;i++){
            int no=nums[i];
            vector<int> store1;
            while (no!=0){
                store1.push_back(no%10);
                no=no/10;
            }
            sort(store1.begin(),store1.end(),greater<int>());
            int num=0;
            for (int i=0;i<store1.size();i++){
                num=(num*10+store1[i]);
            }
            int diff=(num-nums[i]);
            store.push_back({diff,{num,nums[i]}});
        }
        sort(store.begin(),store.end(),greater<pair<int,pair<int,int>>>());
        long long sum=0;
        for (int i=0;i<store.size();i++){
            if (k>0){
                if (store[i].first>0){
                   sum+=store[i].second.first;
                   k--;
                }
                else{
                sum+=store[i].second.second;
                }
            }
            else{
                   sum+=store[i].second.second;
            }
        }
        return sum;
    }
};