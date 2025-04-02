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
        //13：查找菜单 14：简单查询菜单 15：范围查询菜单 17：组合查询菜单
    int choice_13, choice_14, choice_15, choice_16, choice_17;
    //18：租房管理菜单
    int choice_18, choice_19;

    //退出循环判断
    //0：身份选择 1:中介管理 2:房源管理 3:信息查询 4:信息排序 
    int jug0 = 0, jug1 = 0, jug2 = 0, jug3 = 0, jug4 = 0,
        //5:信息统计 6:看房管理 7:租房管理 8:看房预约
        jug5 = 0, jug6 = 0, jug7 = 0, jug8 = 0;
    //9：查找方式 10：简单查询 11：范围查询 12：组合查询
    int jug9 = 0, jug10 = 0, jug11 = 0, jug12 = 0;
    //13：租房管理
    int jug13 = 0, jug14 = 0;
 

    //
    int update_id = 0, delete_id = 0;
    int a;

    //定义用户
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


    //房子定义
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


    //租房定义
    struct Rent* q1, * q2, * tail1, * head1;
    q1 = (struct Rent*)malloc(sizeof(struct Rent));//申请空间
    if (q1 == NULL) { // 判断申请的空间是否为空（NULL）
        printf("内存空间分配失败\n");
        return -1;
    }
    tail1 = q1; // 标记头尾
    head1 = q1;
    q2 = q1;
    tail1->next = NULL;
    head1->prev = NULL;

    //数据读取
    read_user_data(&tail);
    read_house_data(&house_tail);
    read_tenant_data(&tail1);
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
                            case 1:
                                addHouse(house_p1, house_head, house_tail, head, tail);
                                house_tail = house_tail->next;
                                printf("请输入回车键继续：");
                                getchar();
                                clear();

                                break;
                            case 2:
                                printf("请输入要修改的房源ID：");
                                scanf_s("%d", &update_id);


                                if (updateHouse(update_id, house_head)) {
                                    printf("房源修改成功！\n");
                                    printf("请输入回车键继续：");
                                    getchar();
                                    clear();
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
                                    printf("请输入回车键继续：");
                                    getchar();
                                    clear();
                                }
                                else {
                                    printf("删除失败，未找到房源。\n");
                                }
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
                            case 2:

                                jug9 = 1;
                                while (jug9)
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
                                    scanf_s("%d", &choice_13);
                                    clear();
                                    switch (choice_13)
                                    {
                                    case 0:
                                        jug9 = 0;
                                        break;
                                    case 1:
                                        jug10 = 1;
                                        while (jug10)
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
                                            scanf_s("%d", &choice_14);
                                            clear();
                                            switch (choice_14)
                                            {
                                            case 0:
                                                jug10 = 0;
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
                                                getchar();
                                                clear();
                                                break;

                                            }
                                        }
                                        break;
                                    case 2:
                                        jug11 = 1;
                                        while (jug11)
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
                                                jug11 = 0;
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
                            printf("******租房管理******\n");
                            printf("**                **\n");
                            printf("**0.  退    出    **\n");
                            printf("**1.  添加租房    **\n");
                            printf("**2.  删除租房    **\n");
                            printf("**3.  修改租房    **\n");
                            printf("**                **\n");
                            printf("********************\n");

                            scanf("%d", &choice_18);
                            switch (choice_18)
                            {
                            case 0:
                                jug7 = 0;
                                clear();
                                break; 
                            case 1: {
                                        struct Rent* p1;
                                        p1 = (struct Rent*)malloc(sizeof(struct Rent)); // 申请内存
                                        if (p1 == NULL) {  // 判断内存是否分配成功
                                            printf("内存空间分配失败");
                                            return false;
                                        }
                                        addRent(p1, &tail1);
                                        printf("请输入回车键继续：");
                                        getchar();
                                        clear();
                                        break;
                                    }
                            case 2: {
                                        int id1;
                                        printf("输入id\n");
                                        scanf("%d", &id1);
                                        struct Rent* p1 = findRent(id1, head1);
                                        //printf("%d", p1->contractTime);
                                        if (p1 != NULL) {
                                            if (p1->prev != NULL && p1->next != NULL) {
                                                deleteRent(&p1->prev, &p1, &p1->next);
                                            }
                                            else if (p1->prev == NULL) { p1->next->prev == NULL, free(p1); }
                                            else if (p1->next == NULL) { p1->prev->next == NULL, free(p1); }
                                        }
                                        else printf("没有找到，删除失败");
                                        printf("请输入回车键继续：");
                                        getchar();
                                        clear();
                                        break;
                                    }
                            case 3: {
                                        int choice; int id1;
                                        printf("输入id\n");
                                        scanf("%d", &id1);
                                        struct Rent* p1 = findRent(id1, head1);
                                        if (p1 != NULL) {
                                            printf("请选择要修改的租房信息字段:\n");
                                            printf("1. 租房编号\n");
                                            printf("2. 合同签订日期\n");
                                            printf("3. 出租开始日期\n");
                                            printf("4. 预计出租时长\n");
                                            printf("5. 中介姓名\n");
                                            printf("6. 租客姓名\n");
                                            printf("7. 房源ID\n");
                                            printf("8. 房源位置\n");
                                            printf("9. 租赁状态\n");
                                            printf("0. 退出修改\n");

                                            scanf("%d", &choice);
                                            while (choice != 0) {
                                                switch (choice) {
                                                case 1:
                                                    printf("请输入新的租房编号: ");
                                                    scanf("%d", &p1->id);
                                                    break;
                                                case 2:
                                                    printf("请输入新的合同签订日期: ");
                                                    scanf("%d", &p1->contractTime);
                                                    break;
                                                case 3:
                                                    printf("请输入新的出租开始日期: ");
                                                    scanf("%d", &p1->rentStartTime);
                                                    break;
                                                case 4:
                                                    printf("请输入新的预计出租时长: ");
                                                    scanf("%d", &p1->rentDuration);
                                                    break;
                                                case 5:
                                                    printf("请输入新的中介姓名: ");
                                                    scanf("%s", p1->agentname);
                                                    break;
                                                case 6:
                                                    printf("请输入新的租客姓名: ");
                                                    scanf("%s", p1->tenantname);
                                                    break;
                                                case 7:
                                                    printf("请输入新的房源ID: ");
                                                    scanf("%d", &p1->house_id);
                                                    break;
                                                case 8://没写
                                                    printf("请输入新的房源位置: ");
                                                    break;
                                                case 9:
                                                    printf("请输入新的租赁状态 (0-已完成, 1-正在租): ");
                                                    scanf("%d", &p1->statement);
                                                    break;
                                                default:
                                                    printf("无效选项，请重新输入\n");
                                                }

                                                // 继续显示菜单，允许用户继续修改
                                                printf("\n请选择要修改的租房信息字段:\n");
                                                printf("1. 租房编号\n");
                                                printf("2. 合同签订日期\n");
                                                printf("3. 出租开始日期\n");
                                                printf("4. 预计出租时长\n");
                                                printf("5. 中介姓名\n");
                                                printf("6. 租客姓名\n");
                                                printf("7. 房源ID\n");
                                                printf("8. 房源位置\n");
                                                printf("9. 租赁状态\n");
                                                printf("0. 退出修改\n");

                                                scanf("%d", &choice);
                                            }
                                            printf("修改完成！\n");
                                        }
                                        else printf("没有找到，修改失败");
                                        printf("请输入回车键继续：");
                                        getchar();
                                        clear();
                                        break;
                                    }
                                   
                                   
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
    write_house_data(house_head);
    write_tenant_data(head1);
    return 0;
}