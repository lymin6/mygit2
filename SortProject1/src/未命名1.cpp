#include <stdio.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	clock_t start,finish;
	double duration;
	srand(time(NULL));
	int a[10000];
	int i;
	int *temp;
	FILE*test=fopen("test.txt","w");
	if(test==NULL) return 0;
	for(i=0;i<10000;i++)
	    a[i]=rand();
	for(i=0;i<10000;i++)
	  fprintf(test,"%d",a[i]);
	fclose(test);
	int *b,*c,*d,*e,*f,m=0,n=0,h=0,l=0,q=0;
	FILE*test=fopen("test.txt","r");
	for(i=0;i<10000;i++){
			fscanf(test,"%d ",a[k]);
			b[m++]=a[i];
			c[n++]=a[i];
			d[h++]=a[i];
			e[l++]=a[i];
			f[q++]=a[i];
		}
	fclose(test);
	
	
	start=clock();
	insertSort(b,10000);
	finish=clock();
	duration=(double)(finish-start);
	printf("insertSort:%lfms\n",duration);
	    
	start=clock();
	MergeSort(c,0,9999,temp);
	finish=clock();
	duration=(double)(finish-start);
	printf("MergeSortt:%lfms\n",duration);
	    
	start=clock();
	QuickSort_Recursion(d, 0, 9999);
	finish=clock();
	duration=(double)(finish-start);
	printf("QuickSort_Recursion:%lfms\n",duration);
	    
	int max=e[0];
    for(l=0;l<10000;l++){
    	if(e[l]>max){
    		max=e[l];
		}
	}
	start=clock();
	CountSort(e, 10000 , max);
	finish=clock();
	duration=(double)(finish-start);
	printf("CountSort:%lfms\n",duration);
	}
	
	start=clock();
	RadixCountSort(f,10000);
	finish=clock();
	duration=(double)(finish-start);
	printf("RadixCountSort:%lfms\n",duration);
	
	system("pause");
} 
