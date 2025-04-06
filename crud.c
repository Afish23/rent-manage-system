//��ɾ���
#include "crud.h"
#include "utils.h"

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

// �������˳����������û���Ϣ
void printUsersInOrder(struct User* head) {
    if (head == NULL) {
        printf("����Ϊ�գ�û���û���Ϣ��\n");
        return;
    }

    struct User* current = head;

    // �������Ա��Ϣ
    printf("===== ����Ա =====\n");
    current = head;
    while (current != NULL) {
        if (current->role == 1) {
            printf("�û���: %s\n", current->username);
            printf("����: %s\n", current->password);
            printf("�绰����: %s\n", current->phoneNumber);
            printf("-----------------------------\n");
        }
        current = current->next;
    }

    // ����н���Ϣ
    printf("===== �н� =====\n");
    current = head;
    while (current != NULL) {
        if (current->role == 2) {
            printf("�û���: %s\n", current->username);
            printf("����: %s\n", current->password);
            printf("�绰����: %s\n", current->phoneNumber);
            printf("-----------------------------\n");
        }
        current = current->next;
    }

    // ��������Ϣ
    printf("===== ��� =====\n");
    current = head;
    while (current != NULL) {
        if (current->role == 3) {
            printf("�û���: %s\n", current->username);
            printf("����: %s\n", current->password);
            printf("�绰����: %s\n", current->phoneNumber);
            printf("-----------------------------\n");
        }
        current = current->next;
    }
    getchar();
    clear();
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

//��ӷ�Դ
int addHouse(struct House* head, struct House* tail) {
    struct House* newHouse = (struct House*)malloc(sizeof(struct House));
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
    scanf("%s", &newHouse->houseowner);

    printf("�����뷿���绰: ");
    scanf("%s", &newHouse->number);


    printf("������������: ");
    scanf("%s", &newHouse->city);

    printf("������������/��: ");
    scanf("%s", &newHouse->urban);

    printf("����������С������: ");
    scanf("%s", &newHouse->community);

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
    scanf("%s", &newHouse->fitment);

    printf("���������: ");
    scanf("%f", &newHouse->rent);

    printf("�������н��: ");
    scanf("%f", &newHouse->agency_fee);

    printf("������Ѻ��: ");
    scanf("%f", &newHouse->deposit);

    newHouse->status = 0;

    newHouse->rentStartTime = 0;
    newHouse->rentDuration = 0;

    strcpy(newHouse->agentname, "");
    strcpy(newHouse->tenantname, "");

    newHouse->prev = tail;
    tail->next = newHouse;
    newHouse->next = NULL;
    printf("��ӳɹ�!\n");
    getchar();
    clear();
    return 0;
}

//�޸ķ�Դ
bool updateHouse(struct House* head) {
    int house_id;
    printf("������Ҫ�޸ĵķ�ԴID��");
    scanf_s("%d", &house_id);
    struct House* current = head->next;  // ��ͷ����ʼ����
    while (current != NULL) {
        if (current->id == house_id) {  // �ҵ�ƥ��ķ�Դ
            // ��ȡ�û�������·�Դ��Ϣ
            char new_houseowner[100];
            char new_phoneNumber[20];

            int new_room;
            int new_hall;
            int new_status;

            char new_fitment[100];
            float new_rent;
            float new_agency_fee;
            float new_deposit;

            // ��ʾ�û������µķ�Դ��Ϣ
            printf("�������µķ�������: ");
            scanf("%s", new_houseowner);
            printf("�������µĵ绰����: ");
            scanf("%s", new_phoneNumber);

            printf("�������µ��ҵ�����: ");
            scanf("%d", &new_room);
            printf("�������µ���������: ");
            scanf("%d", &new_hall);

            printf("�������µ�װ�����: ");
            scanf("%s", new_fitment);

            printf("�������µ����: ");
            scanf("%f", &new_rent);
            printf("�������µ��н��: ");
            scanf("%f", &new_agency_fee);
            printf("�������µ�Ѻ��: ");
            scanf("%f", &new_deposit);

            printf("�����뷿Դ״̬: ");
            scanf("%d", &new_status);

            // ���·�Դ�ĸ�����Ϣ
            strcpy(current->houseowner, new_houseowner);
            strcpy(current->number, new_phoneNumber);

            current->room = new_room;
            current->hall = new_hall;

            strcpy(current->fitment, new_fitment);
            current->rent = new_rent;
            current->agency_fee = new_agency_fee;
            current->deposit = new_deposit;
            current->status = new_status;

            printf("��Դ��Ϣ���³ɹ���\n");
            getchar();
            clear();
            return true;  // �޸ĳɹ�
        }
        current = current->next;  // ����������
    }
    printf("δ�ҵ�ƥ��ķ�Դ��\n");
    getchar();
    clear();
    return false;  // δ�ҵ���Ӧ��Դ���޸�ʧ��
}

//ɾ����Դ
bool deleteHouse(struct House* head) {
    int house_id;
    printf("������Ҫɾ���ķ�ԴID��");
    scanf_s("%d", &house_id);
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
            printf("ɾ���ɹ�\n");
            printf("������س���������");
            getchar();
            clear();
            return true;  // ɾ���ɹ�
        }
        current = current->next;  // ����������
    }
    printf("ɾ��ʧ��\n");
    printf("������س���������");
    getchar();
    clear();
    return false;  // δ�ҵ���Ӧ��Դ��ɾ��ʧ��
}



