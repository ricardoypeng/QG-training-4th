#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "../inc/randnum.h"
using namespace std;
#define random(x) (rand()%x)
void randnum(FILE *fp, int n, int m)
{
	fp = fopen("./data_in.txt", "w");
	srand((int)time(0));
    for(int x=0;x<=n;x++)
        fprintf(fp, "%d\n", (int)random(m)/1);
    return;
}
