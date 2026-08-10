class Solution {
public:
    int findsum(vector<vector<int>>& grid,vector<int>& store){
        int n=grid.size();
        int m=grid[0].size();
        int dr=-1,dc=-1;
        for(int i=1;i<n;i++){
            vector<int>temp(m,0);
            for (int j=0;j<m;j++){
                  int up=INT_MAX,left=INT_MAX;
                  if(i+dr>=0){
                    up=0;
                    up+=store[j];
                  }
                  if (j+dc>=0){
                    left=0;
                    left+=temp[j-1];
                  }
                  temp[j]=grid[i][j]+min(up,left);
         }
         store=temp;
        }
        return store[m-1];
            }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>store(m,0);
        store[0]=grid[0][0];
        for (int i=1;i<m;i++){
            store[i]+=grid[0][i]+store[i-1];
        }

        int ans=findsum(grid,store);
        return ans;
    }
};