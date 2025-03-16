//数据结构定义
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char username[20];
    char password[20];
    int role;  // 0-管理员 1-中介 2-租客
} User;

typedef struct {
    int id;
    int agent_id;
    char address[100];
    double price;
    int status;  // 0-可租 1-已租 2-申请中
} House;

typedef struct {
    int id;
    int tenant_id;
    int house_id;
    int status;  // 0-待处理 1-通过 2-拒绝
} Application;