class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt1=0;
        for (int i=0;i<31;i++){
            if ((num2>>i)&1){
                cnt1++;
            }
        }
        vector<int> setbit(32,0);
        int cnt2=0;
        for (int i=0;i<31;i++){
            if ((num1>>i)&1){
                cnt2++;
                setbit[i]=1;
            }
        }
        if (cnt1==cnt2){
            return num1;
        }
        else if (cnt1>cnt2){
            int left=cnt1-cnt2;
            for (int i=0;i<31&&left>0;i++){
                if (setbit[i]==0){
                    setbit[i]=1;
                    left--;
                }
            }
            int sum=0;
            for (int i=0;i<31;i++){
                if (setbit[i]==1){
                    sum+=1<<i;
                }
            }
            return sum;
        }
        int left=cnt2-cnt1;
        for (int i=0;i<31&&left>0;i++){
            if (setbit[i]==1){
                setbit[i]=0;
                left--;
            }
        }
       int sum = 0;
for (int i=0; i<31; i++) {
    if (setbit[i] == 1) {
        sum += (1 << i);
    }
}
return sum;
    }
};