#include<list>
#include<string>
#include<algorithm>

#include<stdio.h>

using namespace std;

int main()
{
	int test_case;
	scanf("%d",&test_case);
	for(int _test_case=0;_test_case<test_case;++_test_case)
	{
		int op_case;
		list<string> person;
		scanf("%d",&op_case);
		for(int _op_case=0;_op_case<op_case;++_op_case)
		{
			int operation,position;
			char name[20];
			scanf("%d%s",&operation,name);
			if(1==operation)
			{
				scanf("%d",&position);
				list<string>::iterator it=person.begin();
				for(int _position=0;_position<position;++_position)
				{
					it++;
				}
				person.insert(it,name);
			}
			else
			{
				list<string>::iterator it;
				it=find(person.begin(),person.end(),name);
				person.erase(it);
			}
		}
		list<string>::iterator it=person.begin();
		for(;it!=person.end();++it)
		{
			printf("%s\n",it->c_str());
		}
	}
	return 0;
}