#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
int n;
vector<vector<double>> prob;

vector<double> solve() {
    vector<vector<double>> dp(2 * n, vector<double>(n + 1, 0.0));
    for (int i = 0; i < n; i++) {
        dp[i][i + 1] = 1.0;  // Each competitor wins with probability 1 against himself
    }

    for (int i = n; i < 2 * n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[a][j] * prob[j - 1][b] + dp[b][j] * prob[j - 1][a];
        }
    }

    return dp[2 * n - 2];
}

int main(){ _
    cout << setprecision(6) << fixed;
    while (cin >> n && n != 0) {
        prob.assign(n, vector<double>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> prob[i][j];
            }
        }

        vector<double> result = solve();
        cout << result[1] << endl;
    }
    return 0;
}
