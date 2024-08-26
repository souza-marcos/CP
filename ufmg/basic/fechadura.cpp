#include <iostream>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

int main(){ _
    int n, m; cin >> n >> m;
    int arr[n];
    for(auto& el: arr) cin >> el;

    int cont = 0;
    for(int i = 0; i < n - 1; i++){
        int mov = m - arr[i];
        arr[i + 1] += mov;
        cont += abs(mov);
    }
    cont += abs(m - arr[n - 1]);
    cout << cont << endl;
    return 0;
} 
