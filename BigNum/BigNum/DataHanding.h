#include <iostream>
#include <string>

using namespace std;


const string MAX_QInt_str = "170141183460469231731687303715884105727";
const string MIN_QInt_str = "-170141183460469231731687303715884105728";

//Hàm loại chữ số 0 thừa ở đầu
// Input là chuỗi cần loại bỏ
// Output là chuỗi sau khi loại bỏ
string Ease0InHead(string);


//Hàm chia chuỗi string cho 2
//	Input là chuỗi cần chia và tham chiếu số dư
// Output là chuỗi kết quả và sô dư
string DivisionString2(string, int&);


//Hàm nhân chuỗi stirng cho 2
// Input là chuỗi cân nhân
// Output là kết quả
string MulString(string, string);


//Hàm cộng hai chuỗi số thực lớn không âm
//		Input là 2 string số thực
//		Output là tổng cùa 2 string
string AdditionString(string A, string B);



//Hàm mũ 
//Input là số cần mũ và cơ số
//output là đáp án sau khi mũ
string Power(string, int);

//Hàm chuyển số int sang chuỗi
string String(unsigned int);

//Hàm chuyển string sang int
int Int(string);
