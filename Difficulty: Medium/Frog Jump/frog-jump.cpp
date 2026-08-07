class Solution {
  public:
    int minCost(vector<int>& height) {
        if (height.size()==1){
            return 0;
        }
        if (height.size()==2){
            return abs(height[1]-height[0]);
        }
        int prev1=0,prev2=abs(height[0]-height[1]);
        for (int i=2;i<height.size();i++){
            int curr=min(prev1+abs(height[i]-height[i-2]),prev2+abs(height[i]-height[i-1]));
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
};