#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Stack.h"
/*�沨�����ʽ
 *--->    a-(b+c)*d-e/f
 *--->    abc+d*-ef/-
 *����ֱ�����
 *ջΪ��ʱ���������������ջ������������ջ 
 *����������ջ,��������ջ������ջԪ�������ֱ������ջ�ǣ����������
 *����������������ȼ�С��ջ������������ȼ�ʱ�������������ȼ����ڻ���ڸ�������ģ�Ȼ���ٽ����������ջ
 *���ջ��Ԫ�����γ�ջ 
 */
int main(){
	Stack op;
	initStack(&op);
//	initStack(&num);
    int num[100]={0};
	char str[100]={0};  //��ʼ�� //��׺���ʽ 
//	char str2[100]={0};    //���������׺���ʽ��������� 
	int i=0;       //str[i]
	int j=0;       //num[j] ������������� 
	printf("��������׺���ʽ����Ӣ��״̬�����룩��");
	gets(str);     //Ӣ��״̬ 
	int n=0;       //n��Ϊ��ʱ����ȡ������
	int number=0,b=0; 
	printf("���׺���ʽΪ��"); 
	while(str[i]!='\0'||!isEmptyStack(&op))     //�� ��û�б�������׺���ʽ ����˵ �ѱ�������ʽ�������ջ�ڻ���Ԫ��ʱ 
	{
		if(str[i] >='0'&&str[i]<='9')
		{
		    n*=10;             //���Ǹ������Ƕ�λ�� 
			n=n+str[i] -'0';     //���ַ�ת�������� 
//			printf("%d", n);
			i++;
			if (str[i]<'0'||str[i]>'9')    //��str[i]�������֣���Ϊ�����ʱ����ζ��һ�����ֵĶ�ȡ����
			{
//				pushStack(&num,n);     //���� 
				printf("%d ", n);
				j++; 
				num[j]=n;
//				printf("%d ", num[j]);
				n = 0;
			}
		}
		if (!(str[i]>='0'&&str[i]<='9')){                   //������Ĵ��� 
			if((isEmptyStack(&op)&&str[i]!='\0')||str[i]=='('){        //ջΪ�ջ���������ʱ
		        pushStack(&op,str[i]);
		        i++;
		        }
			else if(str[i]==')'){            //������ʱ   &&!isEmptyStack(&op)
	    	    if(getTopStack(&op)!='('){      //Ҫһֱ���ֱ����ȡ�� �� �� ��ջ�����
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
		    else if((str[i]=='+')||(str[i]=='-')){    //��+����-ʱ�� 
		        	if(!isEmptyStack(&op)&&getTopStack(&op)!='('){  // �ǿ�ջ����ջ����Ϊ������Ҫ��ջ 
		        		b=j;
	    	            j--;
		        		number=calculation(getTopStack(&op),num[b],num[j]);
		        		num[j]=number;
		        		printf("%c ", getTopStack(&op));
		        		popStack(&op);
		        	}
						pushStack(&op,str[i]);        //��ջ��ջ��Ϊ��ʱ����ջ 
		        		i++;
				}
			else if((str[i]=='*')||(str[i]=='/')){             //����*����/ʱ 
				    if(!isEmptyStack(&op)&&getTopStack(&op)!='('){        //�ǿ�ջ����ջ��Ϊ������Ҫ�ж�str[i]��ջ�������ȼ��������� 
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
		while(!isEmptyStack(&op)&&str[i]=='\0'){              //�����ʽ�ѱ����꣬�������ջ����Ԫ��ʱ����ջֱ����ջ 
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
   	printf("�ñ��ʽ�Ľ��Ϊ%d\n", num[j]);
   	system("pause");
}
