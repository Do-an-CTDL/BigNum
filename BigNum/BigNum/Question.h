﻿#pragma once
#include <fstream>
#include <sstream>
#include <algorithm>

#include "QInt.h"


//Hàm nhập dữ liệu từ file
//void Input(ifstream &, ofstream&);
void Input(string ,string);


//Hàm xử lý đầu vào và trả ra kết quả
string Solve(string);


//Kiểm tra chuỗi đâu vào có phải chỉ thị hay không
bool checkQuestion(string);

//Kiểm tra xem đầu vào là toán hạng gì
int CheckOperand(string);


//Chuyển Từ QInt sang hệ số đích (2, 10, 16)
string ConvertQIntToBase(QInt );




