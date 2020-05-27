#include "DataHanding.h"


bool isOverFlowDec(string x)
{
	if (x[0] != '-')
	{
		if (x.length() > MAX_QInt_str.length())
			return true;
		if (x.length() < MAX_QInt_str.length())
			return false;
		if (x > MAX_QInt_str)
			return true;
	}
	if (x[0] == '-')
	{
		if (x.length() > MIN_QInt_str.length())
			return true;
		if (x.length() < MIN_QInt_str.length())
			return false;
		if (x > MIN_QInt_str)
			return true;
	}
	return false;
}



//Hàm loại chữ số 0 thừa ở đầu
// Input là chuỗi cần loại bỏ
// Output là chuỗi sau khi loại bỏ
string Ease0InHead(string a) {


	int i = 0;
	if (a[0] == '-')
		i = 1;
	while (i < a.size()) {

		if (a[i] == '0')
			a.erase(0, 1);
		else {
			break;
		}
	}
	string b = a;

	return b;
}

//Hàm chia chuỗi string cho 2
//	Input là chuỗi cần chia và tham chiếu số dư
// Output là chuỗi kết quả và sô dư
string DivisionString2(string a, int& balance) {

	a = Ease0InHead(a);
	string m_Balance;
	string Res;
	
	for (int i = 0; i < a.size(); i++) {

		m_Balance += a[i];
		Res += stoi(m_Balance) / 2 + '0';
		m_Balance = stoi(m_Balance) % 2 + '0'; //Lấy số dư còn lại

		if (m_Balance == "0") //Nếu dư 0
			m_Balance = "";
	}

	//Xóa những kí tự 0 thừa ở đầu
	Res = Ease0InHead(Res);
	if (m_Balance == "")
		balance = 0;
	else
		balance = 1;

	return Res;
}



string MulString(string a, string b) {



	//nếu 1 trong 2 = 0 thì kq = 0
	if (a == "" || b == "")
		return "0";


	if (a == "1")
		return b;
	if (b == "1")
		return a;

	a = Ease0InHead(a);
	a = Ease0InHead(b);
	
	string res = "0";

	int sizeA = a.size();
	int sizeB = b.size();
	int j;

	string tmp = "0", tmp2 = "0";

	for (int iB = b.size() - 1; iB >= 0; iB--){
		j = tmp.length() - 1;
		for (int iA = a.size() - 1; iA >= 0; iA--){
			unsigned int mul = tmp[j] - '0' + (a[iA] - '0') * (b[iB] - '0');
			tmp[j++] = (mul % 10) + '0';
			tmp = char((mul / 10) + '0') + tmp;
		}

		/*for (int i = 0; i < tmp.size() / 2; i++){
			swap(tmp[i], tmp[tmp.length() - i - 1]);
		}*/
		res = AdditionString(res, tmp);
		tmp = tmp2 + "0";
		tmp2 = tmp;
	}


	return res;

}

//Hàm cộng hai chuỗi số thực lớn không âm
//		Input là 2 string số thực
//		Output là tổng cùa 2 string
string AdditionString(string A, string B)
{
	A = Ease0InHead(A);
	B = Ease0InHead(B);
	bool isFloat = 0;
	int posA;
	int posB;

	string result = "";
	int j = 0;
	
	posA = A.length();
	posB = B.length();

	while (posA < posB)
	{
		A = "0" + A;
		posA++;
	}
	while (posB < posA)
	{
		B = "0" + B;
		posB++;
	}


	for (j = 0; j < A.length(); result += "0", j++);
	for (int i = A.length() - 1; i >= 0; i--)
	{
		int sum = (result[i] - '0') + (A[i] - '0') + (B[i] - '0');
		result[i] = (sum % 10) + '0';
		if (i > 0)
			result[i - 1] = (sum / 10) + '0';
		else
			result = to_string(sum / 10) + result;
	}

	result = Ease0InHead(result);

	return result;
}


//Hàm mũ 
//Input là số cần mũ và cơ số
//output là đáp án sau khi mũ
string Power(string a, int x) {

	a = Ease0InHead(a);
	if (x == 0)
		return "1";
	string res = "1";

	for (int i = 0; i < x; i++) {
		//res = Ease0InHead(res);
		res = MulString(res, a);
	}
	return res;
}


//Hàm chuyển từ số sang chuỗi
string String(unsigned int a) {

	string tmp;
	while (a) {

		tmp = char(a % 10 + '0') + tmp;
		a /= 10;
	}

	return tmp;
}


//hàm chuyển string sang int
int Int(string a) {

	int res = 0;
	int x = 1;
	for (int i = int(a.size() - 1); i >= 0; i--){
		
		res += (a[i] - '0') * x;
		x *= 10;
	}

	return res;
}