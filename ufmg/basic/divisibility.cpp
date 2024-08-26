#include <iostream>
using namespace std;
#define endl "\n"
int main(){
	int t, a, b;
	cin >> t;
	while(t-- > 0){
		cin >> a >> b;
		cout << a - (a/b + 1)*b << endl;
	}
	return 0;
}

