class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Build Suffix Array
        vector<int> a = nums;
        a.push_back(0);

        int N = n + 1;

        vector<int> p(N), c(N);

        vector<pair<int, int>> v(N);

        for (int i = 0; i < N; i++)
            v[i] = {a[i], i};

        sort(v.begin(), v.end());

        for (int i = 0; i < N; i++)
            p[i] = v[i].second;

        c[p[0]] = 0;

        for (int i = 1; i < N; i++) {
            c[p[i]] = c[p[i - 1]] +
                      (v[i].first != v[i - 1].first);
        }

        int k = 0;

        while ((1 << k) < N) {
            int len = 1 << k;

            vector<int> pn(N), cn(N);

            for (int i = 0; i < N; i++) {
                pn[i] = p[i] - len;

                if (pn[i] < 0)
                    pn[i] += N;
            }

            vector<int> cnt(N, 0);

            for (int i = 0; i < N; i++)
                cnt[c[pn[i]]]++;

            for (int i = 1; i < N; i++)
                cnt[i] += cnt[i - 1];

            for (int i = N - 1; i >= 0; i--)
                p[--cnt[c[pn[i]]]] = pn[i];

            cn[p[0]] = 0;

            for (int i = 1; i < N; i++) {
                pair<int, int> cur = {
                    c[p[i]], c[(p[i] + len) % N]
                };

                pair<int, int> prev = {
                    c[p[i - 1]], c[(p[i - 1] + len) % N]
                };

                cn[p[i]] = cn[p[i - 1]] + (cur != prev);
            }

            c = cn;
            k++;
        }

        // Remove the empty suffix
        vector<int> sa;

        for (int i = 1; i < N; i++)
            sa.push_back(p[i]);

        // Step 2: Build LCP Array
        vector<int> rank(n);

        for (int i = 0; i < n; i++)
            rank[sa[i]] = i;

        vector<int> lcp(n, 0);

        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = rank[i];

            if (r == n - 1) {
                h = 0;
                continue;
            }

            int j = sa[r + 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;

            if (h > 0)
                h--;
        }

        // Step 3: Find minimum unique subarray length

        // find minimum unique subarray length 
        int ans = n;

        for (int i = 0; i < n; i++) {
            int common = 0;

            if (i > 0)
                common = max(common, lcp[i - 1]);

            if (i < n - 1)
                common = max(common, lcp[i]);

            int required = common + 1;

            if (required <= n - sa[i])
                ans = min(ans, required);
        }

        return ans;
    }
};