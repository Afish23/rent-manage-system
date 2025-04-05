#include "statistics.h"
//统计楼层
void statisHousesFloor(struct House* head) {
    struct House* p = head;
    int targetFloor;
    printf("请输入需要统计的楼层数：");
    scanf("%d", &targetFloor);
    int countFloor = 0;
    while (p != NULL) {
        if (p->floor == targetFloor) {
            countFloor++;


        }
        p = p->next; // 遍历链表
    }
    printf("%d楼层的数量为：%d\n", targetFloor, countFloor);
    printf("请按回车键继续：");
    getchar();
    clear();
}

void statisHousesToward(struct House* head) {
    struct House* p = head;
    printf("请输入需要统计的朝向（0-北, 1-南, 2-东, 3-西, 4-东南, 5-东北, 6-西南, 7-西北）：");
    int targetToward;
    scanf("%d", &targetToward);

    int countToward = 0;
    while (p != NULL) {
        if (p->toward == targetToward) {
            countToward++;
        }
        p = p->next; // 遍历链表
    }
    printf("朝向 %d 的房源数量为：%d\n", targetToward, countToward);
    printf("请按回车键继续：");
    getchar(); // 等待回车
    clear();
}

void statisHousesRent(struct House* head) {
    struct House* p = head;
    float targetRentMin, targetRentMax;
    printf("请输入需要统计的租金范围（最小租金 最大租金）：");
    scanf("%f %f", &targetRentMin, &targetRentMax);

    int countRent = 0;
    while (p != NULL) {
        if (p->rent >= targetRentMin && p->rent <= targetRentMax) {
            countRent++;
        }
        p = p->next; // 遍历链表
    }
    printf("租金在 %.2f 到 %.2f 之间的房源数量为：%d\n", targetRentMin, targetRentMax, countRent);
    printf("请按回车键继续：");
    getchar(); // 等待回车
    clear();
}

void statisHousesArea(struct House* head) {
    struct House* p = head;
    float targetAreaMin, targetAreaMax;
    printf("请输入需要统计的面积范围（最小面积 最大面积）：");
    scanf("%f %f", &targetAreaMin, &targetAreaMax);

    int countArea = 0;
    while (p != NULL) {
        if (p->Area >= targetAreaMin && p->Area <= targetAreaMax) {
            countArea++;
        }
        p = p->next; // 遍历链表
    }
    printf("面积在 %.2f 到 %.2f 之间的房源数量为：%d\n", targetAreaMin, targetAreaMax, countArea);
    printf("请按回车键继续：");
    getchar(); // 等待回车
    clear();
}

void statisHousesRoom(struct House* head) {
    struct House* p = head;
    int targetRoom;
    printf("请输入需要统计的房间数（室）：");
    scanf("%d", &targetRoom);

    int countRoom = 0;
    while (p != NULL) {
        if (p->room == targetRoom) {
            countRoom++;
        }
        p = p->next; // 遍历链表
    }
    printf("%d室的房源数量为：%d\n", targetRoom, countRoom);
    printf("请按回车键继续：");
    getchar(); // 等待回车
    clear();
}

void statisHousesFitment(struct House* head) {
    struct House* p = head;
    printf("请输入需要统计的装修情况（已装修/未装修）：");
    char targetFitment[10];
    scanf("%s", targetFitment);

    int countFitment = 0;
    while (p != NULL) {
        if (strcmp(p->fitment, targetFitment) == 0) {
            countFitment++;
        }
        p = p->next; // 遍历链表
    }
    printf("装修情况为 %s 的房源数量为：%d\n", targetFitment, countFitment);
    printf("请按回车键继续：");
    getchar(); // 等待回车
    clear();
}



