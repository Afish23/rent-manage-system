//���ݽṹ����
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char username[20];
    char password[20];
    int role;  // 0-����Ա 1-�н� 2-���
} User;

typedef struct {
    int id;
    int agent_id;
    char address[100];
    double price;
    int status;  // 0-���� 1-���� 2-������
} House;

typedef struct {
    int id;
    int tenant_id;
    int house_id;
    int status;  // 0-������ 1-ͨ�� 2-�ܾ�
} Application;