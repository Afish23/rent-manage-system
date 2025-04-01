//增删查改
#include "crud.h"
#include "utils.h"
#include "data.h"

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

//添加租房信息
bool addRent(int id, int contractTime, int rentStartTime, int rentDuration, struct User* agent, struct User* tenant, struct House* house, struct Rent* p1, struct Rent* p2, struct Rent* tail) {
    p1 = (struct Rent*)malloc(sizeof(struct Rent)); // 申请内存
    if (p1 == NULL) {  // 判断内存是否分配成功
        printf("内存空间分配失败");
        return false;
    }

    // 初始化租房信息
    p1->id = id;
    p1->contractTime = contractTime;
    p1->rentStartTime = rentStartTime;
    p1->rentDuration = rentDuration;
    p1->agent = agent;
    p1->tenant = tenant;
    p1->house = house;
    p1->statement = 1;  // 假设新租房是正在租的状态

    // 将新节点加入租房链表
    tail->next = p1;
    tail = p1;
    tail->next = NULL;
    p1->prev = p2;
    p2 = p1; // 延长链表

    return true;
}

//查找租房用户
/*
struct Rent* findRent(int input_role, struct Rent* p1, struct Rent* head)
{
    p1 = head->next; // 从链表的第一个租房信息开始
    int input_id, input_contractTime, input_rentStartTime, input_rentDuration;
    // 提示用户输入查询条件
    printf("请输入要查找租房信息的租房编号：");
    scanf("%d", &input_id);

    printf("请输入要查找租房信息的合同签订日期：");
    scanf("%d", &input_contractTime);

    printf("请输入要查找租房信息的出租开始日期：");
    scanf("%d", &input_rentStartTime);

    printf("请输入要查找租房信息的预计出租时长：");
    scanf("%d", &input_rentDuration);

    // 遍历链表查找匹配的租房信息
    while (p1 != NULL)
    {   
        if (p1->role == input_role)
        {
            // 判断租房ID、合同签订日期、出租开始日期和预计出租时长是否都匹配
            if (p1->id == input_id && p1->contractTime == input_contractTime &&
                p1->rentStartTime == input_rentStartTime && p1->rentDuration == input_rentDuration)
            {
                printf("查找租房信息成功！\n");
                getchar(); // 消耗掉多余的换行符
                clear();  // 假设清屏函数
                return p1; // 返回找到的租房信息
            }
        }

        p1 = p1->next; // 移动到下一个租房信息节点
    }

    // 如果遍历完链表仍未找到匹配的租房信息
    printf("找不到租房信息\n");
    getchar(); // 消耗掉多余的换行符
    clear();  // 假设清屏函数
    return NULL; // 返回NULL表示未找到
}

//删除租房用户
void deleteRent(int input_id, struct Rent* p1, struct Rent* head, struct Rent* tail)
{
    struct Rent* delete_p = findRent(input_id, p1, head); // 查找要删除的Rent节点
    if (delete_p != NULL)
    {
        int jug = 0;
        printf("您确定要删除租房信息吗？\n1确认\t 2取消：\n");
        scanf("%d", &jug);
        if (jug == 1)
        {
            // 如果是尾节点
            if (delete_p->next == NULL)
            {
                tail = delete_p->prev;  // 更新tail
                delete_p->prev->next = NULL;  // 删除节点
                free(delete_p);  // 释放内存
            }
            // 如果是头节点
            else if (delete_p->prev == NULL)
            {
                head = delete_p->next;  // 更新head
                delete_p->next->prev = NULL;  // 删除节点
                free(delete_p);  // 释放内存
            }
            else
            {
                delete_p->prev->next = delete_p->next;  // 更新前节点的next指针
                delete_p->next->prev = delete_p->prev;  // 更新后节点的prev指针
                free(delete_p);  // 释放内存
            }

            delete_p = NULL;  // 清空指针
            jug = 0;  // 初始化
            printf("删除成功！\n");
            printf("回车以继续\n");
            getchar();  // 获取回车，暂停
            clear();  // 假设是清屏函数
        }
    }

    return;
}*/