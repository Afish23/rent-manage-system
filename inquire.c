#include "inquire.h"
#include "models.h"
// inquire.c
#include "utils.h"

void simpleQueryHouse1(struct House* head) {
    char city[20];
    printf("�����������У�");
    scanf("%s", city);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (strcmp(p->city, city) == 0) {
            printf("��ԴID��%d\n", p->id);
            printf("����ţ�%d\n", p->house_id);
            printf("�������֣�%s\n", p->houseowner);
            printf("�����绰��%s\n", p->number);
            printf("�����У�%s\n", p->city);
            printf("������/����%s\n", p->urban);
            printf("����С����%s\n", p->community);
            printf("¥�㣺%d\n", p->floor);
            printf("����");
            switch ((int)p->toward)
            {
            case 1:
                printf("��\n");
                break;
            case 2:
                printf("��\n");
                break;
            case 3:
                printf("��\n");
                break;
            case 4:
                printf("��\n");
                break;
            case 5:
                printf("����\n");
                break;
            case 6:
                printf("����\n");
                break;
            case 7:
                printf("����\n");
                break;
            case 8:
                printf("����\n");
                break;

            }
            printf("������%d��%d��\n", p->room,p->hall);
            printf("�����%f\n", p->Area);
            printf("װ���������/δװ�ޣ���%s\n", p->fitment);
            printf("���%f\n", p->rent);
            printf("�ⷿ���ڣ�%d-%d\n", p->time1,p->time2);
            printf("�н飺%s\n", p->agentname);
            printf("��ͣ�%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
    printf("�밲�س���������");
    getchar();
    clear();
}

// 2. ��������/����ѯ��Դ
void simpleQueryHouse2(struct House* head) {
    char urban[20];
    printf("������������/����");
    scanf("%s", urban);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (strcmp(p->urban, urban) == 0) {
            printf("��ԴID��%d\n", p->id);
            printf("����ţ�%d\n", p->house_id);
            printf("�������֣�%s\n", p->houseowner);
            printf("�����绰��%s\n", p->number);
            printf("�����У�%s\n", p->city);
            printf("������/����%s\n", p->urban);
            printf("����С����%s\n", p->community);
            printf("¥�㣺%d\n", p->floor);
            printf("����");
            switch ((int)p->toward)
            {
            case 1:
                printf("��\n");
                break;
            case 2:
                printf("��\n");
                break;
            case 3:
                printf("��\n");
                break;
            case 4:
                printf("��\n");
                break;
            case 5:
                printf("����\n");
                break;
            case 6:
                printf("����\n");
                break;
            case 7:
                printf("����\n");
                break;
            case 8:
                printf("����\n");
                break;

            }
            printf("������%d��%d��\n", p->room, p->hall);
            printf("�����%f\n", p->Area);
            printf("װ���������/δװ�ޣ���%s\n", p->fitment);
            printf("���%f\n", p->rent);
            printf("�ⷿ���ڣ�%d-%d\n", p->time1, p->time2);
            printf("�н飺%s\n", p->agentname);
            printf("��ͣ�%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
    printf("�밲�س���������");
    getchar();
    clear();
}

// 3. ������С����ѯ��Դ
void simpleQueryHouse3(struct House* head) {
    char community[20];
    printf("����������С����");
    scanf("%s", community);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (strcmp(p->community, community) == 0) {
            printf("��ԴID��%d\n", p->id);
            printf("����ţ�%d\n", p->house_id);
            printf("�������֣�%s\n", p->houseowner);
            printf("�����绰��%s\n", p->number);
            printf("�����У�%s\n", p->city);
            printf("������/����%s\n", p->urban);
            printf("����С����%s\n", p->community);
            printf("¥�㣺%d\n", p->floor);
            printf("����");
            switch ((int)p->toward)
            {
            case 1:
                printf("��\n");
                break;
            case 2:
                printf("��\n");
                break;
            case 3:
                printf("��\n");
                break;
            case 4:
                printf("��\n");
                break;
            case 5:
                printf("����\n");
                break;
            case 6:
                printf("����\n");
                break;
            case 7:
                printf("����\n");
                break;
            case 8:
                printf("����\n");
                break;

            }
            printf("������%d��%d��\n", p->room, p->hall);
            printf("�����%f\n", p->Area);
            printf("װ���������/δװ�ޣ���%s\n", p->fitment);
            printf("���%f\n", p->rent);
            printf("�ⷿ���ڣ�%d-%d\n", p->time1, p->time2);
            printf("�н飺%s\n", p->agentname);
            printf("��ͣ�%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
    printf("�밲�س���������");
    getchar();
    clear();
}

// 4. �������ѯ��Դ
void simpleQueryHouse4(struct House* head) {
    enum Toward toward;
    printf("�����볯��0-����1-�ϣ�2-����3-����4-���ϣ�5-������6-���ϣ�7-��������");
    scanf("%d", (int*)&toward);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (p->toward == toward) {
            printf("��ԴID��%d\n", p->id);
            printf("����ţ�%d\n", p->house_id);
            printf("�������֣�%s\n", p->houseowner);
            printf("�����绰��%s\n", p->number);
            printf("�����У�%s\n", p->city);
            printf("������/����%s\n", p->urban);
            printf("����С����%s\n", p->community);
            printf("¥�㣺%d\n", p->floor);
            printf("����");
            switch ((int)p->toward)
            {
            case 1:
                printf("��\n");
                break;
            case 2:
                printf("��\n");
                break;
            case 3:
                printf("��\n");
                break;
            case 4:
                printf("��\n");
                break;
            case 5:
                printf("����\n");
                break;
            case 6:
                printf("����\n");
                break;
            case 7:
                printf("����\n");
                break;
            case 8:
                printf("����\n");
                break;

            }
            printf("������%d��%d��\n", p->room, p->hall);
            printf("�����%f\n", p->Area);
            printf("װ���������/δװ�ޣ���%s\n", p->fitment);
            printf("���%f\n", p->rent);
            printf("�ⷿ���ڣ�%d-%d\n", p->time1, p->time2);
            printf("�н飺%s\n", p->agentname);
            printf("��ͣ�%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
    printf("�밲�س���������");
    getchar();
    clear();
}

// 5. ��������ѯ��Դ
void simpleQueryHouse5(struct House* head) {
    int room, hall;
    printf("�������ҵ�������");
    scanf("%d", &room);
    printf("����������������");
    scanf("%d", &hall);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (p->room == room && p->hall == hall) {
            printf("��ԴID��%d\n", p->id);
            printf("����ţ�%d\n", p->house_id);
            printf("�������֣�%s\n", p->houseowner);
            printf("�����绰��%s\n", p->number);
            printf("�����У�%s\n", p->city);
            printf("������/����%s\n", p->urban);
            printf("����С����%s\n", p->community);
            printf("¥�㣺%d\n", p->floor);
            printf("����");
            switch ((int)p->toward)
            {
            case 1:
                printf("��\n");
                break;
            case 2:
                printf("��\n");
                break;
            case 3:
                printf("��\n");
                break;
            case 4:
                printf("��\n");
                break;
            case 5:
                printf("����\n");
                break;
            case 6:
                printf("����\n");
                break;
            case 7:
                printf("����\n");
                break;
            case 8:
                printf("����\n");
                break;

            }
            printf("������%d��%d��\n", p->room, p->hall);
            printf("�����%f\n", p->Area);
            printf("װ���������/δװ�ޣ���%s\n", p->fitment);
            printf("���%f\n", p->rent);
            printf("�ⷿ���ڣ�%d-%d\n", p->time1, p->time2);
            printf("�н飺%s\n", p->agentname);
            printf("��ͣ�%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
    printf("�밲�س���������");
    getchar();
    clear();
}

// 6. ��װ�������ѯ��Դ
void simpleQueryHouse6(struct House* head) {
    char fitment[10];
    printf("������װ�������");
    scanf("%s", fitment);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (strcmp(p->fitment, fitment) == 0) {
            printf("��ԴID��%d\n", p->id);
            printf("����ţ�%d\n", p->house_id);
            printf("�������֣�%s\n", p->houseowner);
            printf("�����绰��%s\n", p->number);
            printf("�����У�%s\n", p->city);
            printf("������/����%s\n", p->urban);
            printf("����С����%s\n", p->community);
            printf("¥�㣺%d\n", p->floor);
            printf("����");
            switch ((int)p->toward)
            {
            case 1:
                printf("��\n");
                break;
            case 2:
                printf("��\n");
                break;
            case 3:
                printf("��\n");
                break;
            case 4:
                printf("��\n");
                break;
            case 5:
                printf("����\n");
                break;
            case 6:
                printf("����\n");
                break;
            case 7:
                printf("����\n");
                break;
            case 8:
                printf("����\n");
                break;

            }
            printf("������%d��%d��\n", p->room, p->hall);
            printf("�����%f\n", p->Area);
            printf("װ���������/δװ�ޣ���%s\n", p->fitment);
            printf("���%f\n", p->rent);
            printf("�ⷿ���ڣ�%d-%d\n", p->time1, p->time2);
            printf("�н飺%s\n", p->agentname);
            printf("��ͣ�%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
    printf("�밲�س���������");
    getchar();
    clear();
}

// 7. ���н��ѯ��Դ
void simpleQueryHouse7(struct House* head) {
    char username[20];
    printf("�������н��û�����");
    scanf("%s", username);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (p->user_agency != NULL && strcmp(p->user_agency->username, username) == 0) {
            printf("��ԴID��%d\n", p->id);
            printf("����ţ�%d\n", p->house_id);
            printf("�������֣�%s\n", p->houseowner);
            printf("�����绰��%s\n", p->number);
            printf("�����У�%s\n", p->city);
            printf("������/����%s\n", p->urban);
            printf("����С����%s\n", p->community);
            printf("¥�㣺%d\n", p->floor);
            printf("����");
            switch ((int)p->toward)
            {
            case 1:
                printf("��\n");
                break;
            case 2:
                printf("��\n");
                break;
            case 3:
                printf("��\n");
                break;
            case 4:
                printf("��\n");
                break;
            case 5:
                printf("����\n");
                break;
            case 6:
                printf("����\n");
                break;
            case 7:
                printf("����\n");
                break;
            case 8:
                printf("����\n");
                break;

            }
            printf("������%d��%d��\n", p->room, p->hall);
            printf("�����%f\n", p->Area);
            printf("װ���������/δװ�ޣ���%s\n", p->fitment);
            printf("���%f\n", p->rent);
            printf("�ⷿ���ڣ�%d-%d\n", p->time1, p->time2);
            printf("�н飺%s\n", p->agentname);
            printf("��ͣ�%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
    printf("�밲�س���������");
    getchar();
    clear();
}

void rangeQueryRent(struct House* head) {
    float min_rent, max_rent;
    printf("��������С���");
    scanf("%f", &min_rent);
    printf("������������");
    scanf("%f", &max_rent);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (p->rent >= min_rent && p->rent <= max_rent) {
            printf("��ԴID��%d\n", p->id);
            printf("����ţ�%d\n", p->house_id);
            printf("�������֣�%s\n", p->houseowner);
            printf("�����绰��%s\n", p->number);
            printf("�����У�%s\n", p->city);
            printf("������/����%s\n", p->urban);
            printf("����С����%s\n", p->community);
            printf("¥�㣺%d\n", p->floor);
            printf("����");
            switch ((int)p->toward)
            {
            case 1:
                printf("��\n");
                break;
            case 2:
                printf("��\n");
                break;
            case 3:
                printf("��\n");
                break;
            case 4:
                printf("��\n");
                break;
            case 5:
                printf("����\n");
                break;
            case 6:
                printf("����\n");
                break;
            case 7:
                printf("����\n");
                break;
            case 8:
                printf("����\n");
                break;

            }
            printf("������%d��%d��\n", p->room, p->hall);
            printf("�����%f\n", p->Area);
            printf("װ���������/δװ�ޣ���%s\n", p->fitment);
            printf("���%f\n", p->rent);
            printf("�ⷿ���ڣ�%d-%d\n", p->time1, p->time2);
            printf("�н飺%s\n", p->agentname);
            printf("��ͣ�%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
    printf("�밲�س���������");
    getchar();
    clear();
}

// ��Χ��ѯ¥��
void rangeQueryFloor(struct House* head) {
    int min_floor, max_floor;
    printf("��������С¥�㣺");
    scanf("%d", &min_floor);
    printf("���������¥�㣺");
    scanf("%d", &max_floor);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (p->floor >= min_floor && p->floor <= max_floor) {
            printf("��ԴID��%d\n", p->id);
            printf("����ţ�%d\n", p->house_id);
            printf("�������֣�%s\n", p->houseowner);
            printf("�����绰��%s\n", p->number);
            printf("�����У�%s\n", p->city);
            printf("������/����%s\n", p->urban);
            printf("����С����%s\n", p->community);
            printf("¥�㣺%d\n", p->floor);
            printf("����");
            switch ((int)p->toward)
            {
            case 1:
                printf("��\n");
                break;
            case 2:
                printf("��\n");
                break;
            case 3:
                printf("��\n");
                break;
            case 4:
                printf("��\n");
                break;
            case 5:
                printf("����\n");
                break;
            case 6:
                printf("����\n");
                break;
            case 7:
                printf("����\n");
                break;
            case 8:
                printf("����\n");
                break;

            }
            printf("������%d��%d��\n", p->room, p->hall);
            printf("�����%f\n", p->Area);
            printf("װ���������/δװ�ޣ���%s\n", p->fitment);
            printf("���%f\n", p->rent);
            printf("�ⷿ���ڣ�%d-%d\n", p->time1, p->time2);
            printf("�н飺%s\n", p->agentname);
            printf("��ͣ�%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
    printf("�밲�س���������");
    getchar();
    clear();
}

// ��Χ��ѯ���
void rangeQueryArea(struct House* head) {
    float min_area, max_area;
    printf("��������С�����");
    scanf("%f", &min_area);
    printf("��������������");
    scanf("%f", &max_area);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (p->Area >= min_area && p->Area <= max_area) {
            printf("��ԴID��%d\n", p->id);
            printf("����ţ�%d\n", p->house_id);
            printf("�������֣�%s\n", p->houseowner);
            printf("�����绰��%s\n", p->number);
            printf("�����У�%s\n", p->city);
            printf("������/����%s\n", p->urban);
            printf("����С����%s\n", p->community);
            printf("¥�㣺%d\n", p->floor);
            printf("����");
            switch ((int)p->toward)
            {
            case 1:
                printf("��\n");
                break;
            case 2:
                printf("��\n");
                break;
            case 3:
                printf("��\n");
                break;
            case 4:
                printf("��\n");
                break;
            case 5:
                printf("����\n");
                break;
            case 6:
                printf("����\n");
                break;
            case 7:
                printf("����\n");
                break;
            case 8:
                printf("����\n");
                break;

            }
            printf("������%d��%d��\n", p->room, p->hall);
            printf("�����%f\n", p->Area);
            printf("װ���������/δװ�ޣ���%s\n", p->fitment);
            printf("���%f\n", p->rent);
            printf("�ⷿ���ڣ�%d-%d\n", p->time1, p->time2);
            printf("�н飺%s\n", p->agentname);
            printf("��ͣ�%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
    printf("�밲�س���������");
    getchar();
    clear();
}