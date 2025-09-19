#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long n;
        cin >> n;
        if (n % 4 == 1 || n % 4 == 2) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> res;
        res.reserve(2 * n);

        long long x = (n + 3) / 4; // ceil(n/4)
        int a = 2 * x - 1;
        int b = 4 * x - 2;
        int c = 4 * x - 1;
        int d = 4 * x;

        vector<int> p, q, r, s;
        // p,q: numbers strictly between 0 and a
        for (int i = 1; i < a; ++i) {
            if (i % 2) p.push_back(i);
            else q.push_back(i);
        }
        // r,s: numbers strictly between a and b
        for (int i = a + 1; i < b; ++i) {
            if (i % 2) r.push_back(i);
            else s.push_back(i);
        }

        auto append = [&](const vector<int> &v) {
            for (int val : v) res.push_back(val);
        };
        auto append_rev = [&](const vector<int> &v) {
            for (int i = (int)v.size() - 1; i >= 0; --i) res.push_back(v[i]);
        };

        if (n % 4 == 0) {
            // Concatenation for n ≡ 0 (mod 4):
            // s' · p' · b · p · c · s · d · r' · q' · b · a · q · c · r · a · d
            append_rev(s);
            append_rev(p);
            res.push_back(b);
            append(p);
            res.push_back(c);
            append(s);
            res.push_back(d);
            append_rev(r);
            append_rev(q);
            res.push_back(b);
            res.push_back(a);
            append(q);
            res.push_back(c);
            append(r);
            res.push_back(a);
            res.push_back(d);
        } else {
            // n % 4 == 3
            // Concatenation for n ≡ 3 (mod 4):
            // s' · p' · b · p · c · s · a · r' · q' · b · a · q · c · r
            append_rev(s);
            append_rev(p);
            res.push_back(b);
            append(p);
            res.push_back(c);
            append(s);
            res.push_back(a);
            append_rev(r);
            append_rev(q);
            res.push_back(b);
            res.push_back(a);
            append(q);
            res.push_back(c);
            append(r);
        }

        // Output sequence (should have length 2n)
        for (size_t i = 0; i < res.size(); ++i) {
            if (i) cout << ' ';
            cout << res[i];
        }
        cout << '\n';
    }
    return 0;
}