//����ⷿ��Ϣ
bool addRent(struct Rent** tail1, struct User* agent, struct House* head) {
    struct Rent* p1;
    p1 = (struct Rent*)malloc(sizeof(struct Rent)); // �����ڴ�
    if (p1 == NULL) {  // �ж��ڴ��Ƿ����ɹ�
        printf("�ڴ�ռ����ʧ��");
        return false;
    }
    // ���½ڵ�����ⷿ����
    printf("�������ⷿ��Ϣ:\n");
    printf("�������ⷿ ID: ");
    scanf("%d", &p1->id);
    printf("�������ͬǩ��ʱ�䣨���磺20250401��: ");
    scanf("%d", &p1->contractTime);
    printf("�������ⷿ��ʼʱ�䣨���磺20250401��: ");
    scanf("%d", &p1->rentStartTime);
    printf("���������ڣ���λ���£�: ");
    scanf("%d", &p1->rentDuration);
    printf("�����뷿ԴID: ");
    scanf("%d", &p1->house_id);
    printf("�������������: ");
    scanf("%s", &p1->tenantname);
    strcpy(p1->agentname, agent->username);
    struct House* current = head->next;  // ��ͷ����ʼ����
    while (current != NULL) {
        if (current->id == p1->house_id && current->status == 0) {  // �ҵ�ƥ��ķ�Դ
            current->rentStartTime = p1->rentStartTime;
            current->rentDuration = p1->rentDuration;
            strcpy(current->tenantname, p1->tenantname);
            strcpy(current->agentname, p1->agentname);
            current->status = 1;
            p1->statement = 1;  // ���� 1 ��ʾ��Ч״̬
            (*tail1)->next = p1;
            p1->prev = (*tail1);
            (*tail1) = p1;
            (*tail1)->next = NULL;
            printf("�ⷿ�ɹ�\n");
            printf("������س���������");
            getchar();
            clear();
            return true;
        }
        current = current->next;  // ����������
    }
    printf("�ⷿʧ��\n");
    printf("������س���������");
    getchar();
    clear();
    return false;;
}

