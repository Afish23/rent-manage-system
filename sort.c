#include "sort.h"
#include "utils.h"
//对看房中的id进行排序
void simpleSortid(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("请选择你需要的排序方式：\n");
    printf("1.从小到大\n");
    printf("2.从大到小\n");
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
                // 如果交换的是头节点，更新链表头指针
                if (*head == minNode) {
                    *head = current;
                }
                // 由于交换后 current 位置改变，需要重新获取当前位置
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
                // 如果交换的是头节点，更新链表头指针
                if (*head == maxNode) {
                    *head = current;
                }
                // 由于交换后 current 位置改变，需要重新获取当前位置
                current = maxNode;
            }
            current = current->next;
        }
    }
    printList((*head));
}
// 按 contractTime 排序
void simpleSortByContractTime(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("请选择你需要的排序方式：\n");
    printf("1.从小到大\n");
    printf("2.从大到小\n");
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

// 按 rentStartTime 排序
void simpleSortByRentStartTime(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("请选择你需要的排序方式：\n");
    printf("1.从小到大\n");
    printf("2.从大到小\n");
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

// 按 rentDuration 排序
void simpleSortByRentDuration(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("请选择你需要的排序方式：\n");
    printf("1.从小到大\n");
    printf("2.从大到小\n");
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

// 按 statement 排序
void simpleSortByStatement(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("请选择你需要的排序方式：\n");
    printf("1.从小到大\n");
    printf("2.从大到小\n");
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
        printf("其中一个链表为空，无法交换。\n");
        return;
    }

    // 处理 *head1 的前一个节点
    if ((*head1)->prev != NULL) {
        (*head1)->prev->next = *head2;
    }
    // 处理 *head2 的后一个节点
    if ((*head2)->next != NULL) {
        (*head2)->next->prev = *head1;
    }

    // 交换头节点的 next 和 prev 指针
    struct Rent* tempNext = (*head1)->next;
    struct Rent* tempPrev = (*head2)->prev;
    (*head1)->next = (*head2)->next;
    (*head2)->prev = (*head1)->prev;
    (*head1)->prev = tempPrev;
    (*head2)->next = tempNext;

    // 交换头指针
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