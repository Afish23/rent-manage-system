#include "data.h"
#include "models.h"
#include "utils.h"
#include "auth.h"
#include "crud.h"
int main() {

    //0：主菜单 1：身份选择菜单 2：管理员菜单 3：中介菜单 4：租客菜单
    int choice_0 = 1, choice_1, choice_2, choice_3, choice_4;
    //5:中介管理菜单10：看房管理菜单
    int choice_5,choice_10;
    int update_id ,delete_id;//修改房源id
    //6.信息查询菜单7.简单查询菜单8.范围查询菜单9.组合查询菜单
    int choice_6, choice_7,choice_8, choice_9;
    //退出循环判断
    //0：身份选择 1:中介管理
    int jug0 = 0, jug1 = 0,jug2 = 0;

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

   



    struct House* house_p1, * house_p2, * house_tail, * house_head;//构建链表
    house_p1 = (struct House*)malloc(sizeof(struct House));//申请空间
    if (house_p1 == NULL)//判断申请的空间是否为空（NULL）
    {
        printf("内存空间分配失败\n");
        return -1;
    }
    house_tail = house_p1;//标记头尾
    house_head = house_p1;
    house_p2 = house_p1;
    house_tail->next = NULL;
    house_head->prev = NULL;

    //数据读取
    read_user_data(&tail);
    read_house_data(&house_tail);

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
                    case 2:
                        jug1 = 1;
                        while (jug1)
                        {
                            printf("******看房管理******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  添    加    **\n");
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
                                jug1 = 0;
                                break;
                            case 1:
                                addHouse(house_head, house_tail, head, tail);
                                write_house_data(house_head);
                                break;
                            case 2: 
                                printf("请输入要修改的房源ID：");
                                scanf_s("%d", &update_id);

                                
                                if (updateHouse(update_id, house_head)) {
                                    printf("房源修改成功！\n");
                                }
                                else {
                                    printf("修改失败，未找到房源。\n");
                                }
                                break;
                            
                            case 3: 

                                printf("请输入要删除的房源ID：");
                                scanf_s("%d", &delete_id);

                                if (deleteHouse(delete_id, house_head)) {
                                    printf("房源删除成功！\n");
                                }
                                else {
                                    printf("删除失败，未找到房源。\n");
                                }
                                break;
                            
                            
                            default:
                                printf("无效选项，请重新选择。\n");
                                clear();

                            }

                        }
                        break;

                    case 3:
                        jug1 = 1;
                        while(jug1)
                        { 
                            printf("*********查询方式*********\n");
                            printf("**                      **\n");
                            printf("**0.     退    出       **\n");
                            printf("**1.     简单查找       **\n");
                            printf("**2.     范围查找       **\n");
                            printf("**3.     组合查找       **\n");
                            printf("**                      **\n");
                            printf("**************************\n");
                            printf("请选择查找方式:\n");
                            scanf_s("%d", &choice_6);
                            clear();
                            switch (choice_6)
                            {
                            case 0:
                                jug1 = 0;
                                break;
                            case 1:
                                jug2 = 1;
                                while (jug2)
                                {
                                    printf("*********查询方式*********\n");
                                    printf("**                      **\n");
                                    printf("** 0.    退    出        **\n");
                                    printf("**1.     所在市          **\n");
                                    printf("**2.     所在县/区       **\n");
                                    printf("**3.     所在小区        **\n");
                                    printf("**4.     朝    向       **\n");
                                    printf("**5.     室    厅       **\n");
                                    printf("**6.     装修情况        **\n");
                                    printf("**7.     中    介       **\n");
                                    printf("**                      **\n");
                                    printf("**************************\n");
                                    scanf_s("%d", &choice_7);
                                    clear();
                                    switch (choice_7)
                                    {
                                    case 0:
                                        jug2 = 0;
                                        break;
                                    case 1:
                                        simpleQueryHouse1(house_head);
                                        break;
                                    case 2:
                                        simpleQueryHouse2(house_head);
                                        break;
                                    case 3:
                                        simpleQueryHouse3(house_head);
                                        break;
                                    case 4:
                                        simpleQueryHouse4(house_head);
                                        break;
                                    case 5:
                                        simpleQueryHouse5(house_head);
                                        break;
                                    case 6:
                                        simpleQueryHouse6(house_head);
                                        break;
                                    case 7:
                                        simpleQueryHouse7(house_head);
                                        break;
                                    default:
                                        printf("无效选项，请重新选择。\n");
                                        clear();
                                        break;

                                    }
                                }
                                break;
                            case 2:
                                jug2 = 1;
                                while (jug2)
                                {
                                    printf("*********查询方式*********\n");
                                    printf("**                      **\n");
                                    printf("**0.     退    出       **\n");
                                    printf("**1.     租    金       **\n");
                                    printf("**2.     楼    层       **\n");
                                    printf("**3.     面    积       **\n");
                                    printf("**                      **\n");
                                    printf("**************************\n");
                                    scanf_s("%d", &choice_8);
                                    clear();
                                    switch (choice_8) {
                                    case 0:
                                        jug2 = 0;
                                        break;
                                    case 1:
                                        rangeQueryRent(house_head);
                                        break;
                                    case 2:
                                        rangeQueryFloor(house_head);
                                        break;
                                    case 3:
                                        rangeQueryArea(house_head);
                                        break;
                                    default:
                                        printf("无效选项，请重新选择。\n");
                                        clear();
                                        break;
                                    }
                                }
                            
                                break;

                            }

                            
                        }

                        break;
                    case 6:
                        updateMyPassword(p1);
                        continue;
                    case 7:
                        register_user(1, p1, p2, tail, head);
                        write_user_data(head);
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
                                write_user_data(head);
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
            write_user_data(head);
        default:
            break;
        }
    }

    return 0;
}