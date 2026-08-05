class Solution {
    void dfs(vector<int>&ratings, vector<int>& vis,vector<int>&store,int&cnt,int node){
         
          
           if (!vis[node]){
            if (ratings[node+1]<ratings[node]){
                dfs(ratings,vis,store,cnt,node+1);
            }
            
           
           }
           vis[node]=1;
            store[node]=cnt;
            cnt=cnt+1;
           return ;
    }
public:
    int candy(vector<int>& ratings) {
        vector<int>small;
        vector<int>vis(ratings.size(),0);
        vis[ratings.size()-1]=1;
        vector<int>store(ratings.size(),0);
        store[ratings.size()-1]=0;
        for (int i=0;i<ratings.size();i++){
             if (!vis[i]){
                int cnt=0;
                dfs(ratings,vis,store,cnt,i);
             }
        }
        int candy=0;
        int l=0;
        
        for (int i=0;i<store.size();i++){
            int cnt=1;
            if (i>0){
                if (ratings[i]>ratings[i-1]){
                   cnt=l+1;
                }
            }
          
            candy+=max(cnt,store[i]+1);
            l=max(cnt,store[i]+1);
        }
        return candy;
    }
};