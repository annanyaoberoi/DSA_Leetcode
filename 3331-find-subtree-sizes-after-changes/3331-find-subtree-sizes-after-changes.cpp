class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int node = 1; node < n; ++node) {
            children[parent[node]].push_back(node);
        }
        vector<int> sizes(n, 1);
        vector<int> finalParent = parent;
        vector<int> previous(n);
        vector<int> nearest(26, -1);
        stack<pair<int, bool>> events;
        events.emplace(0, false);
        while (!events.empty()) {
            auto [node, leaving] = events.top();
            events.pop();
            int letter = s[node] - 'a';
            if (leaving) {
                nearest[letter] = previous[node];
                if (finalParent[node] != -1) {
                    sizes[finalParent[node]] += sizes[node];
                }
            } else {
                previous[node] = nearest[letter];
                if (nearest[letter] != -1) {
                    finalParent[node] = nearest[letter];
                }
                nearest[letter] = node;
                events.emplace(node, true);
                for (int child : children[node]) {
                    events.emplace(child, false);
                }
            }
        }
        return sizes;
    }
};