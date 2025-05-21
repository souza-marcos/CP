#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _
    int x, n; cin >> x >> n;
    // Dada uma sequencia crescente como saber qual a maior distancia? 
    multiset<int> lengths;
    set<int> points; points.insert({0, x});
    lengths.insert(x);
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        auto it = points.lower_bound(a);
        
        int end = *it, start = *(-- it);
        lengths.erase(lengths.find(end - start));
        if(a-start > 1) lengths.insert(a-start);
        if(end-start > 1) lengths.insert(end - a);

        points.insert(a);
        cout << (sz(lengths) >= 1 ? *lengths.rbegin() : 1) << " ";
    }
    cout << endl;
    return 0;   
} 
