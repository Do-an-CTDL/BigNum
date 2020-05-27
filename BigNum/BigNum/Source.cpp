#include "Question.h"


QInt QInt::_one;
QInt QInt::_zero;
QInt QInt::_max;

int main() {
	
	QInt::InitOne();
	QInt::InitZero();
	QInt::InitMAX();
	

	Input();
	

	return 0;

	
}