#include "sorting.h"

int main() {

	std::cout << "Times for 1000 elements \n";
	array(1000);
	std::cout << "Times for 10000 elements \n";
	array(10000);
	std::cout << "Times for 20000 elements \n";
	array(20000);
}

void array(size_t size)
{
	int* array;
	int* copy_arr;

	array = make_arr(size);
	copy_arr = copy_array(array, size);
	bubble_sort(copy_arr, size);
	copy_arr = copy_array(array, size);
	selection_sort(copy_arr, size);
	copy_arr = copy_array(array, size);
	insertion_sort(copy_arr, size);
	copy_arr = copy_array(array, size);
	auto	start = high_resolution_clock::now();
	merge_sort(copy_arr, 0, size - 1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << "Time taken by function merge_sort: " << duration.count() << " microseconds\n";
	copy_arr = copy_array(array, size);
	start = high_resolution_clock::now();
	quick_sort(copy_arr, 0, size - 1);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	std::cout << "Time taken by function merge_sort: " << duration.count() << " microseconds\n";
}

int* make_arr(size_t size)
{
	int* array;
	array = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % 1000000 + 1;
	}
	return (array);
}

int* copy_array(int* arr, size_t size)
{
	int* array;
	array = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = arr[i];
	}
	return (array);
}

void swap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void bubble_sort(int* arr, size_t size)
{
	auto start = high_resolution_clock::now();
	size_t		i;
	size_t		j;
	bool	t;

	for (i = 0; i < size - 1; ++i)
	{
		t = true;
		for (j = 0; j < size - i - 1; ++j)
			if (arr[j] > arr[j + 1])
			{
				t = false;
				swap(arr[j], arr[j + 1]);
			}
		if (t == true)
		{
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			std::cout << "Time taken by function bubble_sort : " << duration.count() << " microseconds\n";
			return;
		}
	}
}

size_t find_min(int* arr, size_t j, size_t size)
{
	size_t min_index = j++;
	for (; j < size; ++j)
	{
		if (arr[j] < arr[min_index])
			min_index = j;
	}
	return min_index;
}

void selection_sort(int* arr, size_t size)
{
	auto	start = high_resolution_clock::now();
	size_t	min_index;

	for (size_t i = 0; i < size - 2; i++)
	{
		min_index = find_min(arr, i, size);
		if (min_index != i)
			swap(arr[min_index], arr[i]);
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << "Time taken by function selection_sort: " << duration.count() << " microseconds\n";
}

void insertion_sort(int* arr, size_t size)
{
	auto start = high_resolution_clock::now();

	for (size_t i = 1; i < size; ++i)
	{
		for (size_t j = 0; j < i; ++j)
		{
			if (arr[i] < arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << "Time taken by function insertion_sort: " << duration.count() << " microseconds\n";
}

void merge(int *arr, mergeStructure &mergeElem, size_t begin)
{
	size_t	j;
	size_t	i;
	size_t	k;

	k = begin;
	i = 0;
	j = 0;
	while (i < mergeElem.size_l && j < mergeElem.size_r)
	{
		if (mergeElem.left_arr[i] <= mergeElem.right_arr[j])
			arr[k] = mergeElem.left_arr[i++];
		else
			arr[k] = mergeElem.right_arr[j++];
		++k;
	}
	while (i < mergeElem.size_l)
		arr[k++] = mergeElem.left_arr[i++];
	while (j < mergeElem.size_r)
		arr[k++] = mergeElem.right_arr[j++];
}

void merge_part(int* arr, size_t begin, size_t mid, size_t end)
{
	mergeStructure	mergeElem;
	size_t			i;

	mergeElem.size_l = mid - begin + 1;
	mergeElem.size_r = end - mid;
	mergeElem.left_arr = new int[mergeElem.size_l];
	mergeElem.right_arr = new int[mergeElem.size_r];
	for (i = 0; i < mergeElem.size_l; ++i)
		mergeElem.left_arr[i] = arr[begin + i];
	for (i = 0; i < mergeElem.size_r; ++i)
		mergeElem.right_arr[i] = arr[mid + 1 + i];
	merge (arr, mergeElem, begin);
}

void merge_sort(int* arr, size_t begin, size_t end)
{
	
	size_t	mid;

	if (begin >= end)
		return;
	mid = (end + begin) / 2;
	merge_sort(arr, begin, mid);
	merge_sort(arr, mid + 1, end);
	merge_part(arr, begin, mid, end);
}

int	partition(int* arr, int begin, int end)
{
	int		pivot;
	int		index_pivot;

	pivot = arr[end];
	index_pivot = begin - 1;
	for (int i = begin; i < end; ++i)
	{
		if (arr[i] <= pivot)
		{
			++index_pivot;
			swap(arr[index_pivot], arr[i]);
		}
	}
	swap(arr[index_pivot + 1], arr[end]);
	return (index_pivot + 1);
}

void	quick_sort(int* arr, int begin, int end)
{
	if (begin < end)
	{
		int index_pivot = partition(arr, begin, end);
		quick_sort(arr, begin, index_pivot - 1);
		quick_sort(arr, index_pivot + 1, end);
	}
}