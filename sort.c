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