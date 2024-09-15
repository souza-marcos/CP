#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    long long ans = 0;
    
    for(string sub : {"mapie", "map", "pie"}){
        for(size_t pos = 0; (pos = s.find(sub, pos)) != string::npos; ){
            s[pos + sub.length()/2] = '?'; ans ++;
        }
    }
    
    std::cout << ans << endl;
}


int main(){ 
    int t; cin >> t;
    while(t --) solve();


    return 0;
} 
