//��ɾ���
#pragma once
#include "models.h"

//����û�
bool addUser(char* username, char* password, char* phoneNumber, int role, struct User* p1, struct User* p2, struct User* tail);

// �������˳����������û���Ϣ
void printUsersInOrder(struct User* head);

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

//��ӷ�Դ
int addHouse(struct House** head, struct House** tail, struct User* user_agency, struct User* user_custome);
