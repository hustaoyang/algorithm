#include<stdio.h>

int max(int a, int b);
int cut_rod(int *c, int n);

//int q = -1;

int main()
{
 //   int p = -1;
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    //cut_rod(p, 10);

    int k;
    for(k = 1; k <=10;k++)
	printf("%d\n", cut_rod(p, k));
    return 0;
}

max(int a, int b)
{

    return a>b ? a:b;
}

int cut_rod(int *c, int n)
{
    if (n <= 0)
	return 0;
    int q = -1;
    int i;
    for (i = 0;i < n;i++)
	q = max(q, c[i] + cut_rod(c, n-i-1)); 

    return q;   
}

