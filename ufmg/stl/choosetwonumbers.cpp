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
    int n, m, bigN = -1, bigM = -1;
    int temp;
        
    cin >> n;
    while(n-- > 0){
        cin >> temp; 
        if(temp > bigN) bigN = temp;
    }
    cin >> m;
    while(m-- > 0){
        cin >> temp;
        if(temp > bigM) bigM = temp;
    }
    cout << bigN << " " << bigM << endl;
    return 0;
} 
