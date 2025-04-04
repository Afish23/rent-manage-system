//数据操作声明
#pragma once
#include "models.h"


// 文件操作函数
bool read_user_data(struct User** tailp);
bool write_user_data(struct User* headp);
bool read_house_data(struct House** tailp);
bool write_house_data(struct House* tailp);
bool read_rent_data(struct Rent** tailp);
bool write_rent_data(struct Rent* headp);
bool read_Appointment_data(struct Appointment** tailp);
bool write_Appointment_data(struct Appointment* headp);