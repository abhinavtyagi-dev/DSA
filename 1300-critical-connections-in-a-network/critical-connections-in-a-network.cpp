class Solution {
public:
int timer=1;
void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&vis,int tim[],int lowtim[],vector<vector<int>>& bridge){
     vis[node]=1;
     tim[node]=lowtim[node]=timer;
     timer++;
     for (auto it:adj[node]){
        if (it==parent){
            continue;
        }
        if (vis[it]==0){
            dfs(it,node,adj,vis,tim,lowtim,bridge);
            lowtim[node]=min(lowtim[it],lowtim[node]);
            // bridge exist or not
            if (lowtim[it]>tim[node]){
                bridge.push_back({it,node});
            }
        }
        else{
            lowtim[node]=min(lowtim[node],tim[it]);
        }
     }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for (int i=0;i<connections.size();i++){
            int node1=connections[i][0];
            int node2=connections[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        vector<int>vis(n,0);
        vector<vector<int>>bridges;
        int tim[n];
        int mintim[n];
        dfs(0,-1,adj,vis,tim,mintim,bridges);
        return bridges;
    }
};