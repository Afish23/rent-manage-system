//���ݽṹ����
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>

struct Admin//����Ա
{
    char Account[20];//�˺�
    char Key[20];//����
    struct Admin* prev;
    struct Admin* next;
    char invitation[20];//�����룬ÿ������Ա����һ��
    int effective;//���������Ч��
};

struct Agency//�н�
{
    char Account[20];//�н�IDֱ����Ϊ���˻�
    char phone_n[12];//�绰
    char Key[20];//����
    char Name[50];//����
    char Number[9];
    struct Agency* prev;
    struct Agency* next;
};

struct Customer//���
{
    char Account[20];//�˺�
    char Key[20];//����
    char phone_n[12];//�绰
    char Name[50];//����
    struct Customer* prev;
    struct Customer* next;
    int statment;
    char city[20];
};
typedef struct {
    struct House* pre;           // ǰһ����Դ
    struct House* nest;          // ��һ����Դ
    int id;//�����
    char houseowner[10];//��������
    int number;//�����绰
    char city[20];//���ڳ���
    char urban[20];//��������
    char community[20];//����С��
    int floor;//¥��
    enum Toward { N, S, E, W, SE, NE, SW, SN}toward;//����
    int room;//��
    int hall;//��
    float Area;//���
    char fitment[10];//װ�����
    float rent, agency_fee, deposit;//���ã���������н�ѡ�Ѻ��
    struct Agency* agency;//�н�
    struct Customer* custome;//���
    int status;  // 0-���� 1-���� 2-������
} House;

struct Appointment//ԤԼ
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
    int statment;//0����ɣ�1��Ч�У�2����δ����
};