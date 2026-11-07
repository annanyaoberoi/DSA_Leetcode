class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> available;

        priority_queue<array<long long,3>,
        vector<array<long long,3>>,
        greater<array<long long,3>>> busy;

        int n = servers.size();
        int m = tasks.size();

        // Initially all servers are available
        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);

        for(int i = 0; i < m; i++) {

            // Release servers that have finished
            while(!busy.empty() && busy.top()[0] <= i) {

                auto s = busy.top();
                busy.pop();

                available.push({s[1], s[2]});
            }

            // If no server is available, wait
            if(available.empty()) {

                auto s = busy.top();
                busy.pop();

                ans[i] = s[2];

                busy.push({s[0] + tasks[i], s[1], s[2]});
            }
            else {

                auto s = available.top();
                available.pop();

                ans[i] = s.second;

                busy.push({i + tasks[i], s.first, s.second});
            }
        }

        return ans;
    }
};