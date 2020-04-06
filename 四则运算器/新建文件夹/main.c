#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Stack.h"
/*逆波兰表达式
 *a-(b+c)*d-e/f
 *--->abc+d*-ef/-
 *数字直接输出
 *栈为空时，遇到运算符，入栈；遇到（，入栈 
 *遇到），出栈,）不用入栈，将出栈元素输出，直到弹出栈是（，（不输出
 *当遇到运算符的优先级小于栈顶运算符的优先级时，弹出所有优先级大于或等于该运算符的，然后再将该运算符入栈
 *最后栈中元素依次出栈 
 */
int main(){
    Stack op,num;
    initStack(&op);
    initStack(&num);
    char str[100]={0};  //初始化 //中缀表达式 
    int i=0;       //str[i]
    printf("请输入中缀表达式：");
    gets(str);
//    char x=str[100];
    int n=0; //n即为此时所读取的数字
    int p,n1,n2; 
    while(str[i]!='\0')     //当 ||isEmptyStack(&op)
    {
        if (str[i] >='0'&&str[i]<='9')
        {
            n*=10;             //考虑该数字是多位数 
            n+=str[i] -'0';     //把字符转化成整数 
            i++;
            if (str[i]<'0'||str[i]>'9')    //当str[i]不是数字，即为运算符时，意味着一个数字的读取结束，输出数字 
            {
                    pushStack(&num,n);
//                    printf("%d ", n);        //输出数字 
                    n = 0;
            }
     }else{                   //运算符的处理 //出栈运算：表达式读取完、读取）、遇到运算符的优先级小于栈顶运算符的优先级 
        if(isEmptyStack(&op)||str[i]=='('){        //栈为空或者遇到（时
            pushStack(&op,str[i]);
            i++;
    }else if(str[i]==')'){            //遇到）时 
        while(getTopStack(&op)=='('||isEmptyStack(&op)){      //要一直输出直到读取到 （ 
        popStack(&op, str[i]);
        i++;
     }
    }else if (Pri(str[i])<=Pri(getTopStack(&op)))                //str[i]=='\0'&&!isEmptyStack(&op)) || (str[i]==')'&&getTopStack(&op)=='(')|| ??
        {     
            while(Pri(str[i])>=Pri(getTopStack(&op))||!isEmptyStack(&op)){      //要一直输出直到读取到 （ 
            popStack(&op, str[i]);
//            printf("%s", str[i]);     
            i++;
			}
			}
            switch(popStack(&op, getTopStack(&op))) {   //比如说bc-不是c-b，而是b-c 
                
                case '+':
                	n1=popStack(&num, getTopStack(&num));
                    n2=popStack(&num, getTopStack(&num));
                    pushStack(&num,n1+n2);break;
                case '-':
                	n1=popStack(&num, getTopStack(&num));
                    n2=popStack(&num, getTopStack(&num));
                    pushStack(&num,n2-n1);break;
                case '*':
                	n1=popStack(&num, getTopStack(&num));
                    n2=popStack(&num, getTopStack(&num));
                    pushStack(&num,n2*n1);break;
                case '/':
                	n1=popStack(&num, getTopStack(&num));
                    n2=popStack(&num, getTopStack(&num));
                    pushStack(&num,n2/n1);break;
            }
       } 
        
    }
    printf("%s = %d",str, getTopStack(&num));
    return 0;
}
