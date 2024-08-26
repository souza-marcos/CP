#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n; cin >> n;
    map<int, int> sh;
    int el;
    for(int i = 0; i< n; i++){
        cin >> el;
        sh[el] ++;
    } 
    int p, m; cin >> p >> m;

    if(sh[1] >= p && sh[2] >= m) cout << "S" << endl;
    else cout << "N" << endl;

    return 0;
} 
