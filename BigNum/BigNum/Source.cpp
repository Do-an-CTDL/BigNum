#include "Question.h"


QInt QInt::_one;
QInt QInt::_zero;
QInt QInt::_max;

int main() {
	
	QInt::InitOne();
	QInt::InitZero();
	QInt::InitMAX();
	QInt::InitMin();
	

	Input();
	

	return 0;

	
}