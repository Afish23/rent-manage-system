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
