#include "QInt.h"

QInt QInt::_min;
QInt QInt::_zero;

int main() {
	
	QInt::InitMin();
	QInt::InitZero();

	QInt a;
	QInt b;
	a = "-2000";

	a = ~a;

	a.HexToDec();

	return 0;

	
}