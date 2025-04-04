#include "inquire.h"
#include "utils.h"

// 1. �������в�ѯ��Դ��������ȷƥ���ģ��ƥ�䣩
void simpleQueryHouse1(struct House* head) {
    char city[20];
    printf("�����������У�");
    scanf("%s", city);

    struct House* p = head->next;
    int found = 0;

    // ��ȷƥ��
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
            switch ((int)p->toward) {
            case 1: printf("��\n"); break;
            case 2: printf("��\n"); break;
            case 3: printf("��\n"); break;
            case 4: printf("��\n"); break;
            case 5: printf("����\n"); break;
            case 6: printf("����\n"); break;
            case 7: printf("����\n"); break;
            case 8: printf("����\n"); break;
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

    // ģ��ƥ��
    if (!found) {
        printf("δ�ҵ���ȷƥ��ķ�Դ������ģ��ƥ��...\n");
        struct House* closestHouse = NULL;
        int minDistance = 1000;
        p = head->next;
        int a = 0;

        while (p != NULL) {
            int distance = editDistance(p->city, city);
            if (distance <= minDistance) {
                minDistance = distance;
                closestHouse = p;
                a = 1;
            }
            p = p->next;
        }

        if (a == 1) {
            printf("ģ��ƥ�䵽��%s�������Ƿ���ҡ�%s��(y=��/n=��)��",
                closestHouse->city, closestHouse->city);
            getchar();
            char b;
            scanf("%c", &b);

            if (b == 'y') {
                p = head->next;
                while (p != NULL) {
                    if (strcmp(p->city, closestHouse->city) == 0) {
                        printf("��ԴID��%d\n", p->id);
                        printf("����ţ�%d\n", p->house_id);
                        printf("�������֣�%s\n", p->houseowner);
                        printf("�����绰��%s\n", p->number);
                        printf("�����У�%s\n", p->city);
                        printf("������/����%s\n", p->urban);
                        printf("����С����%s\n", p->community);
                        printf("¥�㣺%d\n", p->floor);
                        printf("����");
                        switch ((int)p->toward) {
                        case 1: printf("��\n"); break;
                        case 2: printf("��\n"); break;
                        case 3: printf("��\n"); break;
                        case 4: printf("��\n"); break;
                        case 5: printf("����\n"); break;
                        case 6: printf("����\n"); break;
                        case 7: printf("����\n"); break;
                        case 8: printf("����\n"); break;
                        }
                        printf("������%d��%d��\n", p->room, p->hall);
                        printf("�����%f\n", p->Area);
                        printf("װ���������/δװ�ޣ���%s\n", p->fitment);
                        printf("���%f\n", p->rent);
                        printf("�ⷿ���ڣ�%d-%d\n", p->time1, p->time2);
                        printf("�н飺%s\n", p->agentname);
                        printf("��ͣ�%s\n", p->tenantname);
                    }
                    p = p->next;
                }
            }
            else {
                printf("��ѡ���˲����Ҹ÷�Դ��\n");
            }
        }
        else {
            printf("û���ҵ��κη��������ķ�Դ��\n");
        }
    }

    printf("�밴�س���������");
    getchar();
    clear();
}

// 2. ��������/����ѯ��Դ��������ȷƥ���ģ��ƥ�䣩
void simpleQueryHouse2(struct House* head) {
    char urban[20];
    printf("������������/����");
    scanf("%s", urban);

    struct House* p = head->next;
    int found = 0;

    // ��ȷƥ��
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
            switch ((int)p->toward) {
            case 1: printf("��\n"); break;
            case 2: printf("��\n"); break;
            case 3: printf("��\n"); break;
            case 4: printf("��\n"); break;
            case 5: printf("����\n"); break;
            case 6: printf("����\n"); break;
            case 7: printf("����\n"); break;
            case 8: printf("����\n"); break;
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

    // ģ��ƥ��
    if (!found) {
        printf("δ�ҵ���ȷƥ��ķ�Դ������ģ��ƥ��...\n");
        struct House* closestHouse = NULL;
        int minDistance = 1000;
        p = head->next;
        int a = 0;

        while (p != NULL) {
            int distance = editDistance(p->urban, urban);
            if (distance <= minDistance) {
                minDistance = distance;
                closestHouse = p;
                a = 1;
            }
            p = p->next;
        }

        if (a == 1) {
            printf("ģ��ƥ�䵽��%s�������Ƿ���ҡ�%s��(y=��/n=��)��",
                closestHouse->urban, closestHouse->urban);
            getchar();
            char b;
            scanf("%c", &b);

            if (b == 'y') {
                p = head->next;
                while (p != NULL) {
                    if (strcmp(p->urban, closestHouse->urban) == 0) {
                        printf("��ԴID��%d\n", p->id);
                        printf("����ţ�%d\n", p->house_id);
                        printf("�������֣�%s\n", p->houseowner);
                        printf("�����绰��%s\n", p->number);
                        printf("�����У�%s\n", p->city);
                        printf("������/����%s\n", p->urban);
                        printf("����С����%s\n", p->community);
                        printf("¥�㣺%d\n", p->floor);
                        printf("����");
                        switch ((int)p->toward) {
                        case 1: printf("��\n"); break;
                        case 2: printf("��\n"); break;
                        case 3: printf("��\n"); break;
                        case 4: printf("��\n"); break;
                        case 5: printf("����\n"); break;
                        case 6: printf("����\n"); break;
                        case 7: printf("����\n"); break;
                        case 8: printf("����\n"); break;
                        }
                        printf("������%d��%d��\n", p->room, p->hall);
                        printf("�����%f\n", p->Area);
                        printf("װ���������/δװ�ޣ���%s\n", p->fitment);
                        printf("���%f\n", p->rent);
                        printf("�ⷿ���ڣ�%d-%d\n", p->time1, p->time2);
                        printf("�н飺%s\n", p->agentname);
                        printf("��ͣ�%s\n", p->tenantname);
                    }
                    p = p->next;
                }
            }
            else {
                printf("��ѡ���˲����Ҹ÷�Դ��\n");
            }
        }
        else {
            printf("û���ҵ��κη��������ķ�Դ��\n");
        }
    }

    printf("�밴�س���������");
    getchar();
    clear();
}
// 3. ������С����ѯ��Դ��������ȷƥ���ģ��ƥ�䣩
void simpleQueryHouse3(struct House* head) {
    char community[20];
    printf("����������С����");
    scanf("%s", community);

    struct House* p = head->next;
    int found = 0;

    // ��ȷƥ��
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
            switch ((int)p->toward) {
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

    // ���û���ҵ���ȷƥ�䣬����ģ��ƥ��
    if (!found) {
        printf("δ�ҵ���ȷƥ��ķ�Դ������ģ��ƥ��...\n");
        struct House* closestHouse = NULL;
        int minDistance = 1000;  // ����һ���ϴ�ĳ�ʼ�༭����
        p = head->next;
        int a = 0;

        while (p != NULL) {
            int distance = editDistance(p->community, community);  // ����༭����
            if (distance <= minDistance) {
                minDistance = distance;
                closestHouse = p;
                a = 1;
            }
            p = p->next;
        }
        if (a == 1) {
            printf("ģ��ƥ�䵽��%s�������Ƿ���ҡ�%s��(y=��/n=��)��", closestHouse->community, closestHouse->community);
            getchar();
            char b;
            scanf("%c", &b);



            // �����ӽ�ƥ��ķ�Դ��Ϣ
            if (b == 'y') {
                printf("��ӽ�ƥ��ķ�Դ��Ϣ���£�\n");
                p = head->next;
                while (p != NULL) {
                    if (strcmp(p->community, closestHouse->community) == 0) {
                        printf("��ԴID��%d\n", p->id);
                        printf("����ţ�%d\n", p->house_id);
                        printf("�������֣�%s\n", p->houseowner);
                        printf("�����绰��%s\n", p->number);
                        printf("�����У�%s\n", p->city);
                        printf("������/����%s\n", p->urban);
                        printf("����С����%s\n", p->community);
                        printf("¥�㣺%d\n", p->floor);
                        printf("����");
                        switch ((int)p->toward) {
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

                    }
                    p = p->next;
                }
            }
            else { printf("��ѡ���˲����Ҹ÷�Դ��\n"); }
        }
        else {
            printf("û���ҵ��κη��������ķ�Դ��\n");
        }
    }

    printf("�밴�س���������");
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


void combinedQueryHouse(struct House* head) {
    char inputcity[20], inputurban[20], inputcommunity[20], inputfitment[10];
    int inputfloor, inputtoward, inputroom, inputhall, l, r, l2, r2;

    // ��ȡ�û�����
    printf("���������������ĳ��У�\n");
    scanf("%s", inputcity);

    printf("������������������/����\n");
    scanf("%s", inputurban);

    printf("����������������С����\n");
    scanf("%s", inputcommunity);

    printf("����������������¥�㣺\n");
    scanf("%d", &inputfloor);

    printf("���������������ĳ���0: N, 1: S, 2: E, 3: W, 4: SE, 5: NE, 6: SW, 7: SN����");
    scanf("%d", &inputtoward);

    printf("����������������������");
    scanf("%d", &inputroom);

    printf("����������������������");
    scanf("%d", &inputhall);

    printf("����������������װ�����: (��װ��/δװ��): ");
    scanf("%s", inputfitment);

    printf("�����������Χ��\n");
    printf("��\t");
    scanf("%d", &l);
    printf("�ң�\t");
    scanf("%d", &r);

    printf("���������Χ��\n");
    printf("��\t");
    scanf("%d", &l2);
    printf("�ң�\t");
    scanf("%d", &r2);

    // ������Դ������в���
    struct House* current = head->next;
    int found = 0;

    while (current != NULL) {
        // ����ƥ��
        if ((strcmp(current->city, inputcity) == 0) &&
            (strcmp(current->urban, inputurban) == 0) &&
            (strcmp(current->community, inputcommunity) == 0) &&
            (current->floor == inputfloor) &&
            (current->toward == inputtoward) &&
            (current->room == inputroom) &&
            (current->hall == inputhall) &&
            (strcmp(current->fitment, inputfitment) == 0) &&
            (current->Area >= l && current->Area <= r) &&
            (current->rent >= l2 && current->rent <= r2)) {

            // ��ӡ���������ķ�Դ
            printf("�ҵ����������ķ�Դ:\n");
            printf("��ԴID��%d\n", current->id);
            printf("����ţ�%d\n", current->house_id);
            printf("�������֣�%s\n", current->houseowner);
            printf("�����绰��%s\n", current->number);
            printf("�����У�%s\n", current->city);
            printf("������/����%s\n", current->urban);
            printf("����С����%s\n", current->community);
            printf("¥�㣺%d\n", current->floor);
            printf("����");
            switch (current->toward) {
            case 0: printf("N\n"); break;
            case 1: printf("S\n"); break;
            case 2: printf("E\n"); break;
            case 3: printf("W\n"); break;
            case 4: printf("SE\n"); break;
            case 5: printf("NE\n"); break;
            case 6: printf("SW\n"); break;
            case 7: printf("SN\n"); break;
            }
            printf("������%d��%d��\n", current->room, current->hall);
            printf("�����%.2f\n", current->Area);
            printf("װ�������%s\n", current->fitment);
            printf("���%.2f\n", current->rent);
            printf("�ⷿ���ڣ�%d-%d\n", current->time1, current->time2);
            printf("�н飺%s\n", current->agentname);
            printf("��ͣ�%s\n", current->tenantname);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("δ�ҵ����������ķ�Դ��\n");
    }
    printf("�밲�س���������");
    getchar();
    clear();
}