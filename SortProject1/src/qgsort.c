#include "qgsort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//数组指针 a, 数组长度 n
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

//数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int i=begin;
	int j=mid+1;
	int m=begin;   //拷贝时候的起点 
	int k=0;       //temp[k]
	while(i<=mid&&j<=end){
		if(a[i]<a[j]){
			temp[k++]=a[i++];
		}else{
			temp[k++]=a[j++];
		}
	}
	//剩余的没有放完的 
	while(i<=mid){ 
		temp[k++]=a[i++];
	}
	while(j<=end){
		temp[k++]=a[j++];
	}
	//将temp[]拷贝回到a[]
	for(i=0;i<=k;){
		a[m++]=temp[i++];
	} 
}
//数组指针a，数组起点begin，数组终点end，承载数组指针temp
void MergeSort(int *a,int begin,int end,int *temp){
	int mid;
	if(begin<end){
		mid=(begin+end)/2;
		MergeSort(a,begin,mid,temp);//左部分 
		MergeSort(a,mid+1,end,temp);//右部分 
		MergeArray(a,begin,mid,end,temp);
	}
}

//快速排序（枢轴存放）
int Partition(int *a, int begin, int end){
	int temp=a[begin];//确定枢纽 
	while(begin<end){
		while(begin<end&&a[end]>=temp)end--;//比枢纽小放左边 
		a[begin]=a[end];
	    while(begin<end&&a[begin]<=temp)begin++;//比枢纽大放右边 
	    a[end]=a[begin];
	}
	a[begin]=temp;
	return begin;
}

//快速排序（递归版）
void QuickSort_Recursion(int *a, int begin, int end){
	if(begin<end){
		int pivot=Partition(a, begin, end);
		QuickSort_Recursion(a, begin, pivot-1);//排序枢纽左部分 
		QuickSort_Recursion(a, pivot+1, end);//排序枢纽右部分 
	}
}
//快速排序（非递归版）
//void QuickSort(int *a,int size){
//	
//}

//计数排序 
void CountSort(int *a, int size , int max){
	int b[200000];
	int c[200000];
	int i;
	for(i=0;i<size;i++)
	    b[a[i]]+=1;//统计每个元素出现的次数
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

//求第k大的数 
int kmax(int*a,int size,int k){
	int max;
	insertSort(a, size);
	max=a[size-k];
	return max;
}

