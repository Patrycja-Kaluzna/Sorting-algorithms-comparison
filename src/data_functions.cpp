#include "data_structure.hh"
#include <fstream>
#include <cmath>

// Wczytuje dane wejściowe z pliku
tar* read_data (int size, int* new_size) {
    int for_size = 3 * size, rating, i, j = 2, k = 0, l;
    ifstream data_file("input_data/projekt2_dane.csv");
    tar* extended_tab, * tab = new tar[size];
    string title, line1, line2;
    
    if (data_file.good()) {
        getline(data_file, line1, '\n'); // reading a header
        for (i = 1; i < for_size + 1; i++) {
            if (i % 3 != 0) { // if an ordinal number or a title
                getline(data_file, line1, ',');
                if (i == j) { // if a title
                    if (line1[0] == '"') {  // if a title includes ','
                        title = line1 + ',';
                        do {
                            getline(data_file, line2, ',');
                            title += (line2 + ',');
                        } while (line2[line2.length() - 1] != '"');
                        title[title.length() - 1] = ' ';
                    } else {
                        title = line1;
                    }
                    j += 3;
                }
            } else { // if a rating
                line1 = "";
                getline(data_file, line1);
                if (line1.empty() || isspace(line1[0])) { // if no rating
                    tab[k].set_title(title); 
                    for_size += 3;
                } else {
                    rating = stoi(line1);
                    tab[k].set_title(title);
                    tab[k].set_rating(rating);
                }
                if (i != (3 * for_size)) {
                    k++;
                }
                if (k > (*new_size - 1)) { // if not enough space for input data
                    *new_size += (int)round(0.1 * *new_size);
                    extended_tab = new tar[*new_size];
                    for (l = 0; l < size; l++) {
                        extended_tab[l] = tab[l];
                    }
                    delete [] tab;
                    size = *new_size;
                    tab = extended_tab;
                }
            }
        }
    }
    return tab;   
}

// Filtruje dane wejściowe w celu
// usunięcia tytułów filmów,
// którym brakuje rankingów
tar* filter_data (tar* tab, int* size) {
    tar* filtered_tab = new tar[*size], * tmp_tab;
    int i, j = 0;
    
    for (i = 0; i < *size; i++) {
        if (tab[i].get_rating() != -1) { // if a title has a rating
            filtered_tab[j] = tab[i];
            j++;
        }
    }
    *size = j;
    tmp_tab = new tar[j];
    for (i = 0; i < j; i++) {
        tmp_tab[i] = filtered_tab[i];
    }
    delete [] filtered_tab;
    filtered_tab = new tar[j];
    for (i = 0; i < j; i++) {
        filtered_tab[i] = tmp_tab[i];
    }
    delete [] tmp_tab;
    delete [] tab;
    return filtered_tab;
}

// Zapisuje dane wyjściowe do pliku
void save_data (tar* tab, int size, string file_name) {
    ofstream data_file(file_name);

    for (int i = 0; i < size; i++) {
        if (data_file.good()) {
            data_file << tab[i].get_rating() << ", " << tab[i].get_title() << endl;
        }
    }
}