class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        for (int i=0;i<30;i++){
            if ((((a>>i)&1)|((b>>i)&1))!=((c>>i)&1)){
                if ((c>>i)&1){
                    cnt++;
                }
                else{
                   if ((a>>i)&1){
                    cnt++;
                   } 
                    if ((b>>i)&1){
                    cnt++;
                   } 
                }
            }
        }
        return cnt;
    }
};