#include<iostream>
using namespace std;

int reverseNumber(int num){
	int reversed = 0;
	while(num){  // we reached the end of the digits
        reversed += (num % 10); //add to the ones place
        num /= 10;     //shift to the left

        if(num) reversed *= 10; // shift to the right, but avoid adding an extra
                                // zero at the end.
	}
    return reversed;
}

int main(){
	int numTestCases;
	cin >> numTestCases;
	int a, b;
	int sum;
    for(int i=0; i<numTestCases; i++){
    	cin >> a >> b;
    	sum = reverseNumber(a) + reverseNumber(b);
    	cout << reverseNumber(sum) << "\n";
    }

	
	return 0;
}

