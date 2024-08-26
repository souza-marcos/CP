#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

int main(){ _
    int n; cin >> n;
    vector<int> v(n);
    ll sum = 0;
    for(auto &el : v) { cin >> el; sum += el;} 
    sort(v.begin(), v.end(), [](int l, int r) { return l >= r;});   
    // for(auto el: v) cout << el << " ";
    // cout << endl;
    ll sum2= 0;
    for(int i = 2; i < n; i+=3) sum2 += v[i];
    cout << sum - sum2 << endl;
    return 0;
} 
