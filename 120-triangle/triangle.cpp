class Solution {
public:
  int minsum=INT_MAX;
  int findsumtrian(vector<vector<int>>& triangle,vector<vector<int>>& store,int r,int c){
    if (store[r][c]!=INT_MIN||r==triangle.size()-1){
        return store[r][c];
    }
  
     int same=findsumtrian(triangle,store,r+1,c);
      int frwrd=findsumtrian(triangle,store,r+1,c+1);
      store[r][c]=0;
      store[r][c]+=triangle[r][c]+min(same,frwrd);
      return store[r][c];

  }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>store(n);
        for (int i=0;i<n;i++){
            for (int j=0;j<=i;j++){
                if (i<n-1){
                store[i].push_back(INT_MIN);
                }
                else{
                    store[i].push_back(triangle[i][j]);
                }
            }
        }
        int ans=findsumtrian(triangle,store,0,0);
        return ans;
    }
};