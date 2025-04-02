#include "data.h"
#include "models.h"
#include "utils.h"
#include "auth.h"
#include "crud.h"
int main() {
    
        //0：主菜单 1：身份选择菜单 2：管理员菜单 3：中介菜单 4：租客菜单
    int choice_0 = 1, choice_1, choice_2, choice_3, choice_4,
        //5:管理员-中介管理菜单 6:管理员-房源管理菜单 7:信息查询菜单 8:信息排序菜单
        choice_5, choice_6, choice_7, choice_8,
        //9:信息统计菜单 10:看房管理菜单 11:租房管理菜单 12:看房预约菜单
        choice_9, choice_10, choice_11, choice_12;
        //退出循环判断
        //0：身份选择 1:中介管理 2:房源管理 3:信息查询 4:信息排序 
    int jug0 = 0, jug1 = 0, jug2 = 0, jug3 = 0, jug4 = 0, 
        //5:信息统计 6:看房管理 7:租房管理 8:看房预约
        jug5 = 0, jug6 = 0, jug7 = 0, jug8 = 0;

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


    //数据读取
    read_user_data(&tail);

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
                p1 = login(1, p1, head);
                if (p1 == NULL)
                {
                    break;
                }
                while (jug0)
                {

                    printf("*********功能菜单*********\n");
                    printf("**                      **\n");
                    printf("**0.     退    出       **\n");
                    printf("**1.     房源管理       **\n");
                    printf("**2.     分配中介       **\n");
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
                    case 1:
                        jug2 = 1;
                        while (jug2)
                        {
                            //房源管理界面
                            printf("******房源管理******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  添    加    **\n");
                            printf("**2.  修    改    **\n");
                            printf("**3.  删    除    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_6);
                            clear();
                            switch (choice_6)
                            {
                            case 0:
                                jug2 = 0;
                                break;
                            default:
                                jug2 = 0;
                                break;
                            }
                        }
                        break;
                    case 2:

                    case 3:
                        jug3 = 1;
                        while (jug3)
                        {
                            //信息查询界面
                            printf("******信息查询******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  用户信息    **\n");
                            printf("**2.  房源信息    **\n");
                            printf("**3.  预约信息    **\n");
                            printf("**4.  租房信息    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_7);
                            clear();
                            switch (choice_7)
                            {
                            case 0:
                                jug3 = 0;
                                break;
                            default:
                                jug3 = 0;
                                break;
                            }
                        }
                        break;
                    case 4:
                        jug4 = 1;
                        while (jug4)
                        {
                            //信息排序界面
                            printf("******信息排序******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  房源信息    **\n");
                            printf("**2.  预约信息    **\n");
                            printf("**3.  租房信息    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_8);
                            clear();
                            switch (choice_8)
                            {
                            case 0:
                                jug4 = 0;
                                break;
                            default:
                                jug4 = 0;
                                break;
                            }
                        }
                        break;
                    case 5:
                        jug5 = 1;
                        while (jug5)
                        {
                            //信息统计界面
                            printf("******信息统计******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  房源信息    **\n");
                            printf("**2.  预约信息    **\n");
                            printf("**3.  租房信息    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_9);
                            clear();
                            switch (choice_9)
                            {
                            case 0:
                                jug5 = 0;
                                break;
                            default:
                                jug5 = 0;
                                break;
                            }
                        }
                        break;
                    case 6:
                        updateMyPassword(p1);
                        continue;
                    case 7:
                        register_user(1, p1, p2, tail, head);
                        continue;
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
                                continue;
                            case 2:
                                updatePassword(2, p1, head);
                                continue;
                            case 3:
                                deleteUser(2, p1, head, tail);
                                continue;
                            default:
                                jug1 = 0;
                                break;
                            }
                        }
                        break;
                    case 9:
                        deleteMyUser(p1, tail);
                        jug0 = 0;
                        break;
                    default:
                        jug0 = 0;
                        break;
                    }
                }
                break;
                    
                
            case 2:
                jug0 = 1;

                p1 = login(2, p1, head);
                if (p1 == NULL)
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
                    case 1:
                        jug6 = 1;
                        while (jug6)
                        {
                            //看房管理界面
                            printf("******看房管理******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  查    看    **\n");
                            printf("**2.  修    改    **\n");
                            printf("**3.  删    除    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_10);
                            clear();
                            switch (choice_10)
                            {
                            case 0:
                                jug6 = 0;
                                break;
                            default:
                                jug6 = 0;
                                break;
                            }
                        }
                        break;
                    case 2:
                        jug7 = 1;
                        while (jug7)
                        {
                            //租房管理界面
                            printf("******租房管理******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  新    增    **\n");
                            printf("**2.  查    看    **\n");
                            printf("**3.  修    改    **\n");
                            printf("**4.  删    除    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_11);
                            clear();
                            switch (choice_11)
                            {
                            case 0:
                                jug7 = 0;
                                break;
                            default:
                                jug7 = 0;
                                break;
                            }
                        }
                        break;
                    case 3:
                        jug3 = 1;
                        while (jug3)
                        {
                            //信息查询界面
                            printf("******信息查询******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  房源信息    **\n");
                            printf("**2.  预约信息    **\n");
                            printf("**3.  租房信息    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_7);
                            clear();
                            switch (choice_7)
                            {
                            case 0:
                                jug3 = 0;
                                break;
                            default:
                                jug3 = 0;
                                break;
                            }
                        }
                        break;
                    case 4:
                        jug4 = 1;
                        while (jug4)
                        {
                            //信息排序界面
                            printf("******信息排序******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  房源信息    **\n");
                            printf("**2.  预约信息    **\n");
                            printf("**3.  租房信息    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_8);
                            clear();
                            switch (choice_8)
                            {
                            case 0:
                                jug4 = 0;
                                break;
                            default:
                                jug4 = 0;
                                break;
                            }
                        }
                        break;
                    case 5:
                        jug5 = 1;
                        while (jug5)
                        {
                            //信息统计界面
                            printf("******信息统计******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  房源信息    **\n");
                            printf("**2.  预约信息    **\n");
                            printf("**3.  租房信息    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_9);
                            clear();
                            switch (choice_9)
                            {
                            case 0:
                                jug5 = 0;
                                break;
                            default:
                                jug5 = 0;
                                break;
                            }
                        }
                        break;
                    case 6:
                        updateMyPassword(p1);
                        continue;
                    case 7:
                        deleteMyUser(p1, tail);
                        jug0 = 0;
                        break;
                    default:
                        jug0 = 0;
                        break;
                    }
                }
                break;
                 
            case 3:
                jug0 = 1;

                p1 = login(3, p1, head);
                if (p1 == NULL)
                {
                    break;
                }
               
                while (jug0)
                {

                    printf("*********功能菜单*********\n");
                    printf("**                      **\n");
                    printf("**0.     退    出       **\n");
                    printf("**1.     修改信息       **\n");
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
                    case 1:
                        updateMyNameOrPhoneNumber(p1);
                        continue;
                    case 2:
                        jug8 = 1;
                        while (jug8)
                        {
                            //看房预约界面
                            printf("******看房预约******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  新    增    **\n");
                            printf("**2.  查    看    **\n");
                            printf("**2.  修    改    **\n");
                            printf("**3.  删    除    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_12);
                            clear();
                            switch (choice_12)
                            {
                            case 0:
                                jug8 = 0;
                                break;
                            default:
                                jug8 = 0;
                                break;
                            }
                        }
                        break;
                    case 3:
                        jug3 = 1;
                        while (jug3)
                        {
                            //信息查询界面
                            printf("******信息查询******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  房源信息    **\n");
                            printf("**2.  预约信息    **\n");
                            printf("**3.  租房信息    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_7);
                            clear();
                            switch (choice_7)
                            {
                            case 0:
                                jug3 = 0;
                                break;
                            default:
                                jug3 = 0;
                                break;
                            }
                        }
                        break;
                    case 4:
                        jug4 = 1;
                        while (jug4)
                        {
                            //信息排序界面
                            printf("******信息排序******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  房源信息    **\n");
                            printf("**2.  预约信息    **\n");
                            printf("**3.  租房信息    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_8);
                            clear();
                            switch (choice_8)
                            {
                            case 0:
                                jug4 = 0;
                                break;
                            default:
                                jug4 = 0;
                                break;
                            }
                        }
                        break;
                    case 5:
                        jug5 = 1;
                        while (jug5)
                        {
                            //信息统计界面
                            printf("******信息统计******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  房源信息    **\n");
                            printf("**2.  预约信息    **\n");
                            printf("**3.  租房信息    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("请选择：");
                            scanf_s("%d", &choice_9);
                            clear();
                            switch (choice_9)
                            {
                            case 0:
                                jug5 = 0;
                                break;
                            default:
                                jug5 = 0;
                                break;
                            }
                        }
                        break;
                    case 6:
                        updateMyPassword(p1);
                        continue;
                    case 7:
                        deleteMyUser(p1, tail);
                        jug0 = 0;
                        break;
                    default:
                        jug0 = 0;
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

