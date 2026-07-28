class Solution {
public:
int findparent(vector<int>&par,int node){
    if (node==par[node]){
        return node;
    }
     par[node]=findparent(par,par[node]);
     return par[node];
}
void sizeparent(vector<int>&par,vector<int>&size,int pu,int pv){
    int pau=findparent(par,pu);
    int pav=findparent(par,pv);
    if (pau==pav){
        return ;
    }
    if (size[pau]<size[pav]){
        par[pau]=pav;
        size[pav]+=size[pau];
    }
    else{
      par[pav]=pau;
      size[pau]+=size[pav];
    }
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      vector<int> par(accounts.size(),0);
       vector<int> size(accounts.size(),1);
       for (int i=0;i<par.size();i++){
        par[i]=i;
       }

       map<string,int>mpp;
       for (int i=0;i<accounts.size();i++){
          for (int j=1;j<accounts[i].size();j++){
            if (mpp.find(accounts[i][j])==mpp.end()){
                mpp[accounts[i][j]]=i;
            }
            else{
                if (mpp[accounts[i][j]]!=i){
                int u=mpp[accounts[i][j]];
                int v=i;
                if (findparent(par,u)!=findparent(par,v)){
                    sizeparent(par,size,u,v);
                }
                }
            }
          }
       }
       vector<vector<string>>store(accounts.size());
       for (int i=0;i<par.size();i++){
         int parent=findparent(par,i);
        if (parent==i){
             if (store[parent].empty()){
                        store[parent].push_back(accounts[parent][0]);
                    }
            for (int j=1;j<accounts[i].size();j++){
                if (mpp.find(accounts[i][j])!=mpp.end()){
                  store[i].push_back(accounts[i][j]);
                   mpp.erase(accounts[i][j]);
                }
                 
            }
        }
        else{
            for (int k=1;k<accounts[i].size();k++){
                if (store[parent].empty()){
                        store[parent].push_back(accounts[parent][0]);
                    }
                if (mpp.find(accounts[i][k])!=mpp.end()&&mpp[accounts[i][k]]==i){
                    
                 store[parent].push_back(accounts[i][k]);
                 mpp.erase(accounts[i][k]);
                }
            }
        }
       }
       vector<vector<string>>ans;
       for (int i=0;i<store.size();i++){
         if (!store[i].empty()){
            sort(store[i].begin()+1,store[i].end());
            ans.push_back(store[i]);
            
         }
       }
       return ans;
    }
};