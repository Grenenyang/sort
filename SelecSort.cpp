#include <iostream>
#include <vector>
using namespace std;
void my_printf(int arr[])
{
	for(int i=0;i<10;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

		
void SelecSort(int arr[])
{
	for(int j=0;j<10;j++)
	{
		int minPos=j;
		//1.找到最小的数	
		for(int i=j+1;i<10;i++)
		{
			//2.如果找到比他小的数，
			if(arr[i]<arr[minPos])
				minPos=i;
		}
		//3.把最小的数放到第一个位置
		int temp;
		temp =arr[j];
		arr[j]=arr[minPos];
		arr[minPos]=temp;
	}
	my_printf(arr);
	//return 0;
}
int main()
{
	int arr[]={9,8,7,4,1,6,5,3,2,0};
	my_printf(arr);
	SelecSort(arr);
	//my_printf(arr);
	return 0;
}