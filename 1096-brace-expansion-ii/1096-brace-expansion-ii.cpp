class Solution {
public:
    vector<string> braceExpansionII(string expression) {
          set<string> st;
        
        function<set<string>(int&)> solve = [&](int &i) {
            set<string> ans;
            set<string> cur = {""};

            while (i < expression.size() && expression[i] != '}') {
                if (expression[i] == ',') {
                    ans.insert(cur.begin(), cur.end());
                    cur = {""};
                    i++;
                }
                else if (expression[i] == '{') {
                    i++;

                    set<string> temp = solve(i);

                    i++;

                    set<string> next;

                    for (auto a : cur)
                        for (auto b : temp)
                            next.insert(a + b);

                    cur = next;
                }
                else {
                    char c = expression[i++];

                    set<string> next;

                    for (auto x : cur)
                        next.insert(x + c);

                    cur = next;
                }
            }

            ans.insert(cur.begin(), cur.end());
            return ans;
        };

        int i = 0;
        set<string> result = solve(i);

        return vector<string>(result.begin(), result.end());
        
    }
};