// FIX DEALLOC ERRORS FIRST BEFORE PUSH YO

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int Ex, Ey, Ez, cf;
    struct Node *next;
} Node;

int get_int() {
    int n;
    scanf(" %d", &n);
    return n;
}

int sum(Node *t) {
    return t->Ex + t->Ey + t->Ez;
}

int expcmp(Node *a, Node *b) {
    if (a->Ex > b->Ex) {
        return 1;
    } else if (a->Ex < b->Ex) {
        return -1;
    } else if (a->Ey > b->Ey) {
        return 1;
    } else if (a->Ey < b->Ey) {
        return -1;
    }
    return 0;
}

Node *poly_read() {
    Node *poly = malloc(sizeof(Node));
    poly->next = poly;
    poly->Ex = -1;
    for (int i = 0, n = get_int(); i < n; i++) {
        Node *term = malloc(sizeof(Node));
        term->Ex = get_int();
        term->Ey = get_int();
        term->Ez = get_int();
        term->cf = get_int();
        Node *b = poly, *a = b->next;
        while (expcmp(a, term) > 0) {
            b = a;
            a = a->next;
        }
        b->next = term;
        term->next = a;
    }
    return poly;
}

void poly_add(Node *p, Node *q) {
    Node *a = p->next, *b = q->next;
    Node *r = q;
    while (1) {
        int v = expcmp(a,b);
        if (v < 0) {
            r = b;
            b = b->next;
        } else if (v == 0) {
            if (sum(a) < 0) {
                return;
            }

            b->cf = b->cf + a->cf;
            if (b->cf == 0) {
                Node *t = b;
                r->next = b->next;
                b = b->next;
                free(t);
            } else {
                r = b;
                b = b->next;
            }
            a = a->next;
        } else {
            Node *t = malloc(sizeof(Node));
            t->cf = a->cf;
            t->Ex = a->Ex;
            t->Ey = a->Ey;
            t->Ez = a->Ez;
            r->next = t;
            t->next = b;
            r = t;
            a = a->next;
        }
    }
}

void out(Node *node) {
    for (Node *tmp = node->next; tmp->next != node->next; tmp = tmp->next) {
        printf("%d %d %d %.3f\n", tmp->Ex, tmp->Ey, tmp->Ez, (float) tmp->cf);
    }
}

void rm(Node *n) {
    if (n) {
        rm(n->next);
        free(n);
    }
}

int main(void) {
    Node *poly0 = poly_read();
    Node *poly1 = poly_read();
    poly_add(poly0, poly1);
    out(poly1);
    rm(poly0);
    rm(poly1);
}