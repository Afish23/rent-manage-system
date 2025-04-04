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
int addHouse(struct House* head, struct House* tail);

//修改房子
bool updateHouse(struct House* head);

//删除房子
bool deleteHouse(struct House* head);

//添加租房信息
bool addRent(struct Rent** tail);

// 按照顺序输出所有租房信息
void printRentsInOrder(struct Rent* head);

//查找租房信息
struct Rent* findRent(int id1, struct Rent* head1);

//更新租房信息
void updateRent(struct Rent* head1);

//删除租房信息
bool deleteRent(struct Rent* head1);

//添加预约信息
bool addAppointment(struct Appointment** tail);

// 按照顺序输出所有预约信息
void printAppointmentsInOrder(struct Appointment* head);

//查找预约信息
struct Appointment* findAppointment(int id1, struct Appointment* head1);

//更新预约信息
void updateAppointment(struct Appointment* head2);

//删除预约信息
void deleteAppointment(struct Appointment* head2);
