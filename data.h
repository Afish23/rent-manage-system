//数据操作声明
#pragma once
#include "models.h"


// 文件操作函数
bool read_user_data(struct User** tailp);
bool write_user_data(struct User* headp);

bool read_tenant_data(struct Rent** tailp)；
bool write_tenant_data(struct Rent* headp)；
