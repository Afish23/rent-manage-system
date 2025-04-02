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
int addHouse(struct House** head, struct House** tail, struct User* user_agency, struct User* user_custome) {
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

    printf("请输入房主名字: ");
    scanf("%s", newHouse->houseowner);

    printf("请输入房主电话: ");
    scanf("%s", newHouse->number);

    printf("请输入所在市: ");
    scanf("%s", newHouse->city);

    printf("请输入所在县/区: ");
    scanf("%s", newHouse->urban);

    printf("请输入所在小区名字: ");
    scanf("%s", newHouse->community);

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
    scanf("%s", newHouse->fitment);

    printf("请输入租金: ");
    scanf("%f", &newHouse->rent);

    printf("请输入中介费: ");
    scanf("%f", &newHouse->agency_fee);

    printf("请输入押金: ");
    scanf("%f", &newHouse->deposit);

    printf("请输入租房开始日期 (格式：YYYYMMDD): ");
    scanf("%d", &newHouse->time1);

    printf("请输入租房结束日期 (格式：YYYYMMDD): ");
    scanf("%d", &newHouse->time2);

    // 设置中介和租客信息
    /*newHouse->user_agency = user_agency;
    newHouse->user_custome = user_custome;

    printf("请输入中介姓名: ");
    scanf("%s", newhouse->agentname);

    printf("请输入租客姓名: ");
    scanf("%s", newhouse->tenantname);*/

    printf("请输入房源状态（0: 可租, 1: 已租, 2: 申请中）: ");
    scanf("%d", &newHouse->status);

    // 设置链表的前后指针
    newHouse->prev = *tail;
    if (*tail != NULL)
        (*tail)->next = newHouse; // 将尾节点指向新房源

    newHouse->next = NULL; // 新房源的后继指针为空

    // 更新tail指针
    *tail = newHouse;
    if (*head == NULL) {
        *head = newHouse; // 如果链表为空，设置新房源为头节点
    }
    printf("添加成功!");
    getchar();
    clear();
    return 0; // 房源添加成功
}

