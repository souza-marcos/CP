#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX= 1e5 + 10;
int N, W;

ll memo[110][MAX];
int v[110], w[110];

ll solve(int i, int cap){
    if(cap < 0) return -LINF;
    if(i >= N) return 0;

    ll& p = memo[i][cap];
    if(p != -1) return p;

    return p = (max(solve(i + 1, cap - w[i]) + v[i], solve(i + 1, cap)));
}
bool peguei[110];

void recupera(int i, int cap){
    if(i >= N) return;
    if(cap >= w[i] and solve(i + 1, cap) < solve(i + 1, cap - w[i])){
        peguei[i] = true;
        return recupera(i + 1, cap - w[i]);
    }
    peguei[i] = false;
    return recupera(i + 1, cap);
}


int main(){ _
    cin >> N >> W;
    for(int i = 0; i < N; i ++) cin >> w[i] >> v[i];

    memset(memo, -1, sizeof memo);

    ll lucro_max = solve(0, W);
    recupera(0, W);


    ll peso = 0, lucro = 0;
    for(int i = 0; i< N; i++){
        if(peguei[i]){
            peso += w[i];
            lucro += v[i];
        }
    }

    // assert -> Se for falsa: RTE(Runtime Error)
    assert(lucro_max == lucro and peso <= W);

    cout << lucro_max << endl;

    return 0;
} 
