#include <stdio.h>

void insertion_sort(long int * v, long int n){
    long int c, b, aux, x;
    	for(c=+1; c<=n; c++){
        x = v[c];
        b = c;
        while(x < v[b-1] && b > 0){
        v[b] = v[b-1];
        b--;
        }
        v[b] = x;
      }
   }

// função de seleção a[i .. j] do array a[]

void merge_sort(int i, int j, int a[], int aux[]) {
    if (j <= i) {
        return;
    }

         int verifica (int a[], int ac) {
         int anterior = a[0], sim = 1;
            for (int h = 1; h < ac && sim; ++h) {
            if (anterior > a[h]) sim = 0;
            anterior = a[h];
            }
            printf("Vetor ordenado");
            return sim;
        }

    int mid = (i + j) / 2;


   // if(a[mid] <= a[mid + 1]){
    // printf("Vetor ordenado");
       // return;
    //}

    if (( i+j ) < 8) {
        insertion_sort(a, i+j);
        printf("Fim do insertionSort");
        return;
    }


    // left sub-array is a[i .. mid]
    // right sub-array is a[mid + 1 .. j]

    merge_sort(i, mid, a, aux);     // sort the left sub-array recursively
    merge_sort(mid + 1, j, a, aux);     // sort the right sub-array recursively

    int pointer_left = i;       // pointer_left points to the beginning of the left sub-array
    int pointer_right = mid + 1;        // pointer_right points to the beginning of the right sub-array
    int k;      // k is the loop counter


    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {      // left pointer has reached the limit
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {        // right pointer has reached the limit
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {        // pointer left points to smaller element
            aux[k] = a[pointer_left];
            pointer_left++;
        } else {        // pointer right points to smaller element
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) {      // copy the elements from aux[] to a[]
        a[k] = aux[k];
    }
}


int main() {

  int a[100], aux[100], n, i, d, swap;

  printf("Entre com a quantidade de elementos desejado para um array:\n");
  scanf("%d", &n);

  printf("Entre com %d inteiros\n", n);

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  merge_sort(0, n - 1, a, aux);

  printf(" Segue array:\n");

  for (i = 0; i < n; i++)
     printf("%d\n", a[i]);

  return 0;
}
