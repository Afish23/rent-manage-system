//��ɾ���
#pragma once
#include "models.h"

//����û�
bool addUser(char* username, char* password, char* phoneNumber, int role, struct User* p1, struct User* p2, struct User* tail);

//�����û�
struct User* findUser(int input_role, struct User* p1, struct User* head);

//�����޸��û�����
void updatePassword(int input_role, struct User* p1, struct User* head);

//����ɾ���û�
void deleteUser(int input_role, struct User* p1, struct User* head, struct User* tail);

//�޸��Լ�����
void updateMyPassword(struct User* current_p);

//�޸��Լ��������ֻ���
void updateMyNameOrPhoneNumber(struct User* current_p);

//ɾ���Լ�
void deleteMyUser(struct User* current_p, struct User* tail);

//����ⷿ��Ϣ
bool addRent(int id, int contractTime, int rentStartTime, int rentDuration, struct User* agent, struct User* tenant, struct House* house, struct Rent* p1, struct Rent* p2, struct Rent* tail);

//�����ⷿ�û�
struct Rent* findRent(int input_id, int input_contractTime, int input_rentStartTime, int input_rentDuration, struct Rent* p1, struct Rent* head);

//ɾ���ⷿ�û�
void deleteRent(int input_id, struct Rent* p1, struct Rent* head, struct Rent* tail);