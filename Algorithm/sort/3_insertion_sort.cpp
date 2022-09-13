#include <bits/stdc++.h>
using namespace std;

void my_swap(int *x, int *y)
{
	int tmp;

	tmp = *y;
	*y  = *x;
	*x = tmp;
}

/*삽입 정렬 */
void insertion_sort(int arr[], int cnt)
{
	int j;
	for(int i=0; i<cnt-1; i++)
	{
		j = i;
		while(j>=0 && arr[j] > arr[j+1])
		{
			my_swap(&arr[j], &arr[j+1]);
			j--;
		}
	}
}
 
int ary[10] = { 1, 10 ,5, 3, 8, 7, 6, 4, 2, 9};

int main()
{
    insertion_sort(ary,10);

    for(int i=0; i<10; i++)
    {
        cout << ary[i] << ' ';
    }

}
