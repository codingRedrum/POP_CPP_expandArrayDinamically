// comment below

#include <iostream>
using namespace std;

void zad1(int n);


typedef struct tablica
{
    int *A;
    int size;
} Ttablica;

Ttablica wstaw(Ttablica naz, int liczba);
int najwieksza(Ttablica naz);
int najmniejsza(Ttablica naz);
double sredniaDod(Ttablica naz);
bool czyJedynka(Ttablica naz);

int main(int argc, const char * argv[]) {
    
    Ttablica tab1;
    tab1.size = 0;
    tab1.A = nullptr;
    
    int zmienna;
    
    do {
        cin >> zmienna;
        if (zmienna != 0) {
        tab1 = wstaw(tab1, zmienna);
        }
    } while (zmienna != 0);
    
    cout << "Najwieksza liczba: " << najwieksza(tab1) << endl;
    cout << "Najmniejsza liczba: " << najmniejsza(tab1) << endl;
    cout << "Srednia wynosi: " << sredniaDod(tab1) << endl;
    cout << "czy jest jedynka: " <<czyJedynka(tab1) << endl;
 
    return 0;
}

double sredniaDod(Ttablica naz)
{
    double wynik = 0.0;
    int licznik = 0;
    
    for (int i = 0; i < naz.size; i++) {
        if (naz.A[i] > 0) {
            licznik++;
            wynik += naz.A[i];
        }
    }
    if (licznik > 0) {
        return wynik/licznik;
    } else
        return 0;
    
}

bool czyJedynka(Ttablica naz)
{
    bool ret = false;
    for (int i = 0; i < naz.size && !ret; i++) {
        if (naz.A[i] == 1) {
            ret = true;
        }
    }
    return ret;
}

int najwieksza(Ttablica naz)
{
    int temp = naz.A[0];
    int i;
    for (i = 0; i < naz.size; i++) {
        if (naz.A[i] > temp) {
            temp = naz.A[i];
        }
    }
    
    return temp;
}

int najmniejsza(Ttablica naz)
{
    int temp = naz.A[0];
    int i;
    for (i = 0; i < naz.size; i++) {
        if (naz.A[i] < temp) {
            temp = naz.A[i];
        }
    }
    
    return temp;
}

Ttablica wstaw(Ttablica naz, int liczba)
{
    Ttablica ret;
    int i;
    if (naz.size == 0) {
        ret.size = 1;
        ret.A = new int;
        ret.A[0] = liczba;

    } else{
        ret.size = naz.size+1;
        ret.A = new int[ret.size];
        for (i = 0; i < naz.size; i++) {
            ret.A[i] = naz.A[i];
        }
        ret.A[ret.size-1] = liczba;
    }
        
    return ret;
}

void zad1(int n)
{
    int dodatnie = 0;
    int ujemne = 0;
    int parzyste = 0;
    bool czyJestZero;
    
    int *tab = new int[n];
    // wczytujemy liczby
    for (int i = 0; i < n; i++) {
        tab[i] = i;
        // mozemy rowniez *(tab + i) = i
    }
    // spr ile parzystych
    for (int i = 0; i < n; i++) {
        if ((tab[i] % 2 == 0)) {
            parzyste++;
        }
        // dodatnie czy ujemne
        if (tab[i] < 0) {
            ujemne++;
        } else if (tab[i] == 0)
        {
            czyJestZero = true;
        } else //
            dodatnie++;
    }
    // ktorych wiecej
    if (dodatnie > ujemne) {
        cout<< "Liczb dodatnich jest wiecej. \n";
    } else
        cout<< "Liczb ujemnych jest wiecej. \n";

}

/*
 2. Program wczytuje liczby całkowite i dokłada je do tablicy dynamicznej na bieżąco, przestaje wstawiać liczby do tej tablicy po podaniu liczby 0, tego zera nie wstawia do tablicy. Po skończeniu wstawiania liczb program wykona następujące rzeczy:
 a) wyznaczy największą i najmniejszą liczbę w tej tablicy
 b) obliczy średnią artytmetyczną liczb dodatnich z tej tablicy
 c) sprawdza czy jest jedynka
 ---------------
 do rozwiązania najlepiej jest zastosować typ danych w strukturze
 struct tablica
 {
   int *A;
   int size;
 }
 */
