#include "sorting_functions.cpp"
#include "data_functions.cpp"
#include <iostream>
#include <chrono>

int main () {
    tar* tab, * filtered_tab;
    int* new_size = new int;
    int size = 10000; // ilość danych do wczytwania
    *new_size = size; // rozmiar tablicy po powiększeniu jej
    
    // Wczytywanie danych wejściowych z pliku
    tab = read_data(size, new_size);

    // FIltrowanie danych wejściowych i pomiar czasu 
    auto start = chrono::high_resolution_clock::now();
    filtered_tab = filter_data(tab, new_size);
    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    time *= 1e-9;
    cout << "Filtering data and deleting empty entries time: " << time << " s" << endl;

    // Sortowanie przefiltrowanych danych wejściowych i pomiar czasu
    // Sortowanie przez scalanie
    start = chrono::high_resolution_clock::now();
    merge_sort(filtered_tab, 0, (*new_size - 1));
    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    time *= 1e-9;
    cout << "Merge sort time (data size: " << size << "): " << time << " s" << endl;

    // Sortowanie szybkie
    start = chrono::high_resolution_clock::now();
    quicksort(filtered_tab, 0, (*new_size - 1));
    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    time *= 1e-9;
    cout << "Quicksort time (data size: " << size << "): " << time << " s" << endl;

    // Sortowanie kubełkowe
    start = chrono::high_resolution_clock::now();
    bucket_sort(filtered_tab, *new_size, 10); // 10, bo jest 10 różnych rankingów
    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    time *= 1e-9;
    cout << "Bucket sort time (data size: " << size << "): " << time << " s" << endl;

    // Zapisywanie przefiltrowanych i posortowanych danych do pliku
    save_data(filtered_tab, *new_size, "saved_data/sorted_data.txt");
}