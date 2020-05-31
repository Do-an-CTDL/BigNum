#pragma once
#include "QInt.h"

void QInt::InitZero() {

	_zero._data[0] = 0;
	_zero._data[1] = 0;
	_zero._data[2] = 0;
	_zero._data[3] = 0;
}


//Khởi tạo bảng max
void QInt::InitMAX() {

	_max._data[0] = UINT_MAX;
	_max._data[1] = UINT_MAX;
	_max._data[2] = UINT_MAX;
	_max._data[3] = UINT_MAX - pow(2, 31);

}

//Khởi tạo số 1
void QInt::InitOne() {

	_one._data[0] = 1;
	_one._data[1] = 0;
	_one._data[2] = 0;
	_one._data[3] = 0;

}

void QInt::InitMin() {
	_min._data[0] = 0;
	_min._data[1] = 0;
	_min._data[2] = 0;
	_min._data[3] = 0;

	_min.SetBit(1, Size_charater * Size_Num - 1);
}


//Khơi tạo tham số mặc định
QInt::QInt() {

	_data[0] = 0;
	_data[1] = 0;
	_data[2] = 0;
	_data[3] = 0;
	_base = 2;
}

int QInt::GetnBit() {

	int dem = 0;
	for (int i = Size_charater * Size_Num - 1; i >= 0; i--)
		if (GetBit(i))
			break;
		else
			dem++;

	return Size_charater * Size_Num - dem;
}


//Lấy hệ số đích
int QInt::GetBase() {

	return _base;
}



QInt::QInt(string a, int baseIn, int baseOut) {

	//0: nhị phân
	//1: dec
	//2: hex
	int checkBase = 0; 

	if (baseIn == 2)
		checkBase = 0;
	if (baseIn == 10)
		checkBase = 1;
	if (baseIn == 16)
		checkBase = 2;

	ConvertInputtoData(a, checkBase);

	_base = baseOut;
}

// Hàm lấy bit tại vị tri pos
	//	 Input là vị trí cần lấy bit
	//	 Ouput là Bit tại vị trí pos
bool QInt::GetBit(int pos) {
	
	if (pos < 0 || pos >= Size_Num * Size_charater)
		return 0;
	return (_data[pos / Size_charater] >> (pos % Size_charater)) & 1;
}

// Hàm cài bit vào vị trí pos
	//	Input là vị trí nạp bit
void QInt::SetBit(bool ValuesBit, int pos) {

	if (pos < 0 || pos >= Size_Num * Size_charater)
		return ;

	//Set bit
	if (!ValuesBit) {
		if (GetBit(pos))
		_data[pos / Size_charater] = _data[pos / Size_charater] ^ (1 << (pos % Size_charater));
	}
	else
		_data[pos / Size_charater] = (1 << (pos % Size_charater)) | _data[pos / Size_charater];	
}

//Chuyển sang số bù 2
void QInt::ConvertOpposite2() {

	~*this;
	*this =  *this + _one;
}

//Hàm Chuyển từ dữ liệu đầu vào sang dữ liệu quy ước
// Input là chuỗi string chứa dữ liệu và flag chỉ 1: chuỗi số nguyên, 0 : chuỗi nhị phân, 2: chuỗi hex
void QInt::ConvertInputtoData(string a, int flag) {


	*this = _zero;

	if (flag == 0) {

			for (int i = 0; i < a.length(); i++) {
				SetBit(a[a.size() - i - 1] - '0', i);
			}
			
	}

	if (flag == 1) {
		//Kiem tra co la so am khong
		bool checkNagative = 0;

		if (a[0] == '-') {
			checkNagative = 1;
			a.erase(0, 1);
		}

		//lien tuc chia cho 2
		int balance = 0; //so du
		int pos = 0; // vị trí cần set bit
		while (a != "") {
			a = DivisionString2(a, balance);
			SetBit(balance, pos++);
		}

		if (checkNagative) {
			ConvertOpposite2();
		}
	}

	if (flag == 2){

		//hex
		int pos = 0; //vi tri set bit
		for (int i = a.size() - 1; i >=0; i--) {

			string hextobin = ConvertHexToBin(a[i]);

			for (int j = 3; j >= 0; j--) {

				SetBit(hextobin[j] - '0', pos++);
			}
		}
	}
}
 


