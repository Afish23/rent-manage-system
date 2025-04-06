//实用方法类
#pragma once
#include "models.h"

//用于模糊匹配
int editDistance(const char* str1, const char* str2);

//用于隐藏密码
void hideInput(char* buffer, int maxLength);

//用于清屏
void clear();

//用于打印租房排序信息
void printList(struct Rent* head);

//用于打印房源排序信息
void printHouseList(struct House* head);