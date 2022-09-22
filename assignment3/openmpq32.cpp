#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n = 200, i ,j=99;
    
	int arr1[n], answer[n];
    
	for(i = 0; i < n; i++)
	{
        arr1[i] = rand()%100;
    }    
    
    double time = omp_get_wtime();
    
	#pragma omp parallel for schedule(dynamic,20) shared(arr1, answer,j) private(i)
    for(i = 0; i < n; i++)
    {
        answer[i] = arr1[i] + j;
    }
    
    printf("\nDone In %f Seconds\n\n", omp_get_wtime() - time);
    
	printf("\nArray 1: \n");
    for(i = 0; i < n; i++)
	{
        printf("\t %d", arr1[i]);
    }
    
	printf("\nAnswer: \n");
    for(i = 0; i < n; i++)
	{
        printf("\t %d", answer[i]);
    }
    return 0;
}

