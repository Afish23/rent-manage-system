//��֤����
#include "auth.h"
#include "utils.h"
#include "crud.h"
#include "data.h"

//ʵ�ֵ�¼����
struct User* login(int input_role, struct User* p1, struct User* head) {
    char input_name[20] = { '\0' };
    char input_password[20] = { '\0' };

    p1 = head->next;
    if (p1 == NULL)
    {
        printf("û���˺����ݣ�����ע�ᣡ\n");
        getchar();
        clear();
        return NULL;
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
                    return p1;
                }
                else
                {
                    printf("�������\n");
                    printf("�س��Լ���\n");
                    getchar();
                    clear();
                    return NULL;
                }
            }
        }

        p1 = p1->next;
        if (p1 == NULL)
        {
            printf("�Ҳ�������\n");
            printf("�س��Լ���\n");
            getchar();
            clear();
            return NULL;;
        }
    }
}

//ʵ��ע�Ṧ��
void register_user(int input_role, struct User* p1, struct User* p2, struct User* tail, struct User* head) {
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
                if (!addUser(input_name, input_password_1, input_phoneNumber, input_role, p1, p2, tail))
                {
                    return;
                }
                printf("ע��ɹ���\n");
                
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
