#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int N, K; cin >> N >> K;
    vector<int> h(N);
    for(int& el: h) cin >> el;

    vector<int> memo(N);

    memo[0] = 0;
    for(int i =1; i < N; i++){
        memo[i] = INF;
        for(int j = max(0, i - K); j < i; j++){
            memo[i] = min(memo[i], memo[j] + abs(h[i] - h[j]));
        }
    }
    cout << memo[N - 1] << endl;

    return 0;
} 
