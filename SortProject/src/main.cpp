#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include "../inc/qgsort.h"
#include "../inc/randnum.h"
#include "../inc/tool.h"
using namespace std;
//const time_t qixian=30*24*60*60;
int input[200010]={0}, temp[200010]={0};
int main1()
{
/*	time_t timer;
    struct tm *tblock;
    timer = time(NULL);
    tblock = localtime(&timer);
    printf("Local time is: %s", asctime(tblock));
    timer+=qixian;
    tblock = localtime(&timer);
    printf("Huanshu time is: %s", asctime(tblock));
    return 0;*/
    clock_t start, end; 	
    FILE *fp, *fq;
    bool dd;//运行状态 0正常 1异常 
	bool in_file = 0, out_file = 0;//1文件输入/输出 0手动输入/输出 
	int d, zz = 0, n; //zz -1 退出
    while (1)
	{
		system("cls");
		dd = 0;
		cout<<"************************************"<<endl;
		cout<<"*               警告               *"<<endl;
		cout<<"************************************"<<endl;
		cout<<"* 请输入数字选择用哪种方式输入数据 *"<<endl;
		cout<<"*     文件的话请用换行分割数据     *"<<endl;
		cout<<"* 文件的话请输入到同目录的data_in  *"<<endl;
		cout<<"************************************"<<endl;
		cout<<"*     1.手动     *      2.文件     *"<<endl;
		cout<<"************************************"<<endl;
		if (SHURU(&d) || (d != 1 && d != 2))//检测输入是否合法 
		{
			error_();
			dd = 1;
		}
		if (dd == 1)//出错 重新开始 
		{
			continue;
		}
		if (d==2)
		{
			in_file = 1;
		}
		else
		{
			in_file = 0;
		}
		break;
	}
	if (d==2) 
	{
		if ((fp = fopen("./data_in.txt", "r")) == NULL) 			/*判断有没有文件*/	
		{  
		    if ((fp = fopen("./data_in.txt", "w")) == NULL)			/*如果此文件不存在，创建一个文件*/
	    	{
		        cout<<"*          无法创建文件            *"<<endl;
		        system("pause"); 
		        exit(0);
		    }
			cout<<"*      已创建data_in！        *"<<endl;
		}  
	}
	while(1)
	{
		dd = 0;
		system("cls");
		cout<<"************************************"<<endl;
		cout<<"********欢迎来到整数排序练习********"<<endl;
		cout<<"************************************"<<endl;
		cout<<"*      默认排序方式为从小到大      *"<<endl;
		cout<<"*   结果输出到同目录下的data_out   *"<<endl;
		cout<<"*      最多支持200000个数排序      *"<<endl;
		cout<<"************************************"<<endl;
		cout<<"*        1.插入排序                *"<<endl;
		cout<<"*        2.归并排序                *"<<endl;
		cout<<"*        3.快速排序（递归版）      *"<<endl;
		cout<<"*        4.计数排序                *"<<endl;
		cout<<"*        5.基数计数排序            *"<<endl;
		cout<<"*        6.颜色排序                *"<<endl;
		cout<<"*        7.找到第K大/小的数        *"<<endl;	
		cout<<"*        8.退出                    *"<<endl;
		cout<<"************************************"<<endl;
		cout<<"*         输入数字来选取           *"<<endl;
		cout<<"************************************"<<endl;
		if (SHURU(&d))//检测输入是否合法 
		{
			error_();
			dd = 1;
		}
		if (dd == 1)//出错 重新开始 
		{
			continue;
		} 	
		if (d == 8)
		{
			zz = -1;
			break;
		}
		switch (d)
		{
			case 1 ://插入排序
			{
				system("cls");
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					while (fscanf(fp, "%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				else
				{
					cout<<"请输入数据，空格分割，并用Ctrl+Z结束输出" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				insertSort(input, n);
				end = clock();
				cout<<"插入排序总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				system("pause");
				break;				
			}
			
			case 2 ://归并排序  
			{
				system("cls");
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					while(fscanf(fp, "%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				else
				{
					cout<<"请输入数据，空格分割，并用Ctrl+Z结束输出" <<endl;
					while(scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				MergeSort(input, 1, n, temp);//数组指针a，数组起点begin，数组终点end，承载数组指针temp
				end = clock();
				cout<<"归并排序总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				system("pause");
				break;
			}
								
			case 3 ://快速排序（递归版）
			{
				system("cls");
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					while(fscanf(fp, "%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				else
				{
					cout<<"请输入数据，空格分割，并用Ctrl+Z结束输出" <<endl;
					while(scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				QuickSort_Recursion(input, 1, n);//组指针a，数组起点begin，数组终点end
				end = clock();
				cout<<"快速排序（递归版）总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				system("pause");
				break;	
			}
							
/*			case 4 ://快速排序（非递归版）
			{
				system("cls");
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					while(fscanf(fp, "%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				else
				{
					cout<<"请输入数据，空格分割，并用Ctrl+Z结束输出" <<endl;
					while(scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				void QuickSort(int *a,int size);// *  @param       : 数组指针a，数组长度size
				end = clock();
				cout<<"插入排序总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				system("pause");
				break;
			}*/
				
			case 4 : //计数排序 
			{
				system("cls");
				n = 1;
				int max = 0;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					while(fscanf(fp, "%d", &input[n]) != EOF)
					{
						if(input[n] > max)
						{
							max = input[n];
						}
						n++;
					}
				}
				else
				{
					cout<<"请输入数据，空格分割，并用Ctrl+Z结束输出" <<endl;
					while(scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				CountSort(input, n , max);//数组指针a，数组长度size，数组最大值max
				end = clock();
				cout<<"计数排序总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				system("pause");
				break;
			}
			
			case 5 ://基数计数排序 
			{
				system("cls");
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					while(fscanf(fp, "%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				else
				{
					cout<<"请输入数据，空格分割，并用Ctrl+Z结束输出" <<endl;
					while(scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				RadixCountSort(input, n);//数组指针a，数组长度size
				end = clock();
				cout<<"基数计数排序总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				system("pause");
				break;
			}
			
			case 6 ://颜色排序 
			{
				system("cls");
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					while(fscanf(fp, "%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				else
				{
					cout<<"请输入数据，空格分割，并用Ctrl+Z结束输出" <<endl;
					while(scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				ColorSort(input, n);// *  @param       : 数组指针a（只含0，1，2元素），数组长度size
				end = clock();
				cout<<"颜色排序总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				system("pause");
				break;
			}
			
			case 7 ://找到第K大/小的数
			{
				system("cls");
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					while(fscanf(fp, "%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				else
				{
					cout<<"请输入数据，空格分割，并用Ctrl+Z结束输出" <<endl;
					while(scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				cout<<"结果："<<findnumk(input, n)<<endl;
				end = clock();
				cout<<"查询总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				system("pause");
				break;
			}
			
			default : 
			{
				error_();
				break;
			}
		}
	}
	system("pause");
	return 0;
}
/*
	randnum(fp,200001,50000);//200001个 0-50000的随机数 
	int n = 1,num=0;
    for (int i = 1; i<=10000; i++) 
    {
    	fscanf(fp, "%d", &input[i]);
    	n=i;
	}
    fclose(fp);	
    
    insertSort(input, n);
	for (int i = 1; i <= n; i++)
	{
		if (i != n)
			fprintf(fq, "%d ", input[i]);
		else
			fprintf(fq, "%d\n", input[i]);
	}
	fclose(fq);
    return 0;
}*/ 

