#include<stdio.h>
#include<math.h>
#include<string.h>
int s[30],op1,op2,i;
int top= -1;
char p[30],sym;

int op(int op1,char sym,int op2)
{
switch(sym)
{
case '+' : return op1+op2;
case '-' : return op1-op2;
case '*' : return op1*op2;
case '/' : return op1/op2;
case '%' : return op1%op2;
case '^' :
case '$' : return pow(op1,op2);
}
return 0;
}

int main()
{
printf("\nEnter the valid postfix exp:");
scanf("%s",p);
for(i=0;i<strlen(p);i++)
{
sym=p[i];
if(sym>='0' && sym<='9')
 s[++top]=sym-'0';

else
{
  op2=s[top--];
  op1=s[top--];
  s[++top]=op(op1,sym,op2);
}
}
printf("\nThe result is %d\n",s[top]);
}
