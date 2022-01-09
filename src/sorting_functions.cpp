#include "data_structure.hh"
#include "vector.hh"
#include <iostream>

// Scala dane w algorytmie
// sortowania przez scalanie
void merge (tar* tab, int start_index, int middle, int end_index) {
    int size1 = middle - start_index + 1;
    int size2 = end_index - middle;
    tar* half1 = new tar[size1];
    tar* half2 = new tar[size2];
    int i, j, k;

    for (i = 0; i < size1; i++) {
        half1[i] = tab[start_index + i];
    }
    for (j = 0; j < size2; j++) {
        half2[j] = tab[middle + 1 + j];
    }
    i = 0;
    j = 0;
    k = start_index;
    while (i < size1 && j < size2) {
        if (half1[i].get_rating() <= half2[j].get_rating()) {
            tab[k] = half1[i];
            i++;
        } else {
            tab[k] = half2[j];
            j++;
        }
        k++;
    }
    while (i < size1) {
        tab[k] = half1[i];
        i++;
        k++;
    }
    while (j < size2) {
        tab[k] = half2[j];
        j++;
        k++;
    }
    delete [] half1;
    delete [] half2;
}

// Sortuje dane przy wykorzystaniu
// algorytmu sortowania przez scalanie
void merge_sort (tar* tab, int start_index, int end_index) {
    int middle;
    
    if (start_index >= end_index) { // if a basic step
        return;
    }
    middle = start_index + (end_index - start_index) / 2;
    merge_sort(tab, start_index, middle); // sorting first half
    merge_sort(tab, (middle + 1), end_index); // sorting second half
    merge(tab, start_index, middle, end_index); // merging halves
}

// Dzieli dane w algorytmie
// sorotwania szybkiego
int partition (tar* tab, int start_index, int end_index) {
    int pivot = tab[end_index].get_rating();
    int i = (start_index - 1), j;
 
    for (j = start_index; j <= (end_index - 1); j++) {
        if (tab[j].get_rating() < pivot) {
            i++;
            swap(tab[i], tab[j]);
        }
    }
    swap(tab[i + 1], tab[end_index]);
    return (i + 1);
}

// Sortuje dane przy wkorzystaniu
// algorytmu sortowania szybkiego
void quicksort (tar* tab, int start_index, int end_index) {
    int pivot;

    if (start_index < end_index) { // if not a basic step
        pivot = partition(tab, start_index, end_index);
        quicksort(tab, start_index, (pivot - 1));
        quicksort(tab, (pivot + 1), end_index);
    }
}

// Sortuje dane przy wykorzystaniu
// algorytmu sortowania kubełkowego
void bucket_sort (tar* tab, int size, int number_of_buckets) {
    vector<tar> bucket_tab[number_of_buckets];
    int index, i, j;

    for (i = 0; i < size; i++) {
        index = tab[i].get_rating();
        bucket_tab[index - 1].push_back(tab[i]);
    }
    index = 0;
    for (i = 0; i < number_of_buckets; i++) {
        for (j = 0; j < bucket_tab[i].size(); j++) {
            tab[index++] = bucket_tab[i][j];
        }
    }
}