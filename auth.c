//认证功能
#include "auth.h"
#include "utils.h"
#include "crud.h"
#include "data.h"

//实现登录功能
struct User* login(int input_role, struct User* p1, struct User* head) {
    char input_name[20] = { '\0' };
    char input_password[20] = { '\0' };

    p1 = head->next;
    if (p1 == NULL)
    {
        printf("没有账号数据，请先注册！\n");
        getchar();
        clear();
        return NULL;
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
                    return p1;
                }
                else
                {
                    printf("密码错误\n");
                    printf("回车以继续\n");
                    getchar();
                    clear();
                    return NULL;
                }
            }
        }

        p1 = p1->next;
        if (p1 == NULL)
        {
            printf("找不到对象\n");
            printf("回车以继续\n");
            getchar();
            clear();
            return NULL;;
        }
    }
}

//实现注册功能
void register_user(int input_role, struct User* p1, struct User* p2, struct User* tail, struct User* head) {
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
                if (!addUser(input_name, input_password_1, input_phoneNumber, input_role, p1, p2, tail))
                {
                    return;
                }
                printf("注册成功！\n");
                
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
