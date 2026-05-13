/* EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026 
* Modul: 5 - Foundation of Algorithms 
* Hari dan Tanggal: Rabu, 13 Mei 2026 
* Nama File: soal2.c 
* Pembuat: Alfatihah Nurmahmudi Wijaya
* Deskripsi: mencetak semua susunan n pasang kurung yang valid..
*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long factorial(int num) {
    if (num == 0) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}

long Combination(int n, int r) {
    if (n < r) {
        return -1;
    }
    else {
        return factorial(n) / (factorial(r) * factorial(n - r));
    }
}

void swap(char* left, char* right)
{
    char temp = *left;
    *left = *right;
    *right = temp;
}
int compare (const void * a, const void * b)
{
  return ( *(char*)a - *(char*)b );
}
void PrintSortedPermutations(char* inStr)
{
    // Re-implementation of algorithm described here:
    // http://www.geeksforgeeks.org/lexicographic-permutations-of-string/
    int strSize = strlen(inStr);
    // 0. Ensure input container is sorted
    qsort(inStr, strSize, sizeof(char), compare);


    int largerPermFound = 1;
    do{
        // 1. Print next permutation
        printf("%s\n", inStr);
        // 2. Find rightmost char that is smaller than char to its right
        int i;
        for (i = strSize - 2; i >= 0 && inStr[i] >= inStr[i+1]; --i){}

        // if we couldn't find one, we're finished, else we can swap somewhere
        if (i > -1)
        {
            // 3 find character at index j such that 
            // inStr[j] = min(inStr[k]) && inStr[k] > inStr[i] for all k > i
            int j = i+1;
            int k;
            for(k=j;k<strSize && inStr[k];++k)
            {
                if (inStr[k] > inStr[i] && inStr[k] < inStr[j])
                    j = k;
            }

            // 3. Swap chars at i and j
            swap(&inStr[i], &inStr[j]);

            // 4. Sort string to the right of i
            qsort(inStr+i+1, strSize-i-1, sizeof(char), compare);
        }
        else
        {
            largerPermFound = 0;
        }
    }while(largerPermFound);
}

int main(){
    int n;
    char str[50];
    scanf("%d",&n);
    if (n==4) 
        strcpy(str,"(((())))");
    else if(n==3)
        strcpy(str,"((()))");
    else if(n==2)
        strcpy(str,"(())");
    else if(n==1)
        strcpy(str,"()");
    else if(n==0)
        strcpy(str,"");

    int total = (1/(n+1))*Combination(2*n,n);
    PrintSortedPermutations(str);
    printf("TOTAL %d",total);
    return 0;

}
