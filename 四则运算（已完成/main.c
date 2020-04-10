#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Stack.h"
/*逆波兰表达式
 *--->    a-(b+c)*d-e/f
 *--->    abc+d*-ef/-
 *数字直接输出
 *栈为空时，遇到运算符，入栈；遇到（，入栈 
 *遇到），出栈,）不用入栈，将出栈元素输出，直到弹出栈是（，（不输出
 *当遇到运算符的优先级小于栈顶运算符的优先级时，弹出所有优先级大于或等于该运算符的，然后再将该运算符入栈
 *最后栈中元素依次出栈 
 */
int main(){
	Stack op;
	initStack(&op);
//	initStack(&num);
    int num[100]={0};
	char str[100]={0};  //初始化 //中缀表达式 
//	char str2[100]={0};    //用来储存后缀表达式的运算符号 
	int i=0;       //str[i]
	int j=0;       //num[j] 储存读到的数据 
	printf("请输入中缀表达式（于英文状态下输入）：");
	gets(str);     //英文状态 
	int n=0;       //n即为此时所读取的数字
	int number=0,b=0; 
	printf("其后缀表达式为："); 
	while(str[i]!='\0'||!isEmptyStack(&op))     //当 还没有遍历完中缀表达式 或者说 已遍历完表达式但运算符栈内还有元素时 
	{
		if(str[i] >='0'&&str[i]<='9')
		{
		    n*=10;             //考虑该数字是多位数 
			n=n+str[i] -'0';     //把字符转化成整数 
//			printf("%d", n);
			i++;
			if (str[i]<'0'||str[i]>'9')    //当str[i]不是数字，即为运算符时，意味着一个数字的读取结束
			{
//				pushStack(&num,n);     //储存 
				printf("%d ", n);
				j++; 
				num[j]=n;
//				printf("%d ", num[j]);
				n = 0;
			}
		}
		if (!(str[i]>='0'&&str[i]<='9')){                   //运算符的处理 
			if((isEmptyStack(&op)&&str[i]!='\0')||str[i]=='('){        //栈为空或者遇到（时
		        pushStack(&op,str[i]);
		        i++;
		        }
			else if(str[i]==')'){            //遇到）时   &&!isEmptyStack(&op)
	    	    if(getTopStack(&op)!='('){      //要一直输出直到读取到 （ ， 出栈不输出
	    	        b=j;
	    	        j--;
				    number=calculation(getTopStack(&op),num[b],num[j]); 
                    num[j]=number;
	    	        printf("%c ", getTopStack(&op));
	    		    popStack(&op);		    
				} else if(getTopStack(&op)=='('){                
				    popStack(&op);
					i++;
		        }
				}
		    else if((str[i]=='+')||(str[i]=='-')){    //遇+或者-时： 
		        	if(!isEmptyStack(&op)&&getTopStack(&op)!='('){  // 非空栈或者栈顶不为（，则要出栈 
		        		b=j;
	    	            j--;
		        		number=calculation(getTopStack(&op),num[b],num[j]);
		        		num[j]=number;
		        		printf("%c ", getTopStack(&op));
		        		popStack(&op);
		        	}
						pushStack(&op,str[i]);        //空栈或栈顶为（时，入栈 
		        		i++;
				}
			else if((str[i]=='*')||(str[i]=='/')){             //遇到*或者/时 
				    if(!isEmptyStack(&op)&&getTopStack(&op)!='('){        //非空栈或者栈顶为（，则要判断str[i]和栈顶的优先级再做后续 
				    	if(getTopStack(&op)=='*'||getTopStack(&op)=='/'){
				    		b=j;
	    	                j--;
				    		number=calculation(getTopStack(&op),num[b],num[j]);
		        		    num[j]=number;
				    		printf("%c ", getTopStack(&op));
		        		    popStack(&op);
						}
					}
						pushStack(&op,str[i]);
		        		i++;
				}
		while(!isEmptyStack(&op)&&str[i]=='\0'){              //当表达式已遍历完，但运算符栈还有元素时，出栈直到空栈 
			        b=j;
	    	        j--;
                    number=calculation(getTopStack(&op),num[b],num[j]);
		            num[j]=number; 
					printf("%c ", getTopStack(&op));
	    		    popStack(&op);
				}
		    } 
	}
	printf("\n");
   	printf("该表达式的结果为%d\n", num[j]);
   	system("pause");
}
