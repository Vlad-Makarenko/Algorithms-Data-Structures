#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node {
    char a;
    struct Node *next;
    struct Node *prev;
};

struct List {
    struct Node *head;
    struct Node *tail;
};

struct Node *list_new_node(char a)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->a = a;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void list_add_end(struct List *ls, char a)
{
    struct Node *node = list_new_node(a);

    node->prev = ls->tail;
    if (ls->tail)
        ls->tail->next = node;
    else
        ls->head = node;
    ls->tail = node;
}

int list_remove(struct List *ls, int index)
{
    if (index < 0)
        return 0;
    struct Node *p = ls->head;
    if (index == 0) {
        if (!ls->head)
            return 0;
        ls->head = ls->head->next;
        if (p->next)
            p->next->prev = NULL;
        else
            ls->tail = NULL;
        free(p);
        return 1;
    }
    while (index > 0) {
        if (!p)
            return 0;
        p = p->next;
        index--;
    }
    p->prev->next = p->next;
    if (p->next)
        p->next->prev = p->prev;
    else
        ls->tail = p->prev;
    free(p);
    return 1;
}

struct List *list_new()
{
    struct List *ls = malloc(sizeof(struct List));
    ls->head = NULL;
    ls->tail = NULL;
    return ls;
}

void list_show(struct List *ls, int reverse) {
    if (!reverse)
        for (struct Node *node = ls->head; node != NULL; node = node->next)
            printf("%15c\n", node->a);
    else
        for (struct Node *node = ls->tail; node != NULL; node = node->prev)
            printf("%15c\n", node->a);
    printf("\n");
}


char * DeleteStr(char* string, int start_position, int end_position) {
    if ((end_position - start_position) == 0 && start_position >= strlen(string)) {
        printf("nothing to delete");
        return 0;
    }
    char * new_string = malloc((strlen(string)) * sizeof(char ));
    memcpy(new_string, string, start_position * sizeof(char));
    memcpy(new_string + start_position, string + end_position, (strlen(string) - (end_position - start_position)) * sizeof(char ));
    printf("New string: %s\n", new_string);
    return new_string;
}


int main() {
    char *str = malloc(128 * sizeof (char));
    printf("Enter the string: ");
    scanf("%s", str);
    printf("Enter position: ");
    int start_pos;
    scanf("%d", &start_pos);
    int len;
    printf("Enter length: ");
    scanf("%d", &len);
    int end_pos = start_pos + len;
    clock_t start = clock();
    DeleteStr(str, start_pos, end_pos);
    clock_t end = clock();
    double time_spent1 = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Час затрачений на виконання функції по видаленю підрядка з рядка у векторі з керованою довжиною рядка: %.10f second(s)\n\n", time_spent1);

    int n;
    printf("Enter count of elements: ");
    scanf("%d", &n);
    struct List *ls = list_new();
    for (int i = 0; i<n; i++) {
        char symb;
        printf("Enter symbol: ");
        scanf("%s", &symb);
        list_add_end(ls, symb);
    }
    int side;
    printf("Enter the direction of the list (0 or 1): ");
    scanf("%d", &side);
    printf("Original list: \n");
    list_show(ls, side);
    int index;
    printf("Enter the index of the element to be deleted: ");
    scanf("%d", &index);
    clock_t begin = clock();
    list_remove(ls, index);
    printf("New list: \n");
    list_show(ls, side);
    clock_t finish = clock();
    double time_spent2 = (double)(finish - begin) / CLOCKS_PER_SEC;
    printf("Час затрачений на виконання функції по видаленю підрядка з рядка у символьно-зв’язаному поданню двоспрямованого списку: %.10f second(s) \n", time_spent2);

}





