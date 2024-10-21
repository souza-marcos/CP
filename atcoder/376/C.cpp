#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    vector<int> a(n); for(int& el: a) cin >> el;
    vector<int> b(n-1); for(int& el: b) cin >> el;
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    b.push_back(-INF);


    int cnt = 0; int large = -1;
    int i = 0, j = 0;
    for(; i < n; i ++){
        if(a[i] <= b[j]) { j ++; continue; }
        if(cnt == 0) large = a[i], cnt = 1;
        else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << large << endl;
    return 0;
} 
