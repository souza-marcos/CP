#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
//#define f first
//#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n;cin >> n;
    string s; cin >> s;
    int found = -1;
    int count = 0;
    do{
        found = s.find("z", found + 1);
        if(found != string::npos) count ++;
    }while(found != string::npos);
    
    int one = (s.size() - count * 4)/3;
    while(one-- > 0) cout << "1 ";
    while(count-- > 0) cout << "0 ";
    cout << endl;

    return 0;
} 