void printRentsInOrder(struct Rent* head1) {
    if (head1->next == NULL) {
        printf("����Ϊ�գ�û���ⷿ��Ϣ��\n");
        return;
    }

    struct Rent* current = head1->next;
    int count = 1;

    while (current != NULL) {
        printf("�ⷿ��Ϣ %d:\n", count++);
        printf("  �ⷿ���: %d\n", current->id);
        printf("  ��ͬǩ������: %d\n", current->contractTime);
        printf("  ���⿪ʼ����: %d\n", current->rentStartTime);
        printf("  Ԥ�Ƴ���ʱ��: %d\n", current->rentDuration);
        printf("  �н�����: %s\n", current->agentname);
        printf("  �������: %s\n", current->tenantname);
        printf("  ��ԴID: %d\n", current->house_id);
        printf("  ״̬: %s\n", current->statement == 0 ? "�����" : "������");
        printf("\n");

        current = current->next; // �ƶ�����һ���ڵ�
    }
    getchar();
    clear();
}

void printMyRentsInOrder(struct Rent* head1, struct User* tenant) {
    if (head1->next == NULL) {
        printf("����Ϊ�գ�û���ⷿ��Ϣ��\n");
        return;
    }
    else {
        printf("�����ⷿ��Ϣ���£�\n");
    }
    struct Rent* current = head1->next;
    int count = 1;

    while (current != NULL) {
        if (!strcmp(current->tenantname, tenant->username)) {
            printf("�ⷿ��Ϣ %d:\n", count++);
            printf("  �ⷿ���: %d\n", current->id);
            printf("  ��ͬǩ������: %d\n", current->contractTime);
            printf("  ���⿪ʼ����: %d\n", current->rentStartTime);
            printf("  Ԥ�Ƴ���ʱ��: %d\n", current->rentDuration);
            printf("  �н�����: %s\n", current->agentname);
            printf("  ��ԴID: %d\n", current->house_id);
            printf("  ״̬: %s\n", current->statement == 0 ? "�����" : "������");
            printf("\n");
        }
        current = current->next; // �ƶ�����һ���ڵ�
    }
    if (count == 0) {
        printf("��û���ⷿ��Ϣ��\n");
    }
    getchar();
    clear();
}

//�����ⷿ��Ϣ
struct Rent* findRent(int id, struct Rent* head1) {
    while (head1 != NULL) {
        if (head1->id == id)return head1;
        head1 = head1->next;
    }
    return NULL;
}

void updateRent(struct Rent* head1) {
    int choice,jug = 1,id;
    printf("����id\n");
    scanf("%d", &id);
    struct Rent* p1 = findRent(id, head1);
    if (p1 != NULL) {
        while (jug) {
            printf("��ѡ��Ҫ�޸ĵ��ⷿ��Ϣ�ֶ�:\n");
            printf("1. �ⷿ���\n");
            printf("2. ��ͬǩ������\n");
            printf("3. ���⿪ʼ����\n");
            printf("4. Ԥ�Ƴ���ʱ��\n");
            printf("5. �н�����\n");
            printf("6. �������\n");
            printf("7. ��ԴID\n");
            printf("8. ����״̬\n");
            printf("0. �˳��޸�\n");
            scanf("%d", &choice);
            switch (choice) {
            case 0:
                jug = 0; 
                break;
            case 1:
                printf("�������µ��ⷿ���: ");
                scanf("%d", &p1->id);
                getchar();
                clear();
                continue;
            case 2:
                printf("�������µĺ�ͬǩ������: ");
                scanf("%d", &p1->contractTime);
                getchar();
                clear();
                continue;
            case 3:
                printf("�������µĳ��⿪ʼ����: ");
                scanf("%d", &p1->rentStartTime);
                getchar();
                clear();
                continue;
            case 4:
                printf("�������µ�Ԥ�Ƴ���ʱ��: ");
                scanf("%d", &p1->rentDuration);
                getchar();
                clear();
                continue;
            case 5:
                printf("�������µ��н�����: ");
                scanf("%s", &p1->agentname);
                getchar();
                clear();
                continue;
            case 6:
                printf("�������µ��������: ");
                scanf("%s", &p1->tenantname);
                getchar();
                clear();
                continue;
            case 7:
                printf("�������µķ�ԴID: ");
                scanf("%d", &p1->house_id);
                getchar();
                clear();
                continue;
            case 8:
                printf("�������µ�����״̬ (0-�����, 1-������): ");
                scanf("%d", &p1->statement);
                getchar();
                clear();
                continue;
            default:
                printf("��Чѡ�����������\n");
                getchar();
                clear();
                continue;
            }
        }
        printf("�޸ĳɹ�");
        getchar();
        clear();
    }
    else {
        printf("û���ҵ����޸�ʧ��");
        getchar();
        clear();
    }
}

