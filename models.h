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
    int id;//�����
    char houseowner[10];//��������
    int number;//�����绰
    char city[20];//���ڳ���
    char urban[20];//��������
    char community[20];//����С��
    int floor;//¥��
    enum Toward toward;//����
    int room;//��
    int hall;//��
    float Area;//���
    char fitment[10];//װ�����
    char number[9];//���
    float cost;//����/��
    struct Agency* agency;//�����н�
    struct Customer* custome;//�ⷿ���
    int status;  // 0-���� 1-���� 2-������
} House;

typedef struct {
    int id;
    int tenant_id;
    int house_id;
    int status;  // 0-������ 1-ͨ�� 2-�ܾ�
} Application;