#include <iostream>
#include <vector>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
class BubbleSort
{
	
public:
	BubbleSort(vector<int>&arr) //初始化数组
	{
		srand((int)time(0));
		for (int i=0;i<1000;i++)
		{
			arr.push_back(rand());
		}
	}
	void my_printf(vector<int>arr) //遍历数组
	{
		for (int i=0;i<arr.size();i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	void swap(vector<int>&arr, int i,int j) //交换数组中两个数据位置
	{
		int temp;
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
	void bubblesort(vector<int>&arr)
	{
		for(int j=arr.size()-1; j>0; j--)
		{
			//1.两两交换，找到最大值，
			for (int i=0; i<j ; i++)
			{
				if (arr[i]>arr[i+1])
				{
					swap(arr,i,i+1);
				}
			}
		}
	}
private:
	vector<int>arr;
};
bool judge(vector<int>arr,vector<int>arr1)
{
	for (int i=0; i<arr.size(); i++)
	{
		if(arr[i] != arr1[i])
			return false;
	}
	return true;
}
int main()
{
	vector<int>arr;
	BubbleSort bs(arr);
	vector<int>arr1(arr);
	bs.bubblesort(arr);
	sort(arr1.begin(),arr1.end());
	int ret=judge(arr,arr1);
	if (ret)
	{
		cout<<"你的算法是正确的"<<endl;
	}
	else 
		cout<<"你的算法有问题"<<endl;
	return 0; 
}