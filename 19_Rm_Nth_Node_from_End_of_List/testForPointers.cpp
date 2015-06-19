#include <iostream>

using namespace std;

int main(){
	int x = 2;
	int *xp = &x;
	if(1){
		int *yp = &x;
	}

	cout << *xp <<endl;
}