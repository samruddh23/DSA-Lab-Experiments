Name: Samruddh Jadhav
Roll No.20 
Division: D10C
Lab Experiment 2
Aim: Conversion of Infix Expression to Postfix Expression Using Stack

Code:
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) { stack[++top] = ch; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i, k = 0;
    for (i = 0; infix[i]; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!isEmpty() && peek() != '(') postfix[k++] = pop();
            pop(); // remove '('
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(ch) && ch != '^')
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (!isEmpty()) postfix[k++] = pop();
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}

Output:
Enter infix expression: A*(B+C)/D
Postfix: ABC+*D/

