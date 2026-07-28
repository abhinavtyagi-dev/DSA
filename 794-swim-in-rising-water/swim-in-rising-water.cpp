class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
           set<pair<int,pair<int,int>>>st;
           vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),INT_MAX) );
           st.insert({grid[0][0],{0,0}});;
           int delrow[4]={-1,0,1,0};
           int delcol[4]={0,-1,0,1};
           while (!st.empty()){
            auto it=(*st.begin());
            int t=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if (r==grid.size()-1&&c==grid[0].size()-1){
                return t;
            }
            st.erase({t,{r,c}});
            
            for (int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                if (nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()){
                  if (grid[nr][nc]<=t&&t<dist[nr][nc]){
                    st.insert({t,{nr,nc}});
                    dist[nr][nc]=t;
                  }
                  else if(grid[nr][nc]>t&&grid[nr][nc]<dist[nr][nc]){
                          if (dist[nr][nc]!=INT_MAX){
                            st.erase({dist[nr][nc],{nr,nc}});
                          }
                          st.insert({grid[nr][nc],{nr,nc}});
                          dist[nr][nc]=grid[nr][nc];
                  }
                }
            }
           }
           return -1;
    }
};