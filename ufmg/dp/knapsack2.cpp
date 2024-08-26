#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, W;
vector<pair<int, int>> objs;

int memo[110][10010];
// <- Max value
int solve(int i, int cap){
    if(cap < 0) return -INF;
    if(i == N) return 0;
    
    auto& p = memo[i][cap];
    if(p != -1) return p;

    return p = max(solve(i + 1, cap - objs[i].first) + objs[i].second, solve(i + 1, cap));

}

int main(){ _
    cin >> N >> W;
    objs.resize(N);
    for(auto& el : objs) cin >> el.first >> el.second;

    memset(memo, -1, sizeof memo);
     
    cout << solve(0, W) << endl;
    // for(int i = 0; i <= N; i++){
    //     for(int j = 0; j <= 140; j ++) cout << memo[i][j] << " ";
    //     cout << endl;
    // }

    return 0;
} 
