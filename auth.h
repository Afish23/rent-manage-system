//认证功能
#pragma once
#include "models.h"

//实现登录功能
struct User* login(int input_role, struct User* p1, struct User* head);

//实现注册功能
void register_user(int input_role, struct User* p1, struct User* p2, struct User* tail, struct User* head);

