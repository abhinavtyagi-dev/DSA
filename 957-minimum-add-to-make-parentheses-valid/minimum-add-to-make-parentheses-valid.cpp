class Solution {
public:
    int minAddToMakeValid(string s) {
        int left=0;
        int cnt=0;
        for (int i=0;i<s.length();i++){
            if (s[i]=='('){
                left++;
            }
            if (s[i]==')'){
                if (left!=0){
                    left--;
                }
                else{
                    cnt++;
                }
            }
        }
        return cnt+left;
    }
};