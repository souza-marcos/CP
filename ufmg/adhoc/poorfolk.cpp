#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n; cin >> n;
    vector<ll> vals(n);
    for(auto& el: vals) cin >> el;
    
    sort(vals.begin(), vals.end());
    ll cani = 0, sum = 0;
    for(int i = 0; i < n; i++){
        if(cani + 1 >= vals[i]){
            cani += vals[i];
        }
        else{
            cout << cani + 1 << endl;
            return 0;
        }

    }
    cout << cani + 1 << endl;

    return 0;
} 
