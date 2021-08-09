#include <iostream>
#include <vector>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
class SORT
{
public:
	SORT(vector<int>&arr) //初始化数组
	{
		srand((int)time(0));
		for (int i=0;i<10;i++) 
		{
			arr.push_back(rand()%10);
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
	int doubleSearch(int lightBorder, int rightBorder , vector<int>arr, int target)
	{
		while(lightBorder<=rightBorder)
		{
			int compareIdex=(lightBorder+rightBorder)/2;
			if (arr[compareIdex] == target)
			{
				return compareIdex;
			}
			else if (arr[compareIdex]<target)
			{
				lightBorder=compareIdex-1;
			}
			else
				rightBorder=compareIdex+1;
		}
		return -1;
	}
	/*
	插入排序：时间复杂度         n^2
			  空间复杂度         1
			  稳定性              稳定
	适用于小规模数据

	*/
	void insertSort(vector<int>&arr)
	{
		int tmp,j;
		for (int i = 1;i < arr.size();i++)
		{
			tmp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = tmp;
			my_printf(arr);
		}
		/*for (int i=1; i<arr.size(); i++)
		{
			for (int j=i; j>0 && arr[j]<arr[j-1]; j-- )
			{
				swap(arr,j,j-1);交换方法
			}
		}*/
		
	}
	/*
	希尔排序：时间复杂度         n^1.3
			  空间复杂度         1
			  稳定性              稳定
	适用于中规模数据

	*/
	void shellSort(vector<int>&arr) 
	{
		
		for (int h=arr.size()/2; h>0; h/=2)
		{
			for (int i=h; i<arr.size(); i++)
			{
				for (int j=i; j>h-1 && arr[j]<arr[j-h]; j-=h )
				{
					swap(arr,j,j-h);
				}
			}
		}
	}
	/*
	选择排序：时间复杂度         n^2
			  空间复杂度         1
			  稳定性             不稳定

	*/
	void SelecSort(vector<int>arr)
	{
		for(int j=0;j<arr.size();j++)
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
		//return 0;
	}
	/*
	冒泡排序：时间复杂度         n^2
			  空间复杂度         1
			  稳定性             稳定

	*/
	void bubblesort(vector<int>&arr)
	{
		int lastExchangeIndex = 0;
		int sortBorder = arr.size() - 1;//sortBorder就是无序数列的边界。每一轮排序过程中，sortBorder之后的元素就完全不需要比较了，肯定是有序的
		for(int j=arr.size()-1; j>0; j--)
		{
			bool isSort = true;
			//1.两两交换，找到最大值，
			for (int i=0; i<sortBorder ; i++)
			{
				if (arr[i]>arr[i+1])
				{
					swap(arr,i,i+1);
					isSort = false;//利用布尔变量isSorted作为标记。如果在本轮排序中，元素有交换，则说明数列无序；如果没有元素交换，说明数列已然有序，直接跳出大循环。
					lastExchangeIndex = j;
				}
			}
			sortBorder = lastExchangeIndex;
			if(isSort)
				break;
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
	SORT bs(arr);
	vector<int>arr1(arr);
	bs.my_printf(arr1);
	bs.shellSort(arr1);
	bs.my_printf(arr1);
	sort(arr.begin(),arr.end());
	int ret=judge(arr,arr1);
	if (ret)
	{
		cout<<"你的算法是正确的"<<endl;
	}
	else 
		cout<<"你的算法有问题"<<endl;
	
	return 0; 
}
