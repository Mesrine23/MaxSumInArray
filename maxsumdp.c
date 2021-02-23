#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

void solve (int n, int m, int **p)
{
	int j,maxsum,**dp,i,k,sum1,sum2,sum3,*path,test;

  dp = calloc (n,sizeof(int*));
  if (dp==NULL)
  {
    printf ("ERROR: Calloc returned NULL");
  }
  for (i=0 ; i<=n-1 ; ++i)
  {
    dp[i] = calloc (m,sizeof(int));
    if (dp[i]==NULL)
    {
      printf ("ERROR: Calloc returned NULL");
    }
  }

	printf ("Running maxsumdp\n");

  for (j=0 ; j<=m-1 ; ++j)
    dp[0][j] = p[0][j];

  for (i=1 ; i<=n-1 ; ++i)
	{
		for (j=0 ; j<=m-1 ; ++j)
		{
			if (j-1<0)
      {
        sum1 = p[i][j] + dp[i-1][m-1];
        sum2 = p[i][j] + dp[i-1][j];
        sum3 = p[i][j] + dp[i-1][j+1];
      }
      else if (j+1>m-1)
      {
        sum1 = p[i][j] + dp[i-1][j-1];
        sum2 = p[i][j] + dp[i-1][j];
        sum3 = p[i][j] + dp[i-1][0];
      }
      else
      {
        sum1 = p[i][j] + dp[i-1][j-1];
        sum2 = p[i][j] + dp[i-1][j];
        sum3 = p[i][j] + dp[i-1][j+1];
      }

      if (sum1>=sum2 && sum1>=sum3)
        dp[i][j] = sum1;
      else if (sum2>=sum1 && sum2>=sum3)
        dp[i][j] = sum2;
      else
        dp[i][j] = sum3;
		}
	}


	k=0;
  maxsum=dp[n-1][0];
  for (j=1 ; j<=m-1 ; ++j)
  {
    if (dp[n-1][j] > maxsum)
		{
      maxsum = dp[n-1][j];
			k=j;
		}
  }

	#ifdef PATH

	path = malloc (n*sizeof(int));
	path[n-1] = p[n-1][k];
	for (i=n-1 ; i>=1 ; --i)
	{
		if (k==0)
		{
			sum1=dp[i-1][m-1];
			sum2=dp[i-1][k];
			sum3=dp[i-1][k+1];
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
			sum1=dp[i-1][k-1];
			sum2=dp[i-1][k];
			sum3=dp[i-1][0];
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
			sum1=dp[i-1][k-1];
			sum2=dp[i-1][k];
			sum3=dp[i-1][k+1];
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
	 free(dp[i]);
  free(dp);

	printf ("Max sum is %d\n",maxsum);

	#ifdef PATH
//	test=0;
	for (i=0 ; i<=n-1 ; ++i)
	{
//		test += path[i];
		if (i==n-1)
			printf("%d\n",path[i]);
		else
			printf("%d -> ",path[i]);
	}
//	printf("test = %d\n",test);

	free(path);
	#endif
}
