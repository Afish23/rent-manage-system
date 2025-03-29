#include "data.h"
#include "models.h"
#include "utils.h"
int main() {
    //实现登录功能
    bool login(int input_role, struct User* p1, struct User* head);

    //实现注册功能
    void register_user(int role, struct User* p1, struct User* p2, struct User* tail, struct User* head);

    //添加用户
    bool addUser(char* username, char* password, char* phoneNumber, int role, struct User* p1, struct User* p2, struct User* tail);

    //0：主菜单 1：身份选择菜单 2：管理员菜单 3：中介菜单 4：租客菜单
    int choice_0 = 1, choice_1, choice_2, choice_3, choice_4;
    //5:中介管理菜单
    int choice_5;
    //退出循环判断
    //0：身份选择 1:中介管理
    int jug0 = 0, jug1 = 0;

    struct User* p1, * p2, * tail, * head;
    p1 = (struct User*)malloc(sizeof(struct User));//申请空间
    if (p1 == NULL) { // 判断申请的空间是否为空（NULL）
        printf("内存空间分配失败\n");
        return -1;
    }

    tail = p1; // 标记头尾
    head = p1;
    p2 = p1;
    tail->next = NULL;
    head->prev = NULL;

    struct House* p11, * p21, * tail1, * head1;
    p11 = (struct House*)malloc(sizeof(struct House));//申请空间
    if (p11 == NULL) { // 判断申请的空间是否为空（NULL）
        printf("内存空间分配失败\n");
        return -1;
    }

    tail1 = p11; // 标记头尾
    head1 = p11;
    p21 = p11;
    tail1->next = NULL;
    head1->prev = NULL;


    //数据读取
    read_user_data(&tail);
    read_house_data(&tail1);

    //主界面
    while (choice_0) {
        printf("******登    录******\n");
        printf("**                **\n");
        printf("**0.  关    闭    **\n");
        printf("**1.  登    录    **\n");
        printf("**2.  租客注册    **\n");
        printf("**                **\n");
        printf("********************\n");
        printf("请选择功能：");
        scanf_s("%d", &choice_0);
        clear();

        switch (choice_0) {
        case 0:
            break;
        case 1:
            //身份选择界面
            printf("******身份选择******\n");
            printf("**                **\n");
            printf("**0.  退    出    **\n");
            printf("**1.  管 理 员    **\n");
            printf("**2.  中    介    **\n");
            printf("**3.  租    客    **\n");
            printf("**                **\n");
            printf("********************\n");
            printf("请选择身份：");
            scanf_s("%d", &choice_1);
            clear();
            switch (choice_1)
            {
            case 0:
                break;
            case 1:
                jug0 = 1;

                if (!login(1, p1, head))
                {
                    break;
                }
                while (jug0)
                {

                    printf("*********功能菜单*********\n");
                    printf("**                      **\n");
                    printf("**0.     退    出       **\n");
                    printf("**1.     信息管理       **\n");
                    printf("**2.     看房管理       **\n");
                    printf("**3.     信息查询       **\n");
                    printf("**4.     信息排序       **\n");
                    printf("**5.     信息统计       **\n");
                    printf("**6.     更改密码       **\n");
                    printf("**7.    添加管理员      **\n");
                    printf("**8.     中介管理       **\n");
                    printf("**9.     删除账户       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("请选择功能：");
                    scanf_s("%d", &choice_2);
                    clear();

                    switch (choice_2)
                    {
                    case 0:
                        jug0 = 0;
                        break;
                    case 7:
                        register_user(1, p1, p2, tail, head);
                    case 8:
                        jug1 = 1;
                        while (jug1)
                        {
                            //中介管理界面
                            printf("******中介管理******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  添    加    **\n");
                            printf("**2.  修    改    **\n");
                            printf("**3.  删    除    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_5);
                            clear();
                            switch (choice_5)
                            {
                            case 0:
                                jug1 = 0;
                                break;
                            case 1:
                                register_user(2, p1, p2, tail, head);
                            default:
                                break;
                            }
                        }
                        break;

                    default:
                        break;
                    }
                }
                break;


            case 2:
                jug0 = 1;

                if (!login(2, p1, head))
                {
                    break;
                }
                while (jug0)
                {

                    printf("*********功能菜单*********\n");
                    printf("**                      **\n");
                    printf("**0.     退    出       **\n");
                    printf("**1.     看房管理       **\n");
                    printf("**2.     租房管理       **\n");
                    printf("**3.     信息查询       **\n");
                    printf("**4.     信息排序       **\n");
                    printf("**5.     信息统计       **\n");
                    printf("**6.     更改密码       **\n");
                    printf("**7.     删除账户       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("请选择功能：");
                    scanf_s("%d", &choice_3);
                    clear();

                    switch (choice_3)
                    {
                    case 0:
                        jug0 = 0;
                        break;
                    default:
                        break;
                    }
                }
                break;

            case 3:
                jug0 = 1;

                if (!login(3, p1, head))
                {
                    break;
                }
                while (jug0)
                {

                    printf("*********功能菜单*********\n");
                    printf("**                      **\n");
                    printf("**0.     退    出       **\n");
                    printf("**1.     个人信息       **\n");
                    printf("**2.     看房预约       **\n");
                    printf("**3.     信息查询       **\n");
                    printf("**4.     信息排序       **\n");
                    printf("**5.     信息统计       **\n");
                    printf("**6.     更改密码       **\n");
                    printf("**7.     删除账户       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("请选择功能：");
                    scanf_s("%d", &choice_4);
                    clear();

                    switch (choice_4)
                    {
                    case 0:
                        jug0 = 0;
                        break;
                    default:
                        break;
                    }
                }
                break;
            }
            break;
        case 2:
            register_user(3, p1, p2, tail, head);
        default:
            break;
        }
    }
    write_user_data(head);
    return 0;
}

//实现登录功能
bool login(int input_role, struct User* p1, struct User* head) {
    char input_name[20] = { '\0' };
    char input_password[20] = { '\0' };

    p1 = head->next;
    if (p1 == NULL)
    {
        printf("没有账号数据，请先注册！\n");
        return false;
    }

    printf("请输入姓名：");
    scanf("%s", input_name);

    while (1)
    {
        if (p1->role == input_role)
        {
            if (!strcmp(input_name, p1->username))
            {
                printf("请输入密码:");
                hideInput(input_password, 19);
                if (!strcmp(input_password, p1->password))
                {
                    printf("登录成功，欢迎，用户%s\n", p1->username);
                    printf("回车以继续\n");
                    getchar();
                    clear();
                }
                else
                {
                    printf("密码错误\n");
                    printf("回车以继续\n");
                    getchar();
                    clear();
                    return false;
                }
                return true;;
            }
        }

        p1 = p1->next;
        if (p1 == NULL)
        {
            printf("找不到对象\n");
            printf("回车以继续\n");
            getchar();
            clear();
            return false;;
        }
    }
}

//实现注册功能
void register_user(int role, struct User* p1, struct User* p2, struct User* tail, struct User* head) {
    char input_name[20] = { '\0' };
    char input_password_1[20] = { '\0' };
    char input_password_2[20] = { '\0' };
    char input_phoneNumber[12] = { '\0' };

    memset(input_name, 0, sizeof(input_name));
    printf("请输入姓名：");
    scanf("%s", input_name);

    memset(input_phoneNumber, 0, sizeof(input_phoneNumber));
    printf("请输入电话号码：(11位)");
    scanf("%s", input_phoneNumber);


    while (strlen(input_phoneNumber) != 11)
    {
        clear();
        printf("无效的电话号码！\n");
        printf("请输入正确的的电话号码:");
        memset(input_phoneNumber, 0, sizeof(input_phoneNumber));
        scanf("%s", input_phoneNumber);
    }

    p1 = head->next;
    while (1)
    {
        if (p1 == NULL)
        {
            printf("请输入密码：");
            hideInput(input_password_1, 19);
            printf("请确认密码：");
            hideInput(input_password_2, 19);
            if (!strcmp(input_password_1, input_password_2))
            {
                if (!addUser(input_name, input_password_1, input_phoneNumber, role, p1, p2, tail))
                {
                    return;
                }
                printf("注册成功！\n");
                getchar();
                clear();
                return;
            }
            else
            {
                printf("两次输入不一样的嘞");
                printf("回车以继续");
                getchar();
                clear();
                break;
            }
        }
        if (!strcmp(input_name, p1->username) || !strcmp(input_phoneNumber, p1->phoneNumber))
        {
            printf("该用户已经存在\n");
            printf("按回车以继续\n");
            getchar();
            clear();
            break;
        }
        p1 = p1->next;
    }
}

//添加用户
bool addUser(char* username, char* password, char* phoneNumber, int role, struct User* p1, struct User* p2, struct User* tail)
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
    p1->role = role;


    //数据修改都在上面
    tail->next = p1;
    tail = p1;
    tail->next = NULL;
    p1->prev = p2;
    p2 = p1;//延长链表
    return true;
}