char QInt::ConvertBinToHex(string a) {

	//chuyen chuoi thanh so de tien viec so sanh
	int x = atoi(a.c_str());

	switch (x)
	{
	case 1010:
		return 'A';
		break;
	case 1011:
		return 'B';
		break;
	case 1100:
		return 'C';
		break;
	case 1101:
		return 'D';
		break;
	case 1110:
		return 'E';
		break;
	case 1111:
		return 'F';
		break;
	case 1:
		return '1';
		break;
	case 10:
		return '2';
		break;
	case 11:
		return '3';
		break;
	case 100:
		return '4';
		break;
	case 101:
		return '5';
		break;
	case 110:
		return '6';
		break;
	case 111:
		return '7';
		break;
	case 1000:
		return '8';
		break;
	case 1001:
		return '9';
		break;
	default:
		break;
	}

	return '0';
}

string QInt::ConvertHexToBin(char x)
{
	
	switch (x)
	{
	case '0': 
		return "0000";
		break;
	case '1':
		return "0001";
		break;
	case '2':
		return "0010";
		break;
	case '3':
		return "0011";
		break;
	case '4':
		return "0100";
		break;
	case '5':
		return "0101";
		break;
	case '6':
		return "0110";
		break;
	case '7':
		return "0111";
		break;
	case '8':
		return "1000";
		break;
	case '9':
		return "1001";
		break;
	case 'A':
		return "1010";
		break;
	case 'B':
		return "1011";
		break;
	case 'C':
		return "1100";
		break;
	case 'D':
		return "1101";
		break;
	case 'E':
		return "1110";
		break;
	case 'F':
		return "1111";
		break;
	default:
		break;
	}

	return "0";
}


//Hàm chuyển từ hệ 10 sang hệ 2
	//	Input là đối tương cần chuyển
	//	output là chuỗi string hệ 2
string QInt::DecToBin() {

	string res;
	for (int i = 0; i < Size_Num * Size_charater; i++) {

		res = char(GetBit(i) + '0') + res;
	}

	res = Ease0InHead(res);

	return res;
}


//Hàm chuyển từ hệ 2 sang hệ 10
	//	Input là đối tương cần chuyển
	//	output là chuỗi string hệ 10
string QInt::BinToDec() {

	bool sign = 0;
	if (GetBit(Size_charater * Size_Num - 1)) {
		sign = 1;
		ConvertOpposite2();
	}


	string res;
	for (int i = 0; i <  Size_Num; i++)
	{
		res = AdditionString(res, MulString(String(_data[i]), Power("2", Size_charater * i)));
	}

	if (sign)
		res = "-" + res;

	return res;
}



//Hàm chuyển từ hệ 10 sang hệ 16
	// Input là đối tượng cần chuyển
	// output là chuỗi string hệ 16
string QInt::DecToHex() {

	QInt tmp = *this;
	string Res;
	for (int i = 0; i < Size_Num; i++) {

		//lay het so bit 
		while (tmp._data[i]) {
			
			//Lay 4 bit lien tiep
			string Get4bit ;
			for (int j = 0; j < 4; j++) {

				if (tmp._data[i]) {
					Get4bit = char(int(tmp.GetBit(i*Size_charater) + '0')) + Get4bit;
					tmp._data[i] >>= 1;
				}
			}
			char Get10to16 = ConvertBinToHex(Get4bit);
			Res = Get10to16 + Res;
		}


	}


	return Res;
}

//Chuyển binary sang hex
	//	Vì data được convert về gốc => làm tương tư dec to hex
	// Input là đối tượng cần chuyển
	// output là chuỗi string hệ 16
string QInt::BinToHex()
{
	
	QInt tmp = *this;
	string Res;
	for (int i = 0; i < Size_Num; i++) {

		//lay het so bit 
		while (tmp._data[i]) {

			//Lay 4 bit lien tiep
			string Get4bit;
			for (int j = 0; j < 4; j++) {

				if (tmp._data[i]) {
					Get4bit = char(int(tmp.GetBit(i * Size_charater) + '0')) + Get4bit;
					tmp._data[i] >>= 1;
				}
			}
			char Get10to16 = ConvertBinToHex(Get4bit);
			Res = Get10to16 + Res;
		}


	}


	return Res;
}

