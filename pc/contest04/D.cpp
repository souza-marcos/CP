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

string s;

bool possible(int d){
    int p = d - 1;
    while (p < s.size())
    {
        if(s[p] == 'R') p += d;
        else{
            for(int i = p; i > p - d; i--){
                if(s[i] == 'R') {
                    p = i + d;
                    break;
                }
                else if(i == p-d+1) return false;
            }
        }
    }
    return true;
}


int main(){ _

    int t; cin >> t;
    while(t--){
        cin >> s;
        int l = 1, r = s.size() + 2;
        while(l < r){
            int m = (l + r)/2;
            if(!possible(m)) l = m+1;
            else r = m;
        }

        cout << l << endl;
    }



    return 0;
} 
