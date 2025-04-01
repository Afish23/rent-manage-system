//��ɾ���
#include "crud.h"
#include "utils.h"
#include "data.h"

//����û�
bool addUser(char* username, char* password, char* phoneNumber, int input_role, struct User* p1, struct User* p2, struct User* tail)
{
    p1 = (struct User*)malloc(sizeof(struct User));//����ռ�
    if (p1 == NULL)//�ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
    {
        printf("�ڴ�ռ����ʧ��");
        return false;

    }

    strcpy(p1->username, username);
    strcpy(p1->password, password);
    strcpy(p1->phoneNumber, phoneNumber);
    p1->role = input_role;

    //�����޸Ķ�������
    tail->next = p1;
    tail = p1;
    tail->next = NULL;
    p1->prev = p2;
    p2 = p1;//�ӳ�����
    return true;
}

//�����û�
struct User* findUser(int input_role, struct User* p1, struct User* head)
{
    char input_name[20] = { '\0' };
    char input_phoneNumber[12] = { '\0' };

    p1 = head->next;

    printf("������Ҫ�����û���������");
    scanf("%s", input_name);

    printf("������Ҫ�����û����ֻ����룺");
    scanf("%s", input_phoneNumber);
    while (1)
    {

        if (p1->role == input_role)
        {
            if (!strcmp(input_name, p1->username) && !strcmp(input_phoneNumber, p1->phoneNumber))
            {
                printf("�����û��ɹ���");
                getchar();
                clear();
                return p1;
            }
        }

        p1 = p1->next;
        if (p1 == NULL)
        {
            printf("�Ҳ�������\n");
            getchar();
            clear();
            return NULL;
        }
    }
    return NULL;
}

//�����޸��û�����
void updatePassword(int input_role, struct User* p1, struct User* head)
{
    struct User* update_p = findUser(input_role, p1, head);
    if (update_p != NULL)
    {
        while (1)
        {
            char input_password_1[20] = { '\0' };
            char input_password_2[20] = { '\0' };
            printf("�����������룺");
            hideInput(input_password_1, 19);
            printf("��ȷ�����룺");
            hideInput(input_password_2, 19);
            if (!strcmp(input_password_1, input_password_2))
            {
                strcpy(update_p->password, input_password_1);
                printf("�޸�����ɹ���\n");
                getchar();
                clear();
                break;
            }
            else
            {
                printf("�������벻һ������");
                printf("�س��Լ���");
                getchar();
                clear();
                continue;
            }
        }
    }
    return;
}

//����ɾ���û�
void deleteUser(int input_role, struct User* p1, struct User* head, struct User* tail)
{
    struct User* delete_p = findUser(input_role, p1, head);
    if (delete_p != NULL)
    {
        int jug = 0;
        printf("��ȷ��Ҫɾ����\n1ȷ��\t 2ȡ����\n");
        scanf("%d", &jug);
        if (jug == 1)
        {
            if (delete_p->next == NULL)
            {
                tail = delete_p->prev;
                delete_p->prev->next = NULL;
                free(delete_p);
            }
            else
            {
                delete_p->prev->next = delete_p->next;
                delete_p->next->prev = delete_p->prev;
                free(delete_p);
            }
            delete_p = NULL;
            jug = 0;//��ʼ��
            printf("ɾ���ɹ���\n");
            printf("�س��Լ���\n");
            getchar();
            clear();
        }
    }

    return;
}

//�޸��Լ�����
void updateMyPassword(struct User* current_p)
{
    while (1)
    {
        char input_password_1[20] = { '\0' };
        char input_password_2[20] = { '\0' };
        printf("�����������룺");
        hideInput(input_password_1, 19);
        printf("��ȷ�����룺");
        hideInput(input_password_2, 19);
        if (!strcmp(input_password_1, input_password_2))
        {
            strcpy(current_p->password, input_password_1);
            printf("�޸�����ɹ���\n");
            getchar();
            clear();
            break;
        }
        else
        {
            printf("�������벻һ������");
            printf("�س��Լ���");
            getchar();
            clear();
            continue;
        }
        return;
    }
}

//�޸��Լ��������ֻ���
void updateMyNameOrPhoneNumber(struct User* current_p)
{
    int choice;
    char input_name[20] = { '\0' };
    char input_phoneNumber[12] = { '\0' };
    while (1)
    {
        printf("������Ҫ�޸ĵ���Ϣ\n0�˳�\t1����\t 2�ֻ��ţ�\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            getchar();
            clear();
            break;
        case 1:
            memset(input_name, 0, sizeof(input_name));
            printf("�������޸ĺ��������");
            scanf("%s", input_name);
            strcpy(current_p->username, input_name);
            printf("�޸������ɹ���\n");
            getchar();
            clear();
            continue;
        case 2:
            memset(input_phoneNumber, 0, sizeof(input_phoneNumber));
            printf("�������޸ĺ���ֻ��ţ�");
            scanf("%s", input_phoneNumber);
            strcpy(current_p->phoneNumber, input_phoneNumber);
            printf("�޸��ֻ��ųɹ���\n");
            getchar();
            clear();
            continue;
        }
        return;
    }

}

//ɾ���Լ�
void deleteMyUser(struct User* current_p, struct User* tail)
{
    int jug = 0;
    printf("��ȷ��Ҫɾ����\n1ȷ��\t 2ȡ����\n");
    scanf("%d", &jug);
    if (jug == 1)
    {
        if (current_p->next == NULL)
        {
            tail = current_p->prev;
            current_p->prev->next = NULL;
            free(current_p);
        }
        else
        {
            current_p->prev->next = current_p->next;
            current_p->next->prev = current_p->prev;
            free(current_p);
        }
        current_p = NULL;
        jug = 0;//��ʼ��
        printf("ɾ���ɹ���\n");
        printf("�س��Լ���\n");
        getchar();
        clear();
    }
    return;
}

//����ⷿ��Ϣ
bool addRent(int id, int contractTime, int rentStartTime, int rentDuration, struct User* agent, struct User* tenant, struct House* house, struct Rent* p1, struct Rent* p2, struct Rent* tail) {
    p1 = (struct Rent*)malloc(sizeof(struct Rent)); // �����ڴ�
    if (p1 == NULL) {  // �ж��ڴ��Ƿ����ɹ�
        printf("�ڴ�ռ����ʧ��");
        return false;
    }

    // ��ʼ���ⷿ��Ϣ
    p1->id = id;
    p1->contractTime = contractTime;
    p1->rentStartTime = rentStartTime;
    p1->rentDuration = rentDuration;
    p1->agent = agent;
    p1->tenant = tenant;
    p1->house = house;
    p1->statement = 1;  // �������ⷿ���������״̬

    // ���½ڵ�����ⷿ����
    tail->next = p1;
    tail = p1;
    tail->next = NULL;
    p1->prev = p2;
    p2 = p1; // �ӳ�����

    return true;
}

//�����ⷿ�û�
/*
struct Rent* findRent(int input_role, struct Rent* p1, struct Rent* head)
{
    p1 = head->next; // ������ĵ�һ���ⷿ��Ϣ��ʼ
    int input_id, input_contractTime, input_rentStartTime, input_rentDuration;
    // ��ʾ�û������ѯ����
    printf("������Ҫ�����ⷿ��Ϣ���ⷿ��ţ�");
    scanf("%d", &input_id);

    printf("������Ҫ�����ⷿ��Ϣ�ĺ�ͬǩ�����ڣ�");
    scanf("%d", &input_contractTime);

    printf("������Ҫ�����ⷿ��Ϣ�ĳ��⿪ʼ���ڣ�");
    scanf("%d", &input_rentStartTime);

    printf("������Ҫ�����ⷿ��Ϣ��Ԥ�Ƴ���ʱ����");
    scanf("%d", &input_rentDuration);

    // �����������ƥ����ⷿ��Ϣ
    while (p1 != NULL)
    {   
        if (p1->role == input_role)
        {
            // �ж��ⷿID����ͬǩ�����ڡ����⿪ʼ���ں�Ԥ�Ƴ���ʱ���Ƿ�ƥ��
            if (p1->id == input_id && p1->contractTime == input_contractTime &&
                p1->rentStartTime == input_rentStartTime && p1->rentDuration == input_rentDuration)
            {
                printf("�����ⷿ��Ϣ�ɹ���\n");
                getchar(); // ���ĵ�����Ļ��з�
                clear();  // ������������
                return p1; // �����ҵ����ⷿ��Ϣ
            }
        }

        p1 = p1->next; // �ƶ�����һ���ⷿ��Ϣ�ڵ�
    }

    // ���������������δ�ҵ�ƥ����ⷿ��Ϣ
    printf("�Ҳ����ⷿ��Ϣ\n");
    getchar(); // ���ĵ�����Ļ��з�
    clear();  // ������������
    return NULL; // ����NULL��ʾδ�ҵ�
}

//ɾ���ⷿ�û�
void deleteRent(int input_id, struct Rent* p1, struct Rent* head, struct Rent* tail)
{
    struct Rent* delete_p = findRent(input_id, p1, head); // ����Ҫɾ����Rent�ڵ�
    if (delete_p != NULL)
    {
        int jug = 0;
        printf("��ȷ��Ҫɾ���ⷿ��Ϣ��\n1ȷ��\t 2ȡ����\n");
        scanf("%d", &jug);
        if (jug == 1)
        {
            // �����β�ڵ�
            if (delete_p->next == NULL)
            {
                tail = delete_p->prev;  // ����tail
                delete_p->prev->next = NULL;  // ɾ���ڵ�
                free(delete_p);  // �ͷ��ڴ�
            }
            // �����ͷ�ڵ�
            else if (delete_p->prev == NULL)
            {
                head = delete_p->next;  // ����head
                delete_p->next->prev = NULL;  // ɾ���ڵ�
                free(delete_p);  // �ͷ��ڴ�
            }
            else
            {
                delete_p->prev->next = delete_p->next;  // ����ǰ�ڵ��nextָ��
                delete_p->next->prev = delete_p->prev;  // ���º�ڵ��prevָ��
                free(delete_p);  // �ͷ��ڴ�
            }

            delete_p = NULL;  // ���ָ��
            jug = 0;  // ��ʼ��
            printf("ɾ���ɹ���\n");
            printf("�س��Լ���\n");
            getchar();  // ��ȡ�س�����ͣ
            clear();  // ��������������
        }
    }

    return;
}*/