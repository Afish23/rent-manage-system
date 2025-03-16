#include "auth.h"
#include "admin.h"
#include "agent.h"
#include "tenant.h"
#include "store.h"
#include "models.h"
int main() {
    load_data();

    while (1) {
        printf("******µÇ    Â¼******\n");
        printf("**                **\n");
        printf("**0.  ¹Ø    ±Õ    **\n");
        printf("**1.  µÇ    Â¼    **\n");
        printf("**2.  ×¢    ²á    **\n");
        printf("**                **\n");
        printf("********************\n");
        printf("ÇëÑ¡Ôñ¹¦ÄÜ£º");
    }
    return 0;
}