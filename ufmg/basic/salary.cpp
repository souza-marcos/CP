#include <iostream>
 
using namespace std;
 
int main() {
 
    int a, b; cin >> a >> b;
    double s; cin >> s;
    cout.precision(2);
    cout << "NUMBER = " << a << "\n";
    cout << "SALARY = U$ " << fixed << (b * s) << "\n";
 
    return 0;
}