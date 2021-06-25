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

	//<������>�ǽ���
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
		{"��2",15},
		{ "��3",13 },
		{ "��4",12 },
		{ "��5",16 },
		{ "��6",10 },
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
	//������������
	//testIntType();

	//�����ַ�����
	//testCharType();

	//�����Զ�����������
	testPersonType();

	system("pause");
	return 0;
}