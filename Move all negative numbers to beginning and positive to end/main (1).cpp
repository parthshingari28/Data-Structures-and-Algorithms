#include <iostream>
using namespace std;
void rearrange(int arr[], int n)
{
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			if (i != j)
				swap(arr[i], arr[j]);
			j++;
		}
	}
}
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
int main()
{
	int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<"Input : ";
	printArray(arr, n);
	cout<<endl<<"After Sorting : ";
	rearrange(arr, n);
	printArray(arr, n);
	cout<<endl<<"Time Complexicity : O(n)"<<endl;
	cout<<"Space Complexicity : O(1)";
	return 0;
}
