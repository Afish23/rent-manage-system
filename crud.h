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
int addHouse(struct House* head, struct House* tail);

//�޸ķ���
bool updateHouse(struct House* head);

//ɾ������
bool deleteHouse(struct House* head);

//����ⷿ��Ϣ
bool addRent(struct Rent** tail);

// ����˳����������ⷿ��Ϣ
void printRentsInOrder(struct Rent* head);

//�����ⷿ��Ϣ
struct Rent* findRent(int id1, struct Rent* head1);

//�����ⷿ��Ϣ
void updateRent(struct Rent* head1);

//ɾ���ⷿ��Ϣ
bool deleteRent(struct Rent* head1);

//���ԤԼ��Ϣ
bool addAppointment(struct Appointment** tail);

// ����˳���������ԤԼ��Ϣ
void printAppointmentsInOrder(struct Appointment* head);

//����ԤԼ��Ϣ
struct Appointment* findAppointment(int id1, struct Appointment* head1);

//����ԤԼ��Ϣ
void updateAppointment(struct Appointment* head2);

//ɾ��ԤԼ��Ϣ
void deleteAppointment(struct Appointment* head2);
