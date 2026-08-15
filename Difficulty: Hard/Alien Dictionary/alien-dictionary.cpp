class Solution {
  public:
    string findOrder(vector<string> &words) {

        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        // Mark characters that actually appear
        for (string &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string &a = words[i];
            string &b = words[i + 1];

            int len = min(a.size(), b.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (a[j] != b[j]) {
                    int u = a[j] - 'a';
                    int v = b[j] - 'a';

                    adj[u].push_back(v);
                    indegree[v]++;

                    found = true;
                    break;
                }
            }

            // Invalid case:
            // "abc" comes before "ab"
            if (!found && a.size() > b.size()) {
                return "";
            }
        }

        // Topological sort using Kahn's algorithm
        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Cycle exists
        if (ans.size() != count(present.begin(), present.end(), true)) {
            return "";
        }

        return ans;
    }
};