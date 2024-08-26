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

int main(){ _
    int n; cin >> n;
    int r, c;
    while(n-- >0){
        cin >> r >> c;
        for(int i= 0; i<r; i++){
            for(int j =0; j<c; j++){
                if(i == 0 and j == 0) cout << "W";
                else cout << "B";
            }cout << endl;
        }
    }

    return 0;
} 
