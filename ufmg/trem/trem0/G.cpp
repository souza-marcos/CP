#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

int main(){ _
    int n; cin >> n;
    int a, b, c; a = b = c = 0;
    while(n --){
        int temp; cin >> temp;
        if(temp % 3 == 0) a ++;
        else if(temp % 3 == 1) b ++;
        else c ++;
    }
    cout << a / 2 + min(b, c) << endl;
    return 0;
} 
