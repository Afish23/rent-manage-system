#include "data.h"
#include "models.h"
#include "utils.h"
#include "auth.h"
#include "crud.h"
#include "inquire.h"
#include "statistics.h"
#include "sort.h"
int main() {

    //0�����˵� 1�����ѡ��˵� 2������Ա�˵� 3���н�˵� 4����Ͳ˵�
    int choice_0 = 1, choice_1, choice_2, choice_3, choice_4,
        //5:����Ա-�н����˵� 6:����Ա-��Դ����˵� 7:��Ϣ��ѯ�˵� 8:��Ϣ����˵�
        choice_5, choice_6, choice_7, choice_8,
        //9:��Ϣͳ�Ʋ˵� 10:��������˵� 11:�ⷿ����˵� 12:����ԤԼ�˵�
        choice_9, choice_10, choice_11, choice_12,
        //13�����Ҳ˵� 14���򵥲�ѯ�˵� 15����Χ��ѯ�˵� 16����ϲ�ѯ�˵�
        choice_13, choice_14, choice_15, choice_16,
        //17�� 18���ⷿ����˵� 19:�ⷿ��Ϣ���Ĳ˵�
        choice_17, choice_18, choice_19,
        choice_20, choice_21, choice_22, choice_23, choice_24, choice_25;
    //�˳�ѭ���ж�
        //0�����ѡ�� 1:�н���� 2:��Դ���� 3:��Ϣ��ѯ 4:��Ϣ���� 
    int jug0 = 0, jug1 = 0, jug2 = 0, jug3 = 0, jug4 = 0,
        //5:��Ϣͳ�� 6:�������� 7:�ⷿ���� 8:����ԤԼ 9:��ѯ��ʽ
        jug5 = 0, jug6 = 0, jug7 = 0, jug8 = 0, jug9 = 0,
        //10���򵥲�ѯ 11����Χ��ѯ 12����ϲ�ѯ 13���ⷿ���� 14:�ⷿ��Ϣ����
        jug10 = 0, jug11 = 0, jug12 = 0, jug13 = 0, jug14 = 0,
        jug15 = 0, jug16 = 0, jug17 = 0, jug18 = 0, jug19 = 0, jug20 = 0;


    struct User* p1, * p2, * tail, * head;
    p1 = (struct User*)malloc(sizeof(struct User));//����ռ�
    if (p1 == NULL) { // �ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
        printf("�ڴ�ռ����ʧ��\n");
        return -1;
    }

    tail = p1; // ���ͷβ
    head = p1;
    p2 = p1;
    tail->next = NULL;
    head->prev = NULL;

    struct House* house_p1, * house_p2, * house_tail, * house_head;//��������
    house_p1 = (struct House*)malloc(sizeof(struct House));//����ռ�
    if (house_p1 == NULL)//�ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
    {
        printf("�ڴ�ռ����ʧ��\n");
        return -1;
    }
    house_tail = house_p1;//���ͷβ
    house_head = house_p1;
    house_p2 = house_p1;
    house_tail->next = NULL;
    house_head->prev = NULL;

    //ԤԼ����
    struct Appointment* r1, * r2, * tail2, * head2;
    r1 = (struct Appointment*)malloc(sizeof(struct Appointment));//����ռ�
    if (r1 == NULL) { // �ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
        printf("�ڴ�ռ����ʧ��\n");
        return -1;
    }
    tail2 = r1; // ���ͷβ
    head2 = r1;
    r2 = r1;
    tail2->next = NULL;
    head2->prev = NULL;


    //�ⷿ����
    struct Rent* q1, * q2, * tail1, * head1;
    q1 = (struct Rent*)malloc(sizeof(struct Rent));//����ռ�
    if (q1 == NULL) { // �ж�����Ŀռ��Ƿ�Ϊ�գ�NULL��
        printf("�ڴ�ռ����ʧ��\n");
        return -1;
    }
    tail1 = q1; // ���ͷβ
    head1 = q1;
    q2 = q1;
    tail1->next = NULL;
    head1->prev = NULL;

    //���ݶ�ȡ
    read_user_data(&tail);
    read_house_data(&house_tail);
    read_Appointment_data(&tail2);
    read_rent_data(&tail1);

    //������
    while (choice_0) {
        printf("******��    ¼******\n");
        printf("**                **\n");
        printf("**0.  ��    ��    **\n");
        printf("**1.  ��    ¼    **\n");
        printf("**2.  ���ע��    **\n");
        printf("**                **\n");
        printf("********************\n");
        printf("��ѡ���ܣ�");
        scanf_s("%d", &choice_0);
        clear();

        switch (choice_0) {
        case 0:
            break;
        case 1:
            //���ѡ�����
            printf("******���ѡ��******\n");
            printf("**                **\n");
            printf("**0.  ��    ��    **\n");
            printf("**1.  �� �� Ա    **\n");
            printf("**2.  ��    ��    **\n");
            printf("**3.  ��    ��    **\n");
            printf("**                **\n");
            printf("********************\n");
            printf("��ѡ����ݣ�");
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

                    printf("*********���ܲ˵�*********\n");
                    printf("**                      **\n");
                    printf("**0.     ��    ��       **\n");
                    printf("**1.     ��Դ����       **\n");
                    printf("**2.     �����н�       **\n");
                    printf("**3.     ��Ϣ��ѯ       **\n");
                    printf("**4.     ��Ϣ����       **\n");
                    printf("**5.     ��Ϣͳ��       **\n");
                    printf("**6.     ��������       **\n");
                    printf("**7.    ��ӹ���Ա      **\n");
                    printf("**8.     �н����       **\n");
                    printf("**9.     ɾ���˻�       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("��ѡ���ܣ�");
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
                            //��Դ�������
                            printf("******��Դ����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��    ��    **\n");
                            printf("**2.  ��    ��    **\n");
                            printf("**3.  ɾ    ��    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_6);
                            clear();
                            switch (choice_6)
                            {
                            case 0:
                                jug2 = 0;
                                continue;
                            case 1:
                                addHouse(house_head, house_tail);
                                house_tail = house_tail->next;
                                continue;
                            case 2:
                                updateHouse(house_head);
                                continue;
                            case 3:
                                deleteHouse(house_head);
                                continue;
                            default:
                                printf("��Чѡ�������ѡ��\n");
                                getchar();
                                clear();
                                continue;
                            }
                        }
                        break;
                    case 2:
                        appointAgent(head2);
                        continue;
                    case 3:
                        jug3 = 1;
                        while (jug3)
                        {
                            //��Ϣ��ѯ����
                            printf("******��Ϣ��ѯ******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  �û���Ϣ    **\n");
                            printf("**2.  ��Դ��Ϣ    **\n");
                            printf("**3.  ԤԼ��Ϣ    **\n");
                            printf("**4.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_7);
                            clear();
                            switch (choice_7)
                            {
                            case 0:
                                jug3 = 0;
                                break;
                            case 1:
                                printUsersInOrder(head);
                                continue;
                            case 2:
                                jug9 = 1;
                                while (jug9)
                                {
                                    printf("*********��ѯ��ʽ*********\n");
                                    printf("**                      **\n");
                                    printf("**0.     ��    ��       **\n");
                                    printf("**1.     �򵥲���       **\n");
                                    printf("**2.     ��Χ����       **\n");
                                    printf("**3.     ��ϲ���       **\n");
                                    printf("**                      **\n");
                                    printf("**************************\n");
                                    printf("��ѡ����ҷ�ʽ:\n");
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
                                            printf("*********��ѯ��ʽ*********\n");
                                            printf("**                      **\n");
                                            printf("**0.     ��    ��       **\n");
                                            printf("**1.     �� �� ��       **\n");
                                            printf("**2.     ������/��      **\n");
                                            printf("**3.     ����С��       **\n");
                                            printf("**4.     ��    ��       **\n");
                                            printf("**5.     ��    ��       **\n");
                                            printf("**6.     װ�����       **\n");
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
                                                continue;
                                            case 2:
                                                simpleQueryHouse2(house_head);
                                                continue;
                                            case 3:
                                                simpleQueryHouse3(house_head);
                                                continue;
                                            case 4:
                                                simpleQueryHouse4(house_head);
                                                continue;
                                            case 5:
                                                simpleQueryHouse5(house_head);
                                                continue;
                                            case 6:
                                                simpleQueryHouse6(house_head);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                        break;
                                    case 2:
                                        jug11 = 1;
                                        while (jug11)
                                        {
                                            printf("*********��ѯ��ʽ*********\n");
                                            printf("**                      **\n");
                                            printf("**0.     ��    ��       **\n");
                                            printf("**1.     ��    ��       **\n");
                                            printf("**2.     ¥    ��       **\n");
                                            printf("**3.     ��    ��       **\n");
                                            printf("**                      **\n");
                                            printf("**************************\n");
                                            scanf_s("%d", &choice_15);
                                            clear();
                                            switch (choice_15) {
                                            case 0:
                                                jug11 = 0;
                                                break;
                                            case 1:
                                                rangeQueryRent(house_head);
                                                continue;
                                            case 2:
                                                rangeQueryFloor(house_head);
                                                continue;
                                            case 3:
                                                rangeQueryArea(house_head);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                        break;
                                    case 3:
                                        combinedQueryHouse(head);
                                        continue;
                                    }
                                }
                                break;
                            case 3:
                                printAppointmentsInOrder(head2);
                                continue;
                            case 4:
                                printRentsInOrder(head1);
                                continue;
                            default:
                                printf("��Чѡ�������ѡ��\n");
                                getchar();
                                clear();
                                continue;
                            }
                        }
                        break;
                    case 4:
                        jug4 = 1;
                        while (jug4)
                        {
                            //��Ϣ�������
                            printf("******��Ϣ����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_8);
                            clear();
                            switch (choice_8)
                            {
                            case 0:
                                jug4 = 0;
                                break;
                            case 1:
                                jug16 = 1;
                                while (jug16) {
                                    printf("******��Դ��Ϣ����******\n");
                                    printf("**                    **\n");
                                    printf("**0.  ��    ��        **\n");
                                    printf("**1.  ��һ����        **\n");
                                    printf("**2.  ��������        **\n");
                                    printf("**                    **\n");
                                    printf("************************\n");
                                    printf("��ѡ������ʽ:\n");
                                    scanf_s("%d", &choice_21);
                                    clear();
                                    if (choice_21 == 0) {
                                        jug16 = 0;
                                        break;
                                    }
                                    else if (choice_21 == 1) {
                                        jug15 = 1;
                                        while (jug15) {
                                            printf("******��Դ��Ϣ��һ����******\n");
                                            printf("**                        **\n");
                                            printf("**0.  ��    ��            **\n");
                                            printf("**1.  ��Դ���            **\n");
                                            printf("**2.  �����С            **\n");
                                            printf("**3.  ��    ��            **\n");
                                            printf("**4.  �� �� ��            **\n");
                                            printf("**                        **\n");
                                            printf("****************************\n");
                                            printf("��ѡ������ʽ:\n");
                                            scanf_s("%d", &choice_20);
                                            clear();
                                            switch (choice_20) {
                                            case 0:
                                                jug15 = 0;
                                                break;
                                            case 1:
                                                simpleSortHouseid(&((house_head)->next));
                                                printHouseList((house_head)->next);
                                                continue;
                                            case 2:
                                                simpleSortHouseArea(&((house_head)->next));
                                                printHouseList((house_head)->next);
                                                continue;
                                            case 3:
                                                simpleSortHouseRent(&((house_head)->next));
                                                printHouseList((house_head)->next);
                                                continue;
                                            case 4:
                                                simpleSortHouseAgencyFee(&((house_head)->next));
                                                printHouseList((house_head)->next);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                    }
                                    else if (choice_21 == 2) {
                                        jug15 = 1;
                                        while (jug15) {
                                            printf("******��Դ��Ϣ��������******\n");
                                            printf("**                        **\n");
                                            printf("**0.  ��    ��            **\n");
                                            printf("**1.  �����С            **\n");
                                            printf("**2.  ��    ��            **\n");
                                            printf("**3.  �� �� ��            **\n");
                                            printf("**                        **\n");
                                            printf("****************************\n");
                                            printf("��ѡ����������ʽ:\n");
                                            scanf_s("%d%d", &choice_20, &choice_21);
                                            clear();
                                            switch (choice_20) {
                                            case 0:
                                                jug15 = 0;
                                                break;
                                            case 1:
                                                switch (choice_21) {
                                                case 1:
                                                    printf("�����ظ����룬����������\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                case 2:
                                                    simpleSortHouseArea(&((house_head)->next));
                                                    multSortArea_ByRent(&((house_head)->next));
                                                    printHouseList((house_head)->next);
                                                    continue;
                                                case 3:
                                                    simpleSortHouseArea(&((house_head)->next));
                                                    multSortArea_ByAgencyFee(&((house_head)->next));
                                                    printHouseList((house_head)->next);
                                                    continue;
                                                default:
                                                    printf("��Чѡ�������ѡ��\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                }
                                                continue;
                                            case 2:
                                                switch (choice_21) {
                                                case 1:
                                                    simpleSortHouseRent(&((house_head)->next));
                                                    multSortRent_ByArea(&((house_head)->next));
                                                    printHouseList((house_head)->next);
                                                    continue;
                                                case 2:
                                                    printf("�����ظ����룬����������\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                case 3:
                                                    simpleSortHouseRent(&((house_head)->next));
                                                    multSortRent_ByAgencyFee(&((house_head)->next));
                                                    printHouseList((house_head)->next);
                                                    continue;
                                                default:
                                                    printf("��Чѡ�������ѡ��\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                }
                                                continue;
                                            case 3:
                                                switch (choice_21) {
                                                case 1:
                                                    simpleSortHouseAgencyFee(&((house_head)->next));
                                                    multSortAgencyFee_ByArea(&((house_head)->next));
                                                    printHouseList((house_head)->next);
                                                    continue;
                                                case 2:
                                                    simpleSortHouseAgencyFee(&((house_head)->next));
                                                    multSortAgencyFee_ByRent(&((house_head)->next));
                                                    printHouseList((house_head)->next);
                                                    continue;
                                                case 3:
                                                    printf("�����ظ����룬����������\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                default:
                                                    printf("��Чѡ�������ѡ��\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                }
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }

                                    }
                                }
                            case 2:
                                jug16 = 1;
                                while (jug16) {
                                    printf("******�ⷿ��Ϣ����******\n");
                                    printf("**                    **\n");
                                    printf("**0.  ��    ��        **\n");
                                    printf("**1.  ��һ����        **\n");
                                    printf("**2.  ��������        **\n");
                                    printf("**                    **\n");
                                    printf("************************\n");
                                    printf("��ѡ������ʽ:\n");
                                    scanf_s("%d", &choice_21);
                                    clear();
                                    if (choice_21 == 0) {
                                        jug16 = 0;
                                        break;
                                    }
                                    else if (choice_21 == 1) {
                                        jug15 = 1;
                                        while (jug15) {
                                            printf("******�ⷿ��Ϣ����********\n");
                                            printf("**                      **\n");
                                            printf("**0.  ��    ��          **\n");
                                            printf("**1.  ���ⷿ�������    **\n");
                                            printf("**2.  ����ͬǩ����������**\n");
                                            printf("**3.  �����⿪ʼ��������**\n");
                                            printf("**4.  ��Ԥ�Ƴ���ʱ������**\n");
                                            printf("**5.  ������״̬����    **\n");
                                            printf("**                      **\n");
                                            printf("**************************\n");
                                            printf("��ѡ������ʽ:\n");
                                            scanf_s("%d", &choice_20);
                                            clear();
                                            switch (choice_20) {
                                            case 0:
                                                jug15 = 0;
                                                break;
                                            case 1:
                                                simpleSortid(&((head1)->next));
                                                printList((head1)->next);
                                                continue;
                                            case 2:
                                                simpleSortByContractTime(&((head1)->next));
                                                printList((head1)->next);
                                                continue;
                                            case 3:
                                                simpleSortByRentStartTime(&((head1)->next));
                                                printList((head1)->next);
                                                continue;
                                            case 4:
                                                simpleSortByRentDuration(&((head1)->next));
                                                printList((head1)->next);
                                                continue;
                                            case 5:
                                                simpleSortByStatement(&((head1)->next));
                                                printList((head1)->next);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                    }
                                    else if (choice_21 == 2) {
                                        jug15 = 1;
                                        while (jug15) {
                                            printf("******�ⷿ��Ϣ��������(ǰ������)******\n");
                                            printf("**                                  **\n");
                                            printf("**0.  �˳�                          **\n");
                                            printf("**1.  ���ⷿ�������                **\n");
                                            printf("**2.  ��Ԥ�Ƴ���ʱ������            **\n");
                                            printf("**3.  �����⿪ʼ��������            **\n");
                                            printf("**************************************\n");
                                            printf("��ѡ����������ʽ:\n");
                                            scanf_s("%d%d", &choice_20, &choice_21);
                                            clear();
                                            switch (choice_20) {
                                            case 0:
                                                jug15 = 0;
                                                break;
                                            case 1:
                                                simpleSortid(&((head1)->next));
                                                switch (choice_21) {
                                                case 1:
                                                    printf("�����ظ����룬����������\n");
                                                    continue;
                                                case 2:
                                                    multSortid_ByRentDuration(&((head1)->next));
                                                    printList((head1)->next);
                                                    continue;
                                                case 3:
                                                    multSortid_ByRentStartTime(&((head1)->next));
                                                    printList((head1)->next);
                                                    continue;
                                                default:
                                                    printf("��Чѡ�������ѡ��\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                }
                                                continue;
                                            case 2:
                                                simpleSortByRentDuration(&((head1)->next));
                                                switch (choice_21) {
                                                case 1:
                                                    multSortRentDuration_Byid(&((head1)->next));
                                                    printList((head1)->next);
                                                    continue;
                                                case 2:
                                                    printf("�����ظ����룬����������\n");
                                                    continue;
                                                case 3:
                                                    multSortRentDuration_ByRentStartTime(&((head1)->next));
                                                    printList((head1)->next);
                                                    continue;
                                                default:
                                                    printf("��Чѡ�������ѡ��\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                }
                                                continue;
                                            case 3:
                                                simpleSortByRentStartTime(&((head1)->next));
                                                switch (choice_21) {
                                                case 1:
                                                    multSortRentStartTime_Byid(&((head1)->next));
                                                    printList((head1)->next);
                                                    continue;
                                                case 2:
                                                    multSortRentStartTime_ByRentDuration(&((head1)->next));
                                                    printList((head1)->next);
                                                    continue;
                                                case 3:
                                                    printf("�����ظ����룬����������\n");
                                                    continue;
                                                default:
                                                    printf("��Чѡ�������ѡ��\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                }
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    case 5:
                        jug5 = 1;
                        while (jug5)
                        {
                            //��Ϣͳ�ƽ���
                            printf("******��Ϣͳ��******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_9);
                            clear();
                            switch (choice_9)
                            {
                            case 0:
                                jug5 = 0;
                                break;
                            case 1:
                                jug15 = 1;
                                while (jug15) {

                                    printf("******ͳ�Ʒ�ʽ******\n");
                                    printf("**                **\n");
                                    printf("**0.  ��    ��    **\n");
                                    printf("**1.  ��һ����    **\n");
                                    printf("**2.  ��������    **\n");
                                    printf("**3.  Ԥ��ͳ��    **\n");
                                    printf("**4.  ����ͳ��    **\n");
                                    printf("**                **\n");
                                    printf("********************\n");
                                    printf("��ѡ��");
                                    scanf_s("%d", &choice_20);
                                    clear();
                                    switch (choice_20)
                                    {
                                    case 0:
                                        jug15 = 0;
                                        break;
                                    case 1:
                                        jug16 = 1;
                                        while (jug16)
                                        {
                                            printf("******��һ����ͳ��******\n");
                                            printf("**                   **\n");
                                            printf("**  0.��       ��     **\n");
                                            printf("**  1.¥��    ͳ��    **\n");
                                            printf("**  2.����    ͳ��    **\n");
                                            printf("**  3.���    ͳ��    **\n");
                                            printf("**  4.���    ͳ��    **\n");
                                            printf("**  5.������  ͳ��    **\n");
                                            printf("**  6.װ�����ͳ��    **\n");
                                            printf("**                   **\n");
                                            printf("***********************\n");
                                            printf("��ѡ��");
                                            scanf_s("%d", &choice_21);
                                            clear();
                                            switch (choice_21)
                                            {
                                            case 0:
                                                jug16 = 0;
                                                break;
                                            case 1:
                                                statisHousesFloor(house_head);
                                                continue;
                                            case 2:
                                                statisHousesToward(house_head);
                                                continue;
                                            case 3:
                                                statisHousesRent(house_head);
                                                continue;
                                            case 4:
                                                statisHousesArea(house_head);
                                                continue;
                                            case 5:
                                                statisHousesRoom(house_head);
                                                continue;
                                            case 6:
                                                statisHousesFitment(house_head);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                        continue;
                                    case 2:
                                        jug17 = 1;
                                        while (jug17)
                                        {
                                            printf("********��������ͳ��********\n");
                                            printf("**                       **\n");
                                            printf("**  0.��           ��    **\n");
                                            printf("**  1.�������  ͳ��    **\n");
                                            printf("**  2.�����¥��  ͳ��    **\n");
                                            printf("**  3.����װ��  ͳ��    **\n");
                                            printf("**  4.С����¥��  ͳ��    **\n");
                                            printf("**  5.�������ͳ���ͳ��    **\n");
                                            printf("**                       **\n");
                                            printf("***************************\n");
                                            printf("��ѡ��");
                                            scanf_s("%d", &choice_22);
                                            clear();
                                            switch (choice_22)
                                            {
                                            case 0:
                                                jug17 = 0;
                                                break;
                                            case 1:
                                                statisRentAndArea(house_head);
                                                continue;
                                            case 2:
                                                statisTowardAndFloor(house_head);
                                                continue;
                                            case 3:
                                                statisRentAndFitment(house_head);
                                                continue;
                                            case 4:
                                                statisCommunityAndFloor(house_head);
                                                continue;
                                            case 5:
                                                statisRoomAndToward(house_head);
                                                continue;

                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                        continue;
                                    case 3:
                                        jug18 = 1;
                                        while (jug18)
                                        {
                                            printf("********Ԥ��ͳ��********\n");
                                            printf("**                    **\n");
                                            printf("**  0.��       ��     **\n");
                                            printf("**  1.ƽ������ʱ��     **\n");
                                            printf("**  2.��   ��   ��    **\n");
                                            printf("**                    **\n");
                                            printf("***********************\n");
                                            printf("��ѡ��");
                                            scanf_s("%d", &choice_23);
                                            clear();
                                            switch (choice_23)
                                            {
                                            case 0:
                                                jug18 = 0;
                                                break;
                                            case 1:
                                                statisAverageRentDuration(house_head);
                                                continue;
                                            case 2:
                                                statisOccupancyRate(house_head);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                        continue;
                                    case 4:

                                    default:
                                        printf("��Чѡ�������ѡ��\n");
                                        getchar();
                                        clear();
                                        continue;
                                    }
                                }
                                continue;
                            case 2:
                                jug19 = 1;
                                while (jug19)
                                {
                                    printf("******ԤԼͳ��******\n");
                                    printf("**                **\n");
                                    printf("**0.  ��    ��    **\n");
                                    printf("**1.  ��    ��    **\n");
                                    printf("**2.  ԤԼ���    **\n");
                                    printf("**3.  ����ʱ��    **\n");
                                    printf("**4.  ԤԼʱ��    **\n");
                                    printf("**5.  ��    ��    **\n");
                                    printf("**                **\n");
                                    printf("********************\n");
                                    printf("��ѡ��");
                                    scanf_s("%d", &choice_24);
                                    clear();
                                    switch (choice_24)
                                    {
                                    case 0:
                                        jug19 = 0;
                                        break;
                                    case 1:
                                        statisTotalAppointments(head2);
                                        continue;
                                    case 2:
                                        statisCompletedAppointments(head2);
                                        continue;
                                    case 3:
                                        statisAppointmentDuration(head2);
                                        continue;
                                    case 4:
                                        statisAppointmentInPeriod(head2);
                                        continue;
                                    case 5:
                                        statisAppointmentByTenant(head2);
                                        continue;
                                    default:
                                        printf("��Чѡ�������ѡ��\n");
                                        getchar();
                                        clear();
                                        continue;
                                    }
                                }
                                continue;
                            case 3:
                                jug20 = 1;
                                while (jug20)
                                {
                                    printf("******�ⷿͳ��******\n");
                                    printf("**                **\n");
                                    printf("**0.  ��    ��    **\n");
                                    printf("**1.  ��    ��    **\n");
                                    printf("**2.  ��ͬ����    **\n");
                                    printf("**3.  �ⷿ����    **\n");
                                    printf("**4.  ����ʱ��    **\n");
                                    printf("**5.  ��    ��    **\n");
                                    printf("**                **\n");
                                    printf("********************\n");
                                    printf("��ѡ��");
                                    scanf_s("%d", &choice_25);
                                    clear();
                                    switch (choice_25)
                                    {
                                    case 0:
                                        jug20 = 0;
                                        break;
                                    case 1:
                                        statisTotalRents(head1);
                                        continue;
                                    case 2:
                                        statisRentDate(head1);
                                        continue;
                                    case 3:
                                        statisContractDate(head1);
                                        continue;
                                    case 4:
                                        statisRentDuration(head1);
                                        continue;
                                    case 5:
                                        statisTenant(head1);
                                        continue;
                                    default:
                                        printf("��Чѡ�������ѡ��\n");
                                        getchar();
                                        clear();
                                        continue;
                                    }
                                }
                                continue;
                            default:
                                printf("��Чѡ�������ѡ��\n");
                                getchar();
                                clear();
                                continue;
                            }
                        }
                        break;
                    case 6:
                        updateMyPassword(p1);
                        continue;
                    case 7:
                        register_user(1, p1, p2, tail, head);
                        tail = tail->next;
                        p2 = tail;
                        p1 = tail;
                        continue;
                    case 8:
                        jug1 = 1;
                        while (jug1)
                        {
                            //�н�������
                            printf("******�н����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��    ��    **\n");
                            printf("**2.  ��    ��    **\n");
                            printf("**3.  ɾ    ��    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_5);
                            clear();
                            switch (choice_5)
                            {
                            case 0:
                                jug1 = 0;
                                break;
                            case 1:
                                register_user(2, p1, p2, tail, head);
                                tail = tail->next;
                                p2 = tail;
                                p1 = tail;
                                continue;
                            case 2:
                                updatePassword(2, p1, head);
                                continue;
                            case 3:
                                deleteUser(2, p1, head, tail);
                                continue;
                            default:
                                printf("��Чѡ�������ѡ��\n");
                                getchar();
                                clear();
                                continue;
                            }
                        }
                        break;
                    case 9:
                        deleteMyUser(p1, tail);
                        jug0 = 0;
                        break;
                    default:
                        printf("��Чѡ�������ѡ��\n");
                        getchar();
                        clear();
                        continue;
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

                    printf("*********���ܲ˵�*********\n");
                    printf("**                      **\n");
                    printf("**0.     ��    ��       **\n");
                    printf("**1.     ��������       **\n");
                    printf("**2.     �ⷿ����       **\n");
                    printf("**3.     ��Ϣ��ѯ       **\n");
                    printf("**4.     ��Ϣ����       **\n");
                    printf("**5.     ��Ϣͳ��       **\n");
                    printf("**6.     ��������       **\n");
                    printf("**7.     ɾ���˻�       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("��ѡ���ܣ�");
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
                            //�����������
                            printf("******��������******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ����ԤԼ    **\n");
                            printf("**2.  ��    ��    **\n");
                            printf("**3.  ɾ    ��    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_10);
                            clear();
                            switch (choice_10)
                            {
                            case 0:
                                jug6 = 0;
                                break;
                            case 1:
                                handleAppointment(head2, p1);
                                continue;
                            case 2:
                                updateAppointment(head2);
                                continue;
                            case 3:
                                deleteAppointment(head2);
                                continue;
                            default:
                                printf("��Чѡ�������ѡ��\n");
                                getchar();
                                clear();
                                continue;
                            }
                        }
                        break;
                    case 2:
                        jug7 = 1;
                        while (jug7)
                        {
                            //�ⷿ�������
                            printf("******�ⷿ����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��    ��    **\n");
                            printf("**2.  ��    ��    **\n");
                            printf("**3.  ��    ��    **\n");
                            printf("**4.  ɾ    ��    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_11);
                            clear();
                            switch (choice_11)
                            {
                            case 0:
                                jug7 = 0;
                                break;
                            case 1: 
                                addRent(&tail1, p1, house_head);
                                continue;
                            case 2:
                                printRentsInOrder(head1);
                                continue;
                            case 3: 
                                updateRent(head1);
                                continue;
                            case 4: 
                                deleteRent(head1);
                                continue;
                            default:
                                printf("��Чѡ�����������\n");
                                getchar();
                                clear();
                                continue;
                            }
                        }
                        break;
                    case 3:
                        jug3 = 1;
                        while (jug3)
                        {
                            //��Ϣ��ѯ����
                            printf("******��Ϣ��ѯ******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_7);
                            clear();
                            switch (choice_7)
                            {
                            case 0:
                                jug3 = 0;
                                break;
                            case 1:
                                jug9 = 1;
                                while (jug9)
                                {
                                    printf("*********��ѯ��ʽ*********\n");
                                    printf("**                      **\n");
                                    printf("**0.     ��    ��       **\n");
                                    printf("**1.     �򵥲���       **\n");
                                    printf("**2.     ��Χ����       **\n");
                                    printf("**3.     ��ϲ���       **\n");
                                    printf("**                      **\n");
                                    printf("**************************\n");
                                    printf("��ѡ����ҷ�ʽ:\n");
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
                                            printf("*********��ѯ��ʽ*********\n");
                                            printf("**                      **\n");
                                            printf("**0.     ��    ��       **\n");
                                            printf("**1.     �� �� ��       **\n");
                                            printf("**2.     ������/��      **\n");
                                            printf("**3.     ����С��       **\n");
                                            printf("**4.     ��    ��       **\n");
                                            printf("**5.     ��    ��       **\n");
                                            printf("**6.     װ�����       **\n");
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
                                                continue;
                                            case 2:
                                                simpleQueryHouse2(house_head);
                                                continue;
                                            case 3:
                                                simpleQueryHouse3(house_head);
                                                continue;
                                            case 4:
                                                simpleQueryHouse4(house_head);
                                                continue;
                                            case 5:
                                                simpleQueryHouse5(house_head);
                                                continue;
                                            case 6:
                                                simpleQueryHouse6(house_head);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                        break;
                                    case 2:
                                        jug11 = 1;
                                        while (jug11)
                                        {
                                            printf("*********��ѯ��ʽ*********\n");
                                            printf("**                      **\n");
                                            printf("**0.     ��    ��       **\n");
                                            printf("**1.     ��    ��       **\n");
                                            printf("**2.     ¥    ��       **\n");
                                            printf("**3.     ��    ��       **\n");
                                            printf("**                      **\n");
                                            printf("**************************\n");
                                            scanf_s("%d", &choice_15);
                                            clear();
                                            switch (choice_15) {
                                            case 0:
                                                jug11 = 0;
                                                break;
                                            case 1:
                                                rangeQueryRent(house_head);
                                                continue;
                                            case 2:
                                                rangeQueryFloor(house_head);
                                                continue;
                                            case 3:
                                                rangeQueryArea(house_head);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                        break;
                                    case 3:
                                        combinedQueryHouse(head);
                                        continue;
                                    }
                                }
                                break;
                            case 2:
                                printAppointmentsInOrder(head2);
                                continue;
                            case 3:
                                printRentsInOrder(head1);
                                continue;
                            default:
                                printf("��Чѡ�������ѡ��\n");
                                getchar();
                                clear();
                                continue;
                            }
                        }
                        break;
                    case 4:
                        jug4 = 1;
                        while (jug4)
                        {
                            //��Ϣ�������
                            printf("******��Ϣ����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_8);
                            clear();
                            switch (choice_8)
                            {
                            case 0:
                                jug4 = 0;
                                break;
                            case 1:
                                jug16 = 1;
                                while (jug16) {
                                    printf("******��Դ��Ϣ����******\n");
                                    printf("**                    **\n");
                                    printf("**0.  ��    ��        **\n");
                                    printf("**1.  ��һ����        **\n");
                                    printf("**2.  ��������        **\n");
                                    printf("**                    **\n");
                                    printf("************************\n");
                                    printf("��ѡ������ʽ:\n");
                                    scanf_s("%d", &choice_21);
                                    clear();
                                    if (choice_21 == 0) {
                                        jug16 = 0;
                                        break;
                                    }
                                    else if (choice_21 == 1) {
                                        jug15 = 1;
                                        while (jug15) {
                                            printf("******��Դ��Ϣ��һ����******\n");
                                            printf("**                        **\n");
                                            printf("**0.  ��    ��            **\n");
                                            printf("**1.  ��Դ���            **\n");
                                            printf("**2.  �����С            **\n");
                                            printf("**3.  ��    ��            **\n");
                                            printf("**4.  �� �� ��            **\n");
                                            printf("**                        **\n");
                                            printf("****************************\n");
                                            printf("��ѡ������ʽ:\n");
                                            scanf_s("%d", &choice_20);
                                            clear();
                                            switch (choice_20) {
                                            case 0:
                                                jug15 = 0;
                                                break;
                                            case 1:
                                                simpleSortHouseid(&((house_head)->next));
                                                printHouseList((house_head)->next);
                                                continue;
                                            case 2:
                                                simpleSortHouseArea(&((house_head)->next));
                                                printHouseList((house_head)->next);
                                                continue;
                                            case 3:
                                                simpleSortHouseRent(&((house_head)->next));
                                                printHouseList((house_head)->next);
                                                continue;
                                            case 4:
                                                simpleSortHouseAgencyFee(&((house_head)->next));
                                                printHouseList((house_head)->next);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                    }
                                    else if (choice_21 == 2) {
                                        jug15 = 1;
                                        while (jug15) {
                                            printf("******��Դ��Ϣ��������******\n");
                                            printf("**                        **\n");
                                            printf("**0.  ��    ��            **\n");
                                            printf("**1.  �����С            **\n");
                                            printf("**2.  ��    ��            **\n");
                                            printf("**3.  �� �� ��            **\n");
                                            printf("**                        **\n");
                                            printf("****************************\n");
                                            printf("��ѡ����������ʽ:\n");
                                            scanf_s("%d%d", &choice_20, &choice_21);
                                            clear();
                                            switch (choice_20) {
                                            case 0:
                                                jug15 = 0;
                                                break;
                                            case 1:
                                                switch (choice_21) {
                                                case 1:
                                                    printf("�����ظ����룬����������\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                case 2:
                                                    simpleSortHouseArea(&((house_head)->next));
                                                    multSortArea_ByRent(&((house_head)->next));
                                                    printHouseList((house_head)->next);
                                                    continue;
                                                case 3:
                                                    simpleSortHouseArea(&((house_head)->next));
                                                    multSortArea_ByAgencyFee(&((house_head)->next));
                                                    printHouseList((house_head)->next);
                                                    continue;
                                                default:
                                                    printf("��Чѡ�������ѡ��\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                }
                                                continue;
                                            case 2:
                                                switch (choice_21) {
                                                case 1:
                                                    simpleSortHouseRent(&((house_head)->next));
                                                    multSortRent_ByArea(&((house_head)->next));
                                                    printHouseList((house_head)->next);
                                                    continue;
                                                case 2:
                                                    printf("�����ظ����룬����������\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                case 3:
                                                    simpleSortHouseRent(&((house_head)->next));
                                                    multSortRent_ByAgencyFee(&((house_head)->next));
                                                    printHouseList((house_head)->next);
                                                    continue;
                                                default:
                                                    printf("��Чѡ�������ѡ��\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                }
                                                continue;
                                            case 3:
                                                switch (choice_21) {
                                                case 1:
                                                    simpleSortHouseAgencyFee(&((house_head)->next));
                                                    multSortAgencyFee_ByArea(&((house_head)->next));
                                                    printHouseList((house_head)->next);
                                                    continue;
                                                case 2:
                                                    simpleSortHouseAgencyFee(&((house_head)->next));
                                                    multSortAgencyFee_ByRent(&((house_head)->next));
                                                    printHouseList((house_head)->next);
                                                    continue;
                                                case 3:
                                                    printf("�����ظ����룬����������\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                default:
                                                    printf("��Чѡ�������ѡ��\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                }
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }

                                    }
                                }
                            case 2:
                                jug16 = 1;
                                while (jug16) {
                                    printf("******�ⷿ��Ϣ����******\n");
                                    printf("**                    **\n");
                                    printf("**0.  ��    ��        **\n");
                                    printf("**1.  ��һ����        **\n");
                                    printf("**2.  ��������        **\n");
                                    printf("**                    **\n");
                                    printf("************************\n");
                                    printf("��ѡ������ʽ:\n");
                                    scanf_s("%d", &choice_21);
                                    clear();
                                    if (choice_21 == 0) {
                                        jug16 = 0;
                                        break;
                                    }
                                    else if (choice_21 == 1) {
                                        jug15 = 1;
                                        while (jug15) {
                                            printf("******�ⷿ��Ϣ����********\n");
                                            printf("**                      **\n");
                                            printf("**0.  ��    ��          **\n");
                                            printf("**1.  ���ⷿ�������    **\n");
                                            printf("**2.  ����ͬǩ����������**\n");
                                            printf("**3.  �����⿪ʼ��������**\n");
                                            printf("**4.  ��Ԥ�Ƴ���ʱ������**\n");
                                            printf("**5.  ������״̬����    **\n");
                                            printf("**                      **\n");
                                            printf("**************************\n");
                                            printf("��ѡ������ʽ:\n");
                                            scanf_s("%d", &choice_20);
                                            clear();
                                            switch (choice_20) {
                                            case 0:
                                                jug15 = 0;
                                                break;
                                            case 1:
                                                simpleSortid(&((head1)->next));
                                                printList((head1)->next);
                                                continue;
                                            case 2:
                                                simpleSortByContractTime(&((head1)->next));
                                                printList((head1)->next);
                                                continue;
                                            case 3:
                                                simpleSortByRentStartTime(&((head1)->next));
                                                printList((head1)->next);
                                                continue;
                                            case 4:
                                                simpleSortByRentDuration(&((head1)->next));
                                                printList((head1)->next);
                                                continue;
                                            case 5:
                                                simpleSortByStatement(&((head1)->next));
                                                printList((head1)->next);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                    }
                                    else if (choice_21 == 2) {
                                        jug15 = 1;
                                        while (jug15) {
                                            printf("******�ⷿ��Ϣ��������(ǰ������)******\n");
                                            printf("**                                  **\n");
                                            printf("**0.  �˳�                          **\n");
                                            printf("**1.  ���ⷿ�������                **\n");
                                            printf("**2.  ��Ԥ�Ƴ���ʱ������            **\n");
                                            printf("**3.  �����⿪ʼ��������            **\n");
                                            printf("**************************************\n");
                                            printf("��ѡ����������ʽ:\n");
                                            scanf_s("%d%d", &choice_20, &choice_21);
                                            clear();
                                            switch (choice_20) {
                                            case 0:
                                                jug15 = 0;
                                                break;
                                            case 1:
                                                simpleSortid(&((head1)->next));
                                                switch (choice_21) {
                                                case 1:
                                                    printf("�����ظ����룬����������\n");
                                                    continue;
                                                case 2:
                                                    multSortid_ByRentDuration(&((head1)->next));
                                                    printList((head1)->next);
                                                    continue;
                                                case 3:
                                                    multSortid_ByRentStartTime(&((head1)->next));
                                                    printList((head1)->next);
                                                    continue;
                                                default:
                                                    printf("��Чѡ�������ѡ��\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                }
                                                continue;
                                            case 2:
                                                simpleSortByRentDuration(&((head1)->next));
                                                switch (choice_21) {
                                                case 1:
                                                    multSortRentDuration_Byid(&((head1)->next));
                                                    printList((head1)->next);
                                                    continue;
                                                case 2:
                                                    printf("�����ظ����룬����������\n");
                                                    continue;
                                                case 3:
                                                    multSortRentDuration_ByRentStartTime(&((head1)->next));
                                                    printList((head1)->next);
                                                    continue;
                                                default:
                                                    printf("��Чѡ�������ѡ��\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                }
                                                continue;
                                            case 3:
                                                simpleSortByRentStartTime(&((head1)->next));
                                                switch (choice_21) {
                                                case 1:
                                                    multSortRentStartTime_Byid(&((head1)->next));
                                                    printList((head1)->next);
                                                    continue;
                                                case 2:
                                                    multSortRentStartTime_ByRentDuration(&((head1)->next));
                                                    printList((head1)->next);
                                                    continue;
                                                case 3:
                                                    printf("�����ظ����룬����������\n");
                                                    continue;
                                                default:
                                                    printf("��Чѡ�������ѡ��\n");
                                                    getchar();
                                                    clear();
                                                    continue;
                                                }
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    case 5:
                        jug5 = 1;
                        while (jug5)
                        {
                            //��Ϣͳ�ƽ���
                            printf("******��Ϣͳ��******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_9);
                            clear();
                            switch (choice_9)
                            {
                            case 0:
                                jug5 = 0;
                                break;
                            case 1:
                                jug15 = 1;
                                while (jug15) {

                                    printf("******ͳ�Ʒ�ʽ******\n");
                                    printf("**                **\n");
                                    printf("**0.  ��    ��    **\n");
                                    printf("**1.  ��һ����    **\n");
                                    printf("**2.  ��������    **\n");
                                    printf("**3.  Ԥ��ͳ��    **\n");
                                    printf("**4.  ����ͳ��    **\n");
                                    printf("**                **\n");
                                    printf("********************\n");
                                    printf("��ѡ��");
                                    scanf_s("%d", &choice_20);
                                    clear();
                                    switch (choice_20)
                                    {
                                    case 0:
                                        jug15 = 0;
                                        break;
                                    case 1:
                                        jug16 = 1;
                                        while (jug16)
                                        {
                                            printf("******��һ����ͳ��******\n");
                                            printf("**                   **\n");
                                            printf("**  0.��       ��     **\n");
                                            printf("**  1.¥��    ͳ��    **\n");
                                            printf("**  2.����    ͳ��    **\n");
                                            printf("**  3.���    ͳ��    **\n");
                                            printf("**  4.���    ͳ��    **\n");
                                            printf("**  5.������  ͳ��    **\n");
                                            printf("**  6.װ�����ͳ��    **\n");
                                            printf("**                   **\n");
                                            printf("***********************\n");
                                            printf("��ѡ��");
                                            scanf_s("%d", &choice_21);
                                            clear();
                                            switch (choice_21)
                                            {
                                            case 0:
                                                jug16 = 0;
                                                break;
                                            case 1:
                                                statisHousesFloor(house_head);
                                                continue;
                                            case 2:
                                                statisHousesToward(house_head);
                                                continue;
                                            case 3:
                                                statisHousesRent(house_head);
                                                continue;
                                            case 4:
                                                statisHousesArea(house_head);
                                                continue;
                                            case 5:
                                                statisHousesRoom(house_head);
                                                continue;
                                            case 6:
                                                statisHousesFitment(house_head);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                        continue;
                                    case 2:
                                        jug17 = 1;
                                        while (jug17)
                                        {
                                            printf("********��������ͳ��********\n");
                                            printf("**                       **\n");
                                            printf("**  0.��           ��    **\n");
                                            printf("**  1.�������  ͳ��    **\n");
                                            printf("**  2.�����¥��  ͳ��    **\n");
                                            printf("**  3.����װ��  ͳ��    **\n");
                                            printf("**  4.С����¥��  ͳ��    **\n");
                                            printf("**  5.�������ͳ���ͳ��    **\n");
                                            printf("**                       **\n");
                                            printf("***************************\n");
                                            printf("��ѡ��");
                                            scanf_s("%d", &choice_22);
                                            clear();
                                            switch (choice_22)
                                            {
                                            case 0:
                                                jug17 = 0;
                                                break;
                                            case 1:
                                                statisRentAndArea(house_head);
                                                continue;
                                            case 2:
                                                statisTowardAndFloor(house_head);
                                                continue;
                                            case 3:
                                                statisRentAndFitment(house_head);
                                                continue;
                                            case 4:
                                                statisCommunityAndFloor(house_head);
                                                continue;
                                            case 5:
                                                statisRoomAndToward(house_head);
                                                continue;

                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                        continue;
                                    case 3:
                                        jug18 = 1;
                                        while (jug18)
                                        {
                                            printf("********Ԥ��ͳ��********\n");
                                            printf("**                    **\n");
                                            printf("**  0.��       ��     **\n");
                                            printf("**  1.ƽ������ʱ��     **\n");
                                            printf("**  2.��   ��   ��    **\n");
                                            printf("**                    **\n");
                                            printf("***********************\n");
                                            printf("��ѡ��");
                                            scanf_s("%d", &choice_23);
                                            clear();
                                            switch (choice_23)
                                            {
                                            case 0:
                                                jug18 = 0;
                                                break;
                                            case 1:
                                                statisAverageRentDuration(house_head);
                                                continue;
                                            case 2:
                                                statisOccupancyRate(house_head);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                        continue;
                                    case 4:

                                    default:
                                        printf("��Чѡ�������ѡ��\n");
                                        getchar();
                                        clear();
                                        continue;
                                    }
                                }
                                continue;
                            case 2:
                                jug19 = 1;
                                while (jug19)
                                {
                                    printf("******ԤԼͳ��******\n");
                                    printf("**                **\n");
                                    printf("**0.  ��    ��    **\n");
                                    printf("**1.  ��    ��    **\n");
                                    printf("**2.  ԤԼ���    **\n");
                                    printf("**3.  ����ʱ��    **\n");
                                    printf("**4.  ԤԼʱ��    **\n");
                                    printf("**5.  ��    ��    **\n");
                                    printf("**                **\n");
                                    printf("********************\n");
                                    printf("��ѡ��");
                                    scanf_s("%d", &choice_24);
                                    clear();
                                    switch (choice_24)
                                    {
                                    case 0:
                                        jug19 = 0;
                                        break;
                                    case 1:
                                        statisTotalAppointments(head2);
                                        continue;
                                    case 2:
                                        statisCompletedAppointments(head2);
                                        continue;
                                    case 3:
                                        statisAppointmentDuration(head2);
                                        continue;
                                    case 4:
                                        statisAppointmentInPeriod(head2);
                                        continue;
                                    case 5:
                                        statisAppointmentByTenant(head2);
                                        continue;
                                    default:
                                        printf("��Чѡ�������ѡ��\n");
                                        getchar();
                                        clear();
                                        continue;
                                    }
                                }
                                continue;
                            case 3:
                                jug20 = 1;
                                while (jug20)
                                {
                                    printf("******�ⷿͳ��******\n");
                                    printf("**                **\n");
                                    printf("**0.  ��    ��    **\n");
                                    printf("**1.  ��    ��    **\n");
                                    printf("**2.  ��ͬ����    **\n");
                                    printf("**3.  �ⷿ����    **\n");
                                    printf("**4.  ����ʱ��    **\n");
                                    printf("**5.  ��    ��    **\n");
                                    printf("**                **\n");
                                    printf("********************\n");
                                    printf("��ѡ��");
                                    scanf_s("%d", &choice_25);
                                    clear();
                                    switch (choice_25)
                                    {
                                    case 0:
                                        jug20 = 0;
                                        break;
                                    case 1:
                                        statisTotalRents(head1);
                                        continue;
                                    case 2:
                                        statisRentDate(head1);
                                        continue;
                                    case 3:
                                        statisContractDate(head1);
                                        continue;
                                    case 4:
                                        statisRentDuration(head1);
                                        continue;
                                    case 5:
                                        statisTenant(head1);
                                        continue;
                                    default:
                                        printf("��Чѡ�������ѡ��\n");
                                        getchar();
                                        clear();
                                        continue;
                                    }
                                }
                                continue;
                            default:
                                printf("��Чѡ�����������\n");
                                getchar();
                                clear();
                                continue;
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
                        printf("��Чѡ�����������\n");
                        getchar();
                        clear();
                        continue;
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

                    printf("*********���ܲ˵�*********\n");
                    printf("**                      **\n");
                    printf("**0.     ��    ��       **\n");
                    printf("**1.     �޸���Ϣ       **\n");
                    printf("**2.     ����ԤԼ       **\n");
                    printf("**3.     ��Ϣ��ѯ       **\n");
                    printf("**4.     ��������       **\n");
                    printf("**5.     ɾ���˻�       **\n");
                    printf("**                      **\n");
                    printf("**************************\n");
                    printf("��ѡ���ܣ�");
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
                            //����ԤԼ����
                            printf("******����ԤԼ******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��    ��    **\n");
                            printf("**2.  ��    ��    **\n");
                            printf("**3.  ��    ��    **\n");
                            printf("**4.  ɾ    ��    **\n");
                            printf("**5.  ��ӷ���    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_12);
                            clear();
                            switch (choice_12)
                            {
                            case 0:
                                jug8 = 0;
                                break;
                            case 1: 
                                addAppointment(&tail2, p1);
                                continue;
                            case 2:
                                printMyAppointmentsInOrder(head2, p1);
                                continue;
                            case 3:
                                updateAppointment(head2);
                                continue;
                            case 4:
                                deleteAppointment(head2);
                                continue;
                            case 5:
                                addFeedback(head2, p1);
                                continue;
                            default:
                                printf("��Чѡ�����������\n");
                                getchar();
                                clear();
                                continue;
                            }
                        }
                        break;
                    case 3:
                        jug3 = 1;
                        while (jug3)
                        {
                            //��Ϣ��ѯ����
                            printf("******��Ϣ��ѯ******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
                            printf("**                **\n");
                            printf("********************\n");
                            printf("��ѡ��");
                            scanf_s("%d", &choice_7);
                            clear();
                            switch (choice_7)
                            {
                            case 0:
                                jug3 = 0;
                                break;
                            case 1:
                                jug9 = 1;
                                while (jug9)
                                {
                                    printf("*********��ѯ��ʽ*********\n");
                                    printf("**                      **\n");
                                    printf("**0.     ��    ��       **\n");
                                    printf("**1.     �򵥲���       **\n");
                                    printf("**2.     ��Χ����       **\n");
                                    printf("**3.     ��ϲ���       **\n");
                                    printf("**                      **\n");
                                    printf("**************************\n");
                                    printf("��ѡ����ҷ�ʽ:\n");
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
                                            printf("*********��ѯ��ʽ*********\n");
                                            printf("**                      **\n");
                                            printf("**0.     ��    ��       **\n");
                                            printf("**1.     �� �� ��       **\n");
                                            printf("**2.     ������/��      **\n");
                                            printf("**3.     ����С��       **\n");
                                            printf("**4.     ��    ��       **\n");
                                            printf("**5.     ��    ��       **\n");
                                            printf("**6.     װ�����       **\n");
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
                                                continue;
                                            case 2:
                                                simpleQueryHouse2(house_head);
                                                continue;
                                            case 3:
                                                simpleQueryHouse3(house_head);
                                                continue;
                                            case 4:
                                                simpleQueryHouse4(house_head);
                                                continue;
                                            case 5:
                                                simpleQueryHouse5(house_head);
                                                continue;
                                            case 6:
                                                simpleQueryHouse6(house_head);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                        break;
                                    case 2:
                                        jug11 = 1;
                                        while (jug11)
                                        {
                                            printf("*********��ѯ��ʽ*********\n");
                                            printf("**                      **\n");
                                            printf("**0.     ��    ��       **\n");
                                            printf("**1.     ��    ��       **\n");
                                            printf("**2.     ¥    ��       **\n");
                                            printf("**3.     ��    ��       **\n");
                                            printf("**                      **\n");
                                            printf("**************************\n");
                                            scanf_s("%d", &choice_15);
                                            clear();
                                            switch (choice_15) {
                                            case 0:
                                                jug11 = 0;
                                                break;
                                            case 1:
                                                rangeQueryRent(house_head);
                                                continue;
                                            case 2:
                                                rangeQueryFloor(house_head);
                                                continue;
                                            case 3:
                                                rangeQueryArea(house_head);
                                                continue;
                                            default:
                                                printf("��Чѡ�������ѡ��\n");
                                                getchar();
                                                clear();
                                                continue;
                                            }
                                        }
                                        break;
                                    case 3:
                                        combinedQueryHouse(head);
                                        continue;
                                    }
                                }
                                break;
                            case 2:
                                printMyAppointmentsInOrder(head2, p1);
                                continue;
                            case 3:
                                printMyRentsInOrder(head1, p1);
                                continue;
                            default:
                                printf("��Чѡ�����������\n");
                                getchar();
                                clear();
                                continue;
                            }
                        }
                        break;
                    case 4:
                        updateMyPassword(p1);
                        continue;
                    case 5:
                        deleteMyUser(p1, tail);
                        jug0 = 0;
                        break;
                    default:
                        printf("��Чѡ�����������\n");
                        getchar();
                        clear();
                        continue;
                    }
                }
                break;
            }
            break;
        case 2:
            register_user(3, p1, p2, tail, head);
            tail = tail->next;
            p2 = tail;
            p1 = tail;
        default:
            printf("��Чѡ�����������\n");
            getchar();
            clear();
            continue;
        }
    }
    write_user_data(head);
    write_house_data(house_head);
    write_Appointment_data(head2);
    write_rent_data(head1);
    return 0;
}