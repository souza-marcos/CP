#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

// A ideia eh processar em blocos de to-minimo, 
// meu minimo eh o menor valor maior que eu
// e meu maximo eh o maior valor que esta abaixo de um range 1-para-1. 
// incrementando range para teste

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);

    for(int& el : a) cin >> el;
    for(int& el : b) cin >> el;
    
    int next = n;

    vector<int> fin(n);
    vector<int> dmin(n), dmax(n);
    int sum = 0;
    for(int i = n-1, cnt = 1; i >= 0; i --, cnt ++){
        int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        dmin[i] = b[pos];
        dmax[i] = b[next - 1];
        fin[pos] ++;
        sum += fin[i];
        if(sum == cnt) next = i;
    }

    for(int i = 0; i < n; i ++)
        cout << dmin[i] - a[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i ++)
        cout << dmax[i] - a[i] << " ";
    cout << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
