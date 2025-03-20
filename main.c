#include "auth.h"
#include "admin.h"
#include "agent.h"
#include "tenant.h"
#include "store.h"
#include "models.h"
int main() {
    
    int choice_0 = 1, choice_1, choice_2, choice_3, choice_4;

    //主界面
    while (choice_0) {
        printf("******登    录******\n");
        printf("**                **\n");
        printf("**0.  关    闭    **\n");
        printf("**1.  登    录    **\n");
        printf("**2.  注    册    **\n");
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
                admin_menu();
            case 2:
                agent_menu();
            case 3:
                tenant_menu();
            }
        }
    }
    return 0;
}