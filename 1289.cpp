#include<stdio.h>
#include<string.h>

int pei(char a,char b)
{
	if((a=='A'&&b=='T')||(a=='T'&&b=='A')||(a=='C'&&b=='G')||(a=='G'&&b=='C')) return 1;
	else return 0;
}

int main()
{
	char a[55],b[55];
	while(1)
	{
		scanf("%s",a);
		if(a[0]=='#') break;
		scanf("%s",b);
		int len=strlen(a),i,num=0;
		for(i=0;i<len;i++)
		{
			if(!pei(a[i],b[i])) num++;
		}
		printf("%d\n",num);
	}
}