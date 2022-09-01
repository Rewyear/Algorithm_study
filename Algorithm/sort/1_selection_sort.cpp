#include <bits/stdc++.h>
using namespace std;

void my_swap(int *x, int *y)
{
	int tmp;

	tmp = *y;
	*y  = *x;
	*x = tmp;
}

/* 선택 정렬 */
void selection_sort(int arr[], int cnt)
{
	int min;

	for(int i=0; i<cnt-1; i++)
	{
		min = i;
		for(int j=i; j<cnt;j++)
		{
			if(arr[j] < arr[min]) {
				min = j;
			}
		}
		my_swap(&arr[i],&arr[min]);	
	}
}

 
int ary[10] = { 1, 10 ,5, 3, 8, 7, 6, 4, 2, 9};

int main()
{
    selection_sort(ary,10);

    for(int i=0; i<10; i++)
    {
        cout << ary[i] << ' ';
    }

}
