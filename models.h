//数据结构定义
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>

struct Admin//管理员
{
    char Account[20];//账号
    char Key[20];//密码
    struct Admin* prev;
    struct Admin* next;
    char invitation[20];//邀请码，每个管理员限有一个
    int effective;//邀请码的有效性
};

struct Agency//中介
{
    char Account[20];//中介ID直接作为其账户
    char phone_n[12];//电话
    char Key[20];//密码
    char Name[50];//姓名
    char Number[9];
    struct Agency* prev;
    struct Agency* next;
};

struct Customer//租客
{
    char Account[20];//账号
    char Key[20];//密码
    char phone_n[12];//电话
    char Name[50];//姓名
    struct Customer* prev;
    struct Customer* next;
    int statment;
    char city[20];
};
typedef struct {
    struct House* pre;           // 前一个房源
    struct House* nest;          // 后一个房源
    int id;//房间号
    char houseowner[10];//房主名字
    int number;//房主电话
    char city[20];//所在城市
    char urban[20];//所在区域
    char community[20];//所在小区
    int floor;//楼层
    enum Toward { N, S, E, W, SE, NE, SW, SN}toward;//朝向
    int room;//室
    int hall;//厅
    float Area;//面积
    char fitment[10];//装修情况
    float rent, agency_fee, deposit;//费用，包括租金、中介费、押金
    struct Agency* agency;//中介
    struct Customer* custome;//租客
    int status;  // 0-可租 1-已租 2-申请中
} House;

struct Appointment//预约
{
    struct Appointment* next;
    struct Appointment* prev;
    int year;
    int month;
    int day;
    char Number[9];
    struct Customer* custom;
    struct Flat* flat;
    char cuposition[20];
    char flposition[9];
    int statment;//0已完成，1有效中，2过期未处理
};