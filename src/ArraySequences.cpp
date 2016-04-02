/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void find_AP(int* res, int* arr, int len);

void find_GP(int* res, int* arr, int len);
int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]ff
	if (arr==NULL || len<0)
	return NULL;
	int res[6] = { 0,0,0,0,0,0 };
	find_AP(res, arr, len);
	find_GP(res, arr, len);
	for (int i = 0; i < 6; i++)
		arr[i] = res[i];
	return arr;
}

void find_AP(int* res,int* arr, int len){
	int index = 0;
	while (index < len-2){
		if (arr[index + 2] - arr[index + 1] == arr[index + 1] - arr[index]){
			res[0] = index;
			index++;
			while (index < len - 2 && (arr[index + 2] - arr[index + 1] == arr[index + 1] - arr[index]))
				index++;
			res[1] = index+1;
			break;
		}
		index++;
	}
	while (index < len - 2){
		if (arr[index + 2] - arr[index + 1] == arr[index + 1] - arr[index]){
			res[2] = index;
			index++;
			while (index < len - 2 && (arr[index + 2] - arr[index + 1] == arr[index + 1] - arr[index]))
				index++;
			res[3] = index+1;
			printf("\n%d %d", res[2], res[3]);
			break;
		}
		index++;
	}

}


void find_GP(int* res, int* arr, int len){
	int index = 0;
	while (index < len - 2){
		if (arr[index + 2] / (arr[index + 1]+0.0) == arr[index + 1] / (arr[index]+0.0)){
			res[4] = index;
			index++;
			while (index < len - 2 && (arr[index + 2] / arr[index + 1] == arr[index + 1] / arr[index]))
				index++;
			res[5] = index+1;
			break;
		}
		index++;
	}
}