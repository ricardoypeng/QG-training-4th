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
int main()
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
    clock_t start, end, tt; 	
    FILE *fp, *fq;
    bool dd;//运行状态 0正常 1异常 
	bool in_file = 0, out_file = 0;//1文件输入/输出 0手动输入/输出 
	int d, zz = 0, n; //zz -1 退出
		//	system("cls");
		in_file = 1;
		if ((fp = fopen("./data_in.txt", "r")) == NULL) 			/*判断有没有文件*/	
		{  
		    if ((fp = fopen("./data_in.txt", "w")) == NULL)			/*如果此文件不存在，创建一个文件*/
	    	{
		        cout<<"*          无法创建文件            *"<<endl;
		        system("pause"); 
		        exit(0);
		    }
//			cout<<"*      已创建data_in！        *"<<endl;
		}  
		randnum(fp, 10000, 200000);
	while(1)
	{
		dd = 0;
		//	system("cls");
//		cout<<"************************************"<<endl;
//插入排序
			{
				system("cls");
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=10000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				cout<<"插入排序 10000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=50000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				cout<<"插入排序 50000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=200000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				cout<<"插入排序 200000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				tt = 0;
				for(int zzz = 1 ;zzz<=100000;zzz++)
				{
					n = 1;
					memset(input, 0, sizeof(input));
					if (in_file)
					{
						fp = fopen("./data_in.txt", "r");
						for(int i = 1;i<=100;i++)
						{
							fscanf(fp, "%d", &input[n]);
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
					tt+=end-start;
					fq = fopen("./data_out.txt", "w");
					for (int i = 1; i <= n; i++)
					{
						if (i != n)
							fprintf(fq, "%d ", input[i]);
						else
							fprintf(fq, "%d\n", input[i]);
					}
					fclose(fq);
					cout<<"插入排序 100*100k 总用时："<<tt<<"ms"<<endl;
				}
				system("pause");
				break;				
			}
			
//归并排序  
			{
				system("cls");
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=10000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				MergeSort(input, 1, n, temp); 
				end = clock();
				cout<<"归并排序 10000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=50000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				MergeSort(input, 1, n, temp);
				end = clock();
				cout<<"归并排序 50000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=200000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				MergeSort(input, 1, n, temp);
				end = clock();
				cout<<"归并排序 200000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				tt = 0;
				for(int zzz = 1 ;zzz<=100000;zzz++)
				{
					n = 1;
					memset(input, 0, sizeof(input));
					if (in_file)
					{
						fp = fopen("./data_in.txt", "r");
						for(int i = 1;i<=100;i++)
						{
							fscanf(fp, "%d", &input[n]);
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
					MergeSort(input, 1, n, temp); 
					end = clock();
					tt+=end-start;
					fq = fopen("./data_out.txt", "w");
					for (int i = 1; i <= n; i++)
					{
						if (i != n)
							fprintf(fq, "%d ", input[i]);
						else
							fprintf(fq, "%d\n", input[i]);
					}
					fclose(fq);
					cout<<"归并排序 100*100k 总用时："<<tt<<"ms"<<endl;
				}
				system("pause");
				break;				
			}
								
//快速排序（递归版）
			{
				system("cls");
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=10000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				QuickSort_Recursion(input, 1, n);
				end = clock();
				cout<<"快速排序 10000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=50000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				QuickSort_Recursion(input, 1, n);
				end = clock();
				cout<<"快速排序 50000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=200000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				QuickSort_Recursion(input, 1, n);
				end = clock();
				cout<<"快速排序 200000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				tt = 0;
				for(int zzz = 1 ;zzz<=100000;zzz++)
				{
					n = 1;
					memset(input, 0, sizeof(input));
					if (in_file)
					{
						fp = fopen("./data_in.txt", "r");
						for(int i = 1;i<=100;i++)
						{
							fscanf(fp, "%d", &input[n]);
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
					QuickSort_Recursion(input, 1, n);
					end = clock();
					tt+=end-start;
					fq = fopen("./data_out.txt", "w");
					for (int i = 1; i <= n; i++)
					{
						if (i != n)
							fprintf(fq, "%d ", input[i]);
						else
							fprintf(fq, "%d\n", input[i]);
					}
					fclose(fq);
					cout<<"快速排序 100*100k 总用时："<<tt<<"ms"<<endl;
				}
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
				
//计数排序 
			{
				system("cls");
				n = 1;
				int max;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=10000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				CountSort(input, n , max);
				end = clock();
				cout<<"计数排序 10000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=50000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				CountSort(input, n , max);
				end = clock();
				cout<<"记数排序 50000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=200000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				CountSort(input, n , max);
				end = clock();
				cout<<"记数排序 200000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				tt = 0;
				for(int zzz = 1 ;zzz<=100000;zzz++)
				{
					n = 1;
					memset(input, 0, sizeof(input));
					if (in_file)
					{
						fp = fopen("./data_in.txt", "r");
						for(int i = 1;i<=100;i++)
						{
							fscanf(fp, "%d", &input[n]);
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
					CountSort(input, n , max);
					end = clock();
					tt+=end-start;
					fq = fopen("./data_out.txt", "w");
					for (int i = 1; i <= n; i++)
					{
						if (i != n)
							fprintf(fq, "%d ", input[i]);
						else
							fprintf(fq, "%d\n", input[i]);
					}
					fclose(fq);
					cout<<"记数排序 100*100k 总用时："<<tt<<"ms"<<endl;
				}
				system("pause");
				break;				
			}
			
//基数计数排序 
			{
				system("cls");
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=10000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				RadixCountSort(input, n);
				end = clock();
				cout<<"累计计数排序 10000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=50000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				RadixCountSort(input, n);
				end = clock();
				cout<<"累计记数排序 50000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=200000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				RadixCountSort(input, n);
				end = clock();
				cout<<"累计记数排序 200000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				tt = 0;
				for(int zzz = 1 ;zzz<=100000;zzz++)
				{
					n = 1;
					memset(input, 0, sizeof(input));
					if (in_file)
					{
						fp = fopen("./data_in.txt", "r");
						for(int i = 1;i<=100;i++)
						{
							fscanf(fp, "%d", &input[n]);
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
					RadixCountSort(input, n);
					end = clock();
					tt+=end-start;
					fq = fopen("./data_out.txt", "w");
					for (int i = 1; i <= n; i++)
					{
						if (i != n)
							fprintf(fq, "%d ", input[i]);
						else
							fprintf(fq, "%d\n", input[i]);
					}
					fclose(fq);
					cout<<"累计记数排序 100*100k 总用时："<<tt<<"ms"<<endl;
				}
				system("pause");
				break;				
			}
			
//颜色排序 
			{
				in_file = 1;
				if ((fp = fopen("./data_in.txt", "r")) == NULL) 			/*判断有没有文件*/	
				{  
				    if ((fp = fopen("./data_in.txt", "w")) == NULL)			/*如果此文件不存在，创建一个文件*/
			    	{
				        cout<<"*          无法创建文件            *"<<endl;
				        system("pause"); 
				        exit(0);
				    }
			//		cout<<"*      已创建data_in！        *"<<endl;
				}  
				randnum(fp, 2, 200000);
				system("cls");
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=10000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				ColorSort(input, n);
				end = clock();
				cout<<"颜色排序 10000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=50000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				ColorSort(input, n);
				end = clock();
				cout<<"颜色排序 50000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				n = 1;
				memset(input, 0, sizeof(input));
				if (in_file)
				{
					fp = fopen("./data_in.txt", "r");
					for(int i = 1;i<=200000;i++)
					{
						fscanf(fp, "%d", &input[n]);
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
				ColorSort(input, n);
				end = clock();
				cout<<"颜色排序 200000 总用时："<<(end - start)<<"ms"<<endl;
				fq = fopen("./data_out.txt", "w");
				for (int i = 1; i <= n; i++)
				{
					if (i != n)
						fprintf(fq, "%d ", input[i]);
					else
						fprintf(fq, "%d\n", input[i]);
				}
				fclose(fq);
				
				tt = 0;
				for(int zzz = 1 ;zzz<=100000;zzz++)
				{
					n = 1;
					memset(input, 0, sizeof(input));
					if (in_file)
					{
						fp = fopen("./data_in.txt", "r");
						for(int i = 1;i<=100;i++)
						{
							fscanf(fp, "%d", &input[n]);
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
					ColorSort(input, n);
					end = clock();
					tt+=end-start;
					fq = fopen("./data_out.txt", "w");
					for (int i = 1; i <= n; i++)
					{
						if (i != n)
							fprintf(fq, "%d ", input[i]);
						else
							fprintf(fq, "%d\n", input[i]);
					}
					fclose(fq);
					cout<<"颜色排序 100*100k 总用时："<<tt<<"ms"<<endl;
				}
				system("pause");
				break;				
			}
			
//找到第K大/小的数
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

