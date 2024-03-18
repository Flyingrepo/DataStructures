
#include<stdio.h>
#include<math.h>
#include<string.h>

float compute(char symbol, float op1, float op2)
{
 switch (symbol)
 {
  case '+': return op1 + op2;

  case '-': return op1 - op2;

  case '*': return op1 * op2;

  case '/': return op1 / op2;

  case '$':

  case '^': return pow(op1,op2);

  default : return 0;
 }
}
void main()
{
 float s[20], res, op1, op2;
 int top, i;
 char postfix[20], symbol;
 printf("\nEnter the postfix expression:\n");
 scanf ("%s", postfix);
 top=-1;
 for (i=0; i<strlen(postfix) ;i++)
 {
  symbol = postfix[i];
  if(isdigit(symbol))
  s[++top]=symbol - '0';
  else
  {
   op2 = s[top--];
   op1 = s[top--];
   res = compute(symbol, op1, op2);
   s[++top] = res;
  }
 }
 res = s[top--];
 printf("\nThe result is : %f\n", res);
}



//Solving Tower of Hanoi problem with n disk

#include <stdio.h>
void tower(int n, char beg, char aux, char end )
{
    if (n==0) 
        printf("Illegal, Try with non zero positive integers\n");
    else if (n==1)
        printf("Move disk from %c to %c\n", beg, end); 
    else
    {
        tower(n-1, beg, end, aux);
        tower(1, beg, aux, end);
        tower(n-1, aux, beg, end);
    }
}
void main()
{
    int n;
    char a,b,c;
    printf("Enter number of disks\n");
    scanf("%d",&n);
    printf("Tower of Hanoi for %d disk has following steps:\n",n);
    tower(n,'a','b','c');
}