//增删查改
#include "crud.h"
#include "utils.h"

//添加用户
bool addUser(char* username, char* password, char* phoneNumber, int input_role, struct User* p1, struct User* p2, struct User* tail)
{
    p1 = (struct User*)malloc(sizeof(struct User));//申请空间
    if (p1 == NULL)//判断申请的空间是否为空（NULL）
    {
        printf("内存空间分配失败");
        return false;

    }

    strcpy(p1->username, username);
    strcpy(p1->password, password);
    strcpy(p1->phoneNumber, phoneNumber);
    p1->role = input_role;

    //数据修改都在上面
    tail->next = p1;
    tail = p1;
    tail->next = NULL;
    p1->prev = p2;
    p2 = p1;//延长链表
    return true;
}

// 按照身份顺序输出所有用户信息
void printUsersInOrder(struct User* head) {
    if (head == NULL) {
        printf("链表为空，没有用户信息。\n");
        return;
    }

    struct User* current = head;

    // 输出管理员信息
    printf("===== 管理员 =====\n");
    current = head;
    while (current != NULL) {
        if (current->role == 1) {
            printf("用户名: %s\n", current->username);
            printf("密码: %s\n", current->password);
            printf("电话号码: %s\n", current->phoneNumber);
            printf("-----------------------------\n");
        }
        current = current->next;
    }

    // 输出中介信息
    printf("===== 中介 =====\n");
    current = head;
    while (current != NULL) {
        if (current->role == 2) {
            printf("用户名: %s\n", current->username);
            printf("密码: %s\n", current->password);
            printf("电话号码: %s\n", current->phoneNumber);
            printf("-----------------------------\n");
        }
        current = current->next;
    }

    // 输出租客信息
    printf("===== 租客 =====\n");
    current = head;
    while (current != NULL) {
        if (current->role == 3) {
            printf("用户名: %s\n", current->username);
            printf("密码: %s\n", current->password);
            printf("电话号码: %s\n", current->phoneNumber);
            printf("-----------------------------\n");
        }
        current = current->next;
    }
    getchar();
    clear();
}

//查找用户
struct User* findUser(int input_role, struct User* p1, struct User* head)
{
    char input_name[20] = { '\0' };
    char input_phoneNumber[12] = { '\0' };

    p1 = head->next;

    printf("请输入要查找用户的姓名：");
    scanf("%s", input_name);

    printf("请输入要查找用户的手机号码：");
    scanf("%s", input_phoneNumber);
    while (1)
    {
    
        if (p1->role == input_role)
        {
            if (!strcmp(input_name, p1->username) && !strcmp(input_phoneNumber, p1->phoneNumber))
            {
                printf("查找用户成功！");
                getchar();
                clear();
                return p1;
            }
        }

        p1 = p1->next;
        if (p1 == NULL)
        {
            printf("找不到对象\n");
            getchar();
            clear();
            return NULL;
        }
    }
    return NULL;
}

//查找修改用户密码
void updatePassword(int input_role, struct User* p1, struct User* head)
{   
    struct User* update_p = findUser(input_role, p1, head);
    if (update_p != NULL)
    {
        while (1)
        {
            char input_password_1[20] = { '\0' };
            char input_password_2[20] = { '\0' };
            printf("请输入新密码：");
            hideInput(input_password_1, 19);
            printf("请确认密码：");
            hideInput(input_password_2, 19);
            if (!strcmp(input_password_1, input_password_2))
            {
                strcpy(update_p->password, input_password_1);
                printf("修改密码成功！\n");
                getchar();
                clear();
                break;
            }
            else
            {
                printf("两次输入不一样的嘞");
                printf("回车以继续");
                getchar();
                clear();
                continue;
            }
        }
    }
    return;
}

//查找删除用户
void deleteUser(int input_role, struct User* p1, struct User* head, struct User* tail)
{
    struct User* delete_p = findUser(input_role, p1, head);
    if (delete_p != NULL)
    {
        int jug = 0;
        printf("您确定要删除吗？\n1确认\t 2取消：\n");
        scanf("%d", &jug);
        if (jug == 1)
        {
            if (delete_p->next == NULL)
            {
                tail = delete_p->prev;
                delete_p->prev->next = NULL;
                free(delete_p);
            }
            else
            {
                delete_p->prev->next = delete_p->next;
                delete_p->next->prev = delete_p->prev;
                free(delete_p);
            }
            delete_p = NULL;
            jug = 0;//初始化
            printf("删除成功！\n");
            printf("回车以继续\n");
            getchar();
            clear();
        }
    }
        
    return;
}