//ɾ���ⷿ��Ϣ
bool deleteRent(struct Rent* head1) {
    int id;
    printf("������Ҫɾ�����ⷿ��ϢID��");
    scanf_s("%d", &id);
    struct Rent* current = head1->next; // ��ͷ����ʼ����
    while (current != NULL) {
        if (current->id == id) {  // �ҵ�ƥ�����Ϣ
            // �޸�ǰ��ڵ��ָ��
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            // �ͷŵ�ǰ�ڵ���ڴ�
            free(current);
            printf("ɾ���ɹ�\n");
            printf("������س���������");
            getchar();
            clear();
            return true;  // ɾ���ɹ�
        }
        current = current->next;  // ����������
    }
    printf("ɾ��ʧ��\n");
    printf("������س���������");
    getchar();
    clear();
    return false;  // δ�ҵ���Ӧ��Ϣ��ɾ��ʧ��
}

bool addAppointment(struct Appointment** tail2, struct User* tenant) {
    struct Appointment* r1;
    int choice;
    r1 = (struct Appointment*)malloc(sizeof(struct Appointment)); // �����ڴ�
    if (r1 == NULL) {  // �ж��ڴ��Ƿ����ɹ�
        printf("�ڴ�ռ����ʧ��");
        return false;
    }
    // ���½ڵ�����ⷿ����
    printf("�����뿴����Ϣ:\n");
    printf("�����뿴�� ID: ");
    scanf("%d", &r1->id);
    //TODO �жϷ�Դ�Ƿ����
    printf("�����뷿Դ ID: ");
    scanf("%d", &r1->house_id);
    printf("�����뿴��ʱ�䣨���磺20250401��: ");
    scanf("%d", &r1->time);
    //TODO �ж��н��Ƿ����
    printf("�Ƿ�ָ���н飿1���ǣ�2����: ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("�������н�����: ");
        scanf("%s", &r1->agentname);
        printf("ָ���н�ɹ�\n");
    }
    else {
        printf("δָ���н飬���ɹ�˾ͳһ����\n");
        strcpy(r1->agentname, "δ����");
    }
    strcpy(r1->tenantname, tenant->username);
    r1->duration = 0;
    r1->statement = 0;  // ���� 1 ��ʾ�����
    strcpy(r1->feedback, "");
    (*tail2)->next = r1;
    r1->prev = (*tail2);
    (*tail2) = r1;
    (*tail2)->next = NULL;
    printf("����ɹ�\n");
    printf("������س���������");
    getchar();
    clear();
    return true;
}

bool addFeedback(struct Appointment* head2, struct User* tenant) {
    struct Appointment* current = head2->next;
    int id, count = 0;
    printf("���ɷ����Ŀ���ԤԼ���£�\n");
    while (current != NULL) {
        // ����Ƿ�Ϊ�Ѵ���״̬ (statement == 1) ���������ƥ��
        if (current->statement == 1 && strcmp(current->tenantname, tenant->username) == 0) {
            count++;
            printf("�������: %d\n", current->id);
            printf("����ʱ��: %d\n", current->time);
            printf("����ʱ��: %d\n", current->duration);
            printf("�н�����: %s\n", current->agentname);
            printf("��ԴID: %d\n", current->house_id);
            printf("-----------------------------\n");
        }
        // �ƶ�����һ���ڵ�
        current = current->next;
    }
    if (count == 0) {
        printf("��û�пɷ����Ŀ���ԤԼ\n");
        printf("������س���������");
        getchar();
        clear();
        return false;
    }
    printf("������Ҫ�����Ŀ���ԤԼid\n");
    scanf("%d", &id);
    struct Appointment* p = findAppointment(id, head2);
    if (p != NULL) {
        printf("�����뿴������: ");
        scanf("%s", &p->feedback);
        printf("��������ԤԼ�ɹ�\n");
        printf("������س���������");
        getchar();
        clear();
        return true;
    }
    printf("û�и�ԤԼ\n");
    printf("������س���������");
    getchar();
    clear();
    return false;
}

