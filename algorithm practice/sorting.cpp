#include <stdio.h>
#include <stdlib.h>
int* merging(int* nums_1, int* nums_2, int n_1, int n_2);
int* merging_sorting(int* nums, int number_of_arr);

int main() {
	int a[9] = { 4,3,5,1,2,20,10,9,8 };
	int* sorted = merging_sorting(a, sizeof(a)/sizeof(int));
	for (int i = 0; i < (sizeof(a) / sizeof(int)); i++) {
		printf("%d ", sorted[i]);
	}
	delete[] sorted;
	
}
int* merging(int *nums_1, int *nums_2, int n_1, int n_2) {
	int n1 = 0; 
	int n2 = 0;
	int* sorted_n;
	int n3 = n_1 + n_2;
	sorted_n = new int[n3];

	for (int i = 0; i < n3; i++) {
		if (n1 == n_1) {
			sorted_n[i] = nums_2[n2];
			n2++;
		}
		else if (n2 == n_2) {
			sorted_n[i] = nums_1[n1];
			n1++;
		}

		else if ((nums_1[n1] < nums_2[n2])) {
			sorted_n[i] = nums_1[n1];
	        n1++;
		}
		else {
			sorted_n[i] = nums_2[n2];
			n2++;
		}
	}
	delete[] nums_1;
	delete[] nums_2;
	
	return sorted_n;
}

int* merging_sorting(int* nums, int n_arr) {

	int* nums_1;
	int* nums_2;
	int n_arr1 = n_arr / 2;
	int n_arr2 = n_arr - n_arr1;
	nums_1 = new int[n_arr1];
	nums_2 = new int [n_arr2];
	if (n_arr == 1)
		return nums;
	else {
		
		for (int i = 0; i < n_arr; i++) {
			if (i < n_arr1) {
				nums_1[i] = nums[i];
			}
			else {
				nums_2[i - n_arr1] = nums[i];
			}
		}
	}
	return merging(merging_sorting(nums_1, n_arr1), merging_sorting(nums_2, n_arr2), n_arr1, n_arr2);
	
}