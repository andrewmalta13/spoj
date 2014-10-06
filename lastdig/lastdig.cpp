// 8/25/14 Andrew Malta initial coding


/*Nestor was doing the work of his math class about three days
but he is tired of make operations a lot and he should deliver 
his task tomorrow. His math’s teacher gives two numbers a and b. 
The problem consist in find the last digit of the potency of base
a and index b. Help Nestor with his problem. You are given two 
integer numbers: the base a (0 <= a <= 20) and the index
b (0 <= b <= 2,147,483,000), a and b both are not 0. You have to 
find the last digit of a^b. */
#include<iostream>
#include<cmath>
using namespace std;

//main function to conpute t cases of finding the last digit of
// a to the b power.


//function definitions
int lastDigit(int a, int b);

int main(){
  int t;  // number of test cases that are inputed
  int a, b; //used by the lastDigit function to compute the a^b.
  cin >> t;

  if(t > 30) return 0; //exit the main, the num of test cases is too high

  for(int i = 0; i < t; i++){
     cin >> a >> b;
     cout << lastDigit(a, b) << endl;
  }

}


//Module not complete (works for fairly small numbers. Have to figure out a
//a mathematical way to make this easy for computation. Probably something to do
//with prime factorization.œ
//Aaron dropped some knowledge about fermat's little theorem.
int lastDigit(int a, int b){

   int result = pow(a, b);

   return(result % 10);   // get the last digit.
}

