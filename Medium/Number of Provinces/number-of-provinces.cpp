//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int node, vector<int> adjLs[], int visit[]){
        visit[node] = 1;
        for (auto it : adjLs[node]){
            if (!visit[it]){
                dfs(it, adjLs, visit);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjLs[V];
        for (int i=0;i<V;i++){
            for (int j=0;j<V;j++){
                if (adj[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        int count=0;
        int visit[V] = {0};
        for (int i = 0;i<V;i++){
            if (visit[i]==0){
                count++;
                dfs(i, adjLs, visit);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends