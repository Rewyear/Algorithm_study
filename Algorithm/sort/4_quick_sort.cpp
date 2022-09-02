#include <bits/stdc++.h>
using namespace std;

void my_swap(int *x, int *y)
{
	int tmp;

	tmp = *y;
	*y  = *x;
	*x = tmp;
}

/* 퀵 정렬 */
void quick_sort(int arr[], int start, int end)
{
	if(start >= end) // 퀵 정렬을 해야하는 원소가 1개인 경우
		return;

	int pivot = start;
	int i=start+1, j=end;

	while(i <= j) // 시작 index와 끝 index가 교차하기 이전까지
	{
		while(arr[i] < arr[pivot] && i <= end) { // start에서 pivot 보다 큰 값을 찾을 때까지 index 이동(end 까지만)
			i++;
		}

		while(arr[j] > arr[pivot] && j > start){ // end에서 pivot보다 작은 값을 찾을 때까지 index 이동
			j--;
		}

		if(i > j) /* index 간 교차가 일어난, 즉, 시작점 인덱스보다 끝점 인덱스가 작은 경우 */
			my_swap(&arr[pivot], &arr[j]);
		else /* start에서 pivot 보다 큰 값을 찾고, end에서 pivot보다 작은 값을 찾았을 때 swap */
			my_swap(&arr[i], &arr[j]);
		}

		// 옮긴 pivot 기준으로 분할하여 정복
		quick_sort(arr, start, j-1);
		quick_sort(arr, j+1, end);

	}
}

int ary[10] = { 1, 10 ,5, 3, 8, 7, 6, 4, 2, 9};
int cnt = sizeof(ary) / sizeof(ary[0]);

int main()
{
    quick_sort(ary,cnt-1);

    for(int i=0; i<10; i++)
    {
        cout << ary[i] << ' ';
    }

}
