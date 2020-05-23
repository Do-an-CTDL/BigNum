#include "Question.h"


//Hàm đọc dữ liệu từ file
void Input() {

	ifstream In("input.txt");

	while (!In.eof()) {

		string s;
		string res;
		getline(In, s);


		res = Solve(s);

	}



}


//Kiểm tra chuỗi đâu vào có phải chỉ thị hay không
bool checkQuestion(string Q1) {

	if (Q1 == "10")
		return 1;
	if (Q1 == "16")
		return 1;
	if (Q1 == "2")
		return 1;

	return 0;
}


//Kiểm tra xem đầu vào là toán hạng gì
int CheckOperand(string  a) {

	if (a == "=")
		return 1;
	if (a == "~")
		return 2;
	if (a == "rol")
		return 3;
	if (a == "ror")
		return 4;


	if (a == ">>")
		return 5;
	if (a == "<<")
		return 6;
	if (a == "+")
		return 7;
	if (a == "-")
		return 8;
	if (a == "*")
		return 9;
	if (a == "/")
		return 10;
	return 0;
}


//Hàm xử lý đầu vào và trả về kết quả
string Solve(string s) {

	//kiểu xuất (hệ số)
	int Out;

	//Kiểu nhập
	int input;

	stringstream ss(s);

	string Q1, Q2; //Giả sử nó có 2 question

	//Giả sử lấy 2 chỉ thị
	ss >> Q1;
	ss >> Q2;

	//Kiếm tra xem có phải 2 chỉ thị hay không
	int CountQuestion = checkQuestion(Q1) + checkQuestion(Q2);
	input = atoi(Q1.c_str());
	
	if (CountQuestion == 2) {	

		Out = atoi(Q2.c_str());
	}
	else {

		Out = atoi(Q1.c_str());
	}



	//Trường hợp chỉ có 1 chỉ thị trừ chỉ thị + - * /

	//Kiểm tra xem nó là toán hạng gì

	int operand = CheckOperand(Q2);

	if (operand != 0 && operand <= 4) {

		//Đọc dữ liệu
		string x;
		ss >> x;
		QInt a(x, atoi(Q1.c_str()), atoi(Q2.c_str()));

		if (operand == 2)
			a = ~a;
		if (operand == 3)
			a.ROL();
		if (operand == 4)
			a.ROR();

		
	}

	//Trường hợp là các toán tử cộng trừ nhân chia 
	string Q3;
	ss >> Q3;
	int operand = CheckOperand(Q3);
	if (operand != 0 && operand > 4) {


	}


	return "";
}

