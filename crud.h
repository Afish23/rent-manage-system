//增删查改
#pragma once
#include "models.h"

//添加用户
bool addUser(char* username, char* password, char* phoneNumber, int role, struct User* p1, struct User* p2, struct User* tail);

// 按照身份顺序输出所有用户信息
void printUsersInOrder(struct User* head);

//查找用户
struct User* findUser(int input_role, struct User* p1, struct User* head);

//查找修改用户密码
void updatePassword(int input_role, struct User* p1, struct User* head);

//查找删除用户
void deleteUser(int input_role, struct User* p1, struct User* head, struct User* tail);

//修改自己密码
void updateMyPassword(struct User* current_p);

//修改自己姓名或手机号
void updateMyNameOrPhoneNumber(struct User* current_p);

//删除自己
void deleteMyUser(struct User* current_p, struct User* tail);

//添加房源
int addHouse(struct House** head, struct House** tail, struct User* user_agency, struct User* user_custome);
