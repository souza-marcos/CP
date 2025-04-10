#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 
    int n; cin >> n;
    vector<string> arr(n);
    for(auto& el: arr) cin >> el;

    bool ok = false;
    for(auto& el: arr){
        if(el.substr(0, 2) == "OO"){
            el[0] = el[1] = '+';
            ok = true;
            break;
        } 
        if(el.substr(3, 2) == "OO"){
            el[3] = el[4] = '+', ok = true;
            break;
        } 
    }

    if(!ok) cout << "NO\n";
    else{
        cout << "YES\n";
        for(auto el : arr) cout << el << endl;
    }

} 