// 按租金和面积范围统计房源数量
void statisRentAndArea(struct House* head) {
    struct House* p = head;
    float minRent, maxRent, minArea, maxArea;

    // 输入租金和面积范围
    printf("请输入租金的范围（最小租金和最大租金）：\n");
    printf("最小租金：");
    scanf("%f", &minRent);
    printf("最大租金：");
    scanf("%f", &maxRent);

    printf("请输入面积的范围（最小面积和最大面积）：\n");
    printf("最小面积：");
    scanf("%f", &minArea);
    printf("最大面积：");
    scanf("%f", &maxArea);

    int count = 0;

    // 遍历链表，统计符合条件的房源
    while (p != NULL) {
        if (p->rent >= minRent && p->rent <= maxRent && p->Area >= minArea && p->Area <= maxArea) {
            count++;
        }
        p = p->next; // 遍历下一个房源
    }

    // 输出统计结果
    printf("租金范围为 [%.2f, %.2f] 且面积范围为 [%.2f, %.2f] 的房源数量为：%d\n",
        minRent, maxRent, minArea, maxArea, count);
    printf("请按回车键继续：");
    getchar(); // 读取换行符
    clear();
}
// 按朝向和楼层范围统计房源数量
void statisTowardAndFloor(struct House* head) {
    struct House* p = head;
    int minFloor, maxFloor;
    enum Toward minToward, maxToward;

    // 输入朝向范围和楼层范围
    printf("请输入楼层的范围（最小楼层和最大楼层）：\n");
    printf("最小楼层：");
    scanf("%d", &minFloor);
    printf("最大楼层：");
    scanf("%d", &maxFloor);

    printf("请输入朝向范围（0-北, 1-南, 2-东, 3-西, 4-东南, 5-东北, 6-西南, 7-西北）：\n");
    printf("最小朝向：");
    scanf("%d", &minToward);
    printf("最大朝向：");
    scanf("%d", &maxToward);

    int count = 0;

    // 遍历链表，统计符合条件的房源
    while (p != NULL) {
        if (p->floor >= minFloor && p->floor <= maxFloor && p->toward >= minToward && p->toward <= maxToward) {
            count++;
        }
        p = p->next;
    }

    // 输出统计结果
    printf("楼层范围为 [%d, %d] 且朝向范围为 [%d, %d] 的房源数量为：%d\n",
        minFloor, maxFloor, minToward, maxToward, count);
    printf("请按回车键继续：");
    getchar();
    clear();
}
// 按租金和装修情况统计房源数量
void statisRentAndFitment(struct House* head) {
    struct House* p = head;
    float minRent, maxRent;
    char fitment[10];

    // 输入租金范围和装修情况
    printf("请输入租金的范围（最小租金和最大租金）：\n");
    printf("最小租金：");
    scanf("%f", &minRent);
    printf("最大租金：");
    scanf("%f", &maxRent);

    printf("请输入装修情况（例如：简单、精装修等）：\n");
    printf("装修情况：");
    scanf("%s", fitment);

    int count = 0;

    // 遍历链表，统计符合条件的房源
    while (p != NULL) {
        if (p->rent >= minRent && p->rent <= maxRent && strcmp(p->fitment, fitment) == 0) {
            count++;
        }
        p = p->next;
    }

    // 输出统计结果
    printf("租金范围为 [%.2f, %.2f] 且装修情况为 %s 的房源数量为：%d\n",
        minRent, maxRent, fitment, count);
    printf("请按回车键继续：");
    getchar();
    clear();
}
// 按小区和楼层范围统计房源数量
void statisCommunityAndFloor(struct House* head) {
    struct House* p = head;
    char community[20];
    int minFloor, maxFloor;

    // 输入小区名和楼层范围
    printf("请输入小区名称：\n");
    printf("小区名称：");
    scanf("%s", community);

    printf("请输入楼层的范围（最小楼层和最大楼层）：\n");
    printf("最小楼层：");
    scanf("%d", &minFloor);
    printf("最大楼层：");
    scanf("%d", &maxFloor);

    int count = 0;

    // 遍历链表，统计符合条件的房源
    while (p != NULL) {
        if (strcmp(p->community, community) == 0 && p->floor >= minFloor && p->floor <= maxFloor) {
            count++;
        }
        p = p->next;
    }

    // 输出统计结果
    printf("小区 %s 且楼层范围为 [%d, %d] 的房源数量为：%d\n",
        community, minFloor, maxFloor, count);
    printf("请按回车键继续：");
    getchar();
    clear();
}
// 按房间数和朝向统计房源数量
void statisRoomAndToward(struct House* head) {
    struct House* p = head;
    int minRoom, maxRoom;
    enum Toward minToward, maxToward;

    // 输入房间数范围和朝向范围
    printf("请输入房间数的范围（最小房间数和最大房间数）：\n");
    printf("最小房间数：");
    scanf("%d", &minRoom);
    printf("最大房间数：");
    scanf("%d", &maxRoom);

    printf("请输入朝向范围（0-北, 1-南, 2-东, 3-西, 4-东南, 5-东北, 6-西南, 7-西北）：\n");
    printf("最小朝向：");
    scanf("%d", &minToward);
    printf("最大朝向：");
    scanf("%d", &maxToward);

    int count = 0;

    // 遍历链表，统计符合条件的房源
    while (p != NULL) {
        if (p->room >= minRoom && p->room <= maxRoom && p->toward >= minToward && p->toward <= maxToward) {
            count++;
        }
        p = p->next;
    }

    // 输出统计结果
    printf("房间数范围为 [%d, %d] 且朝向范围为 [%d, %d] 的房源数量为：%d\n",
        minRoom, maxRoom, minToward, maxToward, count);
    printf("请按回车键继续：");
    getchar();
    clear();
}


