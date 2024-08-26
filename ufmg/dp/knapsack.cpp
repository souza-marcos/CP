#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, W;
vector<int> w, v;

ll memo[110][100010];

ll solve(int item, int cap){
    if(cap < 0) return -LINF;
    if(item == N) return 0;

    ll& p = memo[item][cap];
    if(p != -1) return p;
    return p = max(solve(item + 1, cap), solve(item + 1, cap - w[item]) + v[item]);
}

int main(){ _

    cin >> N >> W;
    w.resize(N), v.resize(N);
    for(int i = 0; i<N; i++) cin >> w[i] >> v[i];

    memset(memo, -1, sizeof memo);
    cout << solve(0, W) << endl;


    return 0;
} 
