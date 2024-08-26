#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;
int n; 
pair <int, int> arr[MAX];

bool valid(double t){
    double l = -1e9 - 10, r = 1e9 + 10;
    for(int i = 0; i < n; i++){
        l = max(arr[i].first - t * arr[i].second, l);
        r = min(arr[i].first + t * arr[i].second, r);
        if(l >= r) return false;
    }
    return true;
}

int main(){ _
    cout << fixed << setprecision(10);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    double l = 0, r = 1e9 + 10; // chutando no tempo/limite superior
    for(int i = 0; i < 200; i++){
        double m = (l + r)/2.0;
        if(valid(m)) r = m;
        else l = m;
    }

    cout << (l + r)/2.0 << endl;

    return 0;
} 
