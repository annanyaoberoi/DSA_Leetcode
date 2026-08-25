class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int res = 0;
        for (auto x : operations) {
            if (x == "C") {
                st.pop();
            } else if (x == "D") {
                int top = st.top();
                st.push(top * 2);
            } else if (x == "+") {
                int top = st.top();
                st.pop();
                int topnew = st.top();
                st.push(top);
                st.push(top + topnew);
            } else {
                st.push(stoi(x));
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }return res;
    }
};