#include "inquire.h"
#include "utils.h"

// 1. 按所在市查询房源（包含精确匹配和模糊匹配）
void simpleQueryHouse1(struct House* head) {
    char city[20];
    printf("请输入所在市：");
    scanf("%s", city);

    struct House* p = head->next;
    int found = 0;

    // 精确匹配
    while (p != NULL) {
        if (strcmp(p->city, city) == 0) {
            printf("房源ID：%d\n", p->id);
            printf("房间号：%d\n", p->house_id);
            printf("房主名字：%s\n", p->houseowner);
            printf("房主电话：%s\n", p->number);
            printf("所在市：%s\n", p->city);
            printf("所在县/区：%s\n", p->urban);
            printf("所在小区：%s\n", p->community);
            printf("楼层：%d\n", p->floor);
            printf("朝向：");
            switch ((int)p->toward) {
            case 1: printf("东\n"); break;
            case 2: printf("南\n"); break;
            case 3: printf("西\n"); break;
            case 4: printf("北\n"); break;
            case 5: printf("东南\n"); break;
            case 6: printf("东北\n"); break;
            case 7: printf("西南\n"); break;
            case 8: printf("西北\n"); break;
            }
            printf("室厅：%d室%d厅\n", p->room, p->hall);
            printf("面积：%f\n", p->Area);
            printf("装修情况（已/未装修）：%s\n", p->fitment);
            printf("租金：%f\n", p->rent);
            printf("租房日期：%d-%d\n", p->time1, p->time2);
            printf("中介：%s\n", p->agentname);
            printf("租客：%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    // 模糊匹配
    if (!found) {
        printf("未找到精确匹配的房源，进行模糊匹配...\n");
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
            printf("模糊匹配到“%s”请问是否查找“%s”(y=是/n=否)：",
                closestHouse->city, closestHouse->city);
            getchar();
            char b;
            scanf("%c", &b);

            if (b == 'y') {
                p = head->next;
                while (p != NULL) {
                    if (strcmp(p->city, closestHouse->city) == 0) {
                        printf("房源ID：%d\n", p->id);
                        printf("房间号：%d\n", p->house_id);
                        printf("房主名字：%s\n", p->houseowner);
                        printf("房主电话：%s\n", p->number);
                        printf("所在市：%s\n", p->city);
                        printf("所在县/区：%s\n", p->urban);
                        printf("所在小区：%s\n", p->community);
                        printf("楼层：%d\n", p->floor);
                        printf("朝向：");
                        switch ((int)p->toward) {
                        case 1: printf("东\n"); break;
                        case 2: printf("南\n"); break;
                        case 3: printf("西\n"); break;
                        case 4: printf("北\n"); break;
                        case 5: printf("东南\n"); break;
                        case 6: printf("东北\n"); break;
                        case 7: printf("西南\n"); break;
                        case 8: printf("西北\n"); break;
                        }
                        printf("室厅：%d室%d厅\n", p->room, p->hall);
                        printf("面积：%f\n", p->Area);
                        printf("装修情况（已/未装修）：%s\n", p->fitment);
                        printf("租金：%f\n", p->rent);
                        printf("租房日期：%d-%d\n", p->time1, p->time2);
                        printf("中介：%s\n", p->agentname);
                        printf("租客：%s\n", p->tenantname);
                    }
                    p = p->next;
                }
            }
            else {
                printf("您选择了不查找该房源。\n");
            }
        }
        else {
            printf("没有找到任何符合条件的房源。\n");
        }
    }

    printf("请按回车键继续：");
    getchar();
    clear();
}

// 2. 按所在县/区查询房源（包含精确匹配和模糊匹配）
void simpleQueryHouse2(struct House* head) {
    char urban[20];
    printf("请输入所在县/区：");
    scanf("%s", urban);

    struct House* p = head->next;
    int found = 0;

    // 精确匹配
    while (p != NULL) {
        if (strcmp(p->urban, urban) == 0) {
            printf("房源ID：%d\n", p->id);
            printf("房间号：%d\n", p->house_id);
            printf("房主名字：%s\n", p->houseowner);
            printf("房主电话：%s\n", p->number);
            printf("所在市：%s\n", p->city);
            printf("所在县/区：%s\n", p->urban);
            printf("所在小区：%s\n", p->community);
            printf("楼层：%d\n", p->floor);
            printf("朝向：");
            switch ((int)p->toward) {
            case 1: printf("东\n"); break;
            case 2: printf("南\n"); break;
            case 3: printf("西\n"); break;
            case 4: printf("北\n"); break;
            case 5: printf("东南\n"); break;
            case 6: printf("东北\n"); break;
            case 7: printf("西南\n"); break;
            case 8: printf("西北\n"); break;
            }
            printf("室厅：%d室%d厅\n", p->room, p->hall);
            printf("面积：%f\n", p->Area);
            printf("装修情况（已/未装修）：%s\n", p->fitment);
            printf("租金：%f\n", p->rent);
            printf("租房日期：%d-%d\n", p->time1, p->time2);
            printf("中介：%s\n", p->agentname);
            printf("租客：%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    // 模糊匹配
    if (!found) {
        printf("未找到精确匹配的房源，进行模糊匹配...\n");
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
            printf("模糊匹配到“%s”请问是否查找“%s”(y=是/n=否)：",
                closestHouse->urban, closestHouse->urban);
            getchar();
            char b;
            scanf("%c", &b);

            if (b == 'y') {
                p = head->next;
                while (p != NULL) {
                    if (strcmp(p->urban, closestHouse->urban) == 0) {
                        printf("房源ID：%d\n", p->id);
                        printf("房间号：%d\n", p->house_id);
                        printf("房主名字：%s\n", p->houseowner);
                        printf("房主电话：%s\n", p->number);
                        printf("所在市：%s\n", p->city);
                        printf("所在县/区：%s\n", p->urban);
                        printf("所在小区：%s\n", p->community);
                        printf("楼层：%d\n", p->floor);
                        printf("朝向：");
                        switch ((int)p->toward) {
                        case 1: printf("东\n"); break;
                        case 2: printf("南\n"); break;
                        case 3: printf("西\n"); break;
                        case 4: printf("北\n"); break;
                        case 5: printf("东南\n"); break;
                        case 6: printf("东北\n"); break;
                        case 7: printf("西南\n"); break;
                        case 8: printf("西北\n"); break;
                        }
                        printf("室厅：%d室%d厅\n", p->room, p->hall);
                        printf("面积：%f\n", p->Area);
                        printf("装修情况（已/未装修）：%s\n", p->fitment);
                        printf("租金：%f\n", p->rent);
                        printf("租房日期：%d-%d\n", p->time1, p->time2);
                        printf("中介：%s\n", p->agentname);
                        printf("租客：%s\n", p->tenantname);
                    }
                    p = p->next;
                }
            }
            else {
                printf("您选择了不查找该房源。\n");
            }
        }
        else {
            printf("没有找到任何符合条件的房源。\n");
        }
    }

    printf("请按回车键继续：");
    getchar();
    clear();
}
// 3. 按所在小区查询房源（包含精确匹配和模糊匹配）
void simpleQueryHouse3(struct House* head) {
    char community[20];
    printf("请输入所在小区：");
    scanf("%s", community);

    struct House* p = head->next;
    int found = 0;

    // 精确匹配
    while (p != NULL) {
        if (strcmp(p->community, community) == 0) {
            printf("房源ID：%d\n", p->id);
            printf("房间号：%d\n", p->house_id);
            printf("房主名字：%s\n", p->houseowner);
            printf("房主电话：%s\n", p->number);
            printf("所在市：%s\n", p->city);
            printf("所在县/区：%s\n", p->urban);
            printf("所在小区：%s\n", p->community);
            printf("楼层：%d\n", p->floor);
            printf("朝向：");
            switch ((int)p->toward) {
            case 1:
                printf("东\n");
                break;
            case 2:
                printf("南\n");
                break;
            case 3:
                printf("西\n");
                break;
            case 4:
                printf("北\n");
                break;
            case 5:
                printf("东南\n");
                break;
            case 6:
                printf("东北\n");
                break;
            case 7:
                printf("西南\n");
                break;
            case 8:
                printf("西北\n");
                break;
            }
            printf("室厅：%d室%d厅\n", p->room, p->hall);
            printf("面积：%f\n", p->Area);
            printf("装修情况（已/未装修）：%s\n", p->fitment);
            printf("租金：%f\n", p->rent);
            printf("租房日期：%d-%d\n", p->time1, p->time2);
            printf("中介：%s\n", p->agentname);
            printf("租客：%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    // 如果没有找到精确匹配，进行模糊匹配
    if (!found) {
        printf("未找到精确匹配的房源，进行模糊匹配...\n");
        struct House* closestHouse = NULL;
        int minDistance = 1000;  // 设置一个较大的初始编辑距离
        p = head->next;
        int a = 0;

        while (p != NULL) {
            int distance = editDistance(p->community, community);  // 计算编辑距离
            if (distance <= minDistance) {
                minDistance = distance;
                closestHouse = p;
                a = 1;
            }
            p = p->next;
        }
        if (a == 1) {
            printf("模糊匹配到“%s”请问是否查找“%s”(y=是/n=否)：", closestHouse->community, closestHouse->community);
            getchar();
            char b;
            scanf("%c", &b);



            // 输出最接近匹配的房源信息
            if (b == 'y') {
                printf("最接近匹配的房源信息如下：\n");
                p = head->next;
                while (p != NULL) {
                    if (strcmp(p->community, closestHouse->community) == 0) {
                        printf("房源ID：%d\n", p->id);
                        printf("房间号：%d\n", p->house_id);
                        printf("房主名字：%s\n", p->houseowner);
                        printf("房主电话：%s\n", p->number);
                        printf("所在市：%s\n", p->city);
                        printf("所在县/区：%s\n", p->urban);
                        printf("所在小区：%s\n", p->community);
                        printf("楼层：%d\n", p->floor);
                        printf("朝向：");
                        switch ((int)p->toward) {
                        case 1:
                            printf("东\n");
                            break;
                        case 2:
                            printf("南\n");
                            break;
                        case 3:
                            printf("西\n");
                            break;
                        case 4:
                            printf("北\n");
                            break;
                        case 5:
                            printf("东南\n");
                            break;
                        case 6:
                            printf("东北\n");
                            break;
                        case 7:
                            printf("西南\n");
                            break;
                        case 8:
                            printf("西北\n");
                            break;
                        }
                        printf("室厅：%d室%d厅\n", p->room, p->hall);
                        printf("面积：%f\n", p->Area);
                        printf("装修情况（已/未装修）：%s\n", p->fitment);
                        printf("租金：%f\n", p->rent);
                        printf("租房日期：%d-%d\n", p->time1, p->time2);
                        printf("中介：%s\n", p->agentname);
                        printf("租客：%s\n", p->tenantname);

                    }
                    p = p->next;
                }
            }
            else { printf("您选择了不查找该房源。\n"); }
        }
        else {
            printf("没有找到任何符合条件的房源。\n");
        }
    }

    printf("请按回车键继续：");
    getchar();
    clear();
}


// 4. 按朝向查询房源
void simpleQueryHouse4(struct House* head) {
    enum Toward toward;
    printf("请输入朝向（0-北，1-南，2-东，3-西，4-东南，5-东北，6-西南，7-西北）：");
    scanf("%d", (int*)&toward);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (p->toward == toward) {
            printf("房源ID：%d\n", p->id);
            printf("房间号：%d\n", p->house_id);
            printf("房主名字：%s\n", p->houseowner);
            printf("房主电话：%s\n", p->number);
            printf("所在市：%s\n", p->city);
            printf("所在县/区：%s\n", p->urban);
            printf("所在小区：%s\n", p->community);
            printf("楼层：%d\n", p->floor);
            printf("朝向：");
            switch ((int)p->toward)
            {
            case 1:
                printf("东\n");
                break;
            case 2:
                printf("南\n");
                break;
            case 3:
                printf("西\n");
                break;
            case 4:
                printf("北\n");
                break;
            case 5:
                printf("东南\n");
                break;
            case 6:
                printf("东北\n");
                break;
            case 7:
                printf("西南\n");
                break;
            case 8:
                printf("西北\n");
                break;

            }
            printf("室厅：%d室%d厅\n", p->room, p->hall);
            printf("面积：%f\n", p->Area);
            printf("装修情况（已/未装修）：%s\n", p->fitment);
            printf("租金：%f\n", p->rent);
            printf("租房日期：%d-%d\n", p->time1, p->time2);
            printf("中介：%s\n", p->agentname);
            printf("租客：%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("未找到符合条件的房源信息。\n");
    }
    printf("请安回车键继续：");
    getchar();
    clear();
}

// 5. 按室厅查询房源
void simpleQueryHouse5(struct House* head) {
    int room, hall;
    printf("请输入室的数量：");
    scanf("%d", &room);
    printf("请输入厅的数量：");
    scanf("%d", &hall);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (p->room == room && p->hall == hall) {
            printf("房源ID：%d\n", p->id);
            printf("房间号：%d\n", p->house_id);
            printf("房主名字：%s\n", p->houseowner);
            printf("房主电话：%s\n", p->number);
            printf("所在市：%s\n", p->city);
            printf("所在县/区：%s\n", p->urban);
            printf("所在小区：%s\n", p->community);
            printf("楼层：%d\n", p->floor);
            printf("朝向：");
            switch ((int)p->toward)
            {
            case 1:
                printf("东\n");
                break;
            case 2:
                printf("南\n");
                break;
            case 3:
                printf("西\n");
                break;
            case 4:
                printf("北\n");
                break;
            case 5:
                printf("东南\n");
                break;
            case 6:
                printf("东北\n");
                break;
            case 7:
                printf("西南\n");
                break;
            case 8:
                printf("西北\n");
                break;

            }
            printf("室厅：%d室%d厅\n", p->room, p->hall);
            printf("面积：%f\n", p->Area);
            printf("装修情况（已/未装修）：%s\n", p->fitment);
            printf("租金：%f\n", p->rent);
            printf("租房日期：%d-%d\n", p->time1, p->time2);
            printf("中介：%s\n", p->agentname);
            printf("租客：%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("未找到符合条件的房源信息。\n");
    }
    printf("请安回车键继续：");
    getchar();
    clear();
}

// 6. 按装修情况查询房源
void simpleQueryHouse6(struct House* head) {
    char fitment[10];
    printf("请输入装修情况：");
    scanf("%s", fitment);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (strcmp(p->fitment, fitment) == 0) {
            printf("房源ID：%d\n", p->id);
            printf("房间号：%d\n", p->house_id);
            printf("房主名字：%s\n", p->houseowner);
            printf("房主电话：%s\n", p->number);
            printf("所在市：%s\n", p->city);
            printf("所在县/区：%s\n", p->urban);
            printf("所在小区：%s\n", p->community);
            printf("楼层：%d\n", p->floor);
            printf("朝向：");
            switch ((int)p->toward)
            {
            case 1:
                printf("东\n");
                break;
            case 2:
                printf("南\n");
                break;
            case 3:
                printf("西\n");
                break;
            case 4:
                printf("北\n");
                break;
            case 5:
                printf("东南\n");
                break;
            case 6:
                printf("东北\n");
                break;
            case 7:
                printf("西南\n");
                break;
            case 8:
                printf("西北\n");
                break;

            }
            printf("室厅：%d室%d厅\n", p->room, p->hall);
            printf("面积：%f\n", p->Area);
            printf("装修情况（已/未装修）：%s\n", p->fitment);
            printf("租金：%f\n", p->rent);
            printf("租房日期：%d-%d\n", p->time1, p->time2);
            printf("中介：%s\n", p->agentname);
            printf("租客：%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("未找到符合条件的房源信息。\n");
    }
    printf("请安回车键继续：");
    getchar();
    clear();
}

void rangeQueryRent(struct House* head) {
    float min_rent, max_rent;
    printf("请输入最小租金：");
    scanf("%f", &min_rent);
    printf("请输入最大租金：");
    scanf("%f", &max_rent);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (p->rent >= min_rent && p->rent <= max_rent) {
            printf("房源ID：%d\n", p->id);
            printf("房间号：%d\n", p->house_id);
            printf("房主名字：%s\n", p->houseowner);
            printf("房主电话：%s\n", p->number);
            printf("所在市：%s\n", p->city);
            printf("所在县/区：%s\n", p->urban);
            printf("所在小区：%s\n", p->community);
            printf("楼层：%d\n", p->floor);
            printf("朝向：");
            switch ((int)p->toward)
            {
            case 1:
                printf("东\n");
                break;
            case 2:
                printf("南\n");
                break;
            case 3:
                printf("西\n");
                break;
            case 4:
                printf("北\n");
                break;
            case 5:
                printf("东南\n");
                break;
            case 6:
                printf("东北\n");
                break;
            case 7:
                printf("西南\n");
                break;
            case 8:
                printf("西北\n");
                break;

            }
            printf("室厅：%d室%d厅\n", p->room, p->hall);
            printf("面积：%f\n", p->Area);
            printf("装修情况（已/未装修）：%s\n", p->fitment);
            printf("租金：%f\n", p->rent);
            printf("租房日期：%d-%d\n", p->time1, p->time2);
            printf("中介：%s\n", p->agentname);
            printf("租客：%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("未找到符合条件的房源信息。\n");
    }
    printf("请安回车键继续：");
    getchar();
    clear();
}

// 范围查询楼层
void rangeQueryFloor(struct House* head) {
    int min_floor, max_floor;
    printf("请输入最小楼层：");
    scanf("%d", &min_floor);
    printf("请输入最大楼层：");
    scanf("%d", &max_floor);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (p->floor >= min_floor && p->floor <= max_floor) {
            printf("房源ID：%d\n", p->id);
            printf("房间号：%d\n", p->house_id);
            printf("房主名字：%s\n", p->houseowner);
            printf("房主电话：%s\n", p->number);
            printf("所在市：%s\n", p->city);
            printf("所在县/区：%s\n", p->urban);
            printf("所在小区：%s\n", p->community);
            printf("楼层：%d\n", p->floor);
            printf("朝向：");
            switch ((int)p->toward)
            {
            case 1:
                printf("东\n");
                break;
            case 2:
                printf("南\n");
                break;
            case 3:
                printf("西\n");
                break;
            case 4:
                printf("北\n");
                break;
            case 5:
                printf("东南\n");
                break;
            case 6:
                printf("东北\n");
                break;
            case 7:
                printf("西南\n");
                break;
            case 8:
                printf("西北\n");
                break;

            }
            printf("室厅：%d室%d厅\n", p->room, p->hall);
            printf("面积：%f\n", p->Area);
            printf("装修情况（已/未装修）：%s\n", p->fitment);
            printf("租金：%f\n", p->rent);
            printf("租房日期：%d-%d\n", p->time1, p->time2);
            printf("中介：%s\n", p->agentname);
            printf("租客：%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("未找到符合条件的房源信息。\n");
    }
    printf("请安回车键继续：");
    getchar();
    clear();
}

// 范围查询面积
void rangeQueryArea(struct House* head) {
    float min_area, max_area;
    printf("请输入最小面积：");
    scanf("%f", &min_area);
    printf("请输入最大面积：");
    scanf("%f", &max_area);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (p->Area >= min_area && p->Area <= max_area) {
            printf("房源ID：%d\n", p->id);
            printf("房间号：%d\n", p->house_id);
            printf("房主名字：%s\n", p->houseowner);
            printf("房主电话：%s\n", p->number);
            printf("所在市：%s\n", p->city);
            printf("所在县/区：%s\n", p->urban);
            printf("所在小区：%s\n", p->community);
            printf("楼层：%d\n", p->floor);
            printf("朝向：");
            switch ((int)p->toward)
            {
            case 1:
                printf("东\n");
                break;
            case 2:
                printf("南\n");
                break;
            case 3:
                printf("西\n");
                break;
            case 4:
                printf("北\n");
                break;
            case 5:
                printf("东南\n");
                break;
            case 6:
                printf("东北\n");
                break;
            case 7:
                printf("西南\n");
                break;
            case 8:
                printf("西北\n");
                break;

            }
            printf("室厅：%d室%d厅\n", p->room, p->hall);
            printf("面积：%f\n", p->Area);
            printf("装修情况（已/未装修）：%s\n", p->fitment);
            printf("租金：%f\n", p->rent);
            printf("租房日期：%d-%d\n", p->time1, p->time2);
            printf("中介：%s\n", p->agentname);
            printf("租客：%s\n", p->tenantname);
            found = 1;
        }
        p = p->next;
    }

    if (!found) {
        printf("未找到符合条件的房源信息。\n");
    }
    printf("请安回车键继续：");
    getchar();
    clear();
}


void combinedQueryHouse(struct House* head) {
    char inputcity[20], inputurban[20], inputcommunity[20], inputfitment[10];
    int inputfloor, inputtoward, inputroom, inputhall, l, r, l2, r2;

    // 获取用户输入
    printf("请输入您想搜索的城市：\n");
    scanf("%s", inputcity);

    printf("请输入您想搜索的县/区：\n");
    scanf("%s", inputurban);

    printf("请输入您想搜索的小区：\n");
    scanf("%s", inputcommunity);

    printf("请输入您想搜索的楼层：\n");
    scanf("%d", &inputfloor);

    printf("请输入您想搜索的朝向（0: N, 1: S, 2: E, 3: W, 4: SE, 5: NE, 6: SW, 7: SN）：");
    scanf("%d", &inputtoward);

    printf("请输入您想搜索的室数：");
    scanf("%d", &inputroom);

    printf("请输入您想搜索的厅数：");
    scanf("%d", &inputhall);

    printf("请输入您想搜索的装修情况: (已装修/未装修): ");
    scanf("%s", inputfitment);

    printf("请输入面积范围：\n");
    printf("左：\t");
    scanf("%d", &l);
    printf("右：\t");
    scanf("%d", &r);

    printf("请输入租金范围：\n");
    printf("左：\t");
    scanf("%d", &l2);
    printf("右：\t");
    scanf("%d", &r2);

    // 遍历房源链表进行查找
    struct House* current = head->next;
    int found = 0;

    while (current != NULL) {
        // 进行匹配
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

            // 打印符合条件的房源
            printf("找到符合条件的房源:\n");
            printf("房源ID：%d\n", current->id);
            printf("房间号：%d\n", current->house_id);
            printf("房主名字：%s\n", current->houseowner);
            printf("房主电话：%s\n", current->number);
            printf("所在市：%s\n", current->city);
            printf("所在县/区：%s\n", current->urban);
            printf("所在小区：%s\n", current->community);
            printf("楼层：%d\n", current->floor);
            printf("朝向：");
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
            printf("室厅：%d室%d厅\n", current->room, current->hall);
            printf("面积：%.2f\n", current->Area);
            printf("装修情况：%s\n", current->fitment);
            printf("租金：%.2f\n", current->rent);
            printf("租房日期：%d-%d\n", current->time1, current->time2);
            printf("中介：%s\n", current->agentname);
            printf("租客：%s\n", current->tenantname);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("未找到符合条件的房源。\n");
    }
    printf("请安回车键继续：");
    getchar();
    clear();
}