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
    }
    return;
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

//��ӷ�Դ
int addHouse(struct House*newHouse,struct House* head, struct House* tail, struct User* user_agency, struct User* user_custome) {
    newHouse = (struct House*)malloc(sizeof(struct House));
    if (newHouse == NULL) {
        printf("�ڴ����ʧ��\n");
        return -1;
    }

    // ��ȡ��Դ�ĸ�����Ϣ
    printf("�����뷿ԴID: ");
    scanf("%d", &newHouse->id);

    printf("�����뷿���: ");
    scanf("%d", &newHouse->house_id);

    printf("�����뷿������: ");
    scanf("%s", newHouse->houseowner);

    printf("�����뷿���绰: ");
    scanf("%s", newHouse->number);

    printf("������������: ");
    scanf("%s", newHouse->city);

    printf("������������/��: ");
    scanf("%s", newHouse->urban);

    printf("����������С������: ");
    scanf("%s", newHouse->community);

    printf("������¥��: ");
    scanf("%d", &newHouse->floor);

    printf("�����볯��0: N, 1: S, 2: E, 3: W, 4: SE, 5: NE, 6: SW, 7: SN��: ");
    int toward_input;
    scanf("%d", &toward_input);
    newHouse->toward = (enum Toward)toward_input;

    printf("����������: ");
    scanf("%d", &newHouse->room);

    printf("����������: ");
    scanf("%d", &newHouse->hall);

    printf("�����뷿�����: ");
    scanf("%f", &newHouse->Area);

    printf("������װ�����: ");
    scanf("%s", newHouse->fitment);

    printf("���������: ");
    scanf("%f", &newHouse->rent);

    printf("�������н��: ");
    scanf("%f", &newHouse->agency_fee);

    printf("������Ѻ��: ");
    scanf("%f", &newHouse->deposit);

    printf("�������ⷿ��ʼ���� (��ʽ��YYYYMMDD): ");
    scanf("%d", &newHouse->time1);

    printf("�������ⷿ�������� (��ʽ��YYYYMMDD): ");
    scanf("%d", &newHouse->time2);

    // �����н�������Ϣ
    /*newHouse->user_agency = user_agency;
    newHouse->user_custome = user_custome;

    printf("�������н�����: ");
    scanf("%s", newhouse->agentname);

    printf("�������������: ");
    scanf("%s", newhouse->tenantname);*/

    printf("�����뷿Դ״̬��0: ����, 1: ����, 2: �����У�: ");
    scanf("%d", &newHouse->status);

    newHouse->prev = tail;
    tail->next = newHouse;
    newHouse->next = NULL;
    printf("��ӳɹ�!");
    return 0;
}

//�޸ķ�Դ
bool updateHouse(int house_id, struct House* head) {
    struct House* current = head->next;  // ��ͷ����ʼ����
    while (current != NULL) {
        if (current->id == house_id) {  // �ҵ�ƥ��ķ�Դ
            // ��ȡ�û�������·�Դ��Ϣ
            char new_houseowner[100];
            char new_phoneNumber[20];
            char new_city[100];
            char new_urban[100];
            char new_community[100];
            int new_floor;
            enum Toward new_toward;
            int new_room;
            int new_hall;
            float new_area;
            char new_fitment[100];
            float new_rent;
            float new_agency_fee;
            float new_deposit;
            int new_time1;
            int new_time2;
            int new_status;

            // ��ʾ�û������µķ�Դ��Ϣ
            printf("�������µķ�������: ");
            scanf("%s", new_houseowner);
            printf("�������µĵ绰����: ");
            scanf("%s", new_phoneNumber);
            printf("�������µĳ���: ");
            scanf("%s", new_city);
            printf("�������µĳ���: ");
            scanf("%s", new_urban);
            printf("�������µ�С��: ");
            scanf("%s", new_community);
            printf("�������µ�¥��: ");
            scanf("%d", &new_floor);
            printf("�������µĳ���(0=��, 1=��, 2=��, 3=��): ");
            scanf("%d", &new_toward);
            printf("�������µķ�������: ");
            scanf("%d", &new_room);
            printf("�������µ���������: ");
            scanf("%d", &new_hall);
            printf("�������µ����: ");
            scanf("%f", &new_area);
            printf("�������µ�װ�����: ");
            scanf("%s", new_fitment);
            printf("�������µ����: ");
            scanf("%f", &new_rent);
            printf("�������µ��н��: ");
            scanf("%f", &new_agency_fee);
            printf("�������µ�Ѻ��: ");
            scanf("%f", &new_deposit);
            printf("�������µĳ���ʱ��(��): ");
            scanf("%d", &new_time1);
            printf("�������µĳ���ʱ��(��): ");
            scanf("%d", &new_time2);
            printf("�������µķ�Դ״̬(0=����, 1=����,2=������): ");
            scanf("%d", &new_status);

            // ���·�Դ�ĸ�����Ϣ
            strcpy(current->houseowner, new_houseowner);
            strcpy(current->number, new_phoneNumber);
            strcpy(current->city, new_city);
            strcpy(current->urban, new_urban);
            strcpy(current->community, new_community);
            current->floor = new_floor;
            current->room = new_room;
            current->hall = new_hall;
            current->Area = new_area;
            strcpy(current->fitment, new_fitment);
            current->rent = new_rent;
            current->agency_fee = new_agency_fee;
            current->deposit = new_deposit;
            current->time1 = new_time1;
            current->time2 = new_time2;
            current->toward = new_toward;
            current->status = new_status;

            printf("��Դ��Ϣ���³ɹ���\n");
            return true;  // �޸ĳɹ�
        }
        current = current->next;  // ����������
    }
    printf("δ�ҵ�ƥ��ķ�Դ��\n");
    return false;  // δ�ҵ���Ӧ��Դ���޸�ʧ��
}
//ɾ����Դ
bool deleteHouse(int house_id, struct House* head) {
    struct House* current = head->next; // ��ͷ����ʼ����
    while (current != NULL) {
        if (current->id == house_id) {  // �ҵ�ƥ��ķ�Դ
            // �޸�ǰ��ڵ��ָ��
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            // �ͷŵ�ǰ�ڵ���ڴ�
            free(current);
            return true;  // ɾ���ɹ�
        }
        current = current->next;  // ����������
    }
    return false;  // δ�ҵ���Ӧ��Դ��ɾ��ʧ��
}
