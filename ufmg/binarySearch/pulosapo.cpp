#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string s;

bool valid(int sizejmp){
    int i = -1;
    while(i + sizejmp < s.size()){
        int newi = 0;
        for(int j = sizejmp + i; j > i; j --){
            if(s[j] == 'R') {
                i = newi = j;
                break;
            }
        }
        if(newi == 0) return false;
    }
    return true;
}

void solve(){
    cin >> s;

    int l = 1, r = s.size() + 2;
    while(l + 1 < r){
        int m = (l + r)/2;
        if(valid(m)) r = m;
        else l = m;
    }
    cout << r << endl;
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
