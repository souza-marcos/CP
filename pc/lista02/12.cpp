#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

const int MAX = 1001;
int n, k;
vector<int> premio;
vector<double> chance;
double memo[MAX][MAX];

// max E[X_i] = P[X_i] * (max E[X_i+1] + valor_i)
double dp(int i, int p_res){
    if(p_res < 0) return (double)-INF;
    if(i >= n) return 0;

    double& p = memo[i][p_res];
    if(p >= 0) return p;

    return p = max((dp(i + 1, p_res - 1) + premio[i]),
                   (dp(i + 1, p_res) + premio[i]) * chance[i]/100.0);
}

void solve(){
    premio.resize(n), chance.resize(n);
    for(int& el: premio) cin >> el;
    for(double& el: chance) cin >> el;
    
    for(auto& row: memo) for(double& el: row) el = -1.0;

    cout << fixed << setprecision(2);

    cout << dp(0, k) << endl; 
    // for(auto [el, val] : memo){
    //     auto [i, prob] = el;
    //     cout << i << " " << prob  << " = " << val << endl; 
    // }
}


int main(){_
    while(cin >> n >> k) solve();
    return 0;
}