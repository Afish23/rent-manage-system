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
bool addRent(struct Rent** tail1, struct User* agent, struct House* head);

// ����˳����������ⷿ��Ϣ
void printRentsInOrder(struct Rent* head1);

// ����˳����������Լ��ⷿ��Ϣ
void printMyRentsInOrder(struct Rent* head1, struct User* tenant);

//�����ⷿ��Ϣ
struct Rent* findRent(int id, struct Rent* head1);

//�����ⷿ��Ϣ
void updateRent(struct Rent* head1);

//ɾ���ⷿ��Ϣ
bool deleteRent(struct Rent* head1);

//���ԤԼ��Ϣ
bool addAppointment(struct Appointment** tail2, struct User* tenant);

//��ӷ���
bool addFeedback(struct Appointment* head2, struct User* tenant);

//����ԤԼ��Ϣ
bool handleAppointment(struct Appointment* head2, struct User* agent);

//ָ���н�
bool appointAgent(struct Appointment* head2);

// ����˳���������ԤԼ��Ϣ
void printAppointmentsInOrder(struct Appointment* head2);

// ����˳����������Լ�ԤԼ��Ϣ
void printMyAppointmentsInOrder(struct Appointment* head2, struct User* tenant);

//����ԤԼ��Ϣ
struct Appointment* findAppointment(int id, struct Appointment* head2);

//����ԤԼ��Ϣ
void updateAppointment(struct Appointment* head2);

//ɾ��ԤԼ��Ϣ
void deleteAppointment(struct Appointment* head2);