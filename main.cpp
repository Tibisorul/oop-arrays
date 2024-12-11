#include <cstdint>
#include <iostream>
#include <valarray>
#include <vector>

#include "FilterOperation.h"
#include "SortOperation.h"
#include "StatisticsOperation.h"
#include "Array/Array.h"
#include "Statistics/Statistics.h"
#include "ArrayMenu/ArrayMenu.h"



/*
class Array;
using namespace std;


class Element {
    int valoare;
    public:
    explicit Element(int valoare = 0) {
        this->valoare = valoare;
    }

    int getValoare() const {
        return valoare;
    }
    void setValoare(int valoare) {
        this->valoare = valoare;
    }

    bool operator<(const Element& other) const { return valoare < other.valoare; }
    bool operator>(const Element& other) const { return valoare > other.valoare; }

    bool operator==(const Element& other) const { return valoare == other.valoare; }
    bool operator!=(const Element& other) const { return valoare != other.valoare; }

    friend ostream& operator<<(ostream& os, const Element& elem) {
        os << elem.valoare;
        return os;
    }
};



class Array{
private:
    int n;
    Element *v; // pointerul null pt alocare dinamica
public:

    //constructori cu si fara parametri
    Array() {
        n=1;
        v= new Element[1];
        v[0].setValoare(0);

    }

    Array(int n,const  int valori[]){
        this->n = n;
        v = new Element[n];
        for(int i = 0; i < n; i++){
            v[i].setValoare(valori[i]);
        }
    }

    //constructor de copiere

    Array(const Array &a){
        n = a.n;
        v = new Element[n];
        for(int i = 0; i < n; i++) {
            v[i] = a.v[i];
        }
    }

    Array& operator=(const Array& a) {
        if (this != &a) {  // verificare de auto-atribuire
            delete[] v;  // Eliberăm memoria existentă

            n = a.n;
            v = new Element[n];  // Alocăm memorie pentru array-ul de Elementi

            for (int i = 0; i < n; i++) {
                v[i] = a.v[i];  // Copiem fiecare element
            }
        }
        return *this;
    }

    //destructor
     ~Array() {
        delete []v;
    }

    //getteri
    // de obicei ii facem constant deoarece nu se modifica obiectul

    int getN() const {
        return n;
    }

    /*
    Element *getV() const {
        return v;
    }

    //avem un singur setter deoarece nu are sens ca il setam pe N fara a-l seta pe v sau invers
    void setNV(int n, const int _v[]) {
        delete[] v;
        this->n = n;
        v = new Element[n];
        for(int i=0;i<n;i++){
            v[i].setValoare(_v[i]);
        }
    }#1#



    //metodele pentru suma, maxim si minim sunt constante deoarece acestea nu modifica array-ul
    long long getSum()const{
        //iteram prin toate elementele vectorului si calculam suma
        long long sum = 0;
        for(int i = 0; i < n; i++) sum += v[i].getValoare();

        return sum;

    }

    int getMax() const {
        int maxim = INT32_MIN; // INT32_MIN valoarea minima din INT;
        for(int i = 0; i < n; i++)
            maxim = max(maxim, v[i].getValoare());
        return maxim;
    }

    int getMin() const {
        int minim = INT32_MAX; // INT32_MAX valoarea maxima din INT;
        for(int i = 0; i < n; i++)
            minim = min(minim, v[i].getValoare());
        return minim;
    }

    int getPozMax() const {
        int maxim = INT32_MIN, poz=0;

        //daca maximul se regaseste de mai multe ori, o vom returna pe prima dintre acestea

        for(int i=0; i<n;i++)
            if(maxim < v[i].getValoare()){
                maxim = v[i].getValoare();
                poz = i;
            }

        return poz;
    }

    int getPozMin() const {
        int minim = INT32_MAX, poz=0;

        //daca minimul se regaseste de mai multe ori, o vom returna pe prima dintre acestea

        for(int i=0; i<n;i++)
            if(minim > v[i].getValoare()){
                minim = v[i].getValoare();
                poz = i;
            }
        return poz;
    }


    //am facut posibila si sortarea descrescatoare prin parametrul optional order
    //daca order este un numar negativ, atunci sortarea se va realiza descrescator
    void sort(int order=1){
        if(order >= 0 ) order =1;
        else order =-1;

        //bubble sort

        for(int i = 1; i < n; i++){
            for(int j=0; j < n-i; j++){
                if(order * v[j].getValoare() > order *v[j+1].getValoare()){ //daca order este -1, sortarea se va realiza descrescator
                    Element aux = v[j];
                    v[j] = v[j+1];
                    v[j+1] = aux;
                }
            }
        }

    }

    //Operatori:


    bool operator==( Array a) const {
        if(n != a.n) return false;

        for(int i=0;i<n;i++){
            if(v[i] != a.v[i]) return false;
        }

        return true;
    }

    bool operator!=( Array a) const {
        if(n != a.n) return true;

        for(int i=0;i<n;i++){
            if(v[i] != a.v[i]) return true;
        }

        return false;
    }

    Element& operator[] (int i){
        if(i<n)
        return v[i];
        else return v[0]; // daca indicele dat nu exista in vector, returam valoare primului element
    }

    const Element& operator[](int i) const {
        if (i < n) {
            return v[i];
        } else {
            return v[0];  // Dacă indexul este invalid, returnăm primul element
        }
    }



    // Definim operatorii >> si << ca functii friend pentru ca acestia sa aiba acces la datele private ale clasei array
    friend ostream& operator << (ostream& os, Array a);
    friend istream& operator >> (istream& is, Array &a);
};

ostream& operator << (ostream& os, Array a){
    os<<"Vectorul are "<< a.n<<" elemente:\n";
    for(int i=0;i<a.n;i++){
        os<<a.v[i]<<" ";
    }
    os<<"\n";

    return os;
}

class Statistics {
public:
    static double getMediaElementelor(const Array& arr) {
        if (arr.getN() == 0) return 0;
        return static_cast<double>(arr.getSum()) / arr.getN();
    }

    static double getVarianta(const Array& arr) {
        if (arr.getN() == 0) return 0;
        double mean = getMediaElementelor(arr);
        double variance = 0;

        for(int i = 0; i < arr.getN(); i++) {
            variance += pow(arr[i].getValoare() - mean, 2);
        }
        return variance / arr.getN();
    }

    static double getMediana(Array arr) {
        arr.sort();
        int n = arr.getN();
        if(n % 2 == 0) {
            return (arr[n / 2 - 1].getValoare() + arr[n / 2].getValoare()) / 2;
        }
        else {
            return arr[n / 2].getValoare();
        }
    }
};


istream& operator >> (istream& is, Array &a){
    cout<<"Introduceti numarul de elemente: ";
    is>>a.n;
    cout<<"Introduceti "<<a.n<<" elemente: ";

    delete[] a.v;
    a.v = new Element[a.n];
    for (int i = 0; i < a.n; i++) {
        int temp_val;
        is >> temp_val;
        a.v[i].setValoare(temp_val);  // Setăm valoarea fiecărui Element
    }
    return is;
}

class ArrayMenu {
private:
    vector<Array> arrays;
public:
    ArrayMenu() {}

    void run() {
        int input;
        cout << "Aveti " << arrays.size() << " array-uri. Alegeti o optiune:\n"
             << "1. Adaugati un array.\n"
             << "2. Stergeti un array.\n"
             << "3. Vizualizati un array.\n"
             << "0. Iesire.\n";
        cin >> input;

        while(input != 0) {
            switch (input) {
                case 1:
                    addArray();
                break;
                case 2:
                    removeArray();
                break;
                case 3:
                    viewArray();
                break;
                default:
                    cout << "Optiune invalida! Va rugam sa reintroduceti.\n";
                break;
            }
            cout << "Aveti " << arrays.size() << " array-uri. Alegeti o optiune:\n"
                 << "1. Adaugati un array.\n"
                 << "2. Stergeti un array.\n"
                 << "3. Vizualizati un array.\n"
                 << "0. Iesire.\n";
            cin >> input;
        }
    }
private:
    void addArray() {
        Array a;
        cout << "Introduceti valorile pentru noul array:\n";
        cin >> a;
        arrays.push_back(a);
        cout << "Array adaugat cu succes!\n";
    }
    void removeArray() {
        int x;
        cout << "Introduceti numarul array-ului pe care doriti sa il stergeti ( 1 - " << arrays.size() << " ):\n";
        cin >> x;

        if(x < 1 || x > static_cast<int>(arrays.size())) {
            cout << "Acest array nu exista, va rugam sa reintroduceti.\n";
            return;
        }
        arrays.erase(arrays.begin() + x - 1);
        cout << "Array-ul a fost sters cu succes!\n";
    }

    void viewArray() {
        int arr;
        cout << "Introduceti numarul array-ului pe care doriti sa il vizualizati (1 - " << arrays.size() << "): ";
        cin >> arr;

        if (arr < 1 || arr > static_cast<int>(arrays.size())) {
            cout << "Acest array nu exista, va rugam reintroduceti.\n";
            return;
        }

        Array& selectedArray = arrays[arr - 1];
        cout << selectedArray;

        int option;
        cout << " Alegeti o optiune:\n"
             << "1. Calculati minimul.\n"
             << "2. Calculati maximul.\n"
             << "3. Calculati pozitia minimului.\n"
             << "4. Calculati pozitia maximului.\n"
             << "5. Calculati suma elementelor.\n"
             << "6. Reintroduceti elementele.\n"
             << "7. Sortati elementele.\n"
             << "8. Afisati statistici (media, varianța, mediana).\n"
             << "0. Inapoi.\n";
        cin >> option;

        while (option != 0) {
            if (option == 8) {
                displayStatistics(selectedArray);
            } else {
                handleArrayOption(selectedArray, option);
            }
            cout << selectedArray;
            cout << " Alegeti o optiune:\n"
                 << "1. Calculati minimul.\n"
                 << "2. Calculati maximul.\n"
                 << "3. Calculati pozitia minimului.\n"
                 << "4. Calculati pozitia maximului.\n"
                 << "5. Calculati suma elementelor.\n"
                 << "6. Reintroduceti elementele.\n"
                 << "7. Sortati elementele.\n"
                 << "8. Afisati statistici (media, varianța, mediana).\n"
                 << "0. Inapoi.\n";
            cin >> option;
        }
    }
    void handleArrayOption(Array& array, int option) {
        switch (option) {
            case 1:
                cout << "Valoarea minima din array este: " << array.getMin() << ".\n";
            break;
            case 2:
                cout << "Valoarea maxima din array este: " << array.getMax() << ".\n";
            break;
            case 3:
                cout << "Pozitia valorii minime din array este: " << array.getPozMin() << ".\n";
            break;
            case 4:
                cout << "Pozitia valorii maxime din array este: " << array.getPozMax() << ".\n";
            break;
            case 5:
                cout << "Suma elementelor din array este: " << array.getSum() << ".\n";
            break;
            case 6:
                cout << "Reintroduceti valorile pentru array:\n";
            cin >> array;
            break;
            case 7:
                int order;
            cout << "Crescator / Descrescator? (1 / 0): ";
            cin >> order;
            array.sort(order == 1 ? 1 : -1);
            cout << "Array-ul a fost sortat!\n";
            break;
            default:
                cout << "Optiune invalida!\n";
            break;
        }
    }

    void displayStatistics(const Array& array) {
        cout << "Statistici pentru array-ul selectat:\n";
        cout << "Media: " << Statistics::getMediaElementelor(array) << "\n";
        cout << "Varianța: " << Statistics::getVarianta(array) << "\n";
        cout << "Mediana: " << Statistics::getMediana(array) << "\n";
    }
};

int main(){
    //Meniu

    ArrayMenu menu;
    menu.run();
    return 0;
}*/

