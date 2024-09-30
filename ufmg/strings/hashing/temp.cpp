#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()

pair<ll, ll> compute_hash(const string& s){
    const int p1 = 31, p2 = 37;
    const int m1 = 1e9 + 9, m2 = 1e9 + 7;
    ll hv1 = 0, hv2 = 0, pp1= 1, pp2 = 1;
    for(char c : s){
        hv1 = (hv1 + (c - 'a' + 1) * pp1) % m1;
        hv2 = (hv2 + (c - 'a' + 1) * pp2) % m2;
        pp1 = (pp1 * p1) % m1;
        pp2 = (pp2 * p2) % m2;
    }
    return {hv1, hv2};
}

int main(){ _
    string s; cin >> s;
    auto [f, se] = compute_hash(s);
    cout << f << " " << se << endl;
    return 0;
} 
