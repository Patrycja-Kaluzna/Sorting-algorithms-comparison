#ifndef DATA_STRUCTURE_HH
#define DATA_STRUCTURE_HH

#include <string>

using namespace std;

// Klasa modelująca strukturę danych
// danych do przechowywania tytułów 
// filmów i ich rankingów
class tar { // Title and rating
    
    // Tytuł filmu
    string title = "";

    // Ranking filmu (wartość -1, jeśli brak rankingu)
    int rating = -1;

    public: 

    tar () {}

    ~tar () {}

    // Wczytuje nowy tytuł filmu
    void set_title (string new_title) {
        title = new_title;
    }

    // Wczytuje nowy ranking filmu
    void set_rating (int new_rating) {
        rating = new_rating;
    }

    // Zwraca aktualny tytuł filmu
    string get_title () {
        string actual_title = title;
        return actual_title;
    }

    // Zwraca aktualny ranking filmu
    int get_rating () {
        int actual_rating = rating;
        return actual_rating;
    }

};

#endif