bool handleAppointment(struct Appointment* head2, struct User* agent) {
    struct Appointment* current = head2->next;
    int id, count = 0;
    printf("���Ĵ�����ԤԼ���£�\n");
    while (current != NULL) {
        // ����Ƿ�Ϊ������״̬ (statement == 0) ���н�����ƥ��
        if (current->statement == 0 && strcmp(current->agentname, agent->username) == 0) {
            count++;
            printf("�������: %d\n", current->id);
            printf("����ʱ��: %d\n", current->time);
            printf("�������: %s\n", current->tenantname);
            printf("��ԴID: %d\n", current->house_id);
            printf("-----------------------------\n");
        }
        // �ƶ�����һ���ڵ�
        current = current->next;
    }
    if (count == 0) {
        printf("��û��Ҫ�����ԤԼ\n");
        printf("������س���������");
        getchar();
        clear();
        return false;
    }
    printf("������Ҫ�����ԤԼid\n");
    scanf("%d", &id);
    struct Appointment* p = findAppointment(id, head2);
    if (p != NULL) {
        printf("�����뿴��ʱ�������磺0.5����0.5Сʱ��: ");
        scanf("%d", &p->duration);
        p->statement = 1;
        printf("����ԤԼ�ɹ�\n");
        printf("������س���������");
        getchar();
        clear();
        return true;
    }
    printf("û�и�ԤԼ\n");
    printf("������س���������");
    getchar();
    clear();
    return false;
}


bool appointAgent(struct Appointment* head2) {
    int id;
    printf("������ԤԼid\n");
    scanf("%d", &id);
    struct Appointment* p = findAppointment(id, head2);
    if (!strcmp(p->agentname,"δ����")) {
        //TODO �ж��н��Ƿ����
        printf("�������н�����: ");
        scanf("%19s", &p->agentname);
        printf("ָ���ɹ�");
        getchar();
        clear();
        return true;
    }
    else {
        printf("��ԤԼ�Ѵ����н�");
        getchar();
        clear();
        return false;
    }
}

void printAppointmentsInOrder(struct Appointment* head2) {
    if (head2->next == NULL) {
        printf("����Ϊ�գ�û��ԤԼ��Ϣ��\n");
        return;
    }

    struct Appointment* current = head2->next;
    int count = 1;

    while (current != NULL) {
        printf("ԤԼ��Ϣ %d:\n", count++);
        printf("  �������: %d\n", current->id);
        printf("  ����ʱ��: %d\n", current->time);
        printf("  ����ʱ��: %d\n", current->duration);
        printf("  �н�����: %s\n", current->agentname);
        printf("  �������: %s\n", current->tenantname);
        printf("  ��ԴID: %d\n", current->house_id);
        printf("  ��ͷ���: %s\n", current->feedback);
        printf("  ״̬: %s\n", current->statement == 0 ? "������" : "�����");
        printf("\n");

        current = current->next; // �ƶ�����һ���ڵ�
    }
    getchar();
    clear();
}

void printMyAppointmentsInOrder(struct Appointment* head2, struct User* tenant) {
    if (head2->next == NULL) {
        printf("����Ϊ�գ�û��ԤԼ��Ϣ��\n");
        return;
    }
    else {
        printf("����ԤԼ��Ϣ���£�\n");
    }

    struct Appointment* current = head2->next;
    int count = 1;

    while (current != NULL) {
        if (!strcmp(current->tenantname, tenant->username)) {
            printf("ԤԼ��Ϣ %d:\n", count++);
            printf("  �������: %d\n", current->id);
            printf("  ����ʱ��: %d\n", current->time);
            printf("  ����ʱ��: %d\n", current->duration);
            printf("  �н�����: %s\n", current->agentname);
            printf("  ��ԴID: %d\n", current->house_id);
            printf("  ��ͷ���: %s\n", current->feedback);
            printf("  ״̬: %s\n", current->statement == 0 ? "������" : "�����");
            printf("\n");
        }

        current = current->next; // �ƶ�����һ���ڵ�
    }
    if (count == 0) {
        printf("��û��ԤԼ��Ϣ��\n");
    }
    getchar();
    clear();
}

