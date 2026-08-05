class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> left(ratings.size(),0);
        left[0]=1;
        for (int i=1;i<ratings.size();i++){
              if (ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
              }
              else{
                left[i]=1;
              }
        }
        int sum=max(1,left[ratings.size()-1]);
       int curr=1,right=1;
        for (int i=ratings.size()-2;i>=0;i--){
            if (ratings[i]>ratings[i+1]){
                curr=right+1;
                sum+=max(curr,left[i]);
                right=curr;
            }
            else{
                sum+=left[i];
                right=1;
            }
        }
        return sum;
    }
};