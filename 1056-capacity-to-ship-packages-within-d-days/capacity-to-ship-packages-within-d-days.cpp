class Solution {
public:
 int countdays (vector<int>weights,int weight){
    int days=0;
    int sum=0;
    for (int i=0;i<weights.size();i++){
        sum+=weights[i];
        if (sum==weight){
            days++;
            sum=0;
        }
        if (sum>weight){
          days++;
          sum=weights[i];
        }
    }
    if (sum>0){ // ye edge case yad rkha kro
        days++;
    }
    return days;
 }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,maxi=INT_MIN;
        for (int i=0;i<weights.size();i++){
            sum+=weights[i];
            maxi=max(maxi,weights[i]);
        }
        int s=maxi,e=sum;
        int ans=-1;
        while (s<=e){
            int mid=s+(e-s)/2;
             if (countdays(weights,mid)<=days){
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