#include <iostream>
using namespace std;

int sequentialSearch(const int a[], int item, int n){
	int i;
	for (i = 0; i < n && a[i]!= item; i++);
	if (i == n) {
		return -1;
	}
	return i;
}

void bubSort(int a[], int size) {
	int counter = 0;
	while(counter <= size) {
		for(int i=0; i<size-1; i++) {
			if(a[i]>a[i+1]) {
				swap(a[i],a[i+1]);
			}
		}
		counter++;
	}
	
}

void insSort(int a[], int size) {
	for(int i=0; i<size; i++) {
		for(int j=i; j>0; j--) {
			if(a[j] < a[j-1])
				swap(a[j],a[j-1]);
		}
	}
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int size;

void mSort(int array[], int left, int mid, int right)
{
	int temp[size+1];
	int l1 = left;
	int r1 = mid;
	int l2 = mid+1;
	int r2 = right;
	int index = left;

	for(; l1<=r1 && l2<=r2; index++)
	{
		if(array[l1] < array[l2])
			temp[index] = array[l1++];
		else
			temp[index] = array[l2++];
	}

	for(; l1<=r1; index++)
	{
		temp[index] = array[l1++];
	}

	for (; l2<=r2; index++)
	{
		temp[index] = array[l2++];
	}

	for(index=left; index<=right; index++)
	{
		array[index] = temp[index];
	}
}

void mergeS(int array[], int left, int right) {
	size = right;

	if(left<right)
	{
		int mid = (left+right)/2;
		mergeS(array, left,mid);
		mergeS(array, mid+1, right);

		mSort(array, left, mid, right);
	}
}

int findMax(int array[], int size) {
	int max = array[0];
	for(int i=0; i<size; i++) {
		if(array[i] > max) max = array[i]; 
	}
	return max;
}

void countingSort(int array[], int size) {
	int max = findMax(array, size);
	int tempArray[max+1];
	int result[size];
	for(int i=0; i<max+1; i++) {
		tempArray[i] = 0;
	}
	for(int j=0; j<size; j++) {
		tempArray[array[j]] ++;
	}
	for(int k=0; k<max+1; k++) {
		tempArray[k+1] += tempArray[k];
	}
	for(int l=size-1; l>=0; l--) {
		result[tempArray[array[l]]-1] = array[l];
		tempArray[array[l]]--;
	}
	for(int i=0; i<size; i++) {
		array[i] = result[i];
	}
}


int binarySearch(const int a[], int item, int n) {
	int first = 0;
	int last = n - 1;
	while(first <= last) {
		int mid = (first+last)/2;
		if(item > a[mid]) { 
			first = mid + 1; 
		}
		else if (item < a[mid]) {
			last = mid - 1;
		}
		else
			return mid;
	}
}


void selectionSort(int a[], int n) {
	int i;
	int j;
	int temp;
	for(i=0; i<n-1; i++) {
		int min = i;
		for(j=i+1; j<n; j++) {
			if(a[min]>a[j])
				min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

int main() {
	int a[12] = {5,321432,324,23,33247,9879,87,978,3423,4324,234,3};
	cout << sequentialSearch(a,3,12) << endl;
	int b[10] = {1,2,3,4,5,6,7,8,9,10};
	cout << binarySearch(b,8,10) << endl;
	int c[5] = {5,8,3,2,9};
	selectionSort(c,5);
	for(int i=0; i<5; i++) {
		cout << c[i] << ",";
	}
	cout << "\n";
	return 0;
}