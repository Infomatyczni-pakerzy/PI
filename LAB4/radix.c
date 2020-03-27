#include <stdio.h>

void printArr(int arr[], int len, int k){
	for(int i=0; i<len; i++){
		if(arr[i]==0){
			for(int i=0; i<k; i++){
				printf("0");
			}
			printf("\n");
		}
		else{
			printf("%d\n", arr[i]);
		}
	}
}

int decPow(int pow){
	int x=1;
	for(int i=0; i<pow; i++){
		x*=10;
	}
	return x;
}

int getDigit(int x, int i, int length){
    int rmniejsza = x%decPow(length-i-1);
    int rwieksza = x%decPow(length-i);
    return (rwieksza - rmniejsza)/decPow(length-i-1);
}

//applies counting sort to digits of pos position, n = len(arr)
void countingSort(int arr[], int pos, int n, int number_length){
    int temp[10] = {0};
    int output[n];
    
    for(int i=0; i<n; i++){
        temp[getDigit(arr[i],pos,number_length)]++;
		output[i] = 0;
    }
    for(int i=1; i<10; i++){
        temp[i] = temp[i] + temp[i-1];
    }
	for(int i=0; i<n; i++){
		output[temp[getDigit(arr[i],pos,number_length)]-1] = arr[i];
		temp[getDigit(arr[i],pos,number_length)]--;
	}
	
    for(int i=0; i<n; i++){
		//printf("%d\n", output[i]);
		arr[i] = output[i];
    }
}

void radix(int arr[], int len, int number_length){
	for(int i=number_length-1; i>=0; i--){
		countingSort(arr, i, len, number_length);
	}
}

int main(){
    /*int t[5] = {35,00,20,93,18};
	radix(t, 5, 2);
    printArr(t, 5, 2);*/
    int Z;
    //gets number of data packages Z
    scanf("%d", &Z);

    for(int i=0; i<Z; i++){
    	int n,k;
    	scanf("%d %d", &n, &k);
    	int arr[n];
    	for(int j=0; j<n; j++){
    		scanf("%d", &arr[j]);
		}
		radix(arr, n, k);
		printArr(arr, n, k);
	}
	return 0;
}
