#include<iostream>
#include<stdio.h>
using namespace std;
int main(void)
{
	if(!freopen("D://origin.txt","r",stdin))
	{
		printf("stdandard input stream reopened err!\n");
		exit(EXIT_SUCCESS);
	}
	if(!freopen("D://testdata.txt","w",stdout))
	{
	    printf("standard output stream reopened err2!\n");
		exit(EXIT_SUCCESS);
	}
	int m;//������
	int n;//������
	while(scanf("%d %d",&m,&n)!=EOF)
	{
	    printf("%d %d\n",m,n);
	    for(int i=1;i<=m;i++)
	    {
		    printf("%d ",i);
		    for(int ii=1;ii<=n;ii++)
		    {
			    int a,b;//������ʱ��
		        scanf("%d %d",&a,&b);
			    printf("(%d,%d)",b,a+1);//��������ʱ�䣬����+1
				if(ii-n)
					printf(" ");
		    }
		    printf("\n");
	    }
	    printf("-1\n");
		getchar();
	}
    fclose(stdin);
	fclose(stdout);
	return 0;
}