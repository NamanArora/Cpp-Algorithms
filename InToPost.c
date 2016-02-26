#include <stdio.h>
#include<string.h>
#include<ctype.h>

#define size 5

struct stack
{
    char a[size];
    int top;
}obj;

void push(char n)
    {
        if(obj.top==size-1)
            printf("Stack full\n");
            else
            {
                obj.top++;
                obj.a[obj.top]=n;
                printf("Pushed: %c\n",n);
            }
    }
    char pop()
    {
        if(obj.top==-1){
            printf("Stack is empty");
            return 0;
        }
            else
            {
                char temp=obj.a[obj.top];
                obj.top--;
                printf("Popped: %c\n",temp);
                return temp;
            }
    }
void init()
{
    obj.top=-1;
}

int priority(char x)
{
   if(x == '(')
 return(0);
   if(x == '+' || x == '-')
 return(1);
   if(x == '*' || x == '/' || x == '%')
 return(2);
   return(3);
}
int main(int argc, char **argv)
{
    init();
    char c;int t;
    while((c=getchar())!='n') //until we get 'n'
    {
        if(isalnum(c))
            printf("%c\n",c);
        else if(!iscntrl(c))
        {
            if(c=='(')
                push(c);
            else if(c==')')
                while((t=pop())!='(' && t!=0){}
            else
            {
                while(priority(c)<=priority(obj.a[obj.top]) && obj.top>-1)
                pop();
                push(c);
            }
        }
    }
	return 0;
}
