class Solution {
public:
    int minOperations(string s) {
        vector<char>c1;
        vector<char> c2;
        vector<char>c3;
        for (int i=0;i<s.length();i++){
            c1.push_back(s[i]);
        }
        c2=c1,c3=c1;
        sort(c1.begin(),c1.end());
        bool flag=true;
        for (int i=1;i<s.length();i++){
              if (s[i]<s[i-1]){
                flag=false;
                break;
              }
        }
        if (flag){
            return 0;
        }
        if (s.length()==2){
            return -1;
        }
        if (s[0]==c1[0]||s[s.length()-1]==c1[s.length()-1]){
            return 1;
        }
         sort(c2.begin(),c2.end()-1);
         sort(c2.begin()+1,c2.end());
         int cnt1=2;
         for (int i=1;i<c1.size();i++){
            if (c2[i]<c2[i-1]){
                cnt1=3;
                break;
            }
         }
         int cnt2=2;
         sort(c3.begin()+1,c3.end());
         sort(c3.begin(),c3.end()-1);
         for (int i=1;i<c3.size();i++){
            if (c3[i]<c3[i-1]){
                cnt2=3;
                break;
            }
         }
         return min(cnt1,cnt2);
    }
};