#include<stdio.h>
#include<string.h>

int suit(char a,char b)
{
	if(a=='{'&&b=='}') return 1;
	if(a=='('&&b==')') return 1;
	if(a=='['&&b==']') return 1;
	return 0;
}

int main()
{
	int N,i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		char a[1005],b[1005],loop=0;
		b[0]='#';

		scanf("%s",a);

		int la=strlen(a),j;

		for(j=0;j<la;j++)
		{
			if(a[j]=='{'||a[j]=='}'||a[j]=='('||a[j]==')'||a[j]=='['||a[j]==']')
			{
				if(!suit(b[loop],a[j]))
				{
					loop++;
					b[loop]=a[j];
				}
				else loop--;
			}
		}
		if(loop==0) printf("Case %d: Legal\n",i+1);
		else printf("Case %d: Illegal\n",i+1);
	}
	return 0;
}