#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

typedef long long ll;

int main(){_

    int n; cin >> n;
    string s; cin >> s;

    string cmp1 = "RBG", cmp2 = "RGB";
    for(ll i = 3; i < n; i *= 2){
        cmp1 = cmp1 + cmp1;
        cmp2 = cmp2 + cmp2;
    }

    cmp1 += "RBG"; cmp2 += "RGB";

    int diff1[3], diff2[3];
    memset(diff1, 0, sizeof(diff1));
    memset(diff2, 0, sizeof(diff2));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            if(s[i] != cmp1[i + j]) diff1[j] ++;
            if(s[i] != cmp2[i + j]) diff2[j] ++;
        }
    }

    int difcount = INF;
    for(int j = 0; j < 3; j++){
        difcount = min(difcount, diff1[j]);
        difcount = min(difcount, diff2[j]);
    }

    cout << difcount << endl;

    for(int j = 0; j < 3; j++){
        if(diff1[j] == difcount){
            for(int i = j; i < n + j; i++) cout << cmp1[i];
            cout << endl;
            exit(0);
        }
        if(diff2[j] == difcount){
            for(int i = j; i < n + j; i++) cout << cmp2[i];
            cout << endl;
            exit(0);
        }
    }

    return 0;
}