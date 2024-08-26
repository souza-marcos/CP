#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, K;
vector<int> h;

const int MAX = 1e5 + 10;
int memo[MAX];

// Solucao Top-Down
int solve(int i){
    if(i == 0) return 0;
    if(memo[i] != -1) return memo[i];

    int ret = INF;
    for(int j = max(0, i - K); j < i; j++){
        ret = min(ret, solve(j) + abs(h[j] - h[i]));
    }

    return memo[i] = ret;
}

int main(){ _
    cin >> N >> K;
    h.resize(N);
    for(int& el: h) cin >> el;

    memset(memo, -1, sizeof memo);

    cout << solve(N - 1) << endl;

    return 0;
} 
