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
                // 如果交换的是头节点，更新链表头指针
                if (*head == minNode) {
                    *head = current;
                }
                // 由于交换后 current 位置改变，需要重新获取当前位置
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
                // 如果交换的是头节点，更新链表头指针
                if (*head == maxNode) {
                    *head = current;
                }
                // 由于交换后 current 位置改变，需要重新获取当前位置
            }
            current = current->next;
        }
    }
    //printList((*head));
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

// 按 rentStartTime 排序
void simpleSortByRentStartTime(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("请选择你需要的排序方式：\n");
    printf("1.从小到大\n");
    printf("2.从大到小\n");
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

// 按 rentDuration 排序
void simpleSortByRentDuration(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("请选择你需要的排序方式：\n");
    printf("1.从小到大\n");
    printf("2.从大到小\n");
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

// 按 statement 排序
void simpleSortByStatement(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("请选择你需要的排序方式：\n");
    printf("1.从小到大\n");
    printf("2.从大到小\n");
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

//第二次排rentDuration
void multSortid_ByRentDuration(struct Rent** head) {
    int choice1;
    struct Rent* current = *head;
    printf("这是首排id次排rentDuration的排序：\n");
    printf("请选择你需要rentDuration的排序方式：\n");
    printf("1.从小到大\n");
    printf("2.从大到小\n");
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
    printf("这是首排id次排rentStartTime的排序：\n");
    printf("请选择你需要rentStartTime的排序方式：\n");
    printf("1.从小到大\n");
    printf("2.从大到小\n");
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
        printf("这是首排rentDuration次排id的排序：\n");
        printf("请选择你需要rentDuration的排序方式：\n");
        printf("1.从小到大\n");
        printf("2.从大到小\n");
        scanf("%d", &choice1);

        if (choice1 == 1) { // 从小到大排序
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

        if (choice1 == 2) { // 从大到小排序
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
    printf("这是首排rentDuration次排RentStartTime的排序：\n");
    printf("请选择你需要rentDuration的排序方式：\n");
    printf("1.从小到大\n");
    printf("2.从大到小\n");
    scanf("%d", &choice1);

    if (choice1 == 1) { // 从小到大排序
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

    if (choice1 == 2) { // 从大到小排序
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
    printf("这是首排RentStartTime次排id的排序：\n");
    printf("请选择你需要RentStartTime的排序方式：\n");
    printf("1.从小到大\n");
    printf("2.从大到小\n");
    scanf("%d", &choice2);

    if (choice2 == 1) { // 从小到大排序
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

    if (choice2 == 2) { // 从大到小排序
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
    printf("这是首排RentStartTime次排RentDuration的排序：\n");
    printf("请选择你需要RentDuration的排序方式：\n");
    printf("1.从小到大\n");
    printf("2.从大到小\n");
    scanf("%d", &choice1);

    if (choice1 == 1) { // 从小到大排序
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

    if (choice1 == 2) { // 从大到小排序
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
    // 确保链表不为空
    if (*head1 == NULL || *head2 == NULL) {
        printf("其中一个链表为空，无法交换。\n");
        return;
    }

    // 如果交换的是相邻节点
    if ((*head1)->next == *head2) {
        // head1 是前节点，head2 是后节点
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

        // 更新 head1 和 head2
        *head1 = temp;
        *head2 = (*head1)->next;
    }
    // 如果是交换不相邻的节点
    else {
        // 交换节点时临时保存指针
        struct Rent* tempNext1 = (*head1)->next;
        struct Rent* tempPrev1 = (*head1)->prev;
        struct Rent* tempNext2 = (*head2)->next;
        struct Rent* tempPrev2 = (*head2)->prev;

        // 更新 head1 和 head2 的指针
        (*head1)->next = tempNext2;
        (*head1)->prev = tempPrev2;
        (*head2)->next = tempNext1;
        (*head2)->prev = tempPrev1;

        // 更新其他节点的 prev 和 next 指针
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

        // 更新 head1 和 head2
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