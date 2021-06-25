#include<iostream>
using namespace std;

int sortAllArrType(void *arr1,int elesize,int len,bool(*compareFuc)(void *,void *))
{
	
	char *temp = (char*)malloc(elesize);
	for (int i = 0; i < len; i++)
	{
		int minOrmax = i;
		for (int j = i+1; j < len; j++)
		{
			char *pminOrmax = (char*)arr1 + elesize*minOrmax;
			char *pj = (char*)arr1 + elesize*j;
			
			if (compareFuc(pj,pminOrmax))
			{
				minOrmax = j;
			}
		}
		if(i!= minOrmax)
		{
			char *pi = (char*)arr1 + elesize*i;
			char *pminOrmax = (char*)arr1 + elesize*minOrmax;

			memcpy(temp, pi, elesize);
			memcpy(pi, pminOrmax, elesize);
			memcpy(pminOrmax, temp, elesize);
		}

	}
	return 0;
}

bool compareIntType(void *m, void *n)
{
	int *mm = (int*)m;
	int *nn = (int*)n;

	//<是升序，>是降序
	return *mm < *nn;
	
}
void testIntType()
{
	int arr[5] = { 2,3,1,5,4 };
	int len = sizeof(arr) / sizeof(int);
	sortAllArrType(arr, sizeof(int), len, compareIntType);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	
}


bool compareCharType(void* m,void *n)
{
	char *mm = (char*)m;
	char *nn = (char*)n;
	return *mm < *nn;
}
void testCharType()
{
	char arr[6] = "deacb";
	int len = sizeof(arr) / sizeof(char);
	sortAllArrType(arr, sizeof(char), len, compareCharType);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
}


struct Person
{
	char name[64];
	int age;
};

bool comparePersonType(void* m, void *n)
{
	struct Person *mm = (struct Person*)m;
	struct Person *nn = (struct Person*)n;
	return mm->age < nn->age;
}
void testPersonType()
{
	struct Person arr[5] =
	{
		{"张2",15},
		{ "张3",13 },
		{ "张4",12 },
		{ "张5",16 },
		{ "张6",10 },
	};
	int len = sizeof(arr) / sizeof(struct Person);
	sortAllArrType(arr, sizeof(struct Person), len, comparePersonType);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i].name << " "<<arr[i].age<<endl;
	}
}
int main()
{
	//测试整型数组
	//testIntType();

	//测试字符数组
	//testCharType();

	//测试自定义类型数组
	testPersonType();

	system("pause");
	return 0;
}