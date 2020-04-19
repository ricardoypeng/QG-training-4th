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
    bool dd;//����״̬ 0���� 1�쳣 
	bool in_file = 0, out_file = 0;//1�ļ�����/��� 0�ֶ�����/��� 
	int d, zz = 0, n; //zz -1 �˳�
    while (1)
	{
		system("cls");
		dd = 0;
		cout<<"************************************"<<endl;
		cout<<"*               ����               *"<<endl;
		cout<<"************************************"<<endl;
		cout<<"* ����������ѡ�������ַ�ʽ�������� *"<<endl;
		cout<<"*     �ļ��Ļ����û��зָ�����     *"<<endl;
		cout<<"* �ļ��Ļ������뵽ͬĿ¼��data_in  *"<<endl;
		cout<<"************************************"<<endl;
		cout<<"*     1.�ֶ�     *      2.�ļ�     *"<<endl;
		cout<<"************************************"<<endl;
		if (SHURU(&d) || (d != 1 && d != 2))//��������Ƿ�Ϸ� 
		{
			error_();
			dd = 1;
		}
		if (dd == 1)//���� ���¿�ʼ 
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
		if ((fp = fopen("./data_in.txt", "r")) == NULL) 			/*�ж���û���ļ�*/	
		{  
		    if ((fp = fopen("./data_in.txt", "w")) == NULL)			/*������ļ������ڣ�����һ���ļ�*/
	    	{
		        cout<<"*          �޷������ļ�            *"<<endl;
		        system("pause"); 
		        exit(0);
		    }
			cout<<"*      �Ѵ���data_in��        *"<<endl;
		}  
	}
	while(1)
	{
		dd = 0;
		system("cls");
		cout<<"************************************"<<endl;
		cout<<"********��ӭ��������������ϰ********"<<endl;
		cout<<"************************************"<<endl;
		cout<<"*      Ĭ������ʽΪ��С����      *"<<endl;
		cout<<"*   ��������ͬĿ¼�µ�data_out   *"<<endl;
		cout<<"*      ���֧��200000��������      *"<<endl;
		cout<<"************************************"<<endl;
		cout<<"*        1.��������                *"<<endl;
		cout<<"*        2.�鲢����                *"<<endl;
		cout<<"*        3.�������򣨵ݹ�棩      *"<<endl;
		cout<<"*        4.��������                *"<<endl;
		cout<<"*        5.������������            *"<<endl;
		cout<<"*        6.��ɫ����                *"<<endl;
		cout<<"*        7.�ҵ���K��/С����        *"<<endl;	
		cout<<"*        8.�˳�                    *"<<endl;
		cout<<"************************************"<<endl;
		cout<<"*         ����������ѡȡ           *"<<endl;
		cout<<"************************************"<<endl;
		if (SHURU(&d))//��������Ƿ�Ϸ� 
		{
			error_();
			dd = 1;
		}
		if (dd == 1)//���� ���¿�ʼ 
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
			case 1 ://��������
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
			}
			
			case 2 ://�鲢����  
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
				MergeSort(input, 1, n, temp);//����ָ��a���������begin�������յ�end����������ָ��temp
				end = clock();
				cout<<"�鲢��������ʱ��"<<(end - start)<<"ms"<<endl;
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
								
			case 3 ://�������򣨵ݹ�棩
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
				QuickSort_Recursion(input, 1, n);//��ָ��a���������begin�������յ�end
				end = clock();
				cout<<"�������򣨵ݹ�棩����ʱ��"<<(end - start)<<"ms"<<endl;
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
				
			case 4 : //�������� 
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
					cout<<"���������ݣ��ո�ָ����Ctrl+Z�������" <<endl;
					while(scanf("%d", &input[n]) != EOF)
					{
						n++;
					}
				}
				n--;
				start = clock();
				CountSort(input, n , max);//����ָ��a�����鳤��size���������ֵmax
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
			}
			
			case 5 ://������������ 
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
				RadixCountSort(input, n);//����ָ��a�����鳤��size
				end = clock();
				cout<<"����������������ʱ��"<<(end - start)<<"ms"<<endl;
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
			
			case 6 ://��ɫ���� 
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
				ColorSort(input, n);// *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
				end = clock();
				cout<<"��ɫ��������ʱ��"<<(end - start)<<"ms"<<endl;
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
			
			case 7 ://�ҵ���K��/С����
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

