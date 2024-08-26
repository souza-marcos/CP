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
    map <string, int> dict;
    while(n --){
        string temp; cin >> temp;
        dict[temp] += 1;
        int size = dict[temp];

        if(size == 1) cout << "OK" << endl;
        else cout << temp << size -1 << endl;
    }
    return 0;
} 
