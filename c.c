#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
        int n;
        char name[20];
        struct node *next;
} node;
node *append(node *, char[], int);

void summarise(node *);
node * restock(node *);
node * search(node *, char[]);
void update_database(node *);
void selling(node *, char[], int ); 

int main(void) {
        printf("-------------------------------------\n");
        printf("welcome to the software\n\n");
        printf("press 0 to exit\npress 1 to show inventry\npress 2 to restock inventry\n");
        printf("press 3 to sell icecreams\n\n");
        // reload the data to a live list
        node *list = NULL;
        FILE *file = fopen("data.txt", "r");
        char c[20];
        int t;

        while (fscanf(file, "%s %i", c, &t) != EOF) {
                // add data to list
                list = append(list,c,t);
        }
        fclose(file);
        // at this point, everything is in the linked list

        while (true) {
                printf("-------------------------------------\n");
 
                int n;
                printf("n: ");
                scanf("%i", &n);
                /*      challange that i faced here was that once given input, that option 
                        was going in a forever loop. the problem was that the three lines
                        above were outside the loop, therefore once taken input, n was the same
                        for all the loops, so same condition was checked over and over.
                */
                if (n == 0) {
                        printf("thanks for using icpms\n");
                        update_database(list);
                        return 0;
                } else if (n == 1) {
                        summarise(list); 
                        continue;
                } else if (n == 2) {
                        list = restock(list);
                } else if (n == 3) {
                        printf("enter name quantity: ");
                        char ice_name[20];
                        int quant;
                        scanf("%s %i", ice_name, &quant);
                        selling(list, ice_name, quant);
                }
        }


}

node * search(node *list, char a[]) {
        if (list != NULL) {
                for (node *tmp = list; tmp != NULL; tmp = tmp -> next) {
                        if (!strcmp(a, tmp -> name)) {
                                return tmp;
                        }
                }
        }
        return NULL;
}

node * append(node *list, char a[], int t) {
        node *tmp = malloc(sizeof(node));
        if (tmp != NULL) {
                tmp -> next = NULL;
                tmp -> n = t;
                strcpy(tmp -> name, a);                
        }

        if (list == NULL) {
                return tmp;
        } else {
                tmp -> next = list;
                return tmp;
        }
        
}

void summarise(node *list) {
        printf("\n\nsummary\n\n");
        if (list == NULL) {
                printf("empty\n");
        } else {
                for (node *tmp = list; tmp != NULL; tmp = tmp -> next) {
                        printf("%s %i\n", tmp -> name, tmp -> n);
                }
        }
        
}

node * restock(node *list) {
        int n;
        printf("enter number of items to add or check: ");
        scanf("%i", &n);
        for (int i = 0; i < n; i++) {
                char buffer[20];
                int tmp;

                scanf("%s %i", buffer, &tmp);
                // search if the name exists
                node *res = search(list, buffer);
                if (res != NULL) {
                        res -> n += tmp;
                } else {
                        list = append(list, buffer, tmp);
                }      
        }
        return list;
 
}

void update_database(node *list) {
        /*      since list has all the data, there is no need of the previous
                contents of the file. although inefficient, for the time being
                is working. therefore, the data is read into a linked-list at the
                beginning, and is manipulated. later the data is overwritten to the file*/
        FILE *file = fopen("data.txt", "w");
        for (node *tmp = list; tmp != NULL; tmp = tmp -> next) {
                fprintf(file, "%s %i\n", tmp -> name, tmp -> n);
        }
}

void selling(node *list, char s[], int k) {
        if (list == NULL) {
                printf("no icecreams to sell\n");
        } else {
                node *tmp = search(list, s);
                if (tmp == NULL) {
                        // not inside the list
                        printf("variety not available\n");
                } else {
                        if (tmp -> n >= k) {
                                printf("transaction ok\n");
                                tmp -> n -= k;
                        } else {
                                printf("only %i available\n", tmp -> n);
                        }
                }
        }

}
/*

-------------------------------------
welcome to the software

press 0 to exit
press 1 to show inventry
press 2 to restock inventry
-------------------------------------
n: 1


summary

4 0
sahil 0
1 0
sahil2 0
5 0
gautam 0
6 0
sahil_gautam 0
-------------------------------------
n: 1


summary

4 0
sahil 0
1 0
sahil2 0
5 0
gautam 0
6 0
sahil_gautam 0
-------------------------------------
n: ^C

workspa


this was because maybe just a guess, that i was reading the string and the int 
seperately using fscanfs.

the solution to this is read them in the same fscanf which is != EOF
*/
