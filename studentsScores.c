#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MIN  0
#define MAX 10
#define N  40

void generateArray(float arr[], int n, float min, float max) {
	//srand((int)time(0));

		for (int i = 0; i < n; i++)
			arr[i] = min + rand() % ((int)max - (int)min) + (float)(rand()) / RAND_MAX;
}

void swap(float* a, float* b) {
	float tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(float arr[], int n, int *comps)
{
	int steps = 0;
	for (int i = 0; i < n-1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			steps++;
			if (arr[minIndex] > arr[j]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			swap(&arr[i], &arr[minIndex]);
		}
		steps++;
	}
	*comps = steps;
}



int main() {
	int times = 100;
	int comps = 0;
	

	int total = 0;

	for (int i = 0; i < times; i++) {
		float arr[N];
		comps = 0;
		generateArray(arr, N, MIN, MAX);
		sort(arr, N, &comps);

		for (int i = 0; i < N; i++)
			printf("%0.2f ", arr[i]);

		printf("\n%d\n\n", comps);
		total += comps;
	}

	printf("So buoc trung binh la: %f", (float)(total/times));
}
