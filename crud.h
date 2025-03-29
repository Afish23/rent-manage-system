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

//修改自己姓名或手机号
void updateMyNameOrPhoneNumber(struct User* current_p);

//删除自己
void deleteMyUser(struct User* current_p, struct User* tail);

//添加租房信息
bool addRent(int id, int contractTime, int rentStartTime, int rentDuration, struct User* agent, struct User* tenant, struct House* house, struct Rent* p1, struct Rent* p2, struct Rent* tail);

//查找租房用户
struct Rent* findRent(int input_id, int input_contractTime, int input_rentStartTime, int input_rentDuration, struct Rent* p1, struct Rent* head);

//删除租房用户
void deleteRent(int input_id, struct Rent* p1, struct Rent* head, struct Rent* tail);