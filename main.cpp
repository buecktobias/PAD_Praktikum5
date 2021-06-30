#include <iostream>
#include <ostream>
#include "aufgabe1_b.cpp"

int getCharLength(const char* cs){
    int i = 0;
    while(cs[i] != '\0'){
        i++;
    }
    return i;
}

void print_array_10(int* a ){
    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << std::endl;
    }
}
void print_array_10(char* a ){
    for (int i = 0; i < getCharLength(a); ++i) {
        std::cout << a[i];
    }
}

void start_aufgabe1b() {
    int *a = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << std::endl;
    }

    delete[] a;
    a = nullptr;
    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << std::endl;
    }
}
void start_aufgabe1a(){
    double* pd1 = new double;
    *pd1 = 9.8765;
    std::cout << pd1 << std::endl;
    std::cout << *pd1 << std::endl;
    delete pd1;
    pd1 = nullptr;
    std::cout << *pd1;
}

void start_aufgabe1c(){
    int* a = new int[10]{1,2,3,4,5,6,7,8,9,10};
    print_array_10(a);
}
/*
 * 1d)
 * d) Was macht die Funktion aus Aufgabenteil c), wenn das Datenfeld a nicht genau zehn
    Elemente enthält? Machen Sie einen Verbesserungsvorschlag, mit dem sich die praktische
    Einsetzbarkeit einer solchen Funktion entscheidend verbessert.
    -----------------
    Die Funktion funktioniert nur wenn das Array genau 10 Elemente hat, eine praktischere Lösung wäre es,
    die Funktion so zu verändern, dass sie bei beliebigere Länge funktioniert.
 *
 * Überzeugen Sie sich nochmals anhand Ihrer Lösungen für a) bis d) davon, dass Sie die
grundsätzlichen Mechanismen für Zeiger und dynamische Speicherallokation / –deallokation
wirklich verstanden haben.

 * */

int getArrayLength(const char* cs1){
    return (sizeof(cs1)/sizeof(cs1[0]));
}
void mytolower( char* cs){
    int i = 0;
    while (cs[i] != '\0') {
        cs[i] = std::tolower(cs[i], std::locale());
        i++;
    }
}



char* cstring_copier( const char* cs){
    int length = getCharLength(cs);
    char* copy = new char[length];
    for (int i = 0; i < length; ++i) {
        copy[i] = cs[i];
    }
    return copy;
}

void aufgabe2_a(){
    char* cs;
    int length = 9;
    cs = new char[length]{'H', 'a','l', 'l','o', ' ', 'C', '+', '+'};
    print_array_10(cs);
    mytolower(cs);
    print_array_10(cs);
    std::cout << getArrayLength(cs);
    delete[] cs;
    cs = nullptr;
}

void aufgabe2B(){
    int length = 9;
    char* cs = new char[length]{'H', 'a','l', 'l','o', ' ', 'C', '+', '+'};
    char* copyCs = cstring_copier(cs);
    print_array_10(copyCs);
}

void test(char* cs){
    char* copyCs = cstring_copier(cs);
    print_array_10(copyCs);
    std::cout << std::endl;
    mytolower(copyCs);
    print_array_10(copyCs);
    std::cout << std::endl;

}
void aufgabe2C(){
    test(new char[9]{'H', 'a','l', 'l','o', ' ', 'C', '+', '+'});
    test(new char[3]{'l','o','l'});
    test(new char[4]{'h','a', 'h', 'a'});
    test(new char[4]{'h','_', 'd', 'a'});
    test(new char[4]{'N','U','L','L'});
}

void aufgabe3(){
    {
        int k = 2;
        std::cout << &k << std::endl;
        int j = 2;
        std::cout << &j << std::endl;
        int i = 2;
        std::cout << &i << std::endl;
    }
    int* k = new int;
    *k= 2;
    std::cout << k << std::endl;
    int* j = new int;
    *j= 2;
    std::cout << j << std::endl;
    int* i = new int;
    *i= 2;
    std::cout << i << std::endl;
    delete i;
    delete j;
    delete k;
    int* l = new int;
    *l= 2;
    std::cout << l << std::endl;

}
/*
 * Aufgabe 3
 *  Beim Stack steigt die Adresse, beim Heap sinkt sie. Wenn man den Speicher beim Heap freigibt, sinkt die Adresse
 *
 */
int main() {
    aufgabe3();
    return 0;
}
