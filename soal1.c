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



void _printParenthesis(int pos, int n, int open, int close);

void printParenthesis(int n)
{
    if (n > 0)
        _printParenthesis(0, n, 0, 0);
    return;
}

void _printParenthesis(int pos, int n, int open, int close)
{
    static char str[100];
 
    if (close == n) {
        printf("%s \n", str);
        return;
    }
    else {
        if (open < n) {
            str[pos] = '(';
            _printParenthesis(pos + 1, n, open + 1, close);
        }
        if (open > close) {
            str[pos] = ')';
            _printParenthesis(pos + 1, n, open, close + 1);
        }
 
        
    }
}

int main(){
    int n;
    char str[50];
    scanf("%d",&n);
    // if (n==4) 
    //     strcpy(str,"(((())))");
    // else if(n==3)
    //     strcpy(str,"((()))");
    // else if(n==2)
    //     strcpy(str,"(())");
    // else if(n==1)
    //     strcpy(str,"()");
    // else if(n==0)
    //     strcpy(str,"");

    
    printParenthesis(n);
    int total = Combination(2*n,n)/(n+1);
    printf("TOTAL %d",total);
    return 0;

}
