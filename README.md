# Sorting Algorithms in C 🧮

This repository contains implementations of various sorting algorithms. These algorithms are designed to sort arrays of integers in ascending order. Each algorithm is provided with a detailed description and an analysis of its time complexity.

## Table of Contents 📚

0. [Bubble Sort](#0-bubble_sort.c)
1. [Insertion Sort](#insertion-sort)
2. [Selection Sort](#selection-sort)
3. [Quick Sort](#quick-sort)
4. [Shell Sort - Knuth Sequence](#shell-sort-knuth-sequence)
5. [Cocktail Shaker Sort](#cocktail-shaker-sort)
6. [Counting Sort](#counting-sort)
7. [Merge Sort](#merge-sort)

## Progress: 137/200 📊

Progress Bar: ██████████████████████▓▒░ 68.5%

Acknowledgment: Not all questions have been answered.

## Bubble Sort 🛁

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. It continues to do this until no more swaps are needed.

- Prototype: `void bubble_sort(int *array, size_t size)`
- Time Complexity:
  - Best Case: O(n)
  - Average Case: O(n^2)
  - Worst Case: O(n^2)

## Insertion Sort 📥

Insertion Sort is another simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

- Prototype: `void insertion_sort_list(listint_t **list)`
- Time Complexity:
  - Best Case: O(n)
  - Average Case: O(n^2)
  - Worst Case: O(n^2)

## Selection Sort 📊

Selection Sort is an in-place comparison sorting algorithm. It divides the input list into two parts: the left sub-array, which is sorted, and the right sub-array, which is unsorted. The algorithm repeatedly selects the minimum element from the unsorted sub-array and moves it to the beginning of the sorted sub-array.

- Prototype: `void selection_sort(int *array, size_t size)`
- Time Complexity:
  - Best Case: O(n^2)
  - Average Case: O(n^2)
  - Worst Case: O(n^2)

## Quick Sort 🚀

Quick Sort is a highly efficient and widely used sorting algorithm. It uses a divide-and-conquer approach to sort an array. The basic idea is to select a 'pivot' element from the array and partition the other elements into two sub-arrays, according to whether they are less than or greater than the pivot.

- Prototype: `void quick_sort(int *array, size_t size)`
- Time Complexity:
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - Worst Case: O(n^2)

## Shell Sort - Knuth Sequence 🐚

Shell Sort is an optimization of the insertion sort algorithm that works by comparing elements separated by a fixed gap. The gap is reduced after each pass until it becomes 1, making the final pass an ordinary insertion sort.

- Prototype: `void shell_sort(int *array, size_t size)`

## Cocktail Shaker Sort 🍸

Cocktail Shaker Sort, also known as Bidirectional Bubble Sort, is a variation of the Bubble Sort algorithm. It sorts the list by moving in both directions repeatedly through the list, comparing and swapping elements as necessary.

- Prototype: `void cocktail_sort_list(listint_t **list)`

## Counting Sort 📊

Counting Sort is a non-comparative sorting algorithm that uses counting to determine the position of each element in the sorted output. It is particularly useful when sorting integers within a specific range.

- Prototype: `void counting_sort(int *array, size_t size)`

## Merge Sort 🧩

Merge Sort is an efficient, stable, and comparison-based sorting algorithm. It divides the unsorted list into n sub-lists, each containing one element, and then repeatedly merges sub-lists to produce new sorted sub-lists until there is only one sub-list remaining.

- Prototype: `void merge_sort(int *array, size_t size)`

Feel free to explore the source code for each sorting algorithm in this repository and try them out. Happy sorting! 🎉
