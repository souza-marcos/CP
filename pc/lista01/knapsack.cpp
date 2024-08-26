#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
typedef long long ll;

int N, W;
vector<int> w, v;

ll memo[110][100010];

ll dp(int item, int cap){
    if(cap < 0) return -LINF;
    if(item == N) return 0LL;

    ll &p = memo[item][cap];
    if(p != -1) return p;
    
    return p = max(dp(item + 1, cap - w[item]) + v[item], dp(item + 1, cap));
}

int main(){_
    cin >> N >> W;
    w.resize(N), v.resize(N);
    for(int i = 0; i<N; i++){
        cin >> w[i] >> v[i];
    }

    memset(memo, -1, sizeof memo);
    cout << dp(0, W) << endl;
}