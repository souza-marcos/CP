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
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        ll soma1 = 0, soma2 = 0;
        for(int i= 1; i <n; i++){
            if(i < n/2 || i == n-1) soma1 += pow(2, i);
            else soma2 += pow(2, i);
        }
        cout << abs(soma1 - soma2) << endl;
    }

    return 0;
} 
