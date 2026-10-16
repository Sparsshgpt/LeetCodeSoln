class Solution {
public:
    int sumCounts(vector<int>& nums) {
        using ll = long long;
        const ll MOD = 1000000007;

        int n = nums.size();
        vector<ll> sum(4 * n), sq(4 * n), lazy(4 * n);

        auto apply = [&](int node, int l, int r) {
            ll len = r - l + 1LL;
            sq[node] = (sq[node] + 2LL * sum[node] + len) % MOD;
            sum[node] = (sum[node] + len) % MOD;
            lazy[node]++;
        };

        function<void(int, int, int)> push = [&](int node, int l, int r) {
            if (lazy[node] == 0 || l == r) return;

            int mid = (l + r) / 2;
            ll v = lazy[node];

            auto propagate = [&](int child, int left, int right) {
                ll len = right - left + 1LL;
                sq[child] = (sq[child] + 2LL * v % MOD * sum[child] % MOD
                             + len % MOD * v % MOD * v % MOD) % MOD;
                sum[child] = (sum[child] + len * v) % MOD;
                lazy[child] = (lazy[child] + v) % MOD;
            };

            propagate(node * 2, l, mid);
            propagate(node * 2 + 1, mid + 1, r);
            lazy[node] = 0;
        };

        function<void(int, int, int, int, int)> update =
        [&](int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql) return;

            if (ql <= l && r <= qr) {
                apply(node, l, r);
                return;
            }

            push(node, l, r);

            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr);
            update(node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        vector<int> last(100001, -1);
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            update(1, 0, n - 1, last[nums[i]] + 1, i);
            last[nums[i]] = i;
            ans = (ans + sq[1]) % MOD;
        }

        return (int)ans;
        
    }
};