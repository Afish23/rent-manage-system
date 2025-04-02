#include "inquire.h"
#include "models.h"
// inquire.c
#include "utils.h"

void simpleQueryHouse1(struct House* head) {
    char city[20];
    printf("请输入所在市：");
    scanf("%s", city);

    struct House* p = head->next;
    int found = 0;

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
            printf("室厅：%d室%d厅\n", p->room,p->hall);
            printf("面积：%f\n", p->Area);
            printf("装修情况（已/未装修）：%s\n", p->fitment);
            printf("租金：%f\n", p->rent);
            printf("租房日期：%d-%d\n", p->time1,p->time2);
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

// 2. 按所在县/区查询房源
void simpleQueryHouse2(struct House* head) {
    char urban[20];
    printf("请输入所在县/区：");
    scanf("%s", urban);

    struct House* p = head->next;
    int found = 0;

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

// 3. 按所在小区查询房源
void simpleQueryHouse3(struct House* head) {
    char community[20];
    printf("请输入所在小区：");
    scanf("%s", community);

    struct House* p = head->next;
    int found = 0;

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

// 7. 按中介查询房源
void simpleQueryHouse7(struct House* head) {
    char username[20];
    printf("请输入中介用户名：");
    scanf("%s", username);

    struct House* p = head->next;
    int found = 0;

    while (p != NULL) {
        if (p->user_agency != NULL && strcmp(p->user_agency->username, username) == 0) {
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