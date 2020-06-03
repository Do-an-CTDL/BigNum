#include "Question.h"


QInt QInt::_one;
QInt QInt::_zero;
QInt QInt::_max;
QInt QInt::_min;

int main(int argc, char* argv[]) {
	
	QInt::InitOne();
	QInt::InitZero();
	QInt::InitMAX();
	QInt::InitMin();
	

	//Input("input.txt", "output.txt");

	if (argc < 3) {
		cout << "The format must be correct" << endl;
		cout << "Format: <name>.exe <input>.exe <output>.txt" << endl;
		return 0;
	}
	else {
		
		//Input("input.txt", "output.txt");
		Input(argv[1], argv[2]);
		
	}
	
	

	return 0;

	
}