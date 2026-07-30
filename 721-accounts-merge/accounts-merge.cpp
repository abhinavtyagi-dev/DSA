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
    unordered_map<string ,int>mpp;
    for (int i=0;i<accounts.size();i++){
        for (int j=1;j<accounts[i].size();j++){
            if (mpp.find(accounts[i][j])==mpp.end()){
                mpp[accounts[i][j]]=i;
            }
            else{
                sizeparent(par,size,mpp[accounts[i][j]],i);
            }

        }
    }

    vector<vector<string>>merge(accounts.size());
    for (auto it:mpp){
        int parent=findparent(par,it.second);
        merge[parent].push_back(it.first);
    }
    vector<vector<string>>ans;
    for (int i=0;i<merge.size();i++){
        if (merge[i].size()==0){
            continue;
        }
        vector<string>temp;
        temp.push_back(accounts[i][0]);
        sort(merge[i].begin(),merge[i].end());
        for (auto it:merge[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}
};