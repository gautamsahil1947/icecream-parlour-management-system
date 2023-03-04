#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int balance = 10000;
time_t start;
time_t stop;

typedef struct
{
    char *name;
    int quantity;
}
data;
void restock(void);
void transaction(void);
void electricity_bill(void);
void stocksummary(void);


void main(void)
{
    int n;
    printf("press 1          to enter\npress 0          to exit\n");
    printf("choice: ");
    scanf("%i", &n);


    if (n == 1)
    {
        while (true)
        {
            int p;
            scanf()
        }
    }
    else if (n == 0)
    {
        printf("__________________________________________________\n");
        printf("thankyou for using\n");
    }
    else
    {
        main();
    }
}



void restock(void)
{

}

void transaction(void)
{

}

void electricity_bill(void)
{

}

void stocksummary(void)
{

}