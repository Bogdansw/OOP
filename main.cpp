#include <iostream>
#include <string>
using namespace std;

class Carte {
private:
    string titlu;
    string autor;
    int anPublicare;
    int numarPagini;
    bool disponibila;
    
public:
    Carte() {
        titlu = "Fara titlu";
        autor = "Anonim";
        anPublicare = 2000;
        numarPagini = 0;
        disponibila = true;
        cout << "Constructor implicit apelat" << endl;
    }
    
    Carte(string t, string a, int an, int pagini) {
        titlu = t;
        autor = a;
        anPublicare = an;
        numarPagini = pagini;
        disponibila = true;
        cout << "Constructor cu parametri apelat pentru: " << titlu << endl;
    }
    
    Carte(string t, string a, int an, int pagini, bool disp) {
        titlu = t;
        autor = a;
        anPublicare = an;
        numarPagini = pagini;
        disponibila = disp;
        cout << "Constructor complet apelat pentru: " << titlu << endl;
    }
    
    ~Carte() {
        cout << "Destructor apelat pentru: " << titlu << endl;
    }
    
    void afisareDetalii() {
        cout << "\n--- Detalii Carte ---" << endl;
        cout << "Titlu: " << titlu << endl;
        cout << "Autor: " << autor << endl;
        cout << "An publicare: " << anPublicare << endl;
        cout << "Numar pagini: " << numarPagini << endl;
        cout << "Status: " << (disponibila ? "Disponibila" : "Imprumutata") << endl;
    }
    
    void modificaTitlu(string titluNou) {
        titlu = titluNou;
        cout << "Titlul a fost modificat in: " << titlu << endl;
    }
    
    void modificaAutor(string autorNou) {
        autor = autorNou;
        cout << "Autorul a fost modificat in: " << autor << endl;
    }
    
    void imprumuta() {
        if (disponibila) {
            disponibila = false;
            cout << "Cartea \"" << titlu << "\" a fost imprumutata" << endl;
        } else {
            cout << "Cartea \"" << titlu << "\" este deja imprumutata" << endl;
        }
    }
    
    void returneaza() {
        if (!disponibila) {
            disponibila = true;
            cout << "Cartea \"" << titlu << "\" a fost returnata" << endl;
        } else {
            cout << "Cartea \"" << titlu << "\" nu era imprumutata" << endl;
        }
    }
};

int main() {
    
    cout << "Test Constructor 1:" << endl;
    Carte carte1;
    carte1.afisareDetalii();
    
    cout << "\nTest Constructor 2:" << endl;
    Carte carte2("Moara cu noroc", "Ioan Slavici", 1881, 120);
    carte2.afisareDetalii();
    
    cout << "\nTest Constructor 3:" << endl;
    Carte carte3("Amintiri din copilarie", "Ion Creanga", 1892, 180, true);
    carte3.afisareDetalii();
    
    cout << "\n=== Testare Metode ===\n" << endl;
    
    cout << "Test Metoda 2 - Modificare titlu:" << endl;
    carte1.modificaTitlu("Carte noua");
    
    cout << "\nTest Metoda 3 - Modificare autor:" << endl;
    carte1.modificaAutor("Autor necunoscut");
    carte1.afisareDetalii();
    
    cout << "\nTest Metoda 4 - Imprumutare:" << endl;
    carte2.imprumuta();
    carte2.afisareDetalii();
    
    cout << "\nTest Metoda 5 - Returnare:" << endl;
    carte2.returneaza();
    carte2.afisareDetalii();
    
    
    return 0;
}