//Chuyển chuỗi hex sang dec
// Chuỗi hex đã được đưa vào data bây giờ chỉ cần chuyển theo data là xong
string QInt::HexToDec() {

	QInt tmp = *this;
	
	string res; // kêt quả
	string Pow = "1";
	for (int i = 0; i < Size_Num; i++) {

		//cho code he 2

	}

	for (int i = 0; i < res.size(); i++) {


		cout << res[i];
	}

	return "0";
}


//Chuyển chuỗi hex sang bin
	// Chuỗi hex đã được đưa vào data bây giờ chỉ cần chuyển theo data là ra bin
	// nên thuật toán y hệt như dec to bin
string QInt::HexToBin() {

	return DecToBin();
}
//------------------------------TOÁN TỬ------------------------------//

//Toán tử not
QInt QInt::operator~() {


	for (int i = 0; i < Size_charater * Size_Num; i++) {

		SetBit(1 - GetBit(i), i);
	}

	return *this;
}


//Toán tử bằng
bool QInt::operator ==(QInt a) {
	for (int i = 0; i < Size_Num; i++) {
		if (_data[i] != a._data[i]) {
			return 0;
		}
	}
	return 1;
}

//Toán tử cộng
QInt QInt::Add(QInt& a, QInt& b, bool& bit) {
	QInt result = _zero;
	result._base = a._base;

	bool  remember = 0;
	int res_add;
	for (int i = 0; i < Size_charater * Size_Num; i++)
	{
		//lấy 2 bit tương ứng ở vị trí của nhau
		bool bitofa = a.GetBit(i);
		bool bitofb = b.GetBit(i);
		res_add = int(bitofa) + int(bitofb) + int(remember);
		switch (res_add)
		{
		case 3: remember = 1; result.SetBit(1, i); break;
		case 2: remember = 1; result.SetBit(0, i); break;
		case 1: remember = 0; result.SetBit(1, i); break;
		case 0: remember = 0; result.SetBit(0, i); break;
		default:
			break;
		}
	}
	bit = remember;
	return result;
}

QInt QInt::operator + (QInt& a) {
	 
	QInt result = _zero;
	result._base = _base;


	bool  remember = 0;
	int res_add;
	for (int i = 0; i < Size_charater*Size_Num ; i++)
	{
		//lấy 2 bit tương ứng ở vị trí của nhau
		bool bitofa = a.GetBit(i);
		bool bitofb = GetBit(i);
		res_add = int(bitofa) + int(bitofb) + int(remember);
		switch (res_add)
		{
		case 3: remember = 1; result.SetBit(1, i); break;
		case 2: remember = 1; result.SetBit(0, i); break;
		case 1: remember = 0; result.SetBit(1, i); break;
		case 0: remember = 0; result.SetBit(0, i); break;
		default:
			break;
		}
	}

	//Kiem tra du
	if (remember != 0) {
		result._data[0] = 0;
		result._data[1] = 0;
		result._data[2] = 0;
		result._data[3] = 0;

	}

	return result;
}

//Toán tử trừ
QInt QInt::operator- (QInt& a) {
	a.ConvertOpposite2();
	return (*this + a);
}

