#include <iostream>
#include <cstdlib>
using namespace std;

void quickSort (int *arr, int low, int high)
{
	if (low >= high)
		return;

	int pivot = arr[low];
	int left = low, right = high;

	while (left < right) {
		while (left < right && arr[right] >= pivot)
			--right;
		arr[left] = arr[right];

		while (left < right && arr[left] <= pivot)
			++left;
		arr[right] = arr[left];
	}
	arr[left] = pivot;
	quickSort (arr, low, left - 1);
	quickSort (arr, left + 1, high);
}

void mergeSort_merge (int *arr, int low, int mid, int high)
{
	int *tmp = (int *) malloc (sizeof (int) * (high - low + 1));
	int i = low;
	int j = mid + 1;
	int k = 0;
	while (i <= mid || j <= high) {
		if (i <= mid && j <= high) {
			tmp[k] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
			++k;
		} else if (i <= mid) {
			tmp[k] = arr[i++];
			++k;
		} else if (j <= high) {
			tmp[k] = arr[j++];
			++k;
		}
	}
	for (int m = low; m <= high; ++m)
		arr[m] = tmp[m - low];
}
void mergeSort (int *arr, int low, int high)
{
	if (low >= high)
		return;
	if (high - low == 1) {
		if (arr[low] > arr[high]) {
			int tmp = arr[low];
			arr[low] = arr[high];
			arr[high] = tmp;
		}
		return;
	}
	int mid = (low + high) / 2;
	mergeSort (arr, low, mid);
	mergeSort (arr, mid + 1, high);
	mergeSort_merge (arr, low, mid, high);
}

void insertionSort (int *arr, int low, int high)
{
	for (int i = low + 1; i <= high; ++i) {
		int cur = arr[i];
		int j = i;
		while (j > low && arr[j - 1] > cur) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = cur;
	}
}

void bubbleSort (int *arr, int low, int high)
{
	bool swapped = false;
	int tmp = 0;
	do {
		swapped = false;
		for (int i = low + 1; i <= high; ++i) {
			if (arr[i - 1] > arr[i]) {
				tmp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = tmp;
				swapped = true;
			}
		}
	} while (swapped);
}

int main ()
{
	int t;
	cin >> t;
	//int arr[1001];
	while (t--) {
		int N;
		cin >> N;
		int *arr = new int[N];
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		quickSort (arr, 0, N - 1);
		for (int i = 0; i < N; ++i)
			cout << arr[i] << endl;
		delete[] arr;
	}
	return 0;
}