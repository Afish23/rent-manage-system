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
 
//ɾ���Լ�
void deleteMyUser(struct User* current_p, struct User* tail);

//��ӷ���
int addHouse(struct House* newHouse, struct House* head, struct House* tail, struct User* user_agency, struct User* user_custome);

//�޸ķ���
bool updateHouse(int house_id, struct House* head);

//ɾ������
bool deleteHouse(int house_id, struct House* head);



bool addRent(struct Rent* p1, struct Rent* tail);
struct Rent* findRent(int id1, struct Rent* head1);
void deleteRent(struct Rent** prev, struct Rent** head1, struct Rent** next);