//Toán tử nhân
//Thực hiện phép nhân M * Q
QInt QInt::operator*(QInt b) {
	bool remember = 0; //Bit nhớ phụ
	QInt A = _zero; //Mảng nhớ phụ

	QInt res = _zero; //Kết quả phép nhân
	A._base = res._base = _base;

	bool sign = 0; //Bit dấu 
	//Check dấu kết quả
	if (this->GetBit(Size_charater * Size_Num - 1) != b.GetBit(Size_charater * Size_Num - 1)) {
		sign = 1; //Hai số trái dấu nhau thì kết quả sẽ là 1 số âm
	}

	//Lưu hai thừa số vào 2 biến M, Q để tránh mất dữ liệu
	QInt M = *this; 
	QInt Q = b;
	if (M.GetBit(Size_charater * Size_Num - 1) == 1) {
		M.ConvertOpposite2(); //Nếu là số âm thì chuyển lại thành số dương
	}
	if (Q.GetBit(Size_charater * Size_Num - 1) == 1) {
		Q.ConvertOpposite2(); //Nếu là số âm thì chuyển lại thành số dương
	}

	int demNhan = 0; // Dem so lan da nhan
	//Bắt đầu thực hiện phép nhân
	for (int i = Size_charater * Size_Num; i > 0; i--) {
		bool tmp = Q.GetBit(0); //Dùng để lưu trữ bit phải nhất của Q
		if (tmp) {
			QInt Tmp = M;
			Tmp = Tmp << demNhan;
			A = Add(A, Tmp, remember); //Nếu bit cuối của Q = 1 thì lấy [A+M] -> [remember,A]
		}
		Q = Q.SHR(1);
		demNhan++;
	}

	//Check tràn số
	/*if (A == _zero && remember == 0) {
		res = Q;
	}*/
	//Kiểm tra dấu của phép nhân
	if (sign == 1) {
		A.ConvertOpposite2();
	}

	return A;

}

//Toán tử chia
//Thực hiện phép tính Q/M 
//Q là số bị chia Dividend, M là số chia divisor
QInt QInt::operator/(QInt b) {
	//Kiểm tra TH tràn
	//Khi -128/-1 = 128 => Tràn số

	QInt check_128 = _min; 	//Tạo số -128
	//Tạo số -1
	QInt check_1 = _one;
	check_1.ConvertOpposite2();

	if (*this == check_128 && b == check_1) {
		QInt res = _zero;
		return res;
	}

	bool sign = 0; //Bit dấu 
	//Check dấu kết quả
	if (this->GetBit(Size_charater * Size_Num - 1) != b.GetBit(Size_charater * Size_Num - 1)) {
		sign = 1; //Hai số trái dấu nhau thì kết quả sẽ là 1 số âm
	}

	//Lưu hai thừa số vào 2 biến M, Q để tránh mất dữ liệu
	QInt Q = *this;
	QInt M = b;
	if (M.GetBit(Size_charater * Size_Num - 1) == 1) {
		M.ConvertOpposite2(); //Nếu là số âm thì chuyển lại thành số dương
	}
	if (Q.GetBit(Size_charater * Size_Num - 1) == 1) {
		Q.ConvertOpposite2(); //Nếu là số âm thì chuyển lại thành số dương
	}

	int nbit = M.GetnBit(); //Số bit biểu diễn của số M
	QInt res = _zero; //Biến kết quả
	QInt oposite = M; // Khởi tạo số đối của M 
	oposite.ConvertOpposite2();

	QInt A = Q; //Gán A = Q
	A = A.SHR(Size_charater * Size_Num - nbit); //Lấy nbit đầu từ trái sang của Q
	Q = Q << (nbit); //Dịch Q đi nbit
	for (int i = 0; i <= Size_charater * Size_Num - nbit; i++) {
		bool remember = 0;
		QInt tmp = _zero;
		tmp = Add(A, oposite, remember); //Lấy A - M
		//Lấy bit dấu của kết quả
		//Nếu là 0 tức là A > M và ngược lại
		if (tmp.GetBit(Size_charater * Size_Num - 1) == 0) { 
			A = tmp; //Gán kết quả vào mảng A
			res = res << (1);
			res.SetBit(1, 0);
		}
		else {
			res = res << (1);
			res.SetBit(0, 0);
		}
		A = A << 1;
		A.SetBit(Q.GetBit(Size_charater * Size_Num - 1), 0);
		Q = Q << 1;
	}

	if (sign == 1) {
		res.ConvertOpposite2();
	}
	res._base = _base;
	return res;
}

//Toán tử and
QInt QInt::operator&(QInt& a)
{

	//lấy từng bit ra và and với bit còn lại
	for (int i = 0; i < Size_charater * Size_Num; i++) {

		bool bita = a.GetBit(i);

		SetBit(GetBit(i) & bita, i);

	}

	return *this;

}

