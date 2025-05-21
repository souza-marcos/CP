#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    map<int, int> last;
    int maxv = 0, cur_start = 0;
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        if(last.count(a)){
            cur_start=max(last[a]+1,cur_start);
        }
        last[a] = i;
        maxv = max(maxv, i - cur_start + 1);
    }
    cout << maxv << endl;
    return 0;   
} 
