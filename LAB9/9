#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
    char n[20];
    int a;
    char s;
    float g;
    struct Data *next;
};

class List {
protected:
    struct Data *head;
    struct Data *cur;

public:
    List();
    ~List();
    void add(char n[], int a, char s, float g);
    void remove(char n[]);
    void first();
    void next();
    void showAll();
    int find(char n[]);
    struct Data* current();
    void update(char n[], int a, char s, float g);
};

void editMenu(List *L);
void addMenu(List *L);
void searchMenu(List *L);
void readFile(List *L);
void writeFile(List *L);

List::List() {
    head = NULL;
    cur = NULL;
}

List::~List() {
    struct Data *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void List::add(char n[], int a, char s, float g) {
    struct Data *node = (struct Data*)malloc(sizeof(struct Data));
    strcpy(node->n, n);
    node->a = a;
    node->s = s;
    node->g = g;
    node->next = head;
    head = node;
}

void List::remove(char n[]) {
    struct Data *tmp = head, *prev = NULL;

    while (tmp != NULL && strcmp(tmp->n, n) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        printf("Data not found\n");
        return;
    }

    if (prev == NULL)
        head = tmp->next;
    else
        prev->next = tmp->next;

    free(tmp);
    printf("Delete success\n");
}

void List::first() {
    cur = head;
}

void List::next() {
    if (cur != NULL)
        cur = cur->next;
}

struct Data* List::current() {
    return cur;
}

int List::find(char n[]) {
    struct Data *tmp = head;
    while (tmp != NULL) {
        if (strcmp(tmp->n, n) == 0) {
            cur = tmp;
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

void List::update(char n[], int a, char s, float g) {
    if (cur != NULL) {
        strcpy(cur->n, n);
        cur->a = a;
        cur->s = s;
        cur->g = g;
    }
}

void List::showAll() {
    struct Data *tmp = head;
    while (tmp != NULL) {
        printf("%s %d %c %.2f\n",
               tmp->n,
               tmp->a,
               tmp->s,
               tmp->g);
        tmp = tmp->next;
    }
}

void readFile(List *L) {
    FILE *fp;
    char n[20], s;
    int a;
    float g;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("No file, new start\n");
        return;
    }

    while (fscanf(fp, "%s %d %c %f", n, &a, &s, &g) == 4) {
        L->add(n, a, s, g);
    }

    fclose(fp);
}

void writeFile(List *L) {
    FILE *fp;
    struct Data *tmp;

    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("File error\n");
        return;
    }

    L->first();
    tmp = L->current();

    while (tmp != NULL) {
        fprintf(fp, "%s %d %c %.2f\n",
                tmp->n,
                tmp->a,
                tmp->s,
                tmp->g);
        L->next();
        tmp = L->current();
    }

    fclose(fp);
}

void addMenu(List *L) {
    char n[20], s;
    int a;
    float g;

    printf("Name: ");
    scanf("%s", n);
    printf("Age: ");
    scanf("%d", &a);
    printf("Sex: ");
    scanf(" %c", &s);
    printf("GPA: ");
    scanf("%f", &g);

    L->add(n, a, s, g);
}

void searchMenu(List *L) {
    char n[20];
    printf("Find name: ");
    scanf("%s", n);

    if (L->find(n)) {
        struct Data *tmp = L->current();
        printf("Found: %s %d %c %.2f\n",
               tmp->n,
               tmp->a,
               tmp->s,
               tmp->g);
    } else {
        printf("Not found\n");
    }
}

void editMenu(List *L) {
    char n[20], s;
    int a;
    float g;

    printf("Edit name: ");
    scanf("%s", n);

    if (L->find(n)) {
        printf("New Name: ");
        scanf("%s", n);
        printf("New Age: ");
        scanf("%d", &a);
        printf("New Sex: ");
        scanf(" %c", &s);
        printf("New GPA: ");
        scanf("%f", &g);

        L->update(n, a, s, g);
        printf("Update success\n");
    } else {
        printf("Data not found\n");
    }
}

int main() {
    List L;
    int ch;
    char n[20];

    readFile(&L);

    printf("(1)Add (2)Edit (3)Delete (4)Find (5)Show (0)Exit: ");
    scanf("%d", &ch);

    while (ch != 0) {
        switch (ch) {
        case 1:
            addMenu(&L);
            break;
        case 2:
            editMenu(&L);
            break;
        case 3:
            printf("Delete name: ");
            scanf("%s", n);
            L.remove(n);
            break;
        case 4:
            searchMenu(&L);
            break;
        case 5:
            L.showAll();
            break;
        }

        printf("(1)Add (2)Edit (3)Delete (4)Find (5)Show (0)Exit: ");
        scanf("%d", &ch);
    }

    writeFile(&L);
    return 0;
}
