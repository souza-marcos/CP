#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'


int main(){_

    double n; cin >> n;
    int cents = n * 100;
    cout << "NOTAS:" << endl;
    cout << cents/10000 << " nota(s) de R$100.00\n";
    cents %= 10000;
    cout << cents/5000 << " nota(s) de R$50.00\n";
    cents %= 5000;
    cout << cents/2000 << " nota(s) de R$20.00\n";
    cents %= 2000;
    cout << cents/1000 << " nota(s) de R$10.00\n";
    cents %= 1000;
    cout << cents/500 << " nota(s) de R$5.00\n";
    cents %= 500;
    cout << cents/200 << " nota(s) de R$2.00\n";
    cents %= 200;
    cout << "MOEDAS:\n";

    cout << cents/100 << " moeda(s) de R$1.00\n";
    cents %= 100;
    cout << cents/50 << " moeda(s) de R$0.50\n";
    cents %= 50;
    cout << cents/25 << " moeda(s) de R$0.25\n";
    cents %= 25;
    cout << cents/10 << " moeda(s) de R$0.10\n";
    cents %= 10;
    cout << cents/5 << " moeda(s) de R$0.05\n";
    cents %= 5;
    cout << cents << " moeda(s) de R$0.01\n";

    return 0;
}