#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()

int N, W;
vector<ll> v, w;
#define MAXN 3001
ll memo[MAXN][MAXN];

ll dp(int i, int cap){
    if(i >= N) return 0;
    if(cap < 0) return -LINF;

    ll &p = memo[i][cap];
    if(p!=-1) return p;
    ll maxv = -LINF;

}

int main(){ _
    cin >> n >> W;
    v.resize(n), w.resize(n);
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i]; 
    }

    cout << dp(0, W) << endl;
    return 0;
} 
