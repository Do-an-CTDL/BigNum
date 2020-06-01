#include "Question.h"


QInt QInt::_one;
QInt QInt::_zero;
QInt QInt::_max;
QInt QInt::_min;

int main(){//int argc, char* argv[]) {
	
	QInt::InitOne();
	QInt::InitZero();
	QInt::InitMAX();
	QInt::InitMin();
	

	Input("input.txt", "output.txt");

	/*ifstream in;
	ofstream out;
	if (argc < 3) {
		cout << "The format must be correct" << endl;
		cout << "Format: <name>.exe <input>.exe <output>.txt" << endl;
		return 0;
	}
	else {
		in.open(argv[1]);
		out.open(argv[2]);
		Input(in, out);

		in.close();
		out.close();
	}*/
	
	

	return 0;

	
}