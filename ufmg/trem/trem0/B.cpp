#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

int main(){ _
    int n; cin >> n;
    int r[n], c[n];
    for(int &el: r) { cin >> el; }
    for(int &el: c) { cin >> el; }
    int q; cin >> q;
    while(q --){
        int a, b; cin >> a >> b; a--, b--;
        cout << (r[a] + c[b] > n ? "#" : ".");
    }
    cout << endl;
    return 0;
} 
