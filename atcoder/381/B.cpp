#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    string s; cin >> s;
    if(sz(s)%2){ cout << "No\n"; return 0;}

    vector<bool> arr(26, false);

    for(int i = 0; i < sz(s); i += 2){
        if(s[i] != s[i + 1]) {
            cout << "No\n";
            return 0;
        }

        if(arr[s[i]-'a']) {
            cout << "No\n";
            return 0;
        }

        arr[s[i]-'a']=true;
    }

    cout << "Yes\n";
    return 0;
} 
