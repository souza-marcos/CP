#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n;
    cin >> n;
    int cnt = 0;
    while(n --){
        char type; int s;
        cin >> type >> s;
        if(type == 'P') { cnt += s; continue; }

        if(cnt >= s){
            cout << "NO\n";
            cnt -= s;
        }
        else{
            cout << "YES\n";
            cnt = 0;
        }
    }

    return 0;
} 
