#pragma once
#include <fstream>
#include <sstream>
#include <algorithm>

#include "QInt.h"


//Hàm nhập dữ liệu từ file
void Input();


//Hàm xử lý đầu vào và trả ra kết quả
string Solve(string);


//Kiểm tra chuỗi đâu vào có phải chỉ thị hay không
bool checkQuestion(string);

//Kiểm tra xem đầu vào là toán hạng gì
int CheckOperand(string);







