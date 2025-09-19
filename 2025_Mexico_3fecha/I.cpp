#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128_t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int64> A(n+1), B(m+1);
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int j = 1; j <= m; ++j) cin >> B[j];

    // prefix sums of A
    vector<int64> pref(n+1, 0);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + A[i];

    // S1 = sum i * A[i]
    i128 S1 = 0;
    for (int i = 1; i <= n; ++i) S1 += (i128)i * (i128)A[i];

    i128 answer = 0;

    for (int j = 1; j <= m; ++j) {
        // compute S2_j = sum floor(i/j) * A[i]
        i128 S2 = 0;
        // iterate blocks: l = q*j, r = min(n, (q+1)j-1)
        for (int l = j, q = 1; l <= n; l += j, ++q) {
            int r = min(n, l + j - 1);
            int64 sumA = pref[r] - pref[l-1];
            S2 += (i128)q * (i128)sumA;
        }
        i128 Tj = S1 - (i128)j * S2;        // T_j = sum (i % j) * A[i]
        answer += (i128)B[j] * Tj;
    }

    // print i128
    if (answer == 0) {
        cout << "0\n";
        return 0;
    }
    bool neg = false;
    if (answer < 0) { neg = true; answer = -answer; }
    string out;
    while (answer > 0) {
        int digit = (int)(answer % 10);
        out.push_back('0' + digit);
        answer /= 10;
    }
    if (neg) out.push_back('-');
    reverse(out.begin(), out.end());
    cout << out << '\n';
    return 0;
}
