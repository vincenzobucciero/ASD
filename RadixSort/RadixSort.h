//
// created by vincenzo on 30/12/22
//

//IMPLEMENTAZIONE RADIX SORT

#include <iostream>
#include <vector>

using namespace std;

class RadixSort {
    private:
        static int getMax(int arr[], int n);
        static int getMaxString(string arr[], int n);
        static void countingSortRadix(int arr[], int n, int exp); 
        static void insertionSortRadix(string arr[], int n);
    public:
        static void radixSort(int arr[], int n);
        static void radixSortString(string arr[], int n);
};

int RadixSort::getMax(int arr[], int n) {
    int mx = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > mx) 
            mx = arr[i]; 
    }
    return mx;
}

//utilizzo del counting sort per ordinare interi
void RadixSort::countingSortRadix(int arr[], int n, int exp) {
    //definisco l'array di output
    int *output = new int[n];
    int i;
    int count[10] = { 0 };

    for(i = 0; i < n; i++) {
        count[(arr[i]/exp)%10]++;
    }
    for(i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void RadixSort::radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    // Esegui il conteggio per ogni cifra. Nota che invece
    // del numero di cifra che passa, exp è passato. exp è 10^i
    // dove i è il numero della cifra corrente
    for(int exp = 1; m/exp > 0; exp *= 10)
        countingSortRadix(arr, n, exp);
}

//funzione che ritorna il massimo in un array di stringhe
int RadixSort::getMaxString(string arr[], int n) {
    int mx = arr[0].length();
    for(int i = 1; i < n; i++) {
        if(arr[i].length() > mx)
            mx = arr[i].length();
    }
    return mx;
}

//utilizzo insertion sort per ordinare stringhe
void RadixSort::insertionSortRadix(string arr[], int n) {
    int i, j;
    string key;

    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void RadixSort::radixSortString(string arr[], int n) {
    int m = getMaxString(arr, n);
    for(int i = 0; i < n; i++)
        insertionSortRadix(arr, n);
}