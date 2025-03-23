class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // Create an adjacency list to represent the graph
    vector<vector<pair<int, int>>> graph(n);
    for (auto& road : roads) {
        int u = road[0], v = road[1], time = road[2];
        graph[u].emplace_back(v, time);
        graph[v].emplace_back(u, time);  // Since the graph is bidirectional
    }

    // Min-heap priority queue: (time, node)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    
    // Distance array to store shortest time to each node
    vector<long long> dist(n, LLONG_MAX);
    // Ways array to store the number of ways to reach each node
    vector<int> ways(n, 0);

    // Initialize starting point (intersection 0)
    pq.emplace(0, 0);
    dist[0] = 0;
    ways[0] = 1;

    while (!pq.empty()) {
        auto [time, node] = pq.top();
        pq.pop();

        // Skip if we already found a shorter path
        if (time > dist[node]) continue;

        // Explore all neighbors
        for (auto& [neighbor, travelTime] : graph[node]) {
            long long newTime = time + travelTime;

            // If a shorter path is found
            if (newTime < dist[neighbor]) {
                dist[neighbor] = newTime;
                ways[neighbor] = ways[node];  // Update ways to this new path
                pq.emplace(newTime, neighbor);
            }
            // If another shortest path is found
            else if (newTime == dist[neighbor]) {
                ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
            }
        }
    }

    // Return the number of ways to reach the last intersection (n-1)
    return ways[n - 1];
    }
};
