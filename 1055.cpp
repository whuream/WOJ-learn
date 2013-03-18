#include<stdio.h>
#include<string.h>
#include<stdint.h>


int main()
{
	char s2[200],line[205],last[15],end[]="ENDOFINPUT";
	int len,i;
	while(1)
	{
		scanf("%s",s2);
		//if(!strcmp(s,end)) break;
		//scanf("%[^\n]s",line);
		//if(strlen(s2)==10) break;
		if(s2[9]=='T') break;
		fflush(stdin);
		gets(line);
		fflush(stdin);
		scanf("%s",last);
		fflush(stdin);
		len=strlen(line);
		for(i=0;i<len;i++)
		{
			if(line[i]>='A'&&line[i]<='Z')
			{
				if(line[i]>='F')
				{
					line[i]-=5;
				}
				else
				{
					line[i]=line[i]-4+'Z'-'A';
				}
			}
		}
		printf("%s\n",line);
	}
	return 0;
}