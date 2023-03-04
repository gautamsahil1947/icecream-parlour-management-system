#include <stdio.h>
#include "functions.c"
#include <time.h>

// amount for transactions
#define default_amount 10000;
int money = default_amount;

float uptime = 0;

// linked list struct for stroing the icecream data
typedef struct ice_cream_inventory
{
    char * name;
    int quantity;
    struct ice_cream_inventory *right;
    struct ice_cream_inventory *left;
}
ice_cream_inventory;


void main(void)
{
    // first interaction
    int n;
    printf("enter 1 to start system, 0 to exit: ");
    scanf("%i", &n);
    
    // enter the system
    if (n == 1)
    {
        printf("\n");
        printf("**************************************\n");
        enter_system();
    }
    else if (n == 0)
    {
        // summarise stock, money, electricity bill etc.
        stock_summary();
        printf("thank you for using the system.\n");
    }
    else
    {
        main();
    }


}