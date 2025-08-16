#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int& el : a) cin >> el;
    for(int& el : b) cin >> el;
    
    vector<pair<int, int>> arr;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j+1 < n; j ++){
            if(a[j] > a[j + 1]){
                arr.emplace_back(1, j);
                swap(a[j], a[j+1]);
            }
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j+1 < n; j ++){
            if(b[j] > b[j + 1]){
                arr.emplace_back(2, j);
                swap(b[j], b[j+1]);
            }
        }
    }

    for(int i = 0; i < n; i ++){
        if(a[i] > b[i]){
            arr.emplace_back(3, i);
        }
    }
    
    cout << sz(arr) << endl;
    for(auto [a, b] : arr) cout << a << " " << b+1 << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
