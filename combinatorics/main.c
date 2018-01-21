/*
 * main.c
 *
 *  Created on: Jan 21, 2018
 *      Author: yas
 */
#include <stdio.h>
#include <stdlib.h>

#define N_SET 3// n=3
#define K_SIMPLE_PERMUTATION 3 // for simple permutation k=n
#define K_SIMPLE_ARRANGEMENT 2 //
#define DISTINCT_USED_SIZE 2 //

void printResult(int *,int );


void simple_arrangement(int *arr,int *buff,int *used,int level,int k,int n);
void arrangement_with_repetition(int *arr,int *buff,int level,int k,int n);
void simple_permutation(int *arr,int *buff,int *used,int level,int k,int n);
void permutation_with_repetition(int *arr,int *buff,int *used,int level,int k,int n);
void simple_combination(int *arr,int *buff,int level,int k,int n,int start);
void combination_with_repetition(int *arr,int *buff,int level,int k,int n,int start);


int main (){
	setbuf(stdout,NULL);
	int i, used[3];
	int buff_simple_permutation[K_SIMPLE_PERMUTATION];//k=n
	int	buff_simple_arrangement[K_SIMPLE_PERMUTATION];
	int used_permutation_repetition[DISTINCT_USED_SIZE]={2,1};
	int arr_permutation_repetition[DISTINCT_USED_SIZE]={1,2};
	int arr[3]={1,2,3};
	for(i=0;i<3;i++){
		used[i]=0;
	}

//	simple_permutation(arr,buff_simple_arrangement,used,0,K_SIMPLE_PERMUTATION,N_SET);
//	simple_arrangement(arr,buff_simple_arrangement,used,0,K_SIMPLE_ARRANGEMENT,N_SET);
//	arrangement_with_repetition(arr,buff_simple_arrangement,0,K_SIMPLE_ARRANGEMENT,N_SET);
	//permutation_with_repetition(arr_permutation_repetition,buff_simple_permutation,used_permutation_repetition,0,K_SIMPLE_PERMUTATION,N_SET);
//	simple_combination(arr,buff_simple_arrangement,0,K_SIMPLE_ARRANGEMENT,N_SET,0);
	combination_with_repetition(arr,buff_simple_arrangement,0,K_SIMPLE_ARRANGEMENT,N_SET,0);

	return 0;
}



/**
 * combination with repetition : order does not  matters, no need to used array
 * n : size fo original set {1,2,3}
 * k : size of resulted subset
 * arr : original set
 * buff : resulted subset which store  current solution
 */
void combination_with_repetition(int *arr,int *buff,int level,int k,int n,int start){
	int i;

	if(level>=k){
		printResult(buff,k);
		return;
	}
	for(i=start;i<n;i++){
			buff[level]=arr[i];
			combination_with_repetition(arr,buff,level+1,k,n,i);
	}
	return;

}


/**
 * simple combination : order does not  matters, no need to used array
 * n : size fo original set {1,2,3}
 * k : size of resulted subset
 * arr : original set
 * buff : resulted subset which store  current solution
 */
void simple_combination(int *arr,int *buff,int level,int k,int n,int start){
	int i;
	// n=k
	if(level>=k){
		printResult(buff,k);
		return;
	}
	for(i=start;i<n;i++){
			buff[level]=arr[i];
			simple_combination(arr,buff,level+1,k,n,i+1);
	}
	return;

}

/**
 * Permutation with repetition : order matters
 * n : size fo original set {1,2,3}
 * k : size of resulted subset
 * arr : original set
 * buff : resulted subset which store  current solution
 */
void permutation_with_repetition(int *arr,int *buff,int *used,int level,int k,int n){
	int i;
	// n=k
	if(level==k){
		printResult(buff,k);
		return;
	}
	for(i=0;i<DISTINCT_USED_SIZE;i++){
		if(used[i]>0){
			used[i]--;
			buff[level]=arr[i];
			permutation_with_repetition(arr,buff,used,level+1,k,n);
			used[i]++;
		}
	}
	return;

}

/**
 * Arangement with repetition : order matters, no need to used array
 * n : size fo original set {1,2,3}
 * k : size of resulted subset
 * arr : original set
 * buff : resulted subset which store  current solution
 */
void arrangement_with_repetition(int *arr,int *buff,int level,int k,int n){
	int i;
	// n=k
	if(level==k){
		printResult(buff,k);
		return;
	}
	for(i=0;i<n;i++){
			buff[level]=arr[i];
			arrangement_with_repetition(arr,buff,level+1,k,n);

	}
	return;

}

/**
 * simple arangement : order matters
 * n : size fo original set {1,2,3}
 * k : size of resulted subset
 * arr : original set
 * buff : resulted subset which store  current solution
 */
void simple_arrangement(int *arr,int *buff,int *used,int level,int k,int n){
	int i;
	// n=k
	if(level==k){
		printResult(buff,k);
		return;
	}
	for(i=0;i<n;i++){
		if(used[i]==0){
			used[i]=1;
			buff[level]=arr[i];
			simple_arrangement(arr,buff,used,level+1,k,n);
			used[i]=0;
		}
	}
	return;

}

// simple permutatioan
void simple_permutation(int *arr,int *buff,int *used,int level,int k,int n){
	int i;
	// n=k
	if(level==k){
		printResult(buff,k);
		return;
	}
	for(i=0;i<n;i++){
		if(used[i]==0){
			used[i]=1;
			buff[level]=arr[i];
			simple_permutation(arr,buff,used,level+1,k,n);
			used[i]=0;
		}
	}
	return;

}
void printResult(int *arr_result,int size_arr_result){
	int i;
	for (i = 0; i < size_arr_result; i++) {
				printf("%d",arr_result[i]);
	}
	printf("\n");
	return ;
}

