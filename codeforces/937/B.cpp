#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0 + i; j < n + i; j++){
            if(j%2 == 0) cout << "##";
            else cout << "..";
        }
        cout << endl;
        for(int j = 0 + i; j < n + i; j++){
            if(j%2 == 0) cout << "##";
            else cout << "..";
        }
        cout << endl;
    }

}


int main(){ _
    int t; cin >> t;
    while(t --) solve();


    return 0;
} 
