class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0,cnt10=0;
        bool flag=true;
        for (int i=0;i<bills.size();i++){
            if (bills[i]==5){
                cnt5++;
            }
           else if (bills[i]==10){
                cnt10++;
                if (cnt5==0){
                    flag=false;
                    break;
                }
                else{
                    cnt5--;
                }
            }
            else{
                if (cnt10>0&&cnt5==0||cnt10==0&&cnt5<3){
                    flag=false;
                    break;
                }
                else if (cnt10>0&&cnt5>0){
                    cnt10--;
                    cnt5--;
                }
                else {
                    cnt5=cnt5-3;
                }

            }
        }
        return flag;
    }
};

// yha pr ye 20 ke changes jb hmne diye to usme gredy use hua h jab hmne 10 and 5 ko jyada priority dii 5 5 5 ke changes se as vo abhi ke liye and acc to future best choice hn