//���ݽṹ����
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
    int role; //1������Ա��2���н飬3�����
};

struct House {
    struct House* prev;// ǰһ����Դ
    struct House* next; // ��һ����Դ
    int id;//��ԴID
    char houseowner[10];//��������
    int number;//�����绰
    char city[20];//������
    char urban[20];//������/��
    char community[20];//����С������
    int floor;//¥��
    enum Toward { N, S, E, W, SE, NE, SW, SN }toward;//����
    int room;//��
    int hall;//��
    float Area;//���
    char fitment[10];//װ�����
    float rent, agency_fee, deposit;//���ã���������н�ѡ�Ѻ��
    int time1, time2;//�ⷿ��ʼ/��������
    struct User* agent;//�н�
    struct User* tenant;//���
    char agentname[20];//�н�����
    char tenantname[20];//�������
    int status;  // 0-���� 1-���� 2-������
};

struct Appointment//ԤԼ��Ϣ
{
    struct Appointment* next;
    struct Appointment* prev;
    int id;//�������
    int time;//����ʱ��
    int duration;//����ʱ��
    struct User* agent;//�н�
    struct User* tenant;//���
    struct House* house;//��Դ
    char agentname[20];//�н�����
    char tenantname[20];//�������
    int id;//��ԴID
    char feedback[20];//��ͷ���
    int statement;//0����ɣ�1������
};

struct Rent//�ⷿ��Ϣ
{
    struct Rent* next;
    struct Rent* prev;
    int id;//�ⷿ���
    int contractTime;//��ͬǩ������
    int rentStartTime;//���⿪ʼ����
    int rentDuration;//Ԥ�Ƴ���ʱ��
    struct User* agent;//�н�
    struct User* tenant;//���
    struct House* house;//��Դ
    char agentname[20];//�н�����
    char tenantname[20];//�������
    int id;//��ԴID
    int statement;//0����ɣ�1������
};
