#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<int> arr(n); for(int& el: arr) cin >> el;


    auto recalc = [](int a, int b){
        if(a < b) return ++a;
        if(a == b) return a;
        return --a;
    };

    vector<int> best_bef = {0, 0}, best_in = {0, 0}, best_end = {0, 0};
    for(int i = 0; i < n; i ++){

        best_bef[i%2] = recalc(best_bef[(i+1)%2], arr[i]);
        best_in[i%2] = max(best_bef[(i+1)%2], best_in[(i+1)%2]);
        best_end[i%2] = max(recalc(best_end[(i+1)%2], arr[i]), recalc(best_in[(i + 1)%2], arr[i]));

        // cout << best_bef[i%2] << " " << best_in[i%2] << " " << best_end[i%2] << "\n";
    }

    cout << min(n-1, max(best_in[(n-1)%2], best_end[(n-1)%2])) << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