//Toán tử or
QInt QInt::operator | (QInt& a)
{

	//lấy từng bit ra và and với bit còn lại
	for (int i = 0; i < Size_charater * Size_Num; i++) {

		bool bita = a.GetBit(i);

		SetBit(GetBit(i) | bita, i);

	}

	return *this;

}

//Toán tử XOR
QInt QInt::operator ^ (QInt& a)
{

	//lấy từng bit ra và and với bit còn lại
	for (int i = 0; i < Size_charater * Size_Num; i++) {

		bool bita = a.GetBit(i);

		SetBit(GetBit(i) ^ bita, i);

	}

	return *this;

}

//Toán tử dịch phải
QInt QInt::operator >>(int sl) {

	QInt res = _zero;
	res._base = _base;


	if (sl >= Size_charater * Size_Num) {
		return res;
	}
	bool sign = GetBit(Size_charater * Size_Num - 1);

	//Nếu dịch hơn 128 bit thì chuỗi bit thu được là 0000 hoặc 1111 tùy thuộc vào bit dấu
	if (sl >= Size_charater * Size_Num) {
		//Nếu là  số âm thì là dãy 1111 và ngược lại
		if (sign == 1) { 
			for (int i = 0; i < Size_charater * Size_Num; i++) {
				res.SetBit(1, i);
			}
		}
		return res;

	}
	for (int i = sl; i < Size_charater * Size_Num; i++)
	{
		res.SetBit(GetBit(i), (i - sl));
	}
	//Moi lan set 1 bit
	for (int i = Size_charater * Size_Num - sl; i < Size_charater * Size_Num; i++)
	{
		res.SetBit(sign, i);
	}
	
	return res;
}

QInt QInt::SHR(int sl) {
	QInt res = _zero;
	res._base = _base;


	//Nếu dịch từ 128 bit trở lên thì kết quả trả về là dãy bit 0
	if (sl >= Size_charater * Size_Num) {
		return res;
	}

	for (int i = sl; i < Size_charater * Size_Num; i++)
	{
		res.SetBit(GetBit(i), (i - sl));
	}
	//Các bit còn lại bên trái chưa được set sẽ mặc định là bit 0 (đúng tính chất dịch trái)

	return res;
}

//Toán tử dịch trái
QInt QInt::operator<<(int sl) {
	QInt res = _zero;

	//Nếu dịch từ 128 bit trở lên thì kết quả trả về là dãy bit 0
	if (sl >= Size_charater * Size_Num) {
		return res;
	}

	for (int i = 0; i < Size_charater * Size_Num - sl; i++)
	{
		res.SetBit(GetBit(Size_charater * Size_Num - 1 - i - sl), Size_charater * Size_Num - 1 - i);
	}
	//Các bit còn lại bên phải chưa được set sẽ mặc định là bit 0 (đúng tính chất dịch trái)

	return res;
}



//---------------KẾT THÚC CÁC HÀM TOÁN TỬ-----------------------------//

//hàm xoay phai bit
// hàm trả về đối tượng sau khi được xoay phải
QInt QInt::ROR()
{
	
	//Lấy bit phải nhất
	bool bit = GetBit(0);
	
	//Đôn bit lên sang phải 1 đơn vị
	for (int i = 0; i < Size_charater *Size_Num - 1; i++)
	{
		bool bitNext = GetBit(i + 1);
		SetBit(bitNext, i);
	}

	//Set bit trái nhất thành bit phải nhất
	SetBit(bit, Size_charater * Size_Num - 1);

	return *this;
}

//Hàm xoay trái bit
//hàm trả về kết quả sau khi xoay trái
QInt QInt::ROL() {


	//Lấy bit trái nhất
	bool bit = GetBit(Size_charater * Size_Num);

	//Đôn bit lên sang trái 1 đơn vị
	for (int i = Size_charater * Size_Num - 1; i >= 0; i--)
	{
		bool bitNext = GetBit(i - 1);
		SetBit(bitNext, i);
	}

	//Set bit trái nhất thành bit phải nhất
	SetBit(bit, 0);

	return *this;
}

