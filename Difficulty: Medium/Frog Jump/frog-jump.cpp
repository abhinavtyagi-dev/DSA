class Solution {
  public:
    int minCost(vector<int>& height) {
         vector<int>cost(height.size(),INT_MAX);
         cost[0]=0;
         int n=height.size();
         for (int i=0;i<n;i++){
             if (i+1<=n-1){
                 cost[i+1]=min(cost[i+1],cost[i]+abs(height[i+1]-height[i]));
             }
             if (i+2<=n-1){
                 cost[i+2]=min(cost[i+2],cost[i]+abs(height[i+2]-height[i]));
             }
         }
        return cost[n-1];
    }
};