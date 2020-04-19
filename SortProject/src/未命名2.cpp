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
    bool dd;//����״̬ 0���� 1�쳣 
	bool in_file = 0, out_file = 0;//1�ļ�����/��� 0�ֶ�����/��� 
	int d, zz = 0, n; //zz -1 �˳�
		//	system("cls");
		in_file = 1;
		if ((fp = fopen("./data_in.txt", "r")) == NULL) 			/*�ж���û���ļ�*/	
		{  
		    if ((fp = fopen("./data_in.txt", "w")) == NULL)			/*������ļ������ڣ�����һ���ļ�*/
	    	{
		        cout<<"*          �޷������ļ�            *"<<endl;
		        system("pause"); 
		        exit(0);
		    }
//			cout<<"*      �Ѵ���data_in��        *"<<endl;
		}  
		randnum(fp, 10000, 200000);
	while(1)
	{
		dd = 0;
		//	system("cls");
//		cout<<"************************************"<<endl;
//��������
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				insertSort(input, n);
				end = clock();
				cout<<"�������� 10000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				insertSort(input, n);
				end = clock();
				cout<<"�������� 50000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				insertSort(input, n);
				end = clock();
				cout<<"�������� 200000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
						cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
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
					cout<<"�������� 100*100k ����ʱ��"<<tt<<"ms"<<endl;
				}
				system("pause");
				break;				
			}
			
//�鲢����  
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				MergeSort(input, 1, n, temp); 
				end = clock();
				cout<<"�鲢���� 10000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				MergeSort(input, 1, n, temp);
				end = clock();
				cout<<"�鲢���� 50000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				MergeSort(input, 1, n, temp);
				end = clock();
				cout<<"�鲢���� 200000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
						cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
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
					cout<<"�鲢���� 100*100k ����ʱ��"<<tt<<"ms"<<endl;
				}
				system("pause");
				break;				
			}
								
//�������򣨵ݹ�棩
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				QuickSort_Recursion(input, 1, n);
				end = clock();
				cout<<"�������� 10000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				QuickSort_Recursion(input, 1, n);
				end = clock();
				cout<<"�������� 50000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				QuickSort_Recursion(input, 1, n);
				end = clock();
				cout<<"�������� 200000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
						cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
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
					cout<<"�������� 100*100k ����ʱ��"<<tt<<"ms"<<endl;
				}
				system("pause");
				break;				
			}
							
/*			case 4 ://�������򣨷ǵݹ�棩
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while(scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				void QuickSort(int *a,int size);// *  @param       : ����ָ��a�����鳤��size
				end = clock();
				cout<<"������������ʱ��"<<(end - start)<<"ms"<<endl;
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
				
//�������� 
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				CountSort(input, n , max);
				end = clock();
				cout<<"�������� 10000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				CountSort(input, n , max);
				end = clock();
				cout<<"�������� 50000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				CountSort(input, n , max);
				end = clock();
				cout<<"�������� 200000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
						cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
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
					cout<<"�������� 100*100k ����ʱ��"<<tt<<"ms"<<endl;
				}
				system("pause");
				break;				
			}
			
//������������ 
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				RadixCountSort(input, n);
				end = clock();
				cout<<"�ۼƼ������� 10000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				RadixCountSort(input, n);
				end = clock();
				cout<<"�ۼƼ������� 50000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				RadixCountSort(input, n);
				end = clock();
				cout<<"�ۼƼ������� 200000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
						cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
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
					cout<<"�ۼƼ������� 100*100k ����ʱ��"<<tt<<"ms"<<endl;
				}
				system("pause");
				break;				
			}
			
//��ɫ���� 
			{
				in_file = 1;
				if ((fp = fopen("./data_in.txt", "r")) == NULL) 			/*�ж���û���ļ�*/	
				{  
				    if ((fp = fopen("./data_in.txt", "w")) == NULL)			/*������ļ������ڣ�����һ���ļ�*/
			    	{
				        cout<<"*          �޷������ļ�            *"<<endl;
				        system("pause"); 
				        exit(0);
				    }
			//		cout<<"*      �Ѵ���data_in��        *"<<endl;
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				ColorSort(input, n);
				end = clock();
				cout<<"��ɫ���� 10000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				ColorSort(input, n);
				end = clock();
				cout<<"��ɫ���� 50000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while (scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				ColorSort(input, n);
				end = clock();
				cout<<"��ɫ���� 200000 ����ʱ��"<<(end - start)<<"ms"<<endl;
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
						cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
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
					cout<<"��ɫ���� 100*100k ����ʱ��"<<tt<<"ms"<<endl;
				}
				system("pause");
				break;				
			}
			
//�ҵ���K��/С����
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while(scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				cout<<"�����"<<findnumk(input, n)<<endl;
				end = clock();
				cout<<"��ѯ����ʱ��"<<(end - start)<<"ms"<<endl;
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
	randnum(fp,200001,50000);//200001�� 0-50000������� 
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

