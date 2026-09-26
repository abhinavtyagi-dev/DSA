class Solution {
public:
    string evaluate(string& s, vector<vector<string>>& knowledge) {
        string ans="";
        unordered_map<string,string> mpp;
        for (int i=0;i<knowledge.size();i++){
            mpp[knowledge[i][0]]=knowledge[i][1];
        }
     for (int i=0;i<s.length(); ){
        if (s[i]=='('){
            i++;
            string s1="";
            while (s[i]!=')'){
                s1+=s[i];
                i++;
            }
          
            if (mpp.find(s1)!=mpp.end()){
            ans+=mpp[s1];// ans=ans+mpp[s1] me copy create hoti h to bht jyada copies create ho jati for big input
            }
            else{
               ans=ans+"?";
            }
        }
        else{
            ans+=s[i];
        }
        i++;
     }
     return ans;
    }
};