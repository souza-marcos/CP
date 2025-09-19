// https://codeforces.com/problemset/problem/2084/C
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll
// os carinhas tem que estar pareados com os mesmos no correspondente (v - u, entao u - v).
// Se for impar tem que ter exatamente um carinha pareado com ele mesmo.
    // Se for par não pode acontecer isso 

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int& el : a) cin >> el;
    for(int& el : b) cin >> el;

    vector<int> mp(n+1, -1);
    vector<int> where(n+1);
    int cnt_equal = 0;
    int pos_equal = -1;
    for(int i = 0; i < n; i ++){
        where[b[i]] = i;
        if(mp[a[i]] == -1) mp[a[i]] = b[i];
        else {
            if(mp[a[i]] != b[i]){
                cout << -1 << endl;
                return;
            }
        } 

        if(mp[b[i]] == -1) mp[b[i]] = a[i];
        else {
            if(mp[b[i]] != a[i]){
                cout << -1 << endl;
                return;
            }
        } 

        if(a[i] == b[i]){
            cnt_equal ++;
            pos_equal = i;
        }
    }
    if((cnt_equal != 1 and n % 2 == 1) or (cnt_equal > 0 and n%2 == 0)) {
        cout << -1 << endl;
        return;
    }

    vector<pair<int, int>> op;
    if(cnt_equal and pos_equal != n/2){
        where[b[pos_equal]] = n/2;
        where[b[n/2]] = pos_equal;
        op.push_back({pos_equal+1, n/2+1});
        swap(a[pos_equal], a[n/2]);
        swap(b[pos_equal], b[n/2]);
    }


    for(int i = 0; i < n/2; i ++){
        int from = where[a[i]];
        int to = n-i-1;
        if(from != to){
            where[b[to]] = from;
            where[b[from]] = to;
            swap(a[from], a[to]);
            swap(b[from], b[to]);

            op.push_back({from+1, to+1});
        }
    }

    cout << sz(op) << endl;
    for(auto [a, b] : op) cout << a << " " << b << endl;

}

int32_t main(){ _ 
    int t; cin >> t;
    while(t --) solve();
}