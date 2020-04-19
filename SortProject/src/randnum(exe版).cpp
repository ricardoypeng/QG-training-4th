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
	cout<<"请输入要生成的数据的范围[0，？]仅支持整数,且？的绝对值小于1e9"<<endl;
	cout<<"？:";
	cin>>m; 
	m++;
	cout<<endl<<"请输入要生成多少数据"<<endl;
	cout<<"数量：";
	cin>>n;
	fp = fopen("../data_in.txt", "w");
	srand((int)time(0));
    for(int x=1;x<=n;x++)
        fprintf(fp, "%d\n", (int)random(m)/1);
    cout<<"生成大成功！"<<endl; 
    return 0;
}
