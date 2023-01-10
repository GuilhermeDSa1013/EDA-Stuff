#include<stdio.h>
#include<stdlib.h>

int separa (int v[], int p, int r) {
    int c = v[r]; // pivô
    int t, j = p;
    for (int k = p; k < r; ++k)
        if (v[k] <= c) {
        t = v[j];
        v[j] = v[k];
        v[j] = v[k];
        v[k] = t;
        ++j;
        }
    t = v[j];
    v[j] = v[r];
    v[j] = v[r];
    v[r] = t;
    return j;
}

void quicksort (int v[], int p, int r){
    if (p < r) {
        int j = separa (v, p, r);
        quicksort (v, p, j-1);
        quicksort (v, j+1, r);
    }
}

main(){
    int v[10] = {1, 7, 8, 6, 0, 5, 3, 9, 4, 2};
    quicksort(v, 0, 9);
    for (int i = 0; i < 10; i++){
        printf("%d - ", v[i]);
    }
}