class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>store(n);
        store[0].push_back(triangle[0][0]);
        for (int i=1;i<n;i++){
            for (int j=0;j<=i;j++){
                store[i].push_back(INT_MAX);
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<=i;j++){
                if (i<n-1&&store[i][j]!=INT_MAX){
                 int s=j,f=j+1;
                 int sum=store[i][j]+triangle[i+1][j];
                 store[i+1][j]=min(store[i+1][j],sum);
                 int sum1=store[i][j]+triangle[i+1][j+1];
                 store[i+1][j+1]=min(store[i+1][j+1],sum1);
                }
            }
        }
        int minans=INT_MAX;
        for (int i=0;i<=n-1;i++){
            minans=min(minans,store[n-1][i]);
        }
        return minans;
    }
};