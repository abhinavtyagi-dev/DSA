class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if (obstacleGrid[0][0]==1||obstacleGrid[n-1][m-1]==1){
            return 0;
        }
           vector<int>prev(m,0);
           for (int i=0;i<m;i++){
            if (obstacleGrid[0][i]==1){
                break;
            }
            if (obstacleGrid[0][i]!=1){
            prev[i]=1;
            }
           }
       
        for (int i=1;i<n;i++){
            vector<int>temp(m,0);
            for(int j=0;j<m;j++){
                if (obstacleGrid[i][j]){
                  continue;
                }
               temp[j]+=prev[j];
               if (j!=0){
                temp[j]+=temp[j-1];
               }
               
            }
            prev=temp;
        }
        return prev[m-1];
    }
};