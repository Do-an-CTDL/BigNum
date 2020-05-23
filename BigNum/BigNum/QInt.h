#pragma once


#include "DataHanding.h"

using namespace std;


#define Size_Num 4

// Kích thước mỗi số trong mảng
#define Size_charater 32


// Đối tượng của bigNum
// 128 bit -> 4x 32 bit để quản lý
class QInt {
public:
	static void InitZero();
	static void InitMin();
	static void InitMAX();
	static QInt _zero, _min, _max;

private:

	unsigned int _data[Size_Num];

	//Cơ số biểu diễn cuối cùng
	int _base;

public:

	//hàm khởi tạo 3 đối số
	//chuỗi dữ liệu, base đầu vào, base đầu ra
	QInt(string, int, int);

	// Hàm lấy bit tại vị tri pos
	//	 Input là vị trí cần lấy bit
	//	 Ouput là Bit tại vị trí pos
	bool GetBit(int pos);

	// Hàm cài bit vao vị trí pos
	//	Input là vị trí nạp bit
	void SetBit(bool, int);

	void ConvertOpposite2();


	//Hàm Chuyển từ dữ liệu đầu vào sang dữ liệu quy ước
	// Input là chuỗi string chứa dữ liệu và flag chỉ 1: chuỗi số nguyên, 0 : chuỗi nhị phân
	void ConvertInputtoData(string, int);

	//Hàm chuyển từ hệ 10 sang hệ 16
	// Input là đối tượng cần chuyển
	// output là chuỗi string hệ 16

	static char ConvertDecToHex(string);

	//Bảng chuyển đổi kí tự dec sang hex
	static string ConvertHexToBin(char);

	string DecToHex();

	//Chuyển chuỗi hex sang dec
	// Chuỗi hex đã được đưa vào data bây giờ chỉ cần chuyển theo data là xong
	string HexToDec();


	//-------------------Toán tử------------------------//
	QInt operator ~();

	//Toán tử gán bằng mặc định là chỉ gán bằng chuỗi nhị phân và dec
	QInt operator = (string);

	//Toán tử + 2 số QInt
	QInt operator +(QInt&);

	//Toán tử and
	QInt operator & (QInt&);

	//Toán tử or
	QInt operator | (QInt&);

	//Toán tử xor
	QInt operator ^ (QInt&);

	//Toán tử dịch phải
	QInt operator >> (int i);

	//Toán tử dịch trái
	QInt operator << (int i);

	//-----------KẾT THÚC CÁC HÀM TOÁN TỬ---------------//


	//------------PHÉP XOAY ROR VÀ ROL-------------------//
	QInt ROR();
	QInt ROL();
	//------------KẾT THÚC PHÉP XOAY BIT------------------//
};







