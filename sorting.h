#pragma once
#include <iostream>
#include <chrono>

using namespace std::chrono;

struct mergeStructure{
	size_t	size_l;
	size_t	size_r;
	int		*left_arr;
	int		*right_arr;
};

void	array(size_t size);
int		*make_arr(size_t size);
int		*copy_array(int *arr, size_t size);
void	swap(int &a, int &b);
void	bubble_sort(int *arr, size_t size);
size_t	find_min(int *arr, size_t j, size_t size);
void	selection_sort(int *arr, size_t size);
void	insertion_sort(int *arr, size_t size);
void	merge(int *arr, mergeStructure &mergeElem, size_t begin);
void	merge_part(int *arr, size_t begin, size_t mid, size_t end);
void	merge_sort(int *arr, size_t begin, size_t end);
int		partition(int *arr, int begin, int end);
void	quick_sort(int *arr, int begin, int end);