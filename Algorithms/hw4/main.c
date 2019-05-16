#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int increasing_helper(int * A, int N, int result)
{
    if(N == 0 || N == -1)
        return result;
    if(A[N] >= A[N-1])
    {
        result = 1;
        return increasing_helper(A, N-1, result);
    }
    else
        return 0;
}


int increasing(int * A, int N)
{
    if (N == -1 || N == 0)
        return 1;
    return(increasing_helper(A, N, 1));
}

int min_rec_1(int * A, int N, int* rec_ct, int* base_ct, int * max_depth){
	// crashes for N < = 0
	if (N==1)
	{
	    *base_ct = *base_ct + 1;
	    return A[0];
	}
	*max_depth = *max_depth + 1;
	int temp = min_rec_1(A, N-1, rec_ct, base_ct, max_depth);
	if (temp < A[N-1])
    {
        *rec_ct = *rec_ct + 1;
        return temp;
    }

	else
    {
        *rec_ct = *rec_ct + 1;
        return A[N-1];
	}

}




int min_rec_2(int * A, int N, int * rec_ct, int * base_ct, int * max_depth){
	// crashes for N < = 0
	if (N==1)
    {
        *base_ct = *base_ct + 1;
        return A[0];
    }
	if (min_rec_2(A,N-1, rec_ct, base_ct, max_depth) < A[N-1])
    {
        *rec_ct = *rec_ct + 1;
        *max_depth = *max_depth + 2;
		return min_rec_2(A,N-1, rec_ct, base_ct, max_depth);
    }
	else
    {
        *rec_ct = *rec_ct + 1;
        return A[N-1];
    }

}


int min_rec_tail(int * A, int N, int * rec_ct, int * base_ct, int * max_depth)
{
    if(N==0)
    {
        *base_ct = *base_ct + 1;
        return A[0];
    }
    N = N - 1;
    *rec_ct = *rec_ct + 1;
    *max_depth = *max_depth + 1;

    if(A[0] > A[N])
    {
        return min_rec_tail(1 + A, N, rec_ct, base_ct, max_depth);
    }
    else
        return min_rec_tail(A, N, rec_ct, base_ct, max_depth);
}



int pal_check(char *a)
{
    int left = 0;
    int right = strlen(a)-1;
    if(right == 1)
        return 1;                    //Length 1 is palindrome
    while(left < right)
    {
        if(a[left] != a[right])  //If the far left and right are equal were still a palindrome
            return 0;              //Not a plaindrome return 0
        left++;
        right--;
    }
    return 1;                   //Is palin, return 1

}

void pal_decomp(char *current, char *rest, char *entire, int n, int k)  //result, outside of result, entire word, length, current length of palins
{
    if (strlen(rest) == 0)
    {
        printf("%s", current);
    }
/*
    char * test;
    strncpy(test, rest, n);

    //Print all palins of length k
    if(pal_check(test) == 1);
        {
            current = strcat(current, test);
            rest = strncpy(rest, rest, strlen(rest)-n);
        } */





}






int main()
{
    int size = 0;
    int i;
    int array[100];
    int previous_size = -1;

    while(1 == 1)   //Take in arrays
    {
        printf("Enter size of array. (Stop with -1.) ");    //Scans array size
        scanf("%d", &size);
        if(size == -1)                                      //Exit loop on -1
        {
            if(previous_size == -1)
                break;
            int rec_ct = 0;
            int base_ct = 0;
            int max_depth = 1;


            int min = min_rec_1(array, previous_size, &rec_ct, &base_ct, &max_depth);
            printf("smallest_1:         smallest = %d, base_ct = %d, rec_ct = %d, max_depth = %d\n", min, base_ct, rec_ct, max_depth);

            rec_ct = 0;
            base_ct = 0;
            max_depth = 0;


            min = min_rec_2(array, previous_size, &rec_ct, &base_ct,  &max_depth);
            printf("smallest_2:         smallest = %d, base_ct = %d, rec_ct = %d, max_depth = %d\n", min, base_ct, rec_ct, max_depth);

            rec_ct = 0;
            base_ct = 0;
            max_depth = 1;

            min = min_rec_tail(array, previous_size, &rec_ct, &base_ct,  &max_depth);
            printf("smallest_tail:      smallest = %d, base_ct = %d, rec_ct = %d, max_depth = %d\n\n", min, base_ct, rec_ct, max_depth);
            break;
        }
        previous_size = size;
        if(size != -1)
        printf("Enter array elements separated by spaces: "); //scans inputs into array
        for(i=0; i<size; i++)
        {
            scanf("%d", &array[i]);
        }

        if(size != -1)
        printf("increasing: %d\n\n", increasing(array, size-1)); //Prints if its increasing or not
    }

    char word[100];
    fgets(word, sizeof word, stdin);
    while(strcmp(word, "-1") != 0)
    {
                                                                //Strings (Task 3)
    printf("Enter strings. (Stop with -1.) ");
    fgets(word, sizeof word, stdin);

    word[strlen(word)-1] = 0;
    int n = strlen(word) - 1;
    pal_decomp(0, word, word, n, 1);
    }



    return 0;
}
