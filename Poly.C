#include<stdio.h>
#include<stdlib.h>

typedef struct Element {
    int value;
    struct Element* next;
} Element;

Element* insertAtHead(Element* head, int x) {
    Element* p = (Element*)malloc(sizeof(Element));
    p->value = x;
    p->next = head;
    head = p;
    return head;
}

Element* createPolynomial(int degree) {
    Element* P = NULL;
    int i = 0;
    int coeff = 0;
    while (i <= degree) {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &coeff);
        P = insertAtHead(P, coeff);
        i++;
    }
    return P;
}

void displayPolynomial(Element* head, int degree) {
    Element* c = head;
    if (head == NULL)
        printf("\nThe list is empty!\n");
    else {
        printf("\nThe Polynomial is:");
        int i = degree;
        while (c != NULL) {
            printf(" %dX^%d ", c->value, i);
            c = c->next;
            i--;
        }
        printf("\n");
    }
}

int calculatePolynomialValue(Element* head, int degree, int x) {
    Element* current = head;
    int result = 0;
    int currentDegree = degree;

    while (current != NULL) {
        int power = 1;
        for (int i = 0; i < currentDegree; i++) {
            power *= x;
        }
        result += current->value * power;
        current = current->next;
        currentDegree--;
    }
    return result;
}

int main() {
    Element* P = NULL;
    int degree = 0;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    P = createPolynomial(degree);

    printf("\nThe polynomial is:\n");
    displayPolynomial(P, degree);

    int x = 0;
    printf("\nEnter the value of x to evaluate the polynomial: ");
    scanf("%d", &x);

    int value = calculatePolynomialValue(P, degree, x);
    printf("\nThe value of the polynomial at x = %d is: %d\n", x, value);

    return 0;
}#include<stdio.h>
#include<stdlib.h>

typedef struct Element {
    int value;
    struct Element* next;
} Element;

Element* insertAtHead(Element* head, int x) {
    Element* p = (Element*)malloc(sizeof(Element));
    p->value = x;
    p->next = head;
    head = p;
    return head;
}

Element* createPolynomial(int degree) {
    Element* P = NULL;
    int i = 0;
    int coeff = 0;
    while (i <= degree) {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &coeff);
        P = insertAtHead(P, coeff);
        i++;
    }
    return P;
}

void displayPolynomial(Element* head, int degree) {
    Element* c = head;
    if (head == NULL)
        printf("\nThe list is empty!\n");
    else {
        printf("\nThe Polynomial is:");
        int i = degree;
        while (c != NULL) {
            printf(" %dX^%d ", c->value, i);
            c = c->next;
            i--;
        }
        printf("\n");
    }
}

int calculatePolynomialValue(Element* head, int degree, int x) {
    Element* current = head;
    int result = 0;
    int currentDegree = degree;

    while (current != NULL) {
        int power = 1;
        for (int i = 0; i < currentDegree; i++) {
            power *= x;
        }
        result += current->value * power;
        current = current->next;
        currentDegree--;
    }
    return result;
}

int main() {
    Element* P = NULL;
    int degree = 0;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    P = createPolynomial(degree);

    printf("\nThe polynomial is:\n");
    displayPolynomial(P, degree);

    int x = 0;
    printf("\nEnter the value of x to evaluate the polynomial: ");
    scanf("%d", &x);

    int value = calculatePolynomialValue(P, degree, x);
    printf("\nThe value of the polynomial at x = %d is: %d\n", x, value);

    return 0;
}
