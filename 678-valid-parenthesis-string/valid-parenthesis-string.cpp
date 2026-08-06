class Solution {
public:
    bool checkValidString(string s) {
        int mini=0,maxi=0; // these are from left open
        for (int i=0;i<s.length();i++){
              if (s[i]=='('){
                mini++;
                maxi++;
              }
              else if (s[i]==')'){
                 if (mini>0){
                    mini--;
                 }
                 maxi--;

            if (maxi<0){
                return false;
            }
        }
        else {
            if (mini>0){
                mini--;
            }
           maxi++;
        }
        }
       
        if (mini==0){
            return true;
        }
        return false;
    }
};