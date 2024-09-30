#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
// memo[i][j] = min de pedras que adiciono nas i primeiras alturas para ter k diferentes valores
vector<pair<int, int>> piles; // valor da pilha, freq
int n;
int memo[501][501];
int dp(int i, int k){
    if(i >= sz(piles) and k >= 0) return 0;
    if(k < 0) return INF;

    int &p = memo[i][k];
    if(p != -1) return p;

    p = min(
        dp(i + 1, k) + piles[i].second * (piles[i-1].first - piles[i].first),
        dp(i + 1, k-1)
    );
    return p;
}

int main(){ _

    int k, a; cin >> n >> k;
    map<int, int> freq;
    for(int i=0; i<n; i ++){
        cin >> a;
        freq[a] ++;
    }
    for(auto [key, val]: freq)
        piles.push_back({key, val});
    reverse(piles.begin(), piles.end());

    memset(memo, -1, sizeof memo);
    cout << dp(1, k-1) << endl;

    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= k; j ++) cout << memo[i][j] << " ";
        cout << endl;
    }

    return 0;
} 
