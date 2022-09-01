#include <bits/stdc++.h>
using namespace std;

void my_swap(int *x, int *y)
{
	int tmp;

	tmp = *y;
	*y  = *x;
	*x = tmp;
}

/* 버블 정렬 */
void bubble_sort(int arr[], int cnt)
{
	for(int i=0; i<cnt-1; i++)
	{
		for(int j=0; j<cnt-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				my_swap(&arr[j], &arr[j+1]);
			}
		}
	}
}
 
int ary[10] = { 1, 10 ,5, 3, 8, 7, 6, 4, 2, 9};

int main()
{
    bubble_sort(ary,10);

    for(int i=0; i<10; i++)
    {
        cout << ary[i] << ' ';
    }

}
