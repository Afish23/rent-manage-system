//增删查改
#pragma once
#include "models.h"

//添加用户
bool addUser(char* username, char* password, char* phoneNumber, int role, struct User* p1, struct User* p2, struct User* tail);

//查找用户
struct User* findUser(int input_role, struct User* p1, struct User* head);

//查找修改用户密码
void updatePassword(int input_role, struct User* p1, struct User* head);

//查找删除用户
void deleteUser(int input_role, struct User* p1, struct User* head, struct User* tail);

//修改自己密码
void updateMyPassword(struct User* current_p);

//删除自己
void deleteMyUser(struct User* current_p, struct User* tail);
