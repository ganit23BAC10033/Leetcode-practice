class Solution {
public:
    struct Node {
        int sid = -1;
        unordered_map<char, unique_ptr<Node>> next;
    };

    long long minimumCost(
        string source, 
        string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        int n = source.size();

         
        unordered_map<string, int> index;
        index.reserve((original.size() + changed.size()) * 2);
        for (auto &s : original)
            if (!index.count(s)) 
                index[s] = index.size();
        for (auto &s : changed)
            if (!index.count(s)) 
                index[s] = (int)index.size();
        int K = index.size();

        const long long INF = (long long)4e18;

         
        vector<vector<long long>> dist(K, vector<long long>(K, INF));
        for (int i = 0; i < cost.size(); ++i) {
            int u = index[original[i]], v = index[changed[i]];
            if (cost[i] < dist[u][v])
                dist[u][v] = cost[i];
        }

         
        for (int k = 0; k < K; ++k)
            for (int u = 0; u < K; ++u)
                if (dist[u][k] != INF)
                    for (int v = 0; v < K; ++v)
                        if ((dist[k][v] != INF) && (dist[u][k] + dist[k][v] < dist[u][v]))
                            dist[u][v] = dist[u][k] + dist[k][v];
                    

         
        Node trie;
        int maxlen = 0;
        for (const auto& [s, sid] : index) {
            Node* node = &trie;
            for (char ch : s) {
                auto& ptr = node->next[ch];    
                if (!ptr) 
                    ptr = make_unique<Node>();
                node = ptr.get();
            }
            node->sid = sid;
            if (s.size() > maxlen) 
                maxlen = s.size();
        }

         
        auto src_starts = buildStartsMap(source, n, maxlen, trie);
        auto tgt_starts = buildStartsMap(target, n, maxlen, trie);

        
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == INF) continue;

            if (source[i] == target[i] && dp[i] < dp[i + 1])
                dp[i + 1] = dp[i];

            auto &sm = src_starts[i];
            auto &tm = tgt_starts[i];
            if (sm.empty() || tm.empty()) continue;

            for (const auto& [l, u] : sm) {
                auto it = tm.find(l);
                if (it == tm.end()) 
                    continue;

                int v = it->second;
                long long d = dist[u][v];
                if ((d != INF) && (dp[i] + d < dp[i + l]))
                    dp[i + l] = dp[i] + d;
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }

    static vector<unordered_map<int,int>> 
    buildStartsMap(const string& s, int n, int maxlen, const Node& trie) {
        vector<unordered_map<int,int>> result(n);
        for (int i = 0; i < n; ++i) {
            const Node* node = &trie;
            for (int j = i; j < n && j < i + maxlen; ++j) {
                auto it = node->next.find(s[j]);
                if (it == node->next.end()) 
                    break;
                node = it->second.get();
                int sid = node->sid;
                if (sid != -1) {
                    result[i][j - i + 1] = sid;
                }
            }
        }
        return result;
    }
};