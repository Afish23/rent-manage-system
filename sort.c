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





void simpleSortHouseid(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("请选择你需要的排序方式：\n");
    printf("1. 从小到大\n");
    printf("2. 从大到小\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {  // 从小到大排序
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
                // 如果交换的是头节点，更新链表头指针
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    else if (choice1 == 2) {  // 从大到小排序
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
                // 如果交换的是头节点，更新链表头指针
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    // printList(*head);  // 如果需要打印排序后的链表，可以在这里调用
}

void simpleSortHouseArea(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("请选择你需要的排序方式：\n");
    printf("1. 从小到大\n");
    printf("2. 从大到小\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {  // 从小到大排序
        while (current != NULL) {
            float area1 = current->Area;
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->Area < area1) {  // 按Area从小到大排序
                    area1 = p->Area;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swapHouse(&current, &minNode);
                // 如果交换的是头节点，更新链表头指针
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    else if (choice1 == 2) {  // 从大到小排序
        while (current != NULL) {
            float area1 = current->Area;
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->Area > area1) {  // 按Area从大到小排序
                    area1 = p->Area;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swapHouse(&current, &maxNode);
                // 如果交换的是头节点，更新链表头指针
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    // printList(*head);  // 如果需要打印排序后的链表，可以在这里调用
}

void simpleSortHouseRent(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("请选择你需要的排序方式：\n");
    printf("1. 从小到大（按租金）\n");
    printf("2. 从大到小（按租金）\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {  // 从小到大排序
        while (current != NULL) {
            float rent1 = current->rent;
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->rent < rent1) {  // 比较租金
                    rent1 = p->rent;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swapHouse(&current, &minNode);
                // 如果交换的是头节点，更新链表头指针
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    else if (choice1 == 2) {  // 从大到小排序
        while (current != NULL) {
            float rent1 = current->rent;
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->rent > rent1) {  // 比较租金
                    rent1 = p->rent;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swapHouse(&current, &maxNode);
                // 如果交换的是头节点，更新链表头指针
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    // printList(*head);  // 如果需要打印排序后的链表，可以在这里调用
}


void simpleSortHouseAgencyFee(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("请选择你需要的排序方式：\n");
    printf("1. 从小到大（按中介费）\n");
    printf("2. 从大到小（按中介费）\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {  // 从小到大排序
        while (current != NULL) {
            float fee1 = current->agency_fee;
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->agency_fee < fee1) {  // 比较中介费
                    fee1 = p->agency_fee;
                    minNode = p;
                }
                p = p->next;
            }

            if (minNode != current) {
                swapHouse(&current, &minNode);
                // 如果交换的是头节点，更新链表头指针
                if (*head == minNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    else if (choice1 == 2) {  // 从大到小排序
        while (current != NULL) {
            float fee1 = current->agency_fee;
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if (p->agency_fee > fee1) {  // 比较中介费
                    fee1 = p->agency_fee;
                    maxNode = p;
                }
                p = p->next;
            }

            if (maxNode != current) {
                swapHouse(&current, &maxNode);
                // 如果交换的是头节点，更新链表头指针
                if (*head == maxNode) {
                    *head = current;
                }
            }
            current = current->next;
        }
    }
    // printList(*head);  // 如果需要打印排序后的链表，可以在这里调用
}


void multSortArea_ByRent(struct House** head) {
    int choice1;
    struct House* current = *head;
    printf("这是根据先排面积和后排租金形成的排序：\n");
    printf("请选择你需要的租金排序方式：\n");
    printf("1. 按租金从小到大排序\n");
    printf("2. 按租金从大到小排序\n");
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
    printf("这是根据先排面积和后排中介费形成的排序：\n");
    printf("请选择你需要的中介费排序方式：\n");
    printf("1. 按中介费从小到大排序\n");
    printf("2. 按中介费从大到小排序\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            float area1 = current->Area;
            float agency_fee1 = current->agency_fee;  // 将rent替换为agency_fee
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ((p->Area == area1 && p->agency_fee < agency_fee1)) {  // 修改为agency_fee
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
            float agency_fee1 = current->agency_fee;  // 将rent替换为agency_fee
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ((p->Area == area1 && p->agency_fee > agency_fee1)) {  // 修改为agency_fee
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
    printf("这是根据先排租金和后排面积形成的排序：\n");
    printf("请选择你需要的租金排序方式：\n");
    printf("1. 按租金从小到大排序\n");
    printf("2. 按租金从大到小排序\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            float rent1 = current->rent;
            float area1 = current->Area;  // 先排租金，后排面积
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ( (p->rent == rent1 && p->Area < area1)) {  // 租金相同按面积排序
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
            float area1 = current->Area;  // 先排租金，后排面积
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ( (p->rent == rent1 && p->Area > area1)) {  // 租金相同按面积排序
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
    printf("这是根据先排租金和后排中介费形成的排序：\n");
    printf("请选择你需要的租金排序方式：\n");
    printf("1. 按租金从小到大排序\n");
    printf("2. 按租金从大到小排序\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            float rent1 = current->rent;
            float agency_fee1 = current->agency_fee;  // 先排租金，后排中介费
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ((p->rent == rent1 && p->agency_fee < agency_fee1)) {  // 租金相同按中介费排序
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
            float agency_fee1 = current->agency_fee;  // 先排租金，后排中介费
            struct House* maxNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ((p->rent == rent1 && p->agency_fee > agency_fee1)) {  // 租金相同按中介费排序
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
    printf("这是根据中介费和面积的排序：\n");
    printf("请选择你需要的排序方式：\n");
    printf("1. 按中介费从小到大排序\n");
    printf("2. 按中介费从大到小排序\n");
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
    printf("这是根据中介费和租金的排序：\n");
    printf("请选择你需要的排序方式：\n");
    printf("1. 按中介费从小到大排序\n");
    printf("2. 按中介费从大到小排序\n");
    scanf("%d", &choice1);

    if (choice1 == 1) {
        while (current->next != NULL) {
            float agency_fee1 = current->agency_fee;
            float rent1 = current->rent;
            struct House* minNode = current;
            struct House* p = current->next;

            while (p != NULL) {
                if ((p->agency_fee == agency_fee1 && p->rent < rent1)) {  // 按中介费排序，租金相同按租金排序
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
                if ( (p->agency_fee == agency_fee1 && p->rent > rent1)) {  // 按中介费排序，租金相同按租金排序
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

void swapHouse(struct House** head1, struct House** head2) {
    // 确保链表不为空
    if (*head1 == NULL || *head2 == NULL) {
        printf("其中一个链表为空，无法交换。\n");
        return;
    }

    // 如果交换的是相邻节点
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

        // 更新 head1 和 head2
        *head1 = temp;
        *head2 = (*head1)->next;
    }
    // 如果交换的是不相邻的节点
    else {
        // 保存相关指针
        struct House* tempNext1 = (*head1)->next;
        struct House* tempPrev1 = (*head1)->prev;
        struct House* tempNext2 = (*head2)->next;
        struct House* tempPrev2 = (*head2)->prev;

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