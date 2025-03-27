//数据操作声明
#pragma once
#include "models.h"


// 文件操作函数
bool read_data(struct User** tailp);
bool write_data(struct User* headp);
