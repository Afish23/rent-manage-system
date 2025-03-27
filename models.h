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
    int id;//房间号
    char houseowner[10];//房主名字
    int number;//房主电话
    char city[20];//所在城市
    char urban[20];//所在区域
    char community[20];//所在小区
    int floor;//楼层
    enum Toward toward;//朝向
    int room;//室
    int hall;//厅
    float Area;//面积
    char fitment[10];//装修情况
    char number[9];//编号
    float cost;//房价/月
    struct Agency* agency;//卖房中介
    struct Customer* custome;//租房租客
    int status;  // 0-可租 1-已租 2-申请中
} House;

typedef struct {
    int id;
    int tenant_id;
    int house_id;
    int status;  // 0-待处理 1-通过 2-拒绝
} Application;