int calculateTotalDays(int date) {
    int year = date / 10000;      // 提取年份
    int month = (date / 100) % 100; // 提取月份
    int day = date % 100;         // 提取日期

    int totalDays = 0;



    totalDays = year * 365 + month * 30 + day; // 加上该月的天数

    return totalDays;
}


void statisAverageRentDuration(struct House* head) {
    struct House* p = head;
    int totalDuration = 0; // 总出租天数
    int totalHouses = 0;   // 房源数量

    while (p != NULL) {
        if (p->status == 1) { // 仅统计已租的房源
            totalDuration += calculateTotalDays(p->rentDuration); // 累加出租天数
            totalHouses++; // 增加已租房源数量
        }
        p = p->next; // 遍历链表
    }

    if (totalHouses > 0) {
        // 将总天数转换为月（假设一个月30天）
        float averageDuration = (float)totalDuration / totalHouses / 30.0;
        printf("所有已租房源的平均出租时间为：%.2f 个月\n", averageDuration);
    }
    else {
        printf("没有已租的房源。\n");
    }

    printf("请按回车键继续：");
    getchar();
    clear();
}


void statisOccupancyRate(struct House* head) {
    int totalHouses = 0;    // 房源总数
    int rentedHouses = 0;   // 已租房源数

    struct House* current = head;

    // 遍历整个链表
    while (current != NULL) {
        totalHouses++;  // 每遍历一个房源，房源总数增加
        if (current->status == 1) {
            rentedHouses++;  // 如果状态为已租，已租房源数增加
        }
        current = current->next;  // 继续遍历下一个房源
    }
    float rate = (rentedHouses / totalHouses) * 100;
    if (totalHouses == 0) {
        printf("当前没有房子出租！");
    }
    else { printf("出租率为%f%%", rate); }
    // 计算出租率
    printf("请按回车键继续：");
    getchar();
    clear();

}


// 统计预约总数的函数
void statisTotalAppointments(struct Appointment* head) {
    int count = 0;
    struct Appointment* current = head->next;

    // 遍历链表直到末尾
    while (current != NULL) {
        count++;
        current = current->next;
    }

    printf("总预约数量：%d\n", count);

    printf("请按回车键继续：");
    getchar();
    clear();

    return count;
}
// 统计已完成预约的数量
void statisCompletedAppointments(struct Appointment* head) {
    int count = 0;
    struct Appointment* current = head->next;

    // 遍历链表直到末尾
    while (current != NULL) {
        // 如果预约已完成（即 statement 为 1），则计数
        if (current->statement == 1) {
            count++;
        }
        current = current->next;
    }

    // 输出已完成预约的数量
    printf("已完成的预约数量：%d\n", count);


    printf("请按回车键继续：");
    getchar();

    clear();
}


// 统计预约时长和计算平均时长
void statisAppointmentDuration(struct Appointment* head) {
    float totalDuration = 0;  // 累加总时长
    float count = 0;          // 记录预约数量
    struct Appointment* current = head->next;

    // 遍历链表直到末尾
    while (current != NULL) {
        totalDuration += current->duration;  // 累加当前预约的时长
        count++;  // 计数总预约数
        current = current->next;
    }



    // 计算并输出平均时长
    if (count > 0) {
        double averageDuration = (double)totalDuration / count;

        printf("总预约时长：%f\n", totalDuration);
        printf("平均预约时长：%.2f\n", averageDuration);
    }
    else {
        printf("没有预约记录。\n");
    }


    printf("请按回车键继续：");
    getchar();

    clear();
}


// 统计时间段内的预约数量
void statisAppointmentInPeriod(struct Appointment* head) {
    int startDate, endDate;
    int count = 0;  // 记录在时间段内的预约数量
    struct Appointment* current = head;

    // 用户输入时间段
    printf("请输入起始时间（格式 YYYYMMDD）：");
    scanf("%d", &startDate);
    printf("请输入结束时间（格式 YYYYMMDD）：");
    scanf("%d", &endDate);

    // 遍历链表直到末尾
    while (current != NULL) {
        if (current->time >= startDate && current->time <= endDate) {
            count++;  // 当前预约日期在时间段内
        }
        current = current->next;
    }

    // 输出统计结果
    printf("在时间段 %d 到 %d 之间的预约数量为：%d\n", startDate, endDate, count);

    // 等待用户输入以继续
    printf("请按回车键继续：");
    getchar();
    getchar();

    clear();
}


// 按租客姓名统计预约数量、预约时间和总时长
void statisAppointmentByTenant(struct Appointment* head) {
    char tenantName[20];       // 用于存储用户输入的租客姓名
    int count = 0;             // 统计预约数量
    int totalDuration = 0;     // 统计总时长
    struct Appointment* current = head;

    // 用户输入租客姓名
    printf("请输入租客姓名：");
    scanf("%s", tenantName);

    // 遍历链表，查找该租客的预约
    while (current != NULL) {
        if (strcmp(current->tenantname, tenantName) == 0) {
            count++;  // 该租客有预约
            totalDuration += current->duration;  // 累加时长
            printf("预约时间：%d, 预约时长：%d分钟\n", current->time, current->duration);
        }
        current = current->next;
    }

    // 输出统计结果
    if (count > 0) {
        printf("租客 %s 的预约数量为：%d\n", tenantName, count);
        printf("租客 %s 的预约总时长为：%d分钟\n", tenantName, totalDuration);
    }
    else {
        printf("未找到租客 %s 的任何预约。\n", tenantName);
    }


    printf("请按回车键继续：");
    getchar();
    getchar();
    clear();
}


// 统计租房总数的函数
void statisTotalRents(struct Rent* head) {
    int count = 0;  // 用于统计租房总数
    struct Rent* current = head->next;  // 用于遍历链表

    // 遍历链表直到末尾
    while (current != NULL) {
        count++;  // 增加租房数量
        current = current->next;  // 移动到下一个租房节点
    }

    // 输出租房总数
    printf("租房总数：%d\n", count);


    printf("请按回车键继续：");
    getchar();
    getchar();
    clear();

}

// 统计租房日期的租房数量，支持输入时间段（格式：YYYYMMDD）
void statisRentDate(struct Rent* head) {
    int count = 0;
    struct Rent* current = head;
    int startDate, endDate;

    // 输入时间段（起始日期和结束日期）
    printf("请输入起始租房日期（格式：YYYYMMDD）：");
    scanf("%d", &startDate);
    printf("请输入结束租房日期（格式：YYYYMMDD）：");
    scanf("%d", &endDate);

    // 确保输入的时间段是合理的（起始日期不晚于结束日期）
    if (startDate > endDate) {
        printf("错误：起始日期不能晚于结束日期。\n");
        return;
    }

    // 遍历链表，检查每个租房的租房日期是否在指定的时间段内
    while (current != NULL) {
        if (current->rentStartTime >= startDate && current->rentStartTime <= endDate) {
            count++;
        }
        current = current->next;
    }

    // 输出租房日期在时间段内的租房数量
    printf("租房日期在 %d 到 %d 之间的租房数量：%d\n", startDate, endDate, count);

    printf("请按回车键继续：");
    getchar();
    getchar();
    clear();
}



// 统计合同日期的租房数量，支持输入时间段
void statisContractDate(struct Rent* head) {
    int count = 0;
    struct Rent* current = head;
    int startDate, endDate;

    // 输入时间段（起始日期和结束日期）
    printf("请输入起始合同日期（格式：YYYYMMDD）：");
    scanf("%d", &startDate);
    printf("请输入结束合同日期（格式：YYYYMMDD）：");
    scanf("%d", &endDate);

    // 确保输入的时间段是合理的（起始日期不晚于结束日期）
    if (startDate > endDate) {
        printf("错误：起始日期不能晚于结束日期。\n");
        return;
    }

    // 遍历链表，检查每个租房的合同日期是否在指定的时间段内
    while (current != NULL) {
        if (current->contractTime >= startDate && current->contractTime <= endDate) {
            count++;
        }
        current = current->next;
    }

    // 输出租房合同日期在时间段内的租房数量
    printf("合同日期在 %d 到 %d 之间的租房数量：%d\n", startDate, endDate, count);

    // 等待用户按回车键继续
    printf("请按回车键继续：");
    getchar();
    getchar();
    clear();
}


// 统计出租时长的租房数量
void statisRentDuration(struct Rent* head) {
    int count = 0;
    struct Rent* current = head;
    int minDuration, maxDuration;

    // 输入出租时长范围
    printf("请输入最小出租时长（月）：");
    scanf("%d", &minDuration);
    printf("请输入最大出租时长（月）：");
    scanf("%d", &maxDuration);

    // 遍历链表，检查每个租房的出租时长是否在指定范围内
    while (current != NULL) {
        if (current->rentDuration >= minDuration && current->rentDuration <= maxDuration) {
            count++;
        }
        current = current->next;
    }

    // 输出出租时长范围内的租房数量
    printf("出租时长在 %d 到 %d 月之间的租房数量：%d\n", minDuration, maxDuration, count);


    printf("请按回车键继续：");
    getchar();
    getchar();
    clear();
}



// 统计租客的租房数量以及租房总时长
void statisTenant(struct Rent* head) {
    int count = 0;
    int totalDuration = 0;  // 总租房时长
    struct Rent* current = head;
    char tenantName[100];

    // 输入租客名字
    printf("请输入租客名字：");
    scanf("%s", tenantName);

    // 遍历链表，检查每个租房的租客是否匹配
    while (current != NULL) {
        if (strcmp(current->tenantname, tenantName) == 0) {  // 如果租客名字匹配
            count++;
            totalDuration += current->rentDuration;  // 累加租房时长
        }
        current = current->next;
    }

    // 输出租客的租房数量和总租房时长
    printf("租客 %s 的租房数量：%d\n", tenantName, count);
    printf("租客 %s 的总租房时长：%d 天（格式：YYYYMMDD）\n", tenantName, totalDuration);

    printf("请按回车键继续：");
    getchar();
    getchar();
    clear();
}
