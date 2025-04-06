#include "sort.h"
#include "utils.h"
//�Կ����е�id��������
void simpleSortid(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("��ѡ������Ҫ������ʽ��\n");
    printf("1.��С����\n");
    printf("2.�Ӵ�С\n");
    scanf("%d", &choice1);
    if (choice1 == 1) {
        while (current->next != NULL) {
            int id1 = current->id;
            struct Rent* minNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if (p->id < id1) {
                    id1 = p->id;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swap(&current, &minNode);
                // �����������ͷ�ڵ㣬��������ͷָ��
                if (*head == minNode) {
                    *head = current;
                }
                // ���ڽ����� current λ�øı䣬��Ҫ���»�ȡ��ǰλ��
            }
            current = current->next;
        }
    }
    if (choice1 == 2) {
        while (current->next != NULL) {
            int id1 = current->id;
            struct Rent* maxNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if (p->id > id1) {
                    id1 = p->id;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swap(&current, &maxNode);
                // �����������ͷ�ڵ㣬��������ͷָ��
                if (*head == maxNode) {
                    *head = current;
                }
                // ���ڽ����� current λ�øı䣬��Ҫ���»�ȡ��ǰλ��
            }
            current = current->next;
        }
    }
    //printList((*head));
}
// �� contractTime ����
void simpleSortByContractTime(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("��ѡ������Ҫ������ʽ��\n");
    printf("1.��С����\n");
    printf("2.�Ӵ�С\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            int id1 = current->contractTime;
            struct Rent* minNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if (p->contractTime < id1) {
                    id1 = p->contractTime;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swap(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    if (choice1 == 2) {
        while (current->next != NULL) {
            int id1 = current->contractTime;
            struct Rent* maxNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if (p->contractTime > id1) {
                    id1 = p->contractTime;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swap(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
   // printList((*head));
}

// �� rentStartTime ����
void simpleSortByRentStartTime(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("��ѡ������Ҫ������ʽ��\n");
    printf("1.��С����\n");
    printf("2.�Ӵ�С\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            int id1 = current->rentStartTime;
            struct Rent* minNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if (p->rentStartTime < id1) {
                    id1 = p->rentStartTime;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swap(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    if (choice1 == 2) {
        while (current->next != NULL) {
            int id1 = current->rentStartTime;
            struct Rent* maxNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if (p->rentStartTime > id1) {
                    id1 = p->rentStartTime;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swap(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    //printList((*head));
}

// �� rentDuration ����
void simpleSortByRentDuration(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("��ѡ������Ҫ������ʽ��\n");
    printf("1.��С����\n");
    printf("2.�Ӵ�С\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            int id1 = current->rentDuration;
            struct Rent* minNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if (p->rentDuration < id1) {
                    id1 = p->rentDuration;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swap(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    if (choice1 == 2) {
        while (current->next != NULL) {
            int id1 = current->rentDuration;
            struct Rent* maxNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if (p->rentDuration > id1) {
                    id1 = p->rentDuration;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swap(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    //printList((*head));
}

// �� statement ����
void simpleSortByStatement(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("��ѡ������Ҫ������ʽ��\n");
    printf("1.��С����\n");
    printf("2.�Ӵ�С\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            int id1 = current->statement;
            struct Rent* minNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if (p->statement < id1) {
                    id1 = p->statement;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swap(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    if (choice1 == 2) {
        while (current->next != NULL) {
            int id1 = current->statement;
            struct Rent* maxNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if (p->statement > id1) {
                    id1 = p->statement;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swap(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    //printList((*head));
}

//�ڶ�����rentDuration
void multSortid_ByRentDuration(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("��������id����rentDuration������\n");
    printf("��ѡ������ҪrentDuration������ʽ��\n");
    printf("1.��С����\n");
    printf("2.�Ӵ�С\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            int id1 = current->rentDuration;
            int id2 = current->id;
            struct Rent* minNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if (p->rentDuration < id1&&id2==p->id) {
                    id1 = p->rentDuration;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swap(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    if (choice1 == 2) {
        while (current->next != NULL) {
            int id1 = current->rentDuration;
            int id2 = current->id;
            struct Rent* maxNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if (p->rentDuration > id1 && id2 == p->id) {
                    id1 = p->rentDuration;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swap(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
}
void multSortid_ByRentStartTime(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("��������id����rentStartTime������\n");
    printf("��ѡ������ҪrentStartTime������ʽ��\n");
    printf("1.��С����\n");
    printf("2.�Ӵ�С\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            int id1 = current->id;
            struct Rent* minNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if ((p->id == id1 && p->rentStartTime < minNode->rentStartTime)) {
                    id1 = p->id;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swap(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    if (choice1 == 2) {
        while (current->next != NULL) {
            int id1 = current->id;
            struct Rent* maxNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if ((p->id == id1 && p->rentStartTime > maxNode->rentStartTime)) {
                    id1 = p->id;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swap(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
}


void multSortRentDuration_Byid(struct Rent** head) {
        int choice1;
        struct Rent* current = *head;
        printf("��������rentDuration����id������\n");
        printf("��ѡ������ҪrentDuration������ʽ��\n");
        printf("1.��С����\n");
        printf("2.�Ӵ�С\n");
        scanf("%d", &choice1);

        if (choice1 == 1) { // ��С��������
            while (current->next != NULL) {
                int rentDuration1 = current->rentDuration;
                struct Rent* minNode = current;
                struct Rent* p = current->next;

                while (p != NULL) {
                    if ( (p->rentDuration == rentDuration1 && p->id < minNode->id)) {
                        minNode = p;
                    }
                    p = p->next;
                }

                if (minNode != current) {
                    swap(&current, &minNode);
                    if (*head == minNode) {
                        *head = current;
                    }
                }
                current = current->next;
            }
        }

        if (choice1 == 2) { // �Ӵ�С����
            while (current->next != NULL) {
                int rentDuration1 = current->rentDuration;
                struct Rent* maxNode = current;
                struct Rent* p = current->next;

                while (p != NULL) {
                    if ((p->rentDuration == rentDuration1 && p->id > maxNode->id)) {
                        maxNode = p;
                    }
                    p = p->next;
                }

                if (maxNode != current) {
                    swap(&current, &maxNode);
                    if (*head == maxNode) {
                        *head = current;
                    }
                }
                current = current->next;
            }
        }
    }

void multSortRentDuration_ByRentStartTime(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("��������rentDuration����RentStartTime������\n");
    printf("��ѡ������ҪrentDuration������ʽ��\n");
    printf("1.��С����\n");
    printf("2.�Ӵ�С\n");
    scanf("%d", &choice1);

    if (choice1 == 1) { // ��С��������
        while (current->next != NULL) {
            int rentDuration1 = current->rentDuration;
            struct Rent* minNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if ((p->rentDuration == rentDuration1 && p->rentStartTime < minNode->rentStartTime)) {
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swap(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }

    if (choice1 == 2) { // �Ӵ�С����
        while (current->next != NULL) {
            int rentDuration1 = current->rentDuration;
            struct Rent* maxNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if ((p->rentDuration == rentDuration1 && p->rentStartTime > maxNode->rentStartTime)) {
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swap(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
}

void multSortRentStartTime_Byid(struct Rent** head) {
    int choice2;
    struct Rent* current = *head;
    printf("��������RentStartTime����id������\n");
    printf("��ѡ������ҪRentStartTime������ʽ��\n");
    printf("1.��С����\n");
    printf("2.�Ӵ�С\n");
    scanf("%d", &choice2);

    if (choice2 == 1) { // ��С��������
        while (current->next != NULL) {
            struct Rent* minNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if ((p->rentStartTime == minNode->rentStartTime && p->id < minNode->id)) {
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swap(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }

    if (choice2 == 2) { // �Ӵ�С����
        while (current->next != NULL) {
            struct Rent* maxNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if ( (p->rentStartTime == maxNode->rentStartTime && p->id > maxNode->id)) {
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swap(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
}


void multSortRentStartTime_ByRentDuration(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("��������RentStartTime����RentDuration������\n");
    printf("��ѡ������ҪRentDuration������ʽ��\n");
    printf("1.��С����\n");
    printf("2.�Ӵ�С\n");
    scanf("%d", &choice1);

    if (choice1 == 1) { // ��С��������
        while (current->next != NULL) {
            int rentStartTime1 = current->rentStartTime;
            struct Rent* minNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if ((p->rentStartTime == rentStartTime1 && p->rentDuration < minNode->rentDuration)) {
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swap(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }

    if (choice1 == 2) { // �Ӵ�С����
        while (current->next != NULL) {
            int rentStartTime1 = current->rentStartTime;
            struct Rent* maxNode = current;
            struct Rent* p = current->next;

            while (p != NULL) {
                if ((p->rentStartTime == rentStartTime1 && p->rentDuration > maxNode->rentDuration)) {
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swap(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
}





void simpleSortHouseid(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("��ѡ������Ҫ������ʽ��\n");
    printf("1. ��С����\n");
    printf("2. �Ӵ�С\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {  // ��С��������
        while (current != NULL) {
            int id1 = current->id;
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->id < id1) {
                    id1 = p->id;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swapHouse(&current, &minNode);
                // �����������ͷ�ڵ㣬��������ͷָ��
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    else if (choice1 == 2) {  // �Ӵ�С����
        while (current != NULL) {
            int id1 = current->id;
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->id > id1) {
                    id1 = p->id;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swapHouse(&current, &maxNode);
                // �����������ͷ�ڵ㣬��������ͷָ��
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    // printList(*head);  // �����Ҫ��ӡ�����������������������
}

void simpleSortHouseArea(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("��ѡ������Ҫ������ʽ��\n");
    printf("1. ��С����\n");
    printf("2. �Ӵ�С\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {  // ��С��������
        while (current != NULL) {
            float area1 = current->Area;
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->Area < area1) {  // ��Area��С��������
                    area1 = p->Area;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swapHouse(&current, &minNode);
                // �����������ͷ�ڵ㣬��������ͷָ��
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    else if (choice1 == 2) {  // �Ӵ�С����
        while (current != NULL) {
            float area1 = current->Area;
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->Area > area1) {  // ��Area�Ӵ�С����
                    area1 = p->Area;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swapHouse(&current, &maxNode);
                // �����������ͷ�ڵ㣬��������ͷָ��
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    // printList(*head);  // �����Ҫ��ӡ�����������������������
}

void simpleSortHouseRent(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("��ѡ������Ҫ������ʽ��\n");
    printf("1. ��С���󣨰����\n");
    printf("2. �Ӵ�С�������\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {  // ��С��������
        while (current != NULL) {
            float rent1 = current->rent;
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->rent < rent1) {  // �Ƚ����
                    rent1 = p->rent;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swapHouse(&current, &minNode);
                // �����������ͷ�ڵ㣬��������ͷָ��
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    else if (choice1 == 2) {  // �Ӵ�С����
        while (current != NULL) {
            float rent1 = current->rent;
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->rent > rent1) {  // �Ƚ����
                    rent1 = p->rent;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swapHouse(&current, &maxNode);
                // �����������ͷ�ڵ㣬��������ͷָ��
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    // printList(*head);  // �����Ҫ��ӡ�����������������������
}


void simpleSortHouseAgencyFee(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("��ѡ������Ҫ������ʽ��\n");
    printf("1. ��С���󣨰��н�ѣ�\n");
    printf("2. �Ӵ�С�����н�ѣ�\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {  // ��С��������
        while (current != NULL) {
            float fee1 = current->agency_fee;
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->agency_fee < fee1) {  // �Ƚ��н��
                    fee1 = p->agency_fee;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swapHouse(&current, &minNode);
                // �����������ͷ�ڵ㣬��������ͷָ��
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    else if (choice1 == 2) {  // �Ӵ�С����
        while (current != NULL) {
            float fee1 = current->agency_fee;
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->agency_fee > fee1) {  // �Ƚ��н��
                    fee1 = p->agency_fee;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swapHouse(&current, &maxNode);
                // �����������ͷ�ڵ㣬��������ͷָ��
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    // printList(*head);  // �����Ҫ��ӡ�����������������������
}


void multSortArea_ByRent(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("���Ǹ�����������ͺ�������γɵ�����\n");
    printf("��ѡ������Ҫ���������ʽ��\n");
    printf("1. ������С��������\n");
    printf("2. �����Ӵ�С����\n");
    scanf("%d", &choice1);
    if (choice1 == 1) {
        while (current->next != NULL) {
            float area1 = current->Area;
            float rent1 = current->rent;
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ( (p->Area == area1 && p->rent < rent1)) {
                    area1 = p->Area;
                    rent1 = p->rent;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swapHouse(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }

    if (choice1 == 2) {
        while (current->next != NULL) {
            float area1 = current->Area;
            float rent1 = current->rent;
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ( (p->Area == area1 && p->rent > rent1)) {
                    area1 = p->Area;
                    rent1 = p->rent;
                    maxNode = p;
                    
                }
                p = p->next;
            }
            if (maxNode != current) {
                swapHouse(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
}



void multSortArea_ByAgencyFee(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("���Ǹ�����������ͺ����н���γɵ�����\n");
    printf("��ѡ������Ҫ���н������ʽ��\n");
    printf("1. ���н�Ѵ�С��������\n");
    printf("2. ���н�ѴӴ�С����\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            float area1 = current->Area;
            float agency_fee1 = current->agency_fee;  // ��rent�滻Ϊagency_fee
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ((p->Area == area1 && p->agency_fee < agency_fee1)) {  // �޸�Ϊagency_fee
                    area1 = p->Area;
                    agency_fee1 = p->agency_fee;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swapHouse(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }

    if (choice1 == 2) {
        while (current->next != NULL) {
            float area1 = current->Area;
            float agency_fee1 = current->agency_fee;  // ��rent�滻Ϊagency_fee
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ((p->Area == area1 && p->agency_fee > agency_fee1)) {  // �޸�Ϊagency_fee
                    area1 = p->Area;
                    agency_fee1 = p->agency_fee;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swapHouse(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
}


void multSortRent_ByArea(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("���Ǹ����������ͺ�������γɵ�����\n");
    printf("��ѡ������Ҫ���������ʽ��\n");
    printf("1. ������С��������\n");
    printf("2. �����Ӵ�С����\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            float rent1 = current->rent;
            float area1 = current->Area;  // ������𣬺������
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ( (p->rent == rent1 && p->Area < area1)) {  // �����ͬ���������
                    rent1 = p->rent;
                    area1 = p->Area;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swapHouse(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }

    if (choice1 == 2) {
        while (current->next != NULL) {
            float rent1 = current->rent;
            float area1 = current->Area;  // ������𣬺������
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ( (p->rent == rent1 && p->Area > area1)) {  // �����ͬ���������
                    rent1 = p->rent;
                    area1 = p->Area;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swapHouse(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
}

void multSortRent_ByAgencyFee(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("���Ǹ����������ͺ����н���γɵ�����\n");
    printf("��ѡ������Ҫ���������ʽ��\n");
    printf("1. ������С��������\n");
    printf("2. �����Ӵ�С����\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            float rent1 = current->rent;
            float agency_fee1 = current->agency_fee;  // ������𣬺����н��
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ((p->rent == rent1 && p->agency_fee < agency_fee1)) {  // �����ͬ���н������
                    rent1 = p->rent;
                    agency_fee1 = p->agency_fee;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swapHouse(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }

    if (choice1 == 2) {
        while (current->next != NULL) {
            float rent1 = current->rent;
            float agency_fee1 = current->agency_fee;  // ������𣬺����н��
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ((p->rent == rent1 && p->agency_fee > agency_fee1)) {  // �����ͬ���н������
                    rent1 = p->rent;
                    agency_fee1 = p->agency_fee;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swapHouse(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
}


void multSortAgencyFee_ByArea(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("���Ǹ����н�Ѻ����������\n");
    printf("��ѡ������Ҫ������ʽ��\n");
    printf("1. ���н�Ѵ�С��������\n");
    printf("2. ���н�ѴӴ�С����\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            float agency_fee1 = current->agency_fee;
            float area1 = current->Area;
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ( (p->agency_fee == agency_fee1 && p->Area < area1)) {
                    agency_fee1 = p->agency_fee;
                    area1 = p->Area;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swapHouse(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }

    if (choice1 == 2) {
        while (current->next != NULL) {
            float agency_fee1 = current->agency_fee;
            float area1 = current->Area;
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ( (p->agency_fee == agency_fee1 && p->Area > area1)) {
                    agency_fee1 = p->agency_fee;
                    area1 = p->Area;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swapHouse(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
}




void multSortAgencyFee_ByRent(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("���Ǹ����н�Ѻ���������\n");
    printf("��ѡ������Ҫ������ʽ��\n");
    printf("1. ���н�Ѵ�С��������\n");
    printf("2. ���н�ѴӴ�С����\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            float agency_fee1 = current->agency_fee;
            float rent1 = current->rent;
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ((p->agency_fee == agency_fee1 && p->rent < rent1)) {  // ���н�����������ͬ���������
                    agency_fee1 = p->agency_fee;
                    rent1 = p->rent;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swapHouse(&current, &minNode);
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }

    if (choice1 == 2) {
        while (current->next != NULL) {
            float agency_fee1 = current->agency_fee;
            float rent1 = current->rent;
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ( (p->agency_fee == agency_fee1 && p->rent > rent1)) {  // ���н�����������ͬ���������
                    agency_fee1 = p->agency_fee;
                    rent1 = p->rent;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swapHouse(&current, &maxNode);
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
}




void swap(struct Rent** head1, struct Rent** head2) {
    // ȷ������Ϊ��
    if (*head1 == NULL || *head2 == NULL) {
        printf("����һ������Ϊ�գ��޷�������\n");
        return;
    }

    // ��������������ڽڵ�
    if ((*head1)->next == *head2) {
        // head1 ��ǰ�ڵ㣬head2 �Ǻ�ڵ�
        struct Rent* temp = *head2;
        (*head1)->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = *head1;
        }
        temp->prev = (*head1)->prev;
        if ((*head1)->prev != NULL) {
            (*head1)->prev->next = temp;
        }
        temp->next = *head1;
        (*head1)->prev = temp;

        // ���� head1 �� head2
        *head1 = temp;
        *head2 = (*head1)->next;
    }
    // ����ǽ��������ڵĽڵ�
    else {
        // �����ڵ�ʱ��ʱ����ָ��
        struct Rent* tempNext1 = (*head1)->next;
        struct Rent* tempPrev1 = (*head1)->prev;
        struct Rent* tempNext2 = (*head2)->next;
        struct Rent* tempPrev2 = (*head2)->prev;

        // ���� head1 �� head2 ��ָ��
        (*head1)->next = tempNext2;
        (*head1)->prev = tempPrev2;
        (*head2)->next = tempNext1;
        (*head2)->prev = tempPrev1;

        // ���������ڵ�� prev �� next ָ��
        if (tempNext1 != NULL) {
            tempNext1->prev = *head2;
        }
        if (tempPrev1 != NULL) {
            tempPrev1->next = *head2;
        }
        if (tempNext2 != NULL) {
            tempNext2->prev = *head1;
        }
        if (tempPrev2 != NULL) {
            tempPrev2->next = *head1;
        }

        // ���� head1 �� head2
        struct Rent* temp = *head1;
        *head1 = *head2;
        *head2 = temp;
    }
}

void swapHouse(struct House** head1, struct House** head2) {
    // ȷ������Ϊ��
    if (*head1 == NULL || *head2 == NULL) {
        printf("����һ������Ϊ�գ��޷�������\n");
        return;
    }

    // ��������������ڽڵ�
    if ((*head1)->next == *head2) {
        struct House* temp = *head2;

        (*head1)->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = *head1;
        }
        temp->prev = (*head1)->prev;
        if ((*head1)->prev != NULL) {
            (*head1)->prev->next = temp;
        }
        temp->next = *head1;
        (*head1)->prev = temp;

        // ���� head1 �� head2
        *head1 = temp;
        *head2 = (*head1)->next;
    }
    // ����������ǲ����ڵĽڵ�
    else {
        // �������ָ��
        struct House* tempNext1 = (*head1)->next;
        struct House* tempPrev1 = (*head1)->prev;
        struct House* tempNext2 = (*head2)->next;
        struct House* tempPrev2 = (*head2)->prev;

        // ���� head1 �� head2 ��ָ��
        (*head1)->next = tempNext2;
        (*head1)->prev = tempPrev2;
        (*head2)->next = tempNext1;
        (*head2)->prev = tempPrev1;

        // ���������ڵ�� prev �� next ָ��
        if (tempNext1 != NULL) {
            tempNext1->prev = *head2;
        }
        if (tempPrev1 != NULL) {
            tempPrev1->next = *head2;
        }
        if (tempNext2 != NULL) {
            tempNext2->prev = *head1;
        }
        if (tempPrev2 != NULL) {
            tempPrev2->next = *head1;
        }

        // ���� head1 �� head2
        struct House* temp = *head1;
        *head1 = *head2;
        *head2 = temp;
    }
}
/*
void multSortid(struct Rent** head) {
        
}
*/

/*

void simpleSortHouse2(struct House* head);
void simpleSortHouse3(struct House* head);
void simpleSortHouse4(struct House* head);
void simpleSortHouse5(struct House* head);
void simpleSortHouse6(struct House* head);
void rangeSortFloor(struct House* head);
void rangeSortArea(struct House* head);
void rangeSortRent(struct House* head);
void combinedSortHouse(struct House* head);
*/