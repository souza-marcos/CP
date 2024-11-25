// https://codeforces.com/gym/103373/problem/B
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    const int MAX = 1e6 + 10;
    vector<ll> prec(MAX, 1);
    prec[1]= 0;
    for(int i = 2; i < MAX; i ++){
        for(int j = 2*i; j < MAX; j += i){
            prec[j] += i;       
        }
    }
    // for(int i = 0; i < 10; i ++) cout << prec[i] << " ";
    // cout << endl;

    int n; cin >> n;
    for(int i = 0 ; i<n; i ++){
        int q; cin >> q;
        cout << prec[q] << " ";
        if(prec[q] < q) cout << "deficient\n";
        else if (prec[q] > q) cout << "abundant\n";
        else cout << "perfect\n";
    }

} 
