#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int lstart, int lend, int rstart, int rend)
{
	int i = lstart;
	int j = rstart;

	int tmp[10]={0,}; // 임시 저장 배열
	int tmpIdx = 0; // 임시 저장 배열의 인덱스

	while(i <= lend && j <= rend) // 왼쪽 배열과 오른쪽 배열을 비교해 나아가면서
	{
		if(arr[i] <= arr[j]) // 최소 값을 찾아 임시 배열에 삽입하여 정렬
			tmp[tmpIdx++] = arr[i++];
		else
			tmp[tmpIdx++] = arr[j++];
	}

	if(i > lend) // 왼쪽 배열이 다 정렬된 경우, 오른쪽 배열에 남은 원소들을 순서대로 채워줌.
		while(j <= rend) tmp[tmpIdx++] = arr[j++];
	else if(j > rend) // 오른쪽 배열이 다 정렬된 경우, 왼쪽 배열에 남은 원소들을 순서대로 채워줌.
		while(i <= lend) tmp[tmpIdx++] = arr[i++];

	for(int p=lstart; p<=rend; p++) // 임시 배열을 본 배열에 copy
		arr[p] = tmp[p-lstart];
}

// 합병 정렬: arr의 start부터 end까지 합병 정렬하는 함수
void merge_sort(int arr[], int start, int end)
{
	int middle=(start+end) / 2; // 절반 나눌 기점의 인덱스

	if(start >= end)
		return;
	
	merge_sort(arr, start, middle); // 기점 왼쪽 원소들을 합병정렬
	merge_sort(arr, middle+1, end); // 기점 오른쪽 원소들을 합병정렬
	merge(arr, start, middle, middle+1, end); // 왼쪽 배열과 오른쪽 배열들을 정렬하여 합침
	
}

int main()
{
	int ary[10] = { 1, 10 ,5, 3, 8, 7, 6, 4, 2, 9};

	merge_sort(ary, 0, 9);

    for(int i=0; i<10; i++)
    {
        cout << ary[i] << ' ';
    }

}
