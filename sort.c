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
        while (current != NULL) {
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
                current = minNode;
            }
            current = current->next;
        }
    }
    if (choice1 == 2) {
        while (current != NULL) {
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
                current = maxNode;
            }
            current = current->next;
        }
    }
    printList((*head));
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
        while (current != NULL) {
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
                current = minNode;
            }
            current = current->next;
        }
    }
    if (choice1 == 2) {
        while (current != NULL) {
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
                current = maxNode;
            }
            current = current->next;
        }
    }
    printList((*head));
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
        while (current != NULL) {
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
                current = minNode;
            }
            current = current->next;
        }
    }
    if (choice1 == 2) {
        while (current != NULL) {
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
                current = maxNode;
            }
            current = current->next;
        }
    }
    printList((*head));
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
        while (current != NULL) {
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
                current = minNode;
            }
            current = current->next;
        }
    }
    if (choice1 == 2) {
        while (current != NULL) {
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
                current = maxNode;
            }
            current = current->next;
        }
    }
    printList((*head));
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
        while (current != NULL) {
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
                current = minNode;
            }
            current = current->next;
        }
    }
    if (choice1 == 2) {
        while (current != NULL) {
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
                current = maxNode;
            }
            current = current->next;
        }
    }
    printList((*head));
}
void swap(struct Rent** head1, struct Rent** head2) {
    if (*head1 == NULL || *head2 == NULL) {
        printf("����һ������Ϊ�գ��޷�������\n");
        return;
    }

    // ���� *head1 ��ǰһ���ڵ�
    if ((*head1)->prev != NULL) {
        (*head1)->prev->next = *head2;
    }
    // ���� *head2 �ĺ�һ���ڵ�
    if ((*head2)->next != NULL) {
        (*head2)->next->prev = *head1;
    }

    // ����ͷ�ڵ�� next �� prev ָ��
    struct Rent* tempNext = (*head1)->next;
    struct Rent* tempPrev = (*head2)->prev;
    (*head1)->next = (*head2)->next;
    (*head2)->prev = (*head1)->prev;
    (*head1)->prev = tempPrev;
    (*head2)->next = tempNext;

    // ����ͷָ��
    struct Rent* temp = *head1;
    *head1 = *head2;
    *head2 = temp;
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