struct Appointment* findAppointment(int id, struct Appointment* head2) {
    while (head2 != NULL) {
        if (head2->id == id)return head2;
        head2 = head2->next;
    }
    return NULL;
}

void updateAppointment(struct Appointment* head2) {
    int choice, jug = 1, id1;
    printf("����id\n");
    scanf("%d", &id1);
    struct Appointment* p1 = findAppointment(id1, head2);
    if (p1 != NULL) {
        while (jug) {
            printf("��ѡ��Ҫ�޸ĵ�ԤԼ��Ϣ�ֶ�:\n");
            printf("1. �������\n");
            printf("2. ����ʱ��\n");
            printf("3. ����ʱ��\n");
            printf("4. �н�����\n");
            printf("5. �������\n");
            printf("6. ��ԴID\n");
            printf("7. ��ͷ���\n");
            printf("8. ԤԼ״̬\n");
            printf("0. �˳��޸�\n");

            scanf("%d", &choice);
            switch (choice) {
            case 0:
                jug = 0;
                break;
            case 1:
                printf("�������µĿ������: ");
                scanf("%d", &p1->id);
                getchar();
                clear();
                continue;
            case 2:
                printf("�������µĿ���ʱ�䣨���磺20250401��: ");
                scanf("%d", &p1->time);
                getchar();
                clear();
                continue;
            case 3:
                printf("�������µĿ���ʱ������λ��Сʱ��: ");
                scanf("%d", &p1->duration);
                getchar();
                clear();
                continue;
            case 4:
                printf("�������µ��н�����: ");
                scanf("%19s", &p1->agentname);
                getchar();
                clear();
                continue;
            case 5:
                printf("�������µ��������: ");
                scanf("%19s", &p1->tenantname);
                getchar();
                clear();
                continue;
            case 6:
                printf("�������µķ�ԴID: ");
                scanf("%d", &p1->house_id);
                getchar();
                clear();
                continue;
            case 7:
                printf("�������µ���ͷ��������19���ַ���: ");
                scanf("%19s", &p1->feedback);
                getchar();
                clear();
                continue;
            case 8:
                printf("�������µ�ԤԼ״̬ (0-�����, 1-������): ");
                scanf("%d", &p1->statement);
                getchar();
                clear();
                continue;
            default:
                printf("��Чѡ�����������\n");
                getchar();
                clear();
                continue;
            }
        }
        printf("�޸ĳɹ�");
        getchar();
        clear();
    }
    else {
        printf("û���ҵ����޸�ʧ��");
        getchar();
        clear();
    }
}

void deleteAppointment(struct Appointment* head2) {
    int id;
    printf("������Ҫɾ����ԤԼ��ϢID��");
    scanf_s("%d", &id);
    struct Appointment* current = head2->next; // ��ͷ����ʼ����
    while (current != NULL) {
        if (current->id == id) {  // �ҵ�ƥ�����Ϣ
            // �޸�ǰ��ڵ��ָ��
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            // �ͷŵ�ǰ�ڵ���ڴ�
            free(current);
            printf("ɾ���ɹ�\n");
            printf("������س���������");
            getchar();
            clear();
            return true;  // ɾ���ɹ�
        }
        current = current->next;  // ����������
    }
    printf("ɾ��ʧ��\n");
    printf("������س���������");
    getchar();
    clear();
    return false;  // δ�ҵ���Ӧ��Ϣ��ɾ��ʧ��
}
