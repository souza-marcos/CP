#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _

    int n; char c1, c2;
    cin >> n >> c1 >> c2;
    string s; cin >> s;
    for(auto c : s){
        if(c != c1)cout << c2;
        else cout << c1;
    }   
    cout << endl;
    return 0;
} 
