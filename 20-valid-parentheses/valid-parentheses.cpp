class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for (int i=0;i<s.length();i++){
            if (st.size()==0){
                st.push(s[i]);
                continue;
            }
            if (s[i]==')'){
                if (st.top()=='('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
                 if (s[i]=='}'){
                if (st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }

             if (s[i]==']'){
                if (st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
             }
                if (s[i]=='('||s[i]=='{'||s[i]=='['){
                    st.push(s[i]);
                }
                else{
                    continue;
                }
        }
            
        if (st.size()==0){
         return true;
        }
        return 0;
    }
};