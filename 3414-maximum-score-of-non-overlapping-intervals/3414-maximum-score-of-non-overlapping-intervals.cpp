class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        sort(a.begin(), a.end());

        vector<long long> start(n);

        for (int i = 0; i < n; i++)
            start[i] = a[i][0];

        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(start.begin(), start.end(), a[i][1]) - start.begin();
        }

        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1, vector<pair<long long, vector<int>>>(5)
        );

        auto better = [&](auto &x, auto &y) {
            if (x.first != y.first)
                return x.first > y.first;
            return x.second < y.second;
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                auto skip = dp[i + 1][k];
                auto take = dp[nxt[i]][k - 1];

                take.first += a[i][2];
                take.second.push_back(a[i][3]);

                sort(take.second.begin(), take.second.end());

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].second;
        
    }
};