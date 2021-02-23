#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int maxsummem (int n, int m, int **p, int i, int j, int **mem)
{
	int sum1,sum2,sum3,max;
  if (mem[i][j]!=0)
    return mem[i][j];
  else
  {
  	if (i==0)
  	{
        mem[i][j] = p[i][j];
        return mem[i][j];
  	}
  	else if (i>0 && j==0)
  	{
  		sum1 = maxsummem (n, m, p, i-1, m-1, mem);
  		sum2 = maxsummem (n, m, p, i-1, j, mem);
  		sum3 = maxsummem (n, m, p, i-1, j+1, mem);
  		if (sum1>=sum2 && sum1>=sum3)
      {
        mem[i][j] = p[i][j] + sum1;
  			return (p[i][j] + sum1);
      }
  		else if (sum2>=sum1 && sum2>=sum3)
      {
        mem[i][j] = p[i][j] + sum2;
  			return (p[i][j] + sum2);
      }
  		else if (sum3>=sum1 && sum3>=sum2)
      {
        mem[i][j] = p[i][j] + sum3;
  			return (p[i][j] + sum3);
      }
  	}
  	else if (i>0 && (j>0 && j<m-1))
  	{
  		sum1 = maxsummem (n, m, p, i-1, j-1, mem);
  		sum2 = maxsummem (n, m, p, i-1, j, mem);
  		sum3 = maxsummem (n, m, p, i-1, j+1, mem);
  		if (sum1>=sum2 && sum1>=sum3)
      {
        mem[i][j] = p[i][j] + sum1;
  			return (p[i][j] + sum1);
      }
  		else if (sum2>=sum1 && sum2>=sum3)
      {
        mem[i][j] = p[i][j] + sum2;
  			return (p[i][j] + sum2);
      }
  		else if (sum3>=sum1 && sum3>=sum2)
      {
        mem[i][j] = p[i][j] + sum3;
  			return (p[i][j] + sum3);
      }
  	}
  	else if (i>0 && j==m-1)
  	{
  		sum1 = maxsummem (n, m, p, i-1, j-1, mem);
  		sum2 = maxsummem (n, m, p, i-1, j, mem);
  		sum3 = maxsummem (n, m, p, i-1, 0, mem);
  		if (sum1>=sum2 && sum1>=sum3)
      {
        mem[i][j] = p[i][j] + sum1;
        return (p[i][j] + sum1);
      }
  		else if (sum2>=sum1 && sum2>=sum3)
      {
        mem[i][j] = p[i][j] + sum2;
        return (p[i][j] + sum2);
      }
  		else if (sum3>=sum1 && sum3>=sum2)
      {
        mem[i][j] = p[i][j] + sum3;
        return (p[i][j] + sum3);
      }
  	}
  }

}


///////////////////////////////////////////////////////////////////////////////////


void solve (int n, int m, int **p)
{
	int j,maxsum=0,sum,**mem,i,*path,sum1,sum2,sum3,k,test;

  mem = calloc (n,sizeof(int*));
  if (mem==NULL)
  {
    printf ("ERROR: Malloc returned NULL");
  }
  for (i=0 ; i<=n-1 ; ++i)
  {
    mem[i] = calloc (m,sizeof(int));
    if (mem[i]==NULL)
    {
      printf ("ERROR: Malloc returned NULL");
    }
  }

	printf ("Running maxsummem\n");

	for (j=0 ; j<=m-1 ; ++j)
	{
		sum = maxsummem(n,m,p,n-1,j,mem);
//		printf ("last sum = %d\n",sum);
		if (sum>maxsum)
			maxsum=sum;
	}
/*	for (i=0 ; i<=n-1 ; ++i)
	{
		for (j=0 ; j<=m-1 ; ++j)
			printf ("%d ",mem[i][j]);
		printf("\n");
	}
*/

	#ifdef PATH

	path = malloc (n*sizeof(int));
	path[n-1] = p[n-1][k];
	for (i=n-1 ; i>=1 ; --i)
	{
		if (k==0)
		{
			sum1=mem[i-1][m-1];
			sum2=mem[i-1][k];
			sum3=mem[i-1][k+1];
			if (sum1>=sum2 && sum1>=sum3)
			{
				path[i-1]=p[i-1][m-1];
				k=m-1;
			}
			else if (sum2>=sum1 && sum2>=sum3)
			{
				path[i-1]=p[i-1][k];
			}
			else if (sum3>=sum1 && sum3>=sum2)
			{
				path[i-1]=p[i-1][k+1];
				++k;
			}
		}
		else if (k==m-1)
		{
			sum1=mem[i-1][k-1];
			sum2=mem[i-1][k];
			sum3=mem[i-1][0];
			if (sum1>=sum2 && sum1>=sum3)
			{
				path[i-1]=p[i-1][k-1];
				--k;
			}
			else if (sum2>=sum1 && sum2>=sum3)
			{
				path[i-1]=p[i-1][k];
			}
			else if (sum3>=sum1 && sum3>=sum2)
			{
				path[i-1]=p[i-1][0];
				k=0;
			}
		}
		else
		{
			sum1=mem[i-1][k-1];
			sum2=mem[i-1][k];
			sum3=mem[i-1][k+1];
			if (sum1>=sum2 && sum1>=sum3)
			{
				path[i-1]=p[i-1][k-1];
				--k;
			}
			else if (sum2>=sum1 && sum2>=sum3)
			{
				path[i-1]=p[i-1][k];
			}
			else if (sum3>=sum1 && sum3>=sum2)
			{
				path[i-1]=p[i-1][k+1];
				++k;
			}
		}
	}
	#endif

  for (i=0 ; i<=n-1 ; ++i)
	 free(mem[i]);
  free(mem);

	printf ("Max sum is %d\n",maxsum);

	#ifdef PATH
	test=0;
	for (i=0 ; i<=n-1 ; ++i)
	{
		test += path[i];
		if (i==n-1)
			printf("%d\n",path[i]);
		else
			printf("%d -> ",path[i]);
	}
	printf("test = %d\n",test);

	free(path);
	#endif
}
