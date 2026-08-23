class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];;
        int maxprofit=INT_MIN;
        for (int i=1;i<prices.size();i++){
             if (prices[i]>mini){
                maxprofit=max(maxprofit,prices[i]-mini);
             }
             else{
                mini=prices[i];
             }
        }
        if (maxprofit==INT_MIN){
            return 0;

        }
        return maxprofit;

    }
};