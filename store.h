//数据存储声明
#pragma once
#include "models.h"

#define MAX_USERS 100
#define MAX_HOUSES 100
#define MAX_APPLICATIONS 100

// 全局数据声明
extern User users[MAX_USERS];
extern House houses[MAX_HOUSES];
extern Application applications[MAX_APPLICATIONS];
extern int user_count;
extern int house_count;
extern int application_count;

// 文件操作函数
void load_data();
void save_data();
