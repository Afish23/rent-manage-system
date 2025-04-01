//数据结构定义
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <time.h> 
#include<Windows.h>
#include<assert.h>
#include <stdbool.h>

struct User
{
    char username[20];
    char password[20];
    char phoneNumber[12];
    struct User* prev;
    struct User* next;
    int role; //1：管理员，2：中介，3：租客
};

struct House {
    struct House* prev;// 前一个房源
    struct House* next; // 后一个房源
    int id;//房源ID
    char houseowner[10];//房主名字
    int number;//房主电话
    char city[20];//所在市
    char urban[20];//所在县/区
    char community[20];//所在小区名字
    int floor;//楼层
    enum Toward { N, S, E, W, SE, NE, SW, SN }toward;//朝向
    int room;//室
    int hall;//厅
    float Area;//面积
    char fitment[10];//装修情况
    float rent, agency_fee, deposit;//费用，包括租金、中介费、押金
    int time1, time2;//租房开始/结束日期
    struct User* agent;//中介
    struct User* tenant;//租客
    char agentname[20];//中介姓名
    char tenantname[20];//租客姓名
    int status;  // 0-可租 1-已租 2-申请中
};

struct Appointment//预约信息
{
    struct Appointment* next;
    struct Appointment* prev;
    int id;//看房编号
    int time;//看房时间
    int duration;//看房时长
    struct User* agent;//中介
    struct User* tenant;//租客
    struct House* house;//房源
    char agentname[20];//中介姓名
    char tenantname[20];//租客姓名
    int id;//房源ID
    char feedback[20];//租客反馈
    int statement;//0已完成，1待处理
};

struct Rent//租房信息
{
    struct Rent* next;
    struct Rent* prev;
    int id;//租房编号
    int contractTime;//合同签订日期
    int rentStartTime;//出租开始日期
    int rentDuration;//预计出租时长
    struct User* agent;//中介
    struct User* tenant;//租客
    struct House* house;//房源
    char agentname[20];//中介姓名
    char tenantname[20];//租客姓名
    int id;//房源ID
    int statement;//0已完成，1正在租
};
