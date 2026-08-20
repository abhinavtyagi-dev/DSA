class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                int match=0,notmatch=0;
                if (str1[i]==str2[j]){
                    match=1+dp[i][j];
                }
                else{
                    int notmatch1=dp[i][j+1];
                    int notmatch2=dp[i+1][j];
                    notmatch=max(notmatch1,notmatch2);

                }
                dp[i+1][j+1]=match+notmatch;
            }
        }
        string s="";
        int l=n,p=m;
         while (l>0&&p>0){
                if (str1[l-1]==str2[p-1]){
                    s+=str1[l-1];
                    l--,p--;
                }
                else if (dp[l-1][p]>dp[l][p-1]){
                    l--;
                }
                else{
                    p--;
                }
         }
            
            reverse(s.begin(),s.end());
            string ans="";
            if (str2.length()>str1.length()){
                int i=0,j=0,k=0;
               
                while (i<s.length()&&j<str1.length()){
                    if (str1[j]!=s[i]){
                       ans+=str1[j];
                       
                    }
                    if (str1[j]==s[i]){
                        while (str2[k]!=s[i]){
                            ans+=str2[k];
                            k++;
                        }
                        
                        ans+=str2[k];
                        k++;
                        i++;
                    }
                  j++;
                }
            
            while (j<str1.length()){
                ans+=str1[j];
                j++;
            }
            while (k<str2.length()){
                ans+=str2[k];
                k++;
            }
            }
            else{
                 int i=0,j=0,k=0;
                 
                while (i<s.length()&&j<str2.length()){
                    if (str2[j]!=s[i]){
                       ans+=str2[j];
                       
                    }
                    if (str2[j]==s[i]){
                        while (str1[k]!=s[i]){
                            ans+=str1[k];
                            k++;
                        }
                        ans+=str1[k];
                        k++;
                        i++;
                    }
                  j++;
                }
            
                while (j<str2.length()){
                ans+=str2[j];
                j++;
            }
            while (k<str1.length()){
                ans+=str1[k];
                k++;
            }
            }
        
        return ans;
    }
};