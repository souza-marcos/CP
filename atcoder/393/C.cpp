#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n, m; cin >> n >> m;
    set<pair<int, int>> g;


    int cnt = 0;
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        if(a == b) {
            cnt ++;
            continue;
        }
        if(g.count({a, b}) or g.count({b, a})) cnt++;
        else {
            g.insert({a, b});
        }
    }

    cout << cnt << endl;
    return 0;
} 
