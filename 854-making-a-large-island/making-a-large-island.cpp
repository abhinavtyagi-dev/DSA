class Solution {
public:
   bool isvalide(int nr,int nc,int n,int m){
    if (nr>=0&&nr<n&&nc>=0&&nc<m){
        return true;
    }
    return false;
   }
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>par(n*m,0);
        vector<int>size(n*m,1);
        for (int i=0;i<(n*m);i++){
            par[i]=i;
        }
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        for (int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if (grid[i][j]==1){
                    int r=i,c=j;
                    for (int k=0;k<4;k++){
                        int nr=delrow[k]+r;
                        int nc=delcol[k]+c;
                        if (isvalide(nr,nc,n,m)){
                             if (grid[nr][nc]==1){
                                int u=(r*m)+c;
                                int v=(nr*m)+nc;
                                if (findparent(par,u)!=findparent(par,v)){
                                    sizeparent(par,size,u,v);
                                }
                             }
                        }
                    }
                }
            }
        }
        int maxcnt=INT_MIN;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
              
                if (grid[i][j]==0){
                    int cnt=1;

                     unordered_map<int,int>mpp;
                    for (int k=0;k<4;k++){
                        int nr=i+delrow[k];
                        int nc=j+delcol[k];
                       
                        if (isvalide(nr,nc,n,m)){
                        if (grid[nr][nc]==1){
                            int parent= findparent(par,((nr*m)+nc));
                            if (mpp.find(parent)==mpp.end()){
                            cnt+=size[parent];
                            mpp[parent]++;
                            }

                        }
                    }
                    }
                    maxcnt=max(maxcnt,cnt);
                }
                
            }
        }
        if (maxcnt==INT_MIN){
            return (n*m);
        }
           return maxcnt;
    }
};