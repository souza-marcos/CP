#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

int n; string s;

bool valid(int size){
    // prefix
    int cont = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = i + size; j < n; j += size) {
            if(s[j] != s[i]) cont ++;
            if(cont >= 2) break;
        }
    }
    if(cont <= 1) return true;
    
    // suffix
    cont = 0;
    for(int i = n - size; i < n; i++){
        for(int j = i - size; j >= 0; j -= size) {
            if(s[j] != s[i]) cont ++;
            if(cont >= 2) break;
        }
    }
    if(cont <= 1) return true;
    return false;
}

void solve(){
    cin >> n; cin >> s;
    for(int i = 1; i < n/2 + 1; i ++){
        if(n % i != 0) continue;
        if(valid(i)){
            cout << i << endl; return;
        }
    }
    cout << n << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
