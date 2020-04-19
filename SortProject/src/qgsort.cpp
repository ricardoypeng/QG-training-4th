#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "../inc/randnum.h"
#include "../inc/qgsort.h"
using namespace std;
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a, int n)
{
	int c;
	int b[n + 1];
	memcpy(b,a,sizeof(b));
	for (int i = 2; i <= n; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			if (b[i] >= a[j])
			{
				c = b[i];
				for(int z = i - 1; z >= j + 1; z--)
				{
					a[z + 1] = a[z];
				}
				a[j + 1] = c; 
				break;
			} 
			if (b[i] < a[j])
			{
				if (j == 1)
				{
					c = b[i];
					for (int z = i - 1; z >= 1; z--)
					{
						a[z + 1] = a[z];
					}
					a[1] = c; 
					continue;
				}
				continue;
			}
		}
	}
	return;
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a, int begin, int mid, int end, int *temp)
{
	int p = begin, q = mid;
//	cout<<"bg:"<<begin<<" end:"<<end<<endl;
	for (int i = begin; i <= end; i++)
	{
//		cout<<"ap:"<<a[p]<<" aq:"<<a[q]<<endl;
		if(p >= mid)
		{
			temp[i] = a[q];
			q++;
//			cout<<"run 1"<<endl;
//			cout<<"i:"<<i<<" temp:"<<temp[i]<<endl;
			continue;
		}
		if(q >= end+1)
		{
			temp[i] = a[p];
			p++;
//			cout<<"run 2"<<endl;
//			cout<<"i:"<<i<<" temp:"<<temp[i]<<endl;
			continue;
		}
		if (a[p] <= a[q])
		{
			temp[i] = a[p];
			p++;
//			cout<<"run 3"<<endl;
		}
		else
		{
			temp[i] = a[q];
			q++;
//			cout<<"run 4"<<endl;
		}
//		cout<<"i:"<<i<<" temp:"<<temp[i]<<endl;
	}
	memcpy(a + begin, temp + begin , sizeof(int)*(end - begin + 1));
//	cout<<"???:"<<endl;
//	for (int i = 1; i <= end - begin + 1; i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	return;
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
	if (begin >= end)
		return;
	int n = end - begin + 1, mid = begin + n / 2;
//	for (int i = 1; i <= n; i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	MergeSort(a, begin, mid-1, temp);
	MergeSort(a, mid, end, temp);
	MergeArray(a, begin, mid, end, temp);
	return; 
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
//	cout<<"00000 a:" <<a[begin]<<" bg:"<<begin<<" end:"<<end<<endl;
	int i = begin + 1, j = end, c;
	bool zz = 0, i1 = 0, j1 = 0;
	if (begin > end)
	{
//		cout<<"error"<<endl;
//		cout<<"bg:"<<begin<<" end:"<<end<<endl;
//		for(int i = begin; i <= end; i++)
//		{
//			cout<<a[i]<<" "; 
//		}
//		cout<<endl;
		return;
	}
	if (begin == end)
	{
//		cout<<"b == g" <<endl;
//		cout<<"bg:"<<begin<<" end:"<<end<<endl;
//		for(int i = begin; i <= end; i++)
//		{
//			cout<<a[i]<<" "; 
//		}
//		cout<<endl;
		return;
	} 
	if (begin + 1 == end)
	{
		if (a[begin] > a[end])
		{
			c = a[end];
			a[end] = a[begin];
			a[begin] = c;
		}
//		cout<<"bg"<<endl;
//		cout<<"bg:"<<begin<<" end:"<<end<<endl;
//		for(int i = begin; i <= end; i++)
//		{
//			cout<<a[i]<<" "; 
//		}
//		cout<<endl;
		return;
	}
	Partition(a, begin, end);
	do
	{
//		cout<<"run ��"<<a[begin]<<" i:"<<i<<" ="<<a[i]<<" j:"<<j<<" ="<<a[j]<<endl; 
		if (i1 == 1 && j1 == 1)
		{
			c = a[i];
			a[i] = a[j];
			a[j] = c;
//			cout<<"����"<<endl;
//			cout<<"1i:"<<i<<" j:"<<j<<endl; 
			i++;
			j--;
			i1 = 0;
			j1 = 0;
			continue;
		}
		if (a[i] > a[begin] && i1 == 0)
		{
			i1 = 1; 
//			cout<<"i����"<<endl;
		}
		else
		{
			if(i1 == 0)
			{
				i++;
			}	
		}
		if (a[j] < a[begin] && j1 == 0)
		{
			j1 = 1;
//			cout<<"j����"<<endl;
		}
		else
		{
			if(j1 == 0)
			{
				j--;
			}	
		}
	}while(i < j);
	if (i > j)
	{
		if(i1 == 0 && j1 == 0)
		{
			if(a[j] <= a[begin])
			{
//				cout<<"a[j] <= a[begin]"<<endl;
				c = a[j];
				a[j] = a[begin];
				a[begin] = c;
				QuickSort_Recursion(a, begin, j);
				QuickSort_Recursion(a, j + 1, end);
//				cout<<"bg:"<<begin<<" end:"<<end<<endl;
//				for(int i = begin; i <= end; i++)
//				{
//					cout<<a[i]<<" "; 
//				}
//				cout<<endl; 
				return;
			}	
		}
		else
		{
			if (i1 == 1)
			{
//				cout<<"i1 == 1"<<endl;
				QuickSort_Recursion(a, begin, i - 1);
				QuickSort_Recursion(a, i, end);
				return;
			}
			else
			{
				if (j1 == 1)
				{
//					cout<<"j1 == 1"<<endl;
					c = a[j];
					a[j] = a[begin];
					a[begin] = c;
					QuickSort_Recursion(a, begin, j);
					QuickSort_Recursion(a, j+1, end);
					return;
				}
			}
		}
	}
	if(i == j)
	{
		if(a[i] <= a[begin])
		{
			c = a[i];
			a[i] = a[begin];
			a[begin] = c;
			QuickSort_Recursion(a, begin, i);
			QuickSort_Recursion(a, i + 1, end);
//			cout<<"bg:"<<begin<<" end:"<<end<<endl;
//			for(int i = begin; i <= end; i++)
//			{
//				cout<<a[i]<<" "; 
//			}
//			cout<<endl; 
			return;
		}
		else
		{
			if(j1 == 1)
			{
				c = a[i - 1];
				a[i - 1] = a[begin];
				a[begin] = c;
				QuickSort_Recursion(a, begin, i - 1);
				QuickSort_Recursion(a, i, end);
//				cout<<"bg:"<<begin<<" end:"<<end<<endl;
//				for(int i = begin; i <= end; i++)
//				{
//					cout<<a[i]<<" "; 
//				}
//				cout<<endl; 
				return;
			}
			QuickSort_Recursion(a, begin, i - 1);
			QuickSort_Recursion(a, i, end);
//			cout<<"bg:"<<begin<<" end:"<<end<<endl;
//			for(int i = begin; i <= end; i++)
//			{
//				cout<<a[i]<<" "; 
//			}
//			cout<<endl;
			return;
		}
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size);



/**
 *  @name        : void Partition(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void Partition(int *a, int begin, int end)
{
	int n, c;
	do
	{
		n = rand()%end;
	}while (n < begin || n > end);
	c = a[n];
	a[n] = a[begin];
	a[begin] = c;
	return;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max)
{
	int n[max + 1], k, temp[size + 1];
	memset(n, 0, sizeof(n));
    for (int i = 1; i <= size; i++) 
	{ 
        n[a[i]]++;
    }
    memset(temp, 0, sizeof(a));
    for (int i = 1; i <= max; i++)
    {
    	n[i] += n[i-1];
	}
    for (int i = size; i >= 1; i--)
    {
    	temp[n[a[i]]--] = a[i];
	}
    memcpy(a, temp, sizeof(temp));
    return;
} 

node *find(node *num, int a)
{
	node *p, *q;
//	cout<<"run0.1"<<endl;
	p = (node*)malloc(sizeof(node));
//	cout<<"run0.2"<<endl;
	p->data = a;
	p->next = NULL;
//	cout<<"q:"<<q<<endl;
	while (1)
	{
//		cout<<"run0.3"<<endl;
		if (num == NULL)
		{
//			cout<<"run0.1"<<endl;
			num = p;
			p->next = NULL;
//			cout<<"num:"<<num<<endl; 
//			cout<<"run0.4"<<endl;
			return num;
		}
		if (a >= q->next->data)
		{
			p->next = q->next;
			q->next = p;
//			cout<<"run0.5"<<endl;
			return num;
		}
	}
}
/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size)
{
	int n[size + 1], k, temp[size + 1], length = 1, dd;
	int d[10]={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 100000000};
	node num[10];
	for(int i = 0; i<= 9; i++)
	{
		num[i].next = NULL; 
	}
//	cout<<"run1"<<endl;
	node *p, *q;
	for (int z = 1; z <= length; z++)
	{
//		cout<<"run2"<<endl;
		for (int i = 1; i <= size; i++) 
		{
//			cout<<"run2.1"<<endl;
			if (z == 1 && a[i] / d[length - 1] != 0)
			{
//				cout<<"run2.2"<<endl;
				while (a[i] / d[length] != 0)
				{
//					cout<<"run2.3"<<endl;
					length++;
				}
//				cout<<"run2.4"<<endl;
			}
			cout<<"run2.5"<<endl;
//			cout<< a[i] / d[z - 1] % 10<<endl;
//			cout<<num[a[i] / d[z - 1] % 10].next<<endl;
			num[a[i] / d[z - 1] % 10].next = find(num[a[i] / d[z - 1] % 10].next, a[i]);
//			cout<<num[a[i] / d[z - 1] % 10].next<<endl;
//			cout<<"run2.6"<<endl;
		}
//		cout<<"run3"<<endl;
		dd = 1;
		for (int i = 0; i <= 9; i++)
		{
//			cout<<"run4"<<endl;
			p = num[i].next;
//			cout<<p<<endl;
			while (1)
			{
//				cout<<"run5"<<endl;
				if (p == NULL)
				{
					break;
				}
				q = p;
				a[dd] = p->data;
//				cout<<a[dd]<<" ";
				p = p->next;
				free(q);
			}
//			cout<<endl;
		}
	}
//		cout<<"l="<<z<<endl;
//		for (int j = 1; j <= size; j++)
//		{ 
//			cout<<a[j]<<" ";
//		}
//		cout<<endl;
//	cout<<"max_length"<<endl; 
//	cout<<length<<endl; 
	return;
} 


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size)
{
	int p0 = 1;			//��ָ��
	int p1 = size;	//βָ��
	int i = 1;
	while( i <= p1 )
	{
		//��ǰֵΪ2����βָ��p1ָ���ֵ�໥������p1��ǰ�ƶ�һλ
		//i��p0λ�ò���
		if ( a[i] == 2 )
		{
			int Temp = a[i];
			a[i] = a[p1];
			a[p1--] = Temp;
		}
		//��ǰֵΪ0������ָ��p0ָ���ֵ�໥������p0����ƶ�һλ
		//i��p0λ�ò���
		else if ( a[i] == 0 && i > p0 )
		{
			int Temp = a[i];
			a[i] = a[p0];
			a[p0++] = Temp;
		}
		//iλ�ò�Ϊ0��2��iҪ����ƶ�һλ��p0��p1λ�ò��䡣
		else
		{
			++i;
		}
	}
	return;
}


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
int findnumk(int *a,int size)
{
	cout<<"Ҫ�ҵ�k�����"<<endl;
	int k;
	cin>>k; 
	QuickSort_Recursion(a, 1, size);
	return a[k];
} 

