//ʵ�÷�����
#pragma once
#include "models.h"

//����ģ��ƥ��
int editDistance(const char* str1, const char* str2);

//������������
void hideInput(char* buffer, int maxLength);

//��������
void clear();

//���ڴ�ӡ�ⷿ������Ϣ
void printList(struct Rent* head);

//���ڴ�ӡ��Դ������Ϣ
void printHouseList(struct House* head);