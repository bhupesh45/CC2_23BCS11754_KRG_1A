class Solution {
  public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];

        for (auto edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int node = it.second;

            for (auto neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int wt = neighbor.second;

                if (dist[adjNode] > time + wt) {
                    dist[adjNode] = time + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxi = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};