int main() {
    ArrayMenu menu;

    // Creăm operațiuni pentru testare
    const SortOperation sortOp(std::vector<int>{3, 1, 4, 1, 5, 9});
    const StatisticsOperation statsOp(std::vector<int>{3, 1, 4, 1, 5, 9});
    const FilterOperation filterOp(std::vector<int>{3, 1, 4, 1, 5, 9});

    // Apelăm meniul principal
    menu.run();

    // Exemplu de utilizare a funcției handleOperation
    std::cout << "Testing operation handling:\n";
    menu.handleOperation(sortOp);
    menu.handleOperation(statsOp);
    menu.handleOperation(filterOp);

    return 0;
}







/*
#include <iostream>
#include <array>

#include <Helper.h>

int main() {
    std::cout << "Hello, world!\n";
    std::array<int, 100> v{};
    int nr;
    std::cout << "Introduceți nr: ";
    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////
    std::cin >> nr;
    /////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < nr; ++i) {
        std::cout << "v[" << i << "] = ";
        std::cin >> v[i];
    }
    std::cout << "\n\n";
    std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
    for(int i = 0; i < nr; ++i) {
        std::cout << "- " << v[i] << "\n";
    }
    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////
    ///                Exemplu de utilizare cod generat                     ///
    ///////////////////////////////////////////////////////////////////////////
    Helper helper;
    helper.help();
    ///////////////////////////////////////////////////////////////////////////
    return 0;
}
*/
