#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll K;
    if (!(cin >> n >> K)) return 0;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    // map cells that are not '#' to 0..m-1
    map<pair<int,int>, int> mp;
    vector<pair<int,int>> inverse;
    int timer = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (arr[i][j] != '#'){
                mp[{i,j}] = timer++;
                inverse.emplace_back(i,j);
            }
        }
    }
    int m = (int)inverse.size();
    if (m == 0){
        // all are '#'
        for (int i = 0; i < n; ++i) cout << arr[i] << '\n';
        return 0;
    }

    // build adjacency A (m x m): A[i][j] = 1 if j is neighbor of i (exclude self)
    vector<vector<bool>> A(m, vector<bool>(m, false));
    for (int t = 0; t < m; ++t){
        int i = inverse[t].first;
        int j = inverse[t].second;
        for (int di = -1; di <= 1; ++di){
            for (int dj = -1; dj <= 1; ++dj){
                if (di == 0 && dj == 0) continue; // skip self
                int ni = i + di;
                int nj = j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && arr[ni][nj] != '#'){
                    int to = mp[{ni,nj}];
                    A[t][to] = true;
                }
            }
        }
    }

    // M = I xor A
    vector<vector<bool>> M = A;
    for (int i = 0; i < m; ++i) M[i][i] = !M[i][i];

    // matrix multiply over GF(2): C = X * Y
    auto mul = [&](const vector<vector<bool>>& X, const vector<vector<bool>>& Y){
        vector<vector<bool>> C(m, vector<bool>(m, false));
        for (int i = 0; i < m; ++i){
            for (int k = 0; k < m; ++k){
                if (!X[i][k]) continue;
                // XOR row k of Y into row i of C
                for (int j = 0; j < m; ++j){
                    C[i][j] = C[i][j] ^ Y[k][j];
                }
            }
        }
        return C;
    };

    // matrix exponentiation: compute M^K
    auto matPow = [&](vector<vector<bool>> base, ll exp){
        vector<vector<bool>> res(m, vector<bool>(m, false));
        for (int i = 0; i < m; ++i) res[i][i] = true; // identity
        while (exp > 0){
            if (exp & 1) res = mul(res, base);    // res = res * base
            base = mul(base, base);               // base = base * base
            exp >>= 1;
        }
        return res;
    };

    vector<vector<bool>> MK = matPow(M, K);

    // initial vector
    vector<bool> init(m, false);
    for (int t = 0; t < m; ++t){
        auto [i,j] = inverse[t];
        init[t] = (arr[i][j] == '1');
    }

    // final = MK * init
    vector<bool> fin(m, false);
    for (int i = 0; i < m; ++i){
        bool val = false;
        for (int j = 0; j < m; ++j){
            if (MK[i][j] && init[j]) val = !val;
        }
        fin[i] = val;
    }

    // print mapped back
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (arr[i][j] == '#') cout << '#';
            else cout << (fin[ mp[{i,j}] ] ? '1' : '0');
        }
        cout << '\n';
    }
    return 0;
}
