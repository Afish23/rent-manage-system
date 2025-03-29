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

struct House{
    struct House* prev;// 前一个房源
    struct House* next; // 后一个房源
    int id;//房间号
    char houseowner[10];//房主名字
    int number;//房主电话
    char city[20];//所在市
    char urban[20];//所在县/区
    char community[20];//所在小区名字
    int floor;//楼层
    enum Toward { N, S, E, W, SE, NE, SW, SN}toward;//朝向
    int room;//室
    int hall;//厅
    float Area;//面积
    char fitment[10];//装修情况
    float rent, agency_fee, deposit;//费用，包括租金、中介费、押金
    int time1, time2;//租房开始/结束日期
    struct User* user_agency;//中介
    struct User* user_custome;//租客
    int status;  // 0-可租 1-已租 2-申请中
} ;

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