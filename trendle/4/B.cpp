#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 
    int a, b, c; cin >> a >> b >> c;


    auto test = [&](int x, int y) -> int {
        if(a%x == 0 and c%y == 0){
            if((a/x) * y == c) return a/x;
        }
        if(a%y == 0 and c%x == 0){
            if((a/y) * x == c) return a/y;
        }
        return -1;
    };

    for(int i = 1; i <= b; i ++){
        if(b%i == 0){
            auto val = test(i, b/i);
            if(val == -1) continue;
            int x = i, y = b/i, z = val; 
            cout << 4*x + 4 * y + 4 * z << endl;
            return 0;
        }
    }

} 
