class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                string curr = q.front();
                q.pop();

                int balance = 0;
                bool valid = true;

                for (char c : curr) {
                    if (c == '(')
                        balance++;
                    else if (c == ')') {
                        balance--;
                        if (balance < 0) {
                            valid = false;
                            break;
                        }
                    }
                }

                if (valid && balance == 0) {
                    ans.push_back(curr);
                    found = true;
                }

                if (found)
                    continue;

                for (int i = 0; i < curr.size(); i++) {
                    if (curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = curr.substr(0, i) + curr.substr(i + 1);

                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            if (found)
                break;
        }

        return ans;
    }
};