//修改自己密码
void updateMyPassword(struct User* current_p)
{
    while (1)
    {
        char input_password_1[20] = { '\0' };
        char input_password_2[20] = { '\0' };
        printf("请输入新密码：");
        hideInput(input_password_1, 19);
        printf("请确认密码：");
        hideInput(input_password_2, 19);
        if (!strcmp(input_password_1, input_password_2))
        {
            strcpy(current_p->password, input_password_1);
            printf("修改密码成功！\n");
            getchar();
            clear();
            break;
        }
        else
        {
            printf("两次输入不一样的嘞");
            printf("回车以继续");
            getchar();
            clear();
            continue;
        }
        return;
    }
}

//修改自己姓名或手机号
void updateMyNameOrPhoneNumber(struct User* current_p)
{
    int choice;
    char input_name[20] = { '\0' };
    char input_phoneNumber[12] = { '\0' };
    while (1)
    {
        printf("请输入要修改的信息\n0退出\t1姓名\t 2手机号：\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            getchar();
            clear();
            break;
        case 1:
            memset(input_name, 0, sizeof(input_name));
            printf("请输入修改后的姓名：");
            scanf("%s", input_name);
            strcpy(current_p->username, input_name);
            printf("修改姓名成功！\n");
            getchar();
            clear();
            continue;
        case 2:
            memset(input_phoneNumber, 0, sizeof(input_phoneNumber));
            printf("请输入修改后的手机号：");
            scanf("%s", input_phoneNumber);
            strcpy(current_p->phoneNumber, input_phoneNumber);
            printf("修改手机号成功！\n");
            getchar();
            clear();
            continue;
        }
        return;
    }

}

//删除自己
void deleteMyUser(struct User* current_p, struct User* tail)
{
    int jug = 0;
    printf("您确定要删除吗？\n1确认\t 2取消：\n");
    scanf("%d", &jug);
    if (jug == 1)
    {
        if (current_p->next == NULL)
        {
            tail = current_p->prev;
            current_p->prev->next = NULL;
            free(current_p);
        }
        else
        {
            current_p->prev->next = current_p->next;
            current_p->next->prev = current_p->prev;
            free(current_p);
        }
        current_p = NULL;
        jug = 0;//初始化
        printf("删除成功！\n");
        printf("回车以继续\n");
        getchar();
        clear();
    }
    return;
}

//添加房源
int addHouse(struct House* head, struct House* tail) {
    struct House* newHouse = (struct House*)malloc(sizeof(struct House));
    if (newHouse == NULL) {
        printf("内存分配失败\n");
        return -1;
    }

    // 获取房源的各项信息
    printf("请输入房源ID: ");
    scanf("%d", &newHouse->id);

    printf("请输入房间号: ");
    scanf("%d", &newHouse->house_id);


    printf("请输入所在市: ");
    scanf("%s", &newHouse->city);

    printf("请输入所在县/区: ");
    scanf("%s", &newHouse->urban);

    printf("请输入所在小区名字: ");
    scanf("%s", &newHouse->community);

    printf("请输入楼层: ");
    scanf("%d", &newHouse->floor);

    printf("请输入朝向（0: N, 1: S, 2: E, 3: W, 4: SE, 5: NE, 6: SW, 7: SN）: ");
    int toward_input;
    scanf("%d", &toward_input);
    newHouse->toward = (enum Toward)toward_input;

    printf("请输入室数: ");
    scanf("%d", &newHouse->room);

    printf("请输入厅数: ");
    scanf("%d", &newHouse->hall);

    printf("请输入房屋面积: ");
    scanf("%f", &newHouse->Area);

    printf("请输入装修情况: ");
    scanf("%s", &newHouse->fitment);

   newHouse->status = 0;

    newHouse->rent = 0;
    newHouse->agency_fee = 0;
    newHouse->deposit = 0;

    newHouse->time1 = 0;
    newHouse->time2 = 0;

    strcpy(newHouse->agentname, "");
    strcpy(newHouse->tenantname, "");

    newHouse->prev = tail;
    tail->next = newHouse;
    newHouse->next = NULL;
    printf("添加成功!\n");
    getchar();
    clear();
    return 0;
}

