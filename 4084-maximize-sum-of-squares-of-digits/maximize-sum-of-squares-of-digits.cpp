class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        while (sum!=0&&num>0){
            if (sum>=9){
                ans+="9";
                sum-=9;
                num--;
            }
            else{
                string s=to_string(sum);
                ans+=s;
                sum=0;
                num--;
            }
        }
        while (num!=0){
            ans+='0';
            num--;
        }
        if (sum!=0){
            return "";
        }
        return ans;
    }
};