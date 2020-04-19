#include "qgsort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//����ָ�� a, ���鳤�� n
void insertSort(int *a,int n){
	int i,tem,j;
	for(i=1;i<n;i++){
		tem=a[i];
		for(j=i;a[j-1]>a[j]&&j>0;j--){
			a[j]=a[j-1];
			a[j-1]=tem;
		}
	}
}

//����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int i=begin;
	int j=mid+1;
	int m=begin;   //����ʱ������ 
	int k=0;       //temp[k]
	while(i<=mid&&j<=end){
		if(a[i]<a[j]){
			temp[k++]=a[i++];
		}else{
			temp[k++]=a[j++];
		}
	}
	//ʣ���û�з���� 
	while(i<=mid){ 
		temp[k++]=a[i++];
	}
	while(j<=end){
		temp[k++]=a[j++];
	}
	//��temp[]�����ص�a[]
	for(i=0;i<=k;){
		a[m++]=temp[i++];
	} 
}
//����ָ��a���������begin�������յ�end����������ָ��temp
void MergeSort(int *a,int begin,int end,int *temp){
	int mid;
	if(begin<end){
		mid=(begin+end)/2;
		MergeSort(a,begin,mid,temp);//�󲿷� 
		MergeSort(a,mid+1,end,temp);//�Ҳ��� 
		MergeArray(a,begin,mid,end,temp);
	}
}

//�������������ţ�
int Partition(int *a, int begin, int end){
	int temp=a[begin];//ȷ����Ŧ 
	while(begin<end){
		while(begin<end&&a[end]>=temp)end--;//����ŦС����� 
		a[begin]=a[end];
	    while(begin<end&&a[begin]<=temp)begin++;//����Ŧ����ұ� 
	    a[end]=a[begin];
	}
	a[begin]=temp;
	return begin;
}

//�������򣨵ݹ�棩
void QuickSort_Recursion(int *a, int begin, int end){
	if(begin<end){
		int pivot=Partition(a, begin, end);
		QuickSort_Recursion(a, begin, pivot-1);//������Ŧ�󲿷� 
		QuickSort_Recursion(a, pivot+1, end);//������Ŧ�Ҳ��� 
	}
}
//�������򣨷ǵݹ�棩
//void QuickSort(int *a,int size){
//	
//}

//�������� 
void CountSort(int *a, int size , int max){
	int b[200000];
	int c[200000];
	int i;
	for(i=0;i<size;i++)
	    b[a[i]]+=1;//ͳ��ÿ��Ԫ�س��ֵĴ���
	for(i=0;i<max;i++)
	    b[i]=b[i]+b[i-1];//
	for(i=size-1;i>=0;i--){
		c[b[i]-1]=a[i];
		b[a[i]]=b[a[i]]-1;
	} 
	for(i=0;i<size;i++)
	    a[i]=c[i];
} 

void RadixCountSort(int *a,int size){
	
}

void ColorSort(int *a,int size){
	int i,j,c0=0,c1=0,c2=0;
	for(i=0;i<size;i++){
		if(a[i]==0) c0++;
		if(a[i]==1) c1++;
		if(a[i]==2) c2++;
	}
	for(j=0;j<c0;j++) a[j]=0;
	for(j=0;j<c1;j++) a[j+c0]=1;
	for(j=0;j<c2;j++) a[j+c0+c1]=2;
}

//���k����� 
int kmax(int*a,int size,int k){
	int max;
	insertSort(a, size);
	max=a[size-k];
	return max;
}

