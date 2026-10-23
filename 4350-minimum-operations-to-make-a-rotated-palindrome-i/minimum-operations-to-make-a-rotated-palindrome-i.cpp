class Solution {
public:
    int minOperations(string s) {
        string s1=s+s;
        int mini=INT_MAX;
        int n=s.length();
        for (int i=0;i<s.length();i++){
            int st=i,e=i+n-1;
            int sum=i;
            while (st<e){
               if (s1[st]<s1[e]){
                 int rig='z'-s1[e]+s1[st]-'a'+1;
                 int lef=s1[e]-s1[st];
                 sum+=min(rig,lef);
               }
               else{
                 int rig='z'-s1[st]+s1[e]-'a'+1;
                 int lef=s1[st]-s1[e];
                 sum+=min(rig,lef);
               }
               st++,e--;
            }
            mini=min(mini,sum);
        }
        return mini;
    }
};