#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _

    ll n, rating; cin >> n >> rating;

    for(int i = 0; i < n; i ++){
        int d, a; cin >> d >> a;
        if(d == 1 and (rating >= 1600 and rating <= 2799)) rating += a;
        if(d == 2 and (rating >= 1200 and rating <= 2399)) rating += a;
    }   

    cout << rating << endl;

    return 0;
} 
