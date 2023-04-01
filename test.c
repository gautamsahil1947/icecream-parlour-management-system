#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
        int n;
        char name[19];
        struct node *next;
} node;

void summarise(void);
void enter_system(void);
void reload(node *list_ptr);
void restock(node *list_ptr);
void put_to_file(node *list);
node *append(node *);

int main(void) {
        /*      no list exists  */        
        node *list = NULL;

        int n;
        printf("enter n: ");
        scanf("%i", &n);

        for (int i = 0; i < n; i++) {
                list = append(list);
        }
        
        /*      a list with n names and quantities exists       */
        for (node *tmp = list; tmp != NULL; tmp = tmp -> next) {
                printf("%s %i\n", tmp -> name, tmp -> n);
                printf("node *next is %p\n", tmp -> next);
        }

        put_to_file(list);
        return 0;





}

void put_to_file(node *list) {
        // this function takes a linked list and puts all the contents to the files
        FILE * file = fopen("data.txt", "w");
        for (node *tmp = list; tmp != NULL; tmp = tmp -> next) {
                fprintf(file, "%s %i\n", tmp -> name, tmp -> n);
        }

        fclose(file);
}


void restock(node *list_ptr) {
        /*      this function loads all the file contents to the data structures
                linked list in this case        */
        

}


node * append(node *list) {

        node *tmp = malloc(sizeof(node));
        if (tmp != NULL) {
                scanf("%s", tmp -> name);
                scanf("%i", &(tmp -> n));
                tmp -> next = NULL;
        } else {
                printf("memory allocation error\n");
                exit(1);
        }

        if (list == NULL) {
                return tmp;                
        } else {
                tmp -> next = list;
                return tmp;
        }
}