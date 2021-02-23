#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int main()
{
  int n,m,**p,i,j;

  scanf("%d",&n);
  scanf("%d",&m);

  p = malloc(n*sizeof(int *));
  if (p==NULL)
  {
  	printf ("ERROR: Malloc returned NULL");
  	return 1;
  }

  for (i=0 ; i<=n-1 ; ++i)
  {
  	p[i] = malloc (m*sizeof(int));
  	if (p[i]==NULL)
  	{
  		printf ("ERROR: Malloc returned NULL");
  		return 2;
	}
  }

  for (i=0 ; i<=n-1 ; ++i)
  {
  	for (j=0 ; j<=m-1 ; ++j)
  	{
  		scanf("%d",&p[i][j]);
	}
  }

  solve (n, m, p);


  for (i=0 ; i<=n-1 ; ++i)
	free(p[i]);
  free(p);
}
