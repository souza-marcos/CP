#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MAX = 1e6 + 10;

int main(){ _
    vector<int> divs(MAX, 0);
    for(int i = 1; i < MAX; i ++){
        for(int j = i; j < MAX; j += i){
            divs[j] ++;
        }
    }

    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        cout << divs[x] << endl;
    }

    return 0;
} 
