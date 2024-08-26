#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;
    string counter = ""; 
    int foccur[k], cont = 0;
    memset(foccur, -1, sizeof(foccur));
    for(int i = 0; i < m; i++){
        char cur = s[i];
        if(foccur[cur - 'a'] == -1) cont ++;
        foccur[cur - 'a'] = i;
        if(cont == k) {
            counter += cur;
            cont = 0;
            memset(foccur, -1, sizeof(foccur)); // bad
        }
        if(counter.size() == n) break;
    }
    if(counter.size() == n){
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;

    for(int i = 0; i < k; i++){
        if(foccur[i] == -1){
            for(int j = 0; j < n - counter.size(); j++) counter += (char)(i + 'a');
            cout << counter << endl;
            return;
        }
    }
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();

    return 0;
} 
