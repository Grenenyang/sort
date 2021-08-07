/*2021.8.5 ————选择排序
一：

	时间复杂度     空间复杂度       稳定性
	n^2		1	       稳定
	
二：算法实现
	1.两两比较，若第一个大于第二个数，交换，将isSort标志置为false，调整边界 
	2.外层循环

总结：冒泡排序相比于选择排序，最优情况下时间复杂度可以到达n，且稳定。
*/


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
}
