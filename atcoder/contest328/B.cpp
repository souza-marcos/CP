#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18

void solve1(){
    int n; cin >> n;
    
    vector<int> D(n);
    for(int &x : D) cin >> x;

    int ans = 0;
    for(int m = 1; m <= n; ++m){
        string month = to_string(m);
        for(int d = 1; d <= D[m - 1]; d++){
            string date = month + to_string(d);
            if(size(set<char>(date.begin(), date.end())) == 1) // Apenas um digito igual 
                ans++;
        }

    }

    cout << ans << endl;
}

int main(){ _
    solve1();
    return 0;
} 
