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

//Khởi tạo bảng min
void QInt::InitMin() {

	_min._data[0] = 1;
	_min._data[1] = 0;
	_min._data[2] = 0;
	_min._data[3] = 0;
}


QInt::QInt(string a, int baseIn, int baseOut) {

	//0: nhị phân
	//1: dec
	//2: hex
	int checkBase; 

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

// Hàm cài bit vao vị trí pos
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
	*this =  *this + _min;
}

//Hàm Chuyển từ dữ liệu đầu vào sang dữ liệu quy ước
// Input là chuỗi string chứa dữ liệu và flag chỉ 1: chuỗi số nguyên, 0 : chuỗi nhị phân, 2: chuỗi hex
void QInt::ConvertInputtoData(string a , int flag) {


	*this = _zero;
	if (flag == 0) {
		
		for (int i = 0; i < a.length(); i++)
		{
			SetBit(a[a.size() - i - 1] - '0', i);
		}

	}
	else
		if (flag == 1){
			//Kiem tra co la so am khong
			bool checkNagative = 0;

			if (a[0] == '-') {
				checkNagative = 1;
				a.erase(0, 1);
			}

			//lien tuc chia cho 2
			int balance = 0; //so du
			int pos = 0; // vị trí cần set bit
			while (a != "" )
			{	

				a = DivisionString2(a, balance);
				SetBit(balance, pos++);
			}

			if (checkNagative) {

				ConvertOpposite2();
			}


		}
		else {
			//hex
			int pos = 0; //vi tri set bit
			for (int i = 0; i < a.size(); i++) {

				string hextobin = ConvertHexToBin(a[i]);

				for (int j = 3; j >= 0; j--) {

					SetBit(hextobin[j] - '0', pos++);
				}
			}
		}
 
}
char QInt::ConvertDecToHex(string a) {

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
			char Get10to16 = ConvertDecToHex(Get4bit);
			Res = Get10to16 + Res;
		}


	}

	cout << Res;

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

//------------------------------TOÁN TỬ------------------------------//

//Toán tử not
QInt QInt::operator~() {


	for (int i = 0; i < Size_charater * Size_Num; i++) {

		SetBit(1 - GetBit(i), i);
	}

	return *this;
}


//Toán tử gán bằng
QInt QInt::operator =(string a) {

	//0: nhị phân
	//1: dec
	//2: hex
	int check = 0; 
	for (int i = 0; i < a.size(); i++) {

		if (a[i] == '-')
			continue;
		if (a[i] != '1' && a[i] != '0')
			if (a[i] >= 'A' && a[i] <= 'F')
				check = 2;
			else
				check = 1;
	}
	


	ConvertInputtoData(a, check);

	return *this;
}

//Toán tử cộng
QInt QInt::operator + (QInt& a) {

	bool  remember = 0;
	int res_add;
	QInt C;
	for (int i = 0; i < Size_charater*Size_Num ; i++)
	{
		//lấy 2 bit tương ứng ở vị trí của nhau
		bool bitofa = a.GetBit(i);
		bool bitofb = GetBit(i);
		res_add = int(bitofa) + int(bitofb) + int(remember);
		switch (res_add)
		{
		case 3: remember = 1; SetBit(1, i); break;
		case 2: remember = 1; SetBit(0, i); break;
		case 1: remember = 0; SetBit(1, i); break;
		case 0: remember = 0; SetBit(0, i); break;
		default:
			break;
		}
	}
	

	return *this;
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
	for (int i = 0; i < Size_charater * Size_Num; i++)
	{
		res. SetBit(GetBit(i + sl), i );
	}
	return res;
}

//Toán Tử dịch trái
QInt QInt::operator<<(int sl) {

	QInt res = _zero;
	for (int i = 0; i < Size_charater * Size_Num; i++)
	{
		SetBit(GetBit(Size_charater *Size_Num - 1 - i - sl), Size_charater * Size_Num - i - 1);
	}


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
	SetBit(bit, Size_charater * Size_Num);

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