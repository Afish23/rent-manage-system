#include "data.h"
#include "models.h"
#include "utils.h"
#include "auth.h"
#include "crud.h"
int main() {
    
        //0�����˵� 1�����ѡ��˵� 2������Ա�˵� 3���н�˵� 4����Ͳ˵�
    int choice_0 = 1, choice_1, choice_2, choice_3, choice_4,
        //5:����Ա-�н����˵� 6:����Ա-��Դ����˵� 7:��Ϣ��ѯ�˵� 8:��Ϣ����˵�
        choice_5, choice_6, choice_7, choice_8,
        //9:��Ϣͳ�Ʋ˵� 10:��������˵� 11:�ⷿ����˵� 12:����ԤԼ�˵�
        choice_9, choice_10, choice_11, choice_12;
        //�˳�ѭ���ж�
        //0�����ѡ�� 1:�н���� 2:��Դ���� 3:��Ϣ��ѯ 4:��Ϣ���� 
    int jug0 = 0, jug1 = 0, jug2 = 0, jug3 = 0, jug4 = 0, 
        //5:��Ϣͳ�� 6:�������� 7:�ⷿ���� 8:����ԤԼ
        jug5 = 0, jug6 = 0, jug7 = 0, jug8 = 0;

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


    //���ݶ�ȡ
    read_user_data(&tail);

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
                            //��Ϣ�������
                            printf("******��Ϣ����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
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
                            printf("**1.  ��    ��    **\n");
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
                            //��Ϣ�������
                            printf("******��Ϣ����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
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

                    printf("*********���ܲ˵�*********\n");
                    printf("**                      **\n");
                    printf("**0.     ��    ��       **\n");
                    printf("**1.     �޸���Ϣ       **\n");
                    printf("**2.     ����ԤԼ       **\n");
                    printf("**3.     ��Ϣ��ѯ       **\n");
                    printf("**4.     ��Ϣ����       **\n");
                    printf("**5.     ��Ϣͳ��       **\n");
                    printf("**6.     ��������       **\n");
                    printf("**7.     ɾ���˻�       **\n");
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
                            printf("**2.  ��    ��    **\n");
                            printf("**3.  ɾ    ��    **\n");
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
                            //��Ϣ�������
                            printf("******��Ϣ����******\n");
                            printf("**                **\n");
                            printf("**0.  ��    ��    **\n");
                            printf("**1.  ��Դ��Ϣ    **\n");
                            printf("**2.  ԤԼ��Ϣ    **\n");
                            printf("**3.  �ⷿ��Ϣ    **\n");
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

