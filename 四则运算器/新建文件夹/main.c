#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Stack.h"
/*�沨�����ʽ
 *a-(b+c)*d-e/f
 *--->abc+d*-ef/-
 *����ֱ�����
 *ջΪ��ʱ���������������ջ������������ջ 
 *����������ջ,��������ջ������ջԪ�������ֱ������ջ�ǣ����������
 *����������������ȼ�С��ջ������������ȼ�ʱ�������������ȼ����ڻ���ڸ�������ģ�Ȼ���ٽ����������ջ
 *���ջ��Ԫ�����γ�ջ 
 */
int main(){
    Stack op,num;
    initStack(&op);
    initStack(&num);
    char str[100]={0};  //��ʼ�� //��׺���ʽ 
    int i=0;       //str[i]
    printf("��������׺���ʽ��");
    gets(str);
//    char x=str[100];
    int n=0; //n��Ϊ��ʱ����ȡ������
    int p,n1,n2; 
    while(str[i]!='\0')     //�� ||isEmptyStack(&op)
    {
        if (str[i] >='0'&&str[i]<='9')
        {
            n*=10;             //���Ǹ������Ƕ�λ�� 
            n+=str[i] -'0';     //���ַ�ת�������� 
            i++;
            if (str[i]<'0'||str[i]>'9')    //��str[i]�������֣���Ϊ�����ʱ����ζ��һ�����ֵĶ�ȡ������������� 
            {
                    pushStack(&num,n);
//                    printf("%d ", n);        //������� 
                    n = 0;
            }
     }else{                   //������Ĵ��� //��ջ���㣺���ʽ��ȡ�ꡢ��ȡ������������������ȼ�С��ջ������������ȼ� 
        if(isEmptyStack(&op)||str[i]=='('){        //ջΪ�ջ���������ʱ
            pushStack(&op,str[i]);
            i++;
    }else if(str[i]==')'){            //������ʱ 
        while(getTopStack(&op)=='('||isEmptyStack(&op)){      //Ҫһֱ���ֱ����ȡ�� �� 
        popStack(&op, str[i]);
        i++;
     }
    }else if (Pri(str[i])<=Pri(getTopStack(&op)))                //str[i]=='\0'&&!isEmptyStack(&op)) || (str[i]==')'&&getTopStack(&op)=='(')|| ??
        {     
            while(Pri(str[i])>=Pri(getTopStack(&op))||!isEmptyStack(&op)){      //Ҫһֱ���ֱ����ȡ�� �� 
            popStack(&op, str[i]);
//            printf("%s", str[i]);     
            i++;
			}
			}
            switch(popStack(&op, getTopStack(&op))) {   //����˵bc-����c-b������b-c 
                
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
