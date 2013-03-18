#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

int main()
{
	list<unsigned int> data;
	while(1)
	{
		unsigned int a;
		scanf("%d",&a);
		if(a==0) break;
		data.push_back(a);
	}
	data.sort();
	list<unsigned int>::iterator end=unique(data.begin(),data.end());
	
	list<unsigned int>::itrator pointer=data.begin();
	for(;pointer!=end;pointer++) printf("%u ",*pointer);
	printf("\n");
	return 0;
}