//修改房源
bool updateHouse(struct House* head) {
    int house_id;
    printf("请输入要修改的房源ID：");
    scanf_s("%d", &house_id);
    struct House* current = head->next;  // 从头部开始遍历
    while (current != NULL) {
        if (current->id == house_id) {  // 找到匹配的房源
            // 获取用户输入的新房源信息
            char new_houseowner[100];
            char new_phoneNumber[20];

            int new_room;
            int new_hall;

            char new_fitment[100];

            // 提示用户输入新的房源信息
            printf("请输入新的房东姓名: ");
            scanf("%s", new_houseowner);
            printf("请输入新的电话号码: ");
            scanf("%s", new_phoneNumber);

            printf("请输入新的室的数量: ");
            scanf("%d", &new_room);
            printf("请输入新的厅的数量: ");
            scanf("%d", &new_hall);

            printf("请输入新的装修情况: ");
            scanf("%s", new_fitment);

            // 更新房源的各个信息
            strcpy(current->houseowner, new_houseowner);
            strcpy(current->number, new_phoneNumber);

            current->room = new_room;
            current->hall = new_hall;

            strcpy(current->fitment, new_fitment);

            printf("房源信息更新成功！\n");
            getchar();
            clear();
            return true;  // 修改成功
        }
        current = current->next;  // 继续向后遍历
    }
    printf("未找到匹配的房源！\n");
    getchar();
    clear();
    return false;  // 未找到对应房源，修改失败
}

//删除房源
bool deleteHouse(struct House* head) {
    int house_id;
    printf("请输入要删除的房源ID：");
    scanf_s("%d", &house_id);
    struct House* current = head->next; // 从头部开始遍历
    while (current != NULL) {
        if (current->id == house_id) {  // 找到匹配的房源
            // 修改前后节点的指针
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            // 释放当前节点的内存
            free(current);
            printf("删除成功\n");
            printf("请输入回车键继续：");
            getchar();
            clear();
            return true;  // 删除成功
        }
        current = current->next;  // 继续向后遍历
    }
    printf("删除失败\n");
    printf("请输入回车键继续：");
    getchar();
    clear();
    return false;  // 未找到对应房源，删除失败
}



//添加租房信息
bool addRent(struct Rent** tail) {
    struct Rent* p1;
    p1 = (struct Rent*)malloc(sizeof(struct Rent)); // 申请内存
    if (p1 == NULL) {  // 判断内存是否分配成功
        printf("内存空间分配失败");
        return false;
    }
    // 将新节点加入租房链表
    printf("请输入租房信息:\n");
    printf("请输入租房 ID: ");
    scanf("%d", &p1->id);
    printf("请输入合同时间（例如：20250401）: ");
    scanf("%d", &p1->contractTime);
    printf("请输入租房开始时间（例如：20250401）: ");
    scanf("%d", &p1->rentStartTime);
    printf("请输入租期（单位：月）: ");
    scanf("%d", &p1->rentDuration);
    p1->statement = 1;  // 假设 1 表示有效状态
    (*tail)->next = p1;
    p1->prev = (*tail);
    (*tail) = p1;
    (*tail)->next = NULL;
    printf("储存成功\n");
    printf("请输入回车键继续：");
    getchar();
    clear();
    return true;
}

void printRentsInOrder(struct Rent* head) {
    if (head->next == NULL) {
        printf("链表为空，没有租房信息。\n");
        return;
    }

    struct Rent* current = head->next;
    int count = 1;

    while (current != NULL) {
        printf("租房信息 %d:\n", count++);
        printf("  租房编号: %d\n", current->id);
        printf("  合同签订日期: %d\n", current->contractTime);
        printf("  出租开始日期: %d\n", current->rentStartTime);
        printf("  预计出租时长: %d\n", current->rentDuration);
        printf("  中介姓名: %s\n", current->agentname);
        printf("  租客姓名: %s\n", current->tenantname);
        printf("  房源ID: %d\n", current->house_id);
        printf("  状态: %s\n", current->statement == 0 ? "已完成" : "正在租");
        printf("\n");

        current = current->next; // 移动到下一个节点
    }
    getchar();
    clear();
}

//查找租房信息
struct Rent* findRent(int id1, struct Rent* head1) {
    while (head1 != NULL) {
        if (head1->id == id1)return head1;
        head1 = head1->next;
    }
    return NULL;
}

void updateRent(struct Rent* head1) {
    int choice,jug = 1,id1;
    printf("输入id\n");
    scanf("%d", &id1);
    struct Rent* p1 = findRent(id1, head1);
    if (p1 != NULL) {
        while (jug) {
            printf("请选择要修改的租房信息字段:\n");
            printf("1. 租房编号\n");
            printf("2. 合同签订日期\n");
            printf("3. 出租开始日期\n");
            printf("4. 预计出租时长\n");
            printf("5. 中介姓名\n");
            printf("6. 租客姓名\n");
            printf("7. 房源ID\n");
            printf("8. 租赁状态\n");
            printf("0. 退出修改\n");
            scanf("%d", &choice);
            switch (choice) {
            case 0:
                jug = 0; 
                break;
            case 1:
                printf("请输入新的租房编号: ");
                scanf("%d", &p1->id);
                getchar();
                clear();
                continue;
            case 2:
                printf("请输入新的合同签订日期: ");
                scanf("%d", &p1->contractTime);
                getchar();
                clear();
                continue;
            case 3:
                printf("请输入新的出租开始日期: ");
                scanf("%d", &p1->rentStartTime);
                getchar();
                clear();
                continue;
            case 4:
                printf("请输入新的预计出租时长: ");
                scanf("%d", &p1->rentDuration);
                getchar();
                clear();
                continue;
            case 5:
                printf("请输入新的中介姓名: ");
                scanf("%s", &p1->agentname);
                getchar();
                clear();
                continue;
            case 6:
                printf("请输入新的租客姓名: ");
                scanf("%s", &p1->tenantname);
                getchar();
                clear();
                continue;
            case 7:
                printf("请输入新的房源ID: ");
                scanf("%d", &p1->house_id);
                getchar();
                clear();
                continue;
            case 8:
                printf("请输入新的租赁状态 (0-已完成, 1-正在租): ");
                scanf("%d", &p1->statement);
                getchar();
                clear();
                continue;
            default:
                printf("无效选项，请重新输入\n");
                getchar();
                clear();
                continue;
            }
        }
        printf("修改成功");
        getchar();
        clear();
    }
    else {
        printf("没有找到，修改失败");
        getchar();
        clear();
    }
}

//删除租房信息
bool deleteRent(struct Rent* head1) {
    int id;
    printf("请输入要删除的租房信息ID：");
    scanf_s("%d", &id);
    struct Rent* current = head1->next; // 从头部开始遍历
    while (current != NULL) {
        if (current->id == id) {  // 找到匹配的信息
            // 修改前后节点的指针
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            // 释放当前节点的内存
            free(current);
            printf("删除成功\n");
            printf("请输入回车键继续：");
            getchar();
            clear();
            return true;  // 删除成功
        }
        current = current->next;  // 继续向后遍历
    }
    printf("删除失败\n");
    printf("请输入回车键继续：");
    getchar();
    clear();
    return false;  // 未找到对应信息，删除失败
}

bool addAppointment(struct Appointment** tai2) {
    struct Appointment* r1;
    r1 = (struct Appointment*)malloc(sizeof(struct Appointment)); // 申请内存
    if (r1 == NULL) {  // 判断内存是否分配成功
        printf("内存空间分配失败");
        return false;
    }
    // 将新节点加入租房链表
    printf("请输入看房信息:\n");
    printf("请输入看房 ID: ");
    scanf("%d", &r1->id);
    printf("请输入看房时间（例如：20250401）: ");
    scanf("%d", &r1->time);
    printf("请输入看房时长（例如：0.5代表0.5小时）: ");
    scanf("%d", &r1->duration);
    r1->statement = 0;  // 假设 1 表示已完成
    (*tai2)->next = r1;
    r1->prev = (*tai2);
    (*tai2) = r1;
    (*tai2)->next = NULL;
    printf("储存成功\n");
    printf("请输入回车键继续：");
    getchar();
    clear();
    return true;
}

void printAppointmentsInOrder(struct Appointment* head) {
    if (head->next == NULL) {
        printf("链表为空，没有预约信息。\n");
        return;
    }

    struct Appointment* current = head->next;
    int count = 1;

    while (current != NULL) {
        printf("预约信息 %d:\n", count++);
        printf("  看房编号: %d\n", current->id);
        printf("  看房时间: %d\n", current->time);
        printf("  看房时长: %d\n", current->duration);
        printf("  中介姓名: %s\n", current->agentname);
        printf("  租客姓名: %s\n", current->tenantname);
        printf("  房源ID: %d\n", current->house_id);
        printf("  租客反馈: %s\n", current->feedback);
        printf("  状态: %s\n", current->statement == 0 ? "待处理" : "已完成");
        printf("\n");

        current = current->next; // 移动到下一个节点
    }
    getchar();
    clear();
}

struct Appointment* findAppointment(int id1, struct Appointment* head1) {
    while (head1 != NULL) {
        if (head1->id == id1)return head1;
        head1 = head1->next;
    }
    return NULL;
}

void updateAppointment(struct Appointment* head2) {
    int choice, jug = 1, id1;
    printf("输入id\n");
    scanf("%d", &id1);
    struct Appointment* p1 = findAppointment(id1, head2);
    if (p1 != NULL) {
        while (jug) {
            printf("请选择要修改的预约信息字段:\n");
            printf("1. 看房编号\n");
            printf("2. 看房时间\n");
            printf("3. 看房时长\n");
            printf("4. 中介姓名\n");
            printf("5. 租客姓名\n");
            printf("6. 房源ID\n");
            printf("7. 租客反馈\n");
            printf("8. 预约状态\n");
            printf("0. 退出修改\n");

            scanf("%d", &choice);
            switch (choice) {
            case 0:
                jug = 0;
                break;
            case 1:
                printf("请输入新的看房编号: ");
                scanf("%d", &p1->id);
                getchar();
                clear();
                continue;
            case 2:
                printf("请输入新的看房时间（例如：20250401）: ");
                scanf("%d", &p1->time);
                getchar();
                clear();
                continue;
            case 3:
                printf("请输入新的看房时长（单位：小时）: ");
                scanf("%d", &p1->duration);
                getchar();
                clear();
                continue;
            case 4:
                printf("请输入新的中介姓名: ");
                scanf("%19s", &p1->agentname);
                getchar();
                clear();
                continue;
            case 5:
                printf("请输入新的租客姓名: ");
                scanf("%19s", &p1->tenantname);
                getchar();
                clear();
                continue;
            case 6:
                printf("请输入新的房源ID: ");
                scanf("%d", &p1->house_id);
                getchar();
                clear();
                continue;
            case 7:
                printf("请输入新的租客反馈（最多19个字符）: ");
                scanf("%19s", &p1->feedback);
                getchar();
                clear();
                continue;
            case 8:
                printf("请输入新的预约状态 (0-已完成, 1-待处理): ");
                scanf("%d", &p1->statement);
                getchar();
                clear();
                continue;
            default:
                printf("无效选项，请重新输入\n");
                getchar();
                clear();
                continue;
            }
        }
        printf("修改成功");
        getchar();
        clear();
    }
    else {
        printf("没有找到，修改失败");
        getchar();
        clear();
    }
}

void deleteAppointment(struct Appointment* head2) {
    int id;
    printf("请输入要删除的预约信息ID：");
    scanf_s("%d", &id);
    struct Appointment* current = head2->next; // 从头部开始遍历
    while (current != NULL) {
        if (current->id == id) {  // 找到匹配的信息
            // 修改前后节点的指针
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            // 释放当前节点的内存
            free(current);
            printf("删除成功\n");
            printf("请输入回车键继续：");
            getchar();
            clear();
            return true;  // 删除成功
        }
        current = current->next;  // 继续向后遍历
    }
    printf("删除失败\n");
    printf("请输入回车键继续：");
    getchar();
    clear();
    return false;  // 未找到对应信息，删除失败
}
