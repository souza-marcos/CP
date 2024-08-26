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
    long long n, m, a; cin >> n >> m >> a;
    long long res = ceil(n/(double)a) * ceil(m/(double)a);
    cout << res << endl;


    return 0;
} 
