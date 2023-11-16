#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX 1500
const int N = 20;

void generateArray(float arr[], int n, float min, float max) {
	//srand((int)time(0));
	
	for (int i = 0; i < n; i++)
			arr[i] = min + rand()%((int)max - (int)min + 1) + (float)(rand())/RAND_MAX;
}

int minIndex(float arr[], int n, int *comps) {
	float minVal = arr[0];
	int minIdx = 0;
	int steps = 0;

	for (int i = 1; i < n; i++) {
		steps++;
		if (arr[i] < minVal) {
			minVal = arr[i];
		}
	}

	for (int i = 0; i < n; i++) {
		steps++;
		if (arr[i] == minVal) {
			*comps = steps;
			return i;
		}
	}
}


int main() {

	int times;
	int comps = 0;
	float arr[MAX];
	scanf("%d", &times);

	float minVal = -2 * N;
	float maxVal = 2 * N;

	int total = 0;
	printf("Bang dem so buoc so sanh tai moi lan chay:\n");
	printf("-------------------\n");

	for (int i = 0; i < times; i++) {

		generateArray(arr, N, minVal, maxVal);

		printf("Du lieu lan chay thu %d:\n", i + 1);
		for (int j = 0; j < N; j++)
			printf("%2.2f ", arr[j]);
		printf("\n");

		int res = minIndex(arr, N, &comps);
		total += comps;
		printf("Ket qua: %d\n", res);
		printf("Lan chay thu %d: %d\n\n", i + 1, comps);

	}

	float avg = (float)(total / times);

	printf("Trung binh: %2.5f", avg);
}