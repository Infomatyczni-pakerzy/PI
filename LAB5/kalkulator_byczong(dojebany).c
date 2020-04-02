// dojebany kalkulator by Byczong oceniony na 100 punktow na 100 mozliwych przez sprawdzarke pani D
#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int top;
    int capacity;
    int* array;
};

struct Stack* initStack(int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void freeStack(struct Stack* stack)
{
    free(stack->array);
    free(stack);
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, int item)
{
    if(isFull(stack))
    {
        printf("Stos przepelniony");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        printf("Stos pusty");
    return stack->array[stack->top--];
}


int main(void)
{  
    int n, k;
    int a, b, i=0;
    char* curr;
    curr = (char*)malloc( (k+1) * sizeof(char));

    scanf("%1d %2d", &n, &k);
    struct Stack* stack = initStack(n);

    do
    {
        scanf(" %s", curr);
        if( curr[0] == '+' || curr[0] == '-' || curr[0] == '*' || curr[0] == '/')
        {
            a = pop(stack);
            b = pop(stack);
            switch(curr[0])
            {
                case '+':
                    push(stack, b + a );
                    break;
                case '-':
                    push(stack, b - a );
                    break;
                case '*':
                    push(stack, b * a );
                    break;
                case '/':
                    push(stack, b / a );
                    break;
                default:
                    break;
            }
        }
        else
        {
            i++;
            push(stack, atoi(curr));
        }
        
    }
    while ( stack->top != 0 || i < n );

    printf("%d", stack->array[0]);
    freeStack(stack);
}
