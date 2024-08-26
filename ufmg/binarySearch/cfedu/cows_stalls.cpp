#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int n, k; vector<int> v;

bool valid(int guess){
    int cnt = 1, cur = v[0];
    for(auto el: v){
        if(el - cur >= guess){
            cur = el, cnt ++;
            if(cnt >= k) return true;
        }
    }
    return false;
}

int main(){ _
    cin >> n >> k;
    v.resize(n);
    for(auto& el: v) cin >> el;

    int l = 0, r = 1e9 + 2;
    while (l + 1 < r){
        int m = (l + r)/2;
        if(valid(m)) l = m; 
        else r = m;
    }
    cout << l << endl;

    return 0;
} 
