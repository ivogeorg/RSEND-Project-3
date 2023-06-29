#include <iostream>
using namespace std;

int main() {
	
	//Given P(POS), P(DOOR|POS) and P(DOOR|¬POS)
	double a = 0.0002 ; //P(POS) = 0.002
	double b = 0.6    ; //P(DOOR|POS) = 0.6
	double c = 0.05   ; //P(DOOR|¬POS) = 0.05
	
	//TODO: Compute P(¬POS) and P(POS|DOOR)
	double d = 1 - a;  //P(¬POS) = 1 - P(POS)
	//P(POS|DOOR) = P(DOOR|POS) * P(POS) / (P(DOOR|POS) * P(POS) + P(DOOR|¬POS) * P(¬POS))
	double e = a * b / (a * b + c * d);                  
	
	//Print Result
	cout << "P(POS|DOOR)= " <<    e    << endl;   // P(POS|DOOR)= 0.00239473
	
	return 0;
}
