#include <iostream>
using namespace std;
#define endl "\n"

bool isPrime(int x){
	for(int i = 2; i * i<= x; i++)
		if(x%i == 0) return false;
	return true;
}

int main(){
	int n, x;cin >> n;
	while(n-- > 0){
		cin >> x;
		if(isPrime(x)) cout << "Prime" << endl;
		else cout << "Not Prime" << endl;
	}
	return 0;
}
		
