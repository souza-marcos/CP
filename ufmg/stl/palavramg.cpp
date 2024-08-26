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

bool isOrd(string p){
    transform(p.begin(), p.end(),p.begin(), ::toupper);
    if(p.size() == 1) return true;
    for(int i= 1; i< p.size(); i++){
        if(p[i] <= p[i-1]) return false;
    }
    return true;
}

int main(){ _
    int n; cin >> n;
    vector<string> pl(n);
    for(auto& sp: pl ){
        cin >> sp;
        cout << sp << ": " << (isOrd(sp)?"O":"N") << endl;
    }

    return 0;
} 
