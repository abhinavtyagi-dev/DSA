class Solution {
public:
    string reverseParentheses(string s) {
        deque<char> dq;
        for (int i=0;i<s.length();i++){
            if (s[i]==')'){
                string s1="";
                while (dq.back()!='('){
                    s1+=dq.back();
                    dq.pop_back();
                }
                dq.pop_back();
                for (int i=0;i<s1.length();i++){
                    dq.push_back(s1[i]);
                }
            }
            else{
                dq.push_back(s[i]);
            }
        }
        string ans="";
        while (!dq.empty()){
            ans+=dq.front();
            dq.pop_front();
        }
        return ans;
    }
};