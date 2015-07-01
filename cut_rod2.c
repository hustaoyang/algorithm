#include<stdio.h>

int memorized_cut_rod(int *p, int n);
int max(int a, int b);

int main()
{
    int p[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int k;
    for(k = 0; k< 10; k++)
	printf("%d\n", memorized_cut_rod(p,k)); 

    return 0;
}

int max(a, b)
{
    return a>b ? a:b;
}

int memorized_cut_rod(p, n)
{
    int i;
    int r[n];
    for (i = 0; i < n; i++)
	r[i] = -1;    // every price isn't < 0


    int j;
    int q = -1;
    for( i = 0; i < n ;i++)
    {
	for (j = 0; j < i; j++)
	    q = max(q, p[j] + r[i - j -1]);
        r[i] = q;
    }   
	
    return r[n-1];
}
