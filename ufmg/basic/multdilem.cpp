#include <iostream>
using namespace std;
#define endl "\n"

bool specialNumber(int n){
	while(n/10 > 0) {
		if(n%10 != 0) return false;
		n /= 10;
	}
	return true;
}

int main(){
	int n, a, b; cin >> n;
	while(n-- > 0){
		cin >> a >> b;
		if(specialNumber(b)){
			int aux = a; a = b; b = aux;
		}
		int c = b % 10;
		cout << c << " x " << a << " + " << b - c << " x " << a << endl;
	}
	return 0;
}

