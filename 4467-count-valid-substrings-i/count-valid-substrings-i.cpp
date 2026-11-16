class Solution {
public:
    long long countValidSubstrings(string s) {
        int lind=-1;
         int l=0,r=0;
         int cnt=0;
         int n=s.length();
         long long ans=0;
         while (r<n){
            if (s[r]=='a'){
                ans+=r-l+1;
                cnt=1;
                lind=r;
            }
            else if (s[r]=='b'){
                ans+=r-l+1;
                if (cnt==1){
                    cnt++;
          }
          else {
            lind=-1;
            cnt=0;
          }
            }
            else if (s[r]=='c'){
                if (cnt==2){
                    l=lind+1;
                    lind=-1;
                    cnt=0;
                    ans+=r-l+1;
                }
                else{
                    ans+=r-l+1;
                    cnt=0;
                    lind=-1;
                }
            }
            else{
                ans+=r-l+1;
                lind=-1;
                cnt=0;
            }
            r++;
         }
         return ans;
    }
};