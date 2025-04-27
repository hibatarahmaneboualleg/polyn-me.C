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

int getSize(Element* head) {
    int size = 0;
    Element* current = head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

int calculatePolynomialValue(Element* head, int x) {
    Element* current = head;
    int result = 0;
    int size = getSize(head);

    while (current != NULL) {
        int power = 1;
        for (int i = 0; i < size - 1; i++) {
            power *= x;
        }
        result += current->value * power;
        current = current->next;
        size--;
    }
    return result;
}

Element* addPolynomials(Element* poly1, Element* poly2) {
    Element* result = NULL;
    Element* ptr1 = poly1;
    Element* ptr2 = poly2;

    while (ptr1 != NULL || ptr2 != NULL) {
        int sum = 0;

        if (ptr1 != NULL) {
            sum += ptr1->value;
            ptr1 = ptr1->next;
        }

        if (ptr2 != NULL) {
            sum += ptr2->value;
            ptr2 = ptr2->next;
        }

        result = insertAtHead(result, sum);
    }

    return result;
}

int main() {
    Element* P1 = NULL;
    Element* P2 = NULL;
    int degree1, degree2;
    int result_deg;

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);
    P1 = createPolynomial(degree1);

    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);
    P2 = createPolynomial(degree2);

    if (degree1 > degree2) {
        result_deg = degree1;
    } else {
        result_deg = degree2;
    }

    printf("\nThe first polynomial is:\n");
    displayPolynomial(P1, degree1);

    printf("\nThe second polynomial is:\n");
    displayPolynomial(P2, degree2);

    Element* sumPoly = addPolynomials(P1, P2);
    printf("\nThe sum of the polynomials is:\n");
    displayPolynomial(sumPoly, result_deg);

}
