#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int maxsumrec (int n, int m, int **p, int i, int j)
{
	int sum1,sum2,sum3,max;
	if (i==0)
	{
		return p[i][j];

	}
	else if (i>0 && j==0)
	{
		sum1 = maxsumrec (n, m, p, i-1, m-1);
		sum2 = maxsumrec (n, m, p, i-1, j);
		sum3 = maxsumrec (n, m, p, i-1, j+1);
		if (sum1>=sum2 && sum1>=sum3)
			return (p[i][j] + sum1);
		else if (sum2>=sum1 && sum2>=sum3)
			return (p[i][j] + sum2);
		else if (sum3>=sum1 && sum3>=sum2)
			return (p[i][j] + sum3);
	}
	else if (i>0 && (j>0 && j<m-1))
	{
		sum1 = maxsumrec (n, m, p, i-1, j-1);
		sum2 = maxsumrec (n, m, p, i-1, j);
		sum3 = maxsumrec (n, m, p, i-1, j+1);
		if (sum1>=sum2 && sum1>=sum3)
			return (p[i][j] + sum1);
		else if (sum2>=sum1 && sum2>=sum3)
			return (p[i][j] + sum2);
		else if (sum3>=sum1 && sum3>=sum2)
			return (p[i][j] + sum3);
	}
	else if (i>0 && j==m-1)
	{
		sum1 = maxsumrec (n, m, p, i-1, j-1);
		sum2 = maxsumrec (n, m, p, i-1, j);
		sum3 = maxsumrec (n, m, p, i-1, 0);
		if (sum1>=sum2 && sum1>=sum3)
			return (p[i][j] + sum1);
		else if (sum2>=sum1 && sum2>=sum3)
			return (p[i][j] + sum2);
		else if (sum3>=sum1 && sum3>=sum2)
			return (p[i][j] + sum3);
	}
}



void solve (int n, int m, int **p)
{
	int j,maxsum=0,sum;
	printf ("Running maxsumrec\n");
	for (j=0 ; j<=m-1 ; ++j)
	{
		sum = maxsumrec(n,m,p,n-1,j);
		if (sum>maxsum)
			maxsum=sum;
	}
	printf ("Max sum is %d\n",maxsum);
}
