#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n; cin >> n;
    while(n > 0){
        multiset<int> ms;
        ll res = 0;

        for(int i = 0; i < n; i ++){
            int k; cin >> k;
            while(k --){
                int a; cin >> a;
                ms.insert(a);
            }

            if(sz(ms) >= 2){
                res += (*ms.rbegin()) - (*ms.begin());
                ms.erase(ms.begin());
                ms.erase(ms.find(*ms.rbegin()));
            }
        }   

        cout << res << endl;

        cin >> n;
    }

} 
