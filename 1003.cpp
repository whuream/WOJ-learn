#include<stdio.h>
#include<string.h>

typedef struct
{
	char name[15];
	int age;
	int tree;
}person;

int main()
{
	person a[13]={
		{"Adam",930,1},
		{"Seth",912,2},
		{"Enosh",905,3},
		{"Kenan",910,4},
		{"Mahalalel",895,5},
		{"Jared",962,6},
		{"Enoch",365,7},
		{"Methuselah",969,8},
		{"Lamech",777,9},
		{"Noah",-1,10},
		{"Shem",-1,11},
		{"Ham",-1,11},
		{"Japheth",-1,11},
	};
	person a1,a2;
	int i;
	while(scanf("%s %s",a1.name,a2.name)!=EOF)
	{
		for(i=0;i<13;i++)
		{
			if(!strcmp(a1.name,a[i].name))
			{
				a1.age=a[i].age;
				a1.tree=a[i].tree;
			}
			if(!strcmp(a2.name,a[i].name))
			{
				a2.age=a[i].age;
				a2.tree=a[i].tree;
			}
		}
		if(a1.tree<a2.tree) printf("Yes\n");
		else printf("No\n");
		if(a1.age==-1||a2.age==-1) printf("No enough information\n");
		else if(a1.age>a2.age) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}