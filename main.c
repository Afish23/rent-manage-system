#include "data.h"
#include "models.h"
#include "utils.h"
int main() {
    //ʵ�ֵ�¼����
    bool login(int input_role, struct User* p1, struct User* head);

    //ʵ��ע�Ṧ��
    void register_user(int role, struct User* p1, struct User* p2, struct User* tail, struct User* head);

    //����û�
    bool addUser(char* username, char* password, char* phoneNumber, int role, struct User* p1, struct User* p2, struct User* tail);

    //0�����˵� 1�����ѡ��˵� 2������Ա�˵� 3���н�˵� 4����Ͳ˵�
    int choice_0 = 1, choice_1, choice_2, choice_3, choice_4;
    //5:�н����˵�
    int choice_5;
    //�˳�ѭ���ж�
    //0�����ѡ�� 1:�н����
    int jug0 = 0, jug1 = 0;

    struct User* p1, * p2, * tail, * head;
    p1 = (struct User*)malloc(sizeof(struct User));//����ռ�
    if (p1 == NULL) { // �ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
        printf("�ڴ�ռ����ʧ��\n");
        return -1;
    }

    tail = p1; // ���ͷβ
    head = p1;
    p2 = p1;
    tail->next = NULL;
    head->prev = NULL;

    struct House* p11, * p21, * tail1, * head1;
    p11 = (struct House*)malloc(sizeof(struct House));//����ռ�
    if (p11 == NULL) { // �ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
        printf("�ڴ�ռ����ʧ��\n");
        return -1;
    }

    tail1 = p11; // ���ͷβ
    head1 = p11;
    p21 = p11;
    tail1->next = NULL;
    head1->prev = NULL;


    //���ݶ�ȡ
    read_user_data(&tail);
    read_house_data(&tail1);

    //������
    while (choice_0) {
        printf("******��    ¼******\n");
        printf("**                **\n");
        printf("**0.  ��    ��    **\n");
        printf("**1.  ��    ¼    **\n");
        printf("**2.  ���ע��    **\n");
        printf("**                **\n");
        printf("********************\n");
        printf("��ѡ���ܣ�");
        scanf_s("%d", &choice_0);
        clear();

        switch (choice_0) {
        case 0:
            break;
        case 1:
            //���ѡ�����
            printf("******���ѡ��******\n");
            printf("**                **\n");
            printf("**0.  ��    ��    **\n");
            printf("**1.  �� �� Ա    **\n");
            printf("**2.  ��    ��    **\n");
            printf("**3.  ��    ��    **\n");
            printf("**                **\n");
            printf("********************\n");
            printf("��ѡ����ݣ�");
            scanf_s("%d", &choice_1);
            clear();
            switch (choice_1)
            {
            case 0:
                break;
            case 1:
                jug0 = 1;

                if (!login(1, p1, head))
                {
                    break;
                }
                while (jug0)
                {

                    printf("*********���ܲ˵�*********\n");
                    printf("**                      **\n");
                    printf("**0.     ��    ��       **\n");
                    printf("**1.     ��Ϣ����       **\n");
                    printf("**2.     ��������       **\n");
                    printf("**3.     ��Ϣ��ѯ       **\n");
                    printf("**4.     ��Ϣ����       **\n");
                    printf("**5.     ��Ϣͳ��       **\n");
                    printf("**6.     ��������       **\n");
                    printf("**7.    ��ӹ���Ա      **\n");
                    printf("**8.     �н����       **\n");
                    printf("**9.     ɾ���˻�       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("��ѡ���ܣ�");
                    scanf_s("%d", &choice_2);
                    clear();

                    switch (choice_2)
                    {
                    case 0:
                        jug0 = 0;
                        break;
                    case 7:
                        register_user(1, p1, p2, tail, head);
                    case 8:
                        jug1 = 1;
                        while (jug1)
                        {
                            //�н�������
                            printf("******�н����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��    ��    **\n");
                            printf("**2.  ��    ��    **\n");
                            printf("**3.  ɾ    ��    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_5);
                            clear();
                            switch (choice_5)
                            {
                            case 0:
                                jug1 = 0;
                                break;
                            case 1:
                                register_user(2, p1, p2, tail, head);
                            default:
                                break;
                            }
                        }
                        break;

                    default:
                        break;
                    }
                }
                break;


            case 2:
                jug0 = 1;

                if (!login(2, p1, head))
                {
                    break;
                }
                while (jug0)
                {

                    printf("*********���ܲ˵�*********\n");
                    printf("**                      **\n");
                    printf("**0.     ��    ��       **\n");
                    printf("**1.     ��������       **\n");
                    printf("**2.     �ⷿ����       **\n");
                    printf("**3.     ��Ϣ��ѯ       **\n");
                    printf("**4.     ��Ϣ����       **\n");
                    printf("**5.     ��Ϣͳ��       **\n");
                    printf("**6.     ��������       **\n");
                    printf("**7.     ɾ���˻�       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("��ѡ���ܣ�");
                    scanf_s("%d", &choice_3);
                    clear();

                    switch (choice_3)
                    {
                    case 0:
                        jug0 = 0;
                        break;
                    default:
                        break;
                    }
                }
                break;

            case 3:
                jug0 = 1;

                if (!login(3, p1, head))
                {
                    break;
                }
                while (jug0)
                {

                    printf("*********���ܲ˵�*********\n");
                    printf("**                      **\n");
                    printf("**0.     ��    ��       **\n");
                    printf("**1.     ������Ϣ       **\n");
                    printf("**2.     ����ԤԼ       **\n");
                    printf("**3.     ��Ϣ��ѯ       **\n");
                    printf("**4.     ��Ϣ����       **\n");
                    printf("**5.     ��Ϣͳ��       **\n");
                    printf("**6.     ��������       **\n");
                    printf("**7.     ɾ���˻�       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("��ѡ���ܣ�");
                    scanf_s("%d", &choice_4);
                    clear();

                    switch (choice_4)
                    {
                    case 0:
                        jug0 = 0;
                        break;
                    default:
                        break;
                    }
                }
                break;
            }
            break;
        case 2:
            register_user(3, p1, p2, tail, head);
        default:
            break;
        }
    }
    write_user_data(head);
    return 0;
}

//ʵ�ֵ�¼����
bool login(int input_role, struct User* p1, struct User* head) {
    char input_name[20] = { '\0' };
    char input_password[20] = { '\0' };

    p1 = head->next;
    if (p1 == NULL)
    {
        printf("û���˺����ݣ�����ע�ᣡ\n");
        return false;
    }

    printf("������������");
    scanf("%s", input_name);

    while (1)
    {
        if (p1->role == input_role)
        {
            if (!strcmp(input_name, p1->username))
            {
                printf("����������:");
                hideInput(input_password, 19);
                if (!strcmp(input_password, p1->password))
                {
                    printf("��¼�ɹ�����ӭ���û�%s\n", p1->username);
                    printf("�س��Լ���\n");
                    getchar();
                    clear();
                }
                else
                {
                    printf("�������\n");
                    printf("�س��Լ���\n");
                    getchar();
                    clear();
                    return false;
                }
                return true;;
            }
        }

        p1 = p1->next;
        if (p1 == NULL)
        {
            printf("�Ҳ�������\n");
            printf("�س��Լ���\n");
            getchar();
            clear();
            return false;;
        }
    }
}

//ʵ��ע�Ṧ��
void register_user(int role, struct User* p1, struct User* p2, struct User* tail, struct User* head) {
    char input_name[20] = { '\0' };
    char input_password_1[20] = { '\0' };
    char input_password_2[20] = { '\0' };
    char input_phoneNumber[12] = { '\0' };

    memset(input_name, 0, sizeof(input_name));
    printf("������������");
    scanf("%s", input_name);

    memset(input_phoneNumber, 0, sizeof(input_phoneNumber));
    printf("������绰���룺(11λ)");
    scanf("%s", input_phoneNumber);


    while (strlen(input_phoneNumber) != 11)
    {
        clear();
        printf("��Ч�ĵ绰���룡\n");
        printf("��������ȷ�ĵĵ绰����:");
        memset(input_phoneNumber, 0, sizeof(input_phoneNumber));
        scanf("%s", input_phoneNumber);
    }

    p1 = head->next;
    while (1)
    {
        if (p1 == NULL)
        {
            printf("���������룺");
            hideInput(input_password_1, 19);
            printf("��ȷ�����룺");
            hideInput(input_password_2, 19);
            if (!strcmp(input_password_1, input_password_2))
            {
                if (!addUser(input_name, input_password_1, input_phoneNumber, role, p1, p2, tail))
                {
                    return;
                }
                printf("ע��ɹ���\n");
                getchar();
                clear();
                return;
            }
            else
            {
                printf("�������벻һ������");
                printf("�س��Լ���");
                getchar();
                clear();
                break;
            }
        }
        if (!strcmp(input_name, p1->username) || !strcmp(input_phoneNumber, p1->phoneNumber))
        {
            printf("���û��Ѿ�����\n");
            printf("���س��Լ���\n");
            getchar();
            clear();
            break;
        }
        p1 = p1->next;
    }
}

//����û�
bool addUser(char* username, char* password, char* phoneNumber, int role, struct User* p1, struct User* p2, struct User* tail)
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
    p1->role = role;


    //�����޸Ķ�������
    tail->next = p1;
    tail = p1;
    tail->next = NULL;
    p1->prev = p2;
    p2 = p1;//�ӳ�����
    return true;
}