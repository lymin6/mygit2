#include <stdio.h>
#include <stdlib.h>
#include "qgsort.h"
#include <time.h>
int main()
{
	int a[10000],b[50000],c[200000];
	int temp[200000];
	int i,j,k;
	clock_t start,finish;
	double duration;
	srand(time(NULL));
//	for(i=0;i<10000;i++)
//	    a[i]=rand();
//	for(j=0;j<50000;j++)
//	    b[j]=rand();
//	for(k=0;k<200000;k++)
//	    c[k]=rand();
    
    printf("�������һ������s[100]�������ĵ�k��ֵ,����k��ֵ��");
	scanf("%d", &k);
	int s[100],p;
	for(p=0;p<100;p++)
	    s[p]=rand();
	int max=kmax(s,100,k);
	printf("������ĵ�%d���ֵΪ%d\n", k, max);
	
	printf("������Q[8]={0,1,0,2,1,1,2,0}������ɫ���򷨣���\n");
	int Q[8]={0,1,0,2,1,1,2,0};
	ColorSort(Q,8);
	for(p=0;p<8;p++){
		printf("%d ", Q[p]);
	}
	printf("\n");
	
	
	printf("������Ϊ10000ʱ,��������ĺ�ʱ��\n");
	int size=10000;
	for(i=0;i<10000;i++)
	    a[i]=rand();
	start=clock();
	insertSort(a,10000);
	finish=clock();
	duration=(double)(finish-start);
	printf("insertSort:%lfms\n",duration);
	
	for(i=0;i<10000;i++)
	    a[i]=rand();
	start=clock();
	MergeSort(a,0,9999,temp);
	finish=clock();
	duration=(double)(finish-start);
	printf("MergeSor:%lfms\n",duration);
	
	for(i=0;i<10000;i++)
	    a[i]=rand();
	start=clock();
	QuickSort_Recursion(a, 0, 9999);
	finish=clock();
	duration=(double)(finish-start);
	printf("QuickSort_Recursion:%lfms\n",duration);
	
	printf("������Ϊ50000ʱ,��������ĺ�ʱ��\n");
	for(j=0;j<50000;j++)
	    b[j]=rand();
	start=clock();
	insertSort(b,50000);
	finish=clock();
	duration=(double)(finish-start);
	printf("insertSort:%lfms\n",duration);
	
	for(j=0;j<50000;j++)
	    b[j]=rand();
	start=clock();
	MergeSort(b,0,49999,temp);
	finish=clock();
	duration=(double)(finish-start);
	printf("MergeSor:%lfms\n",duration);
	
	for(j=0;j<50000;j++)
	    b[j]=rand();
	start=clock();
	QuickSort_Recursion(b, 0, 9999);
	finish=clock();
	duration=(double)(finish-start);
	printf("QuickSort_Recursion:%lfms\n",duration);
	
	printf("������Ϊ200000ʱ,��������ĺ�ʱ��\n");
	for(k=0;k<200000;k++)
	    c[k]=rand();
	start=clock();
	insertSort(c,200000);
	finish=clock();
	duration=(double)(finish-start);
	printf("insertSort:%lfms\n",duration);
	
	for(k=0;k<200000;k++)
	    c[k]=rand();
	start=clock();
	MergeSort(c,0,199999,temp);
	finish=clock();
	duration=(double)(finish-start);
	printf("MergeSor:%lfms\n",duration);
	
	for(k=0;k<200000;k++)
	    c[k]=rand();
	start=clock();
	QuickSort_Recursion(c, 0, 199999);
	finish=clock();
	duration=(double)(finish-start);
	printf("QuickSort_Recursion:%lfms\n",duration);
	
//	100k��������Ϊ100������ 
    int h,l,*o;
    start=clock();
	for(h=0;h<=100000;h++){
		for(l=0;l<100;l++){
			o[l]=rand();
			insertSort(o,100);
		}
	} 
	finish=clock();
    duration=(double)(finish-start);
	printf("insertSort:%lfms\n",duration);


//    int max=a[0];
//    int m;
//    for(m=0;m<10000;m++){
//    	if(a[m]>max){
//    		max=a[m];
//		}
//	}
//	printf("%d\n",max);
//	start=clock();
//	CountSort(a, 10000 , max);
//	finish=clock();
//	duration=(double)(finish-start);
//	printf("CountSort:%lfms\n",duration);
	
	system("pause");
}
