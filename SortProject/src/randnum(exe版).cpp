#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define random(x) (rand()%x)
int main()
{
	FILE *fp;
	int n, m;
	cout<<"������Ҫ���ɵ����ݵķ�Χ[0����]��֧������,�ң��ľ���ֵС��1e9"<<endl;
	cout<<"��:";
	cin>>m; 
	m++;
	cout<<endl<<"������Ҫ���ɶ�������"<<endl;
	cout<<"������";
	cin>>n;
	fp = fopen("../data_in.txt", "w");
	srand((int)time(0));
    for(int x=1;x<=n;x++)
        fprintf(fp, "%d\n", (int)random(m)/1);
    cout<<"���ɴ�ɹ���"<<endl; 
    return 0;
}
