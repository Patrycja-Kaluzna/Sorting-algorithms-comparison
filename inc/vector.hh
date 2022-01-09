#ifndef VECTOR_HH
#define VECTOR_HH

// Szablon klasy modelującej pojęcie
// wektora, które cechują tablica 
// elementów, jego pojemność i 
// aktualna liczba elementów 
// znajdujących się w nim
template <typename type> 
class vector {

    // Tablica elementów
    type* tab_of_elements = new type[1];

    // Pojemność 
    int max_number_of_elements = 1;
    
    // Aktualna liczba elementów
    int actual_number_of_elements = 0;

    public:

    vector () {}

    ~vector () {}

    // Dodaje nowy element na koniec wektora
    void push_back (type new_element);

    // Zwraca aktualną liczbę elementów
    // znajdujących się w wektorze
    int size () const;

    // Zwraca element znajdujący się 
    // pod podanym indeksem w wektorze
    type operator [] (int index) const;

};

// Dodaje nowy element na koniec wektora
template <typename type>
void vector<type>::push_back (type new_element) {
    type* tmp_tab;
    int i;

    if (actual_number_of_elements == max_number_of_elements) { // if not enough space for a new element
        tmp_tab = new type[2 * max_number_of_elements];
        for (i = 0; i < max_number_of_elements; i++) {
            tmp_tab[i] = tab_of_elements[i];
        }
        delete [] tab_of_elements;
        max_number_of_elements *= 2;
        tab_of_elements = tmp_tab;
    }
    tab_of_elements[actual_number_of_elements] = new_element;
    actual_number_of_elements++;
} 

// Zwraca aktualną liczbę elementów
// znajdujących się w wektorze
template <typename type>
int vector<type>::size () const {
    return actual_number_of_elements;
}

// Zwraca element znajdujący się 
// pod podanym indeksem w wektorze
template <typename type>
type vector<type>::operator [] (int index) const {
    if (index <= actual_number_of_elements) {
        return tab_of_elements[index];
    }
}

#endif