class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int r=0,c=0;
        int n=grid.size();
        int m=grid[0].size();
        int lind=-1,rind=-1;
        vector<vector<int>> visit(n,vector<int>(m,0));
        while (r<n&&c<m&&r>=0&&c>=0&&visit[r][c]==0){
            lind=r,rind=c;
              visit[r][c]=1;
              if (grid[r][c]=='R'){
                c=c+1;
              }
              else if (grid[r][c]=='L'){
                c=c-1;
              }
              else if (grid[r][c]=='D'){
                r=r+1;
              }
              else{
                r=r-1;
              }
        }
        return {lind,rind};
    }
};