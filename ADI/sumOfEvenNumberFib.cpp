#include <iostream>

using namespace std;

int sumOfEvenFib(int n){
	int a = 1;
	int b = 1;
	int sum = 0;
	while(b<=n) {
	   if( b % 2 == 0 ) {
	      sum += b;
	   }
	   int c = a+b;
	   a = b;
	   b = c;
	}

	return sum;
}


int main (int argc, char *argv[]) {
	
	if(argc < 2){
	   printf("Pass the number n");
	   exit(1);
	}

	int n = atoi(argv[1]);

	cout << sumOfEvenFib(n) << endl;

	return 0;
}
