#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define COMPARE(x, y) ((x) > (y) ? 1 : ((x) == (y) ? 0 : -1))
struct polynode {
 int coeff;
 int expo;
 struct polynode *link;
};
typedef struct polynode *polyptr;
polyptr heada, headb, headc;
void display(polyptr x) {
 polyptr temp;
 temp = x->link;
 while (temp->link != x) {
 printf("%d x^%d + ", temp->coeff, temp->expo);
 temp = temp->link;
 }
 printf("%d x^%d", temp->coeff, temp->expo);
}
void attach(int c, int e, polyptr *ptr) {
 polyptr temp;
 temp = (polyptr)malloc(sizeof(struct polynode));
 temp->coeff = c;
 temp->expo = e;
 (*ptr)->link = temp;
 *ptr = temp;
}
void cpadd(polyptr a, polyptr b) {
 polyptr starta, lastc;
 int sum, done = FALSE;
 starta = a;
 a = a->link;
 b = b->link;
 headc = (polyptr)malloc(sizeof(struct polynode));
 headc->expo = -1;
 lastc = headc;
 do {
 switch (COMPARE(a->expo, b->expo)) {
 case 1:
 attach(a->coeff, a->expo, &lastc);
 a = a->link;
 break;
 case -1:
 attach(b->coeff, b->expo, &lastc);
 b = b->link;
 break;
 case 0:
 if (a == starta)
 done = TRUE;
 else {
 sum = a->coeff + b->coeff;
 if (sum)
 attach(sum, a->expo, &lastc);
 a = a->link;
 b = b->link;
 }
 break;
 }
 } while (!done);
 lastc->link = headc;
}
void main() {
 polyptr lasta, lastb, temp;
 int c, e, i, n, x, choice, sum = 0;
 heada = (polyptr)malloc(sizeof(struct polynode));
 headb = (polyptr)malloc(sizeof(struct polynode));
 heada->expo = -1;
 headb->expo = -1;
 lasta = heada;
 lastb = headb;
 printf("\nEnter the number of terms of polynomial 1\n");
 scanf("%d", &n);
 for (i = 0; i < n; i++) {
 printf("Enter coefficient and exponent: ");
 scanf("%d %d", &c, &e);
 attach(c, e, &lasta);
 }
 lasta->link = heada;
 printf("\nEnter the number of terms of polynomial 2\n");
 scanf("%d", &n);
 for (i = 0; i < n; i++) {
 printf("Enter coefficient and exponent: ");
 scanf("%d %d", &c, &e);
 attach(c, e, &lastb);
 }
 lastb->link = headb;
 printf("1 - Add\n2 - Evaluate\n");
 scanf("%d", &choice);
 if (choice == 1) {
 cpadd(heada, headb);
 printf("\nPolynomial 1 is\n");
 display(heada);
 printf("\n\nPolynomial 2 is\n");
 display(headb);
 printf("\n\nResult is\n");
 display(headc);
 } else if (choice == 2) {
 printf("Enter x value: ");
 scanf("%d", &x);
 for (temp = heada->link; temp != heada; temp = temp->link)
 sum += temp->coeff * pow(x, temp->expo);
 printf("\nPolynomial A after evaluation is %d\n", sum);
 }
}
