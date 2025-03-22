class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);  // Adjacency list
        vector<bool> visited(n, false);
        
        // Build the graph
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int completeCount = 0;
        
        // DFS to find components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                int edgeCount = 0;
                
                // Perform DFS
                stack<int> st;
                st.push(i);
                visited[i] = true;
                
                while (!st.empty()) {
                    int node = st.top();
                    st.pop();
                    component.push_back(node);
                    
                    for (int neighbor : adj[node]) {
                        edgeCount++;  // Each edge is counted twice
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            st.push(neighbor);
                        }
                    }
                }
                
                int size = component.size();
                int expectedEdges = (size * (size - 1)) / 2;
                
                if (expectedEdges == edgeCount / 2) {  // Divide edgeCount by 2 to avoid double-counting
                    completeCount++;
                }
            }
        }
        
        return completeCount;
    }
};
