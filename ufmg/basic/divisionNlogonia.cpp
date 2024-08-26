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


int main()
{ _
    int k; cin >> k;
    pair<int, int> dcord, hcord;
    
    while(k != 0){
        cin >> dcord.f >> dcord.s;

        while(k-- > 0){
            cin >> hcord.f >> hcord.s;
            if(hcord.f == dcord.f || hcord.s == dcord.s) {
                cout << "divisa" << endl;
                continue;
            }
            if(hcord.f > dcord.f) {
                if(hcord.s > dcord.s) {
                    cout << "NE\n";
                    continue;
                }
                cout << "SE\n";
                continue;
            }
            if(hcord.s > dcord.s) {
                cout << "NO\n";
                continue;
            }
            cout << "SO\n";
        }


        cin >> k;
    } 

    return 0;
} 
