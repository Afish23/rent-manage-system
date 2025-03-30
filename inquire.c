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
            printf("�ҵ���Դ��Ϣ��\n");
            printf("����ţ�%d\n", p->id);
            printf("�����У�%s\n", p->city);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
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
            printf("�ҵ���Դ��Ϣ��\n");
            printf("����ţ�%d\n", p->id);
            printf("������/����%s\n", p->urban);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
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
            printf("�ҵ���Դ��Ϣ��\n");
            printf("����ţ�%d\n", p->id);
            printf("����С����%s\n", p->community);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
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
            printf("�ҵ���Դ��Ϣ��\n");
            printf("����ţ�%d\n", p->id);
            printf("����%d\n", p->toward);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
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
            printf("�ҵ���Դ��Ϣ��\n");
            printf("����ţ�%d\n", p->id);
            printf("�ң�%d\n", p->room);
            printf("����%d\n", p->hall);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
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
            printf("�ҵ���Դ��Ϣ��\n");
            printf("����ţ�%d\n", p->id);
            printf("װ�������%s\n", p->fitment);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
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
            printf("�ҵ���Դ��Ϣ��\n");
            printf("����ţ�%d\n", p->id);
            printf("�н飺%s\n", p->user_agency->username);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
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
            printf("�ҵ���Դ��Ϣ��\n");
            printf("����ţ�%d\n", p->id);
            printf("���%.2f\n", p->rent);
            printf("���ڳ��У�%s\n", p->city);
            printf("��������%s\n", p->urban);
            printf("����С����%s\n", p->community);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
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
            printf("�ҵ���Դ��Ϣ��\n");
            printf("����ţ�%d\n", p->id);
            printf("¥�㣺%d\n", p->floor);
            printf("���ڳ��У�%s\n", p->city);
            printf("��������%s\n", p->urban);
            printf("����С����%s\n", p->community);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
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
            printf("�ҵ���Դ��Ϣ��\n");
            printf("����ţ�%d\n", p->id);
            printf("�����%.2f\n", p->Area);
            printf("���ڳ��У�%s\n", p->city);
            printf("��������%s\n", p->urban);
            printf("����С����%s\n", p->community);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��Ϣ��\n");
    }
}