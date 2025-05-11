#include <iostream>   // Ievades un izvades operācijām
#include <vector>     // Lai izmantotu vektorus
#include <cstdlib>    // Funkcijām srand() un rand()
#include <ctime>      // Funkcijai time(), lai inicializētu gadījuma skaitļu ģeneratoru
#include <algorithm>  // Lai izmantotu find() funkciju
#include <cctype>     // Lai izmantotu toupper() funkciju
#include <string>     // Lai izmantotu string klasi
#include <limits>     // Lai attīrītu nederīgu ievadi 

using namespace std;

// Funkcija, lai zīmētu karātavas atkarībā no kļūdu skaita
void zimeKaratavas(int kludas) {
    cout << "  _______" << endl;
    cout << "  |     |" << endl;

    // Galva
    cout << "  |     ";
    if (kludas > 0)
        cout << "O";
    else
        cout << " ";
    cout << endl;

    // Ķermenis un rokas
    cout << "  |    ";
    if (kludas > 2)
        cout << "/";
    else
        cout << " ";

    if (kludas > 1)
        cout << "|";
    else
        cout << " ";

    if (kludas > 3)
        cout << "\\";
    else
        cout << " ";
    cout << endl;

    // Kājas
    cout << "  |    ";
    if (kludas > 4)
        cout << "/";
    else
        cout << " ";
    cout << " ";
    if (kludas > 5)
        cout << "\\";
    else
        cout << " ";
    cout << endl;

    cout << " __|__" << endl << endl;
}

// Funkcija, lai izvēlētos nejaušu vārdu
string izveletiesNejausuVardu() {
    vector<string> vardi = {
        "PROGRAMME", "KARATAVAS", "DATORS", "STUDENTS", "SKOLA", "AUKSNE", "AUKS", "PUTNS", "ZIEDS", "KALNS",
        "GAISMA", "TILTS", "MAJA", "GRAMATA", "PILSETA", "GADS", "GADIJUMS", "BALTS", "MELNS", "ZALS"
    };

    srand(time(0));
    return vardi[rand() % vardi.size()];
}

// Funkcija, lai pārbaudītu spēlētāju skaita ievadi
int ievadiSpeletajuSkaitu() {
    int speletajuSkaits;
    do {
        cout << "Izvelaties speletaju skaitu (1 vai 2): ";
        cin >> speletajuSkaits;

        if (cin.fail() || (speletajuSkaits != 1 && speletajuSkaits != 2)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Nepareiza ievade! Ludzu, ievadiet ciparu 1 vai 2." << endl;
        }
    } while (speletajuSkaits != 1 && speletajuSkaits != 2);
    return speletajuSkaits;
}

// Funkcija, lai pareizi ievadītu burtu
char ievadiBurtu() {
    string ievade;
    char burts;

    do {
        cout << "Ievadi burtu: ";
        cin >> ievade;

        if (ievade.length() != 1 || !isalpha(ievade[0])) {
            cout << "Nepareiza ievade! Ludzu, ievadi tikai vienu burtu." << endl;
            continue;
        }

        burts = toupper(ievade[0]); 
        break;
    } while (true);

    return burts;
}

void spelet() {
    int speletajuSkaits = ievadiSpeletajuSkaitu();
    string vards;

    if (speletajuSkaits == 2) {
        cout << "1. speletajs, ievadi minamo vardu (lielajiem burtiem): ";
        cin >> vards;

               cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
             << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

        cout << "2. speletajs, vari sakt minet vardu!" << endl;
    } else {
        vards = izveletiesNejausuVardu();
    }

    string atminamiVardi(vards.length(), '_');
    vector<char> minetieBurti;
    int kludas = 0;
    bool uzvara = false;

    while (kludas < 6 && !uzvara) {
        zimeKaratavas(kludas);
        cout << "Vards: " << atminamiVardi << endl;
        cout << "Meginatie burti: ";

        for (char x : minetieBurti) cout << x << " ";
        cout << endl;

        char burts = ievadiBurtu(); // Izsauc ievades funkciju

        if (find(minetieBurti.begin(), minetieBurti.end(), burts) != minetieBurti.end()) {
            cout << "Tu jau meginaji so burtu!" << endl;
            continue;
        }

        minetieBurti.push_back(burts);
        bool atrasts = false;

        for (int i = 0; i < vards.length(); i++) {
            if (vards[i] == burts) {
                atminamiVardi[i] = burts;
                atrasts = true;
            }
        }

        if (!atrasts) {
            kludas++;
            cout << "Nepareizs burts! Tev ir " << (6 - kludas) << " dzivibas." << endl;
        }

        if (atminamiVardi == vards) uzvara = true;
    }

    zimeKaratavas(kludas);

    if (uzvara)
        cout << "Apsveicu! Tu uzvareji! Vards bija: " << vards << endl;
    else
        cout << "Diemzel tu zaudeji. Pareizais vards bija: " << vards << endl;
}

int main() {
    char atkal;

    do {
        spelet();

        do {
            cout << "Spelet velreiz? (J/N): ";
            cin >> atkal;
            atkal = toupper(atkal);

            if (cin.fail() || (atkal != 'J' && atkal != 'N')) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nepareiza ievade! Ludzu, ievadi 'J' lai spēlētu vēlreiz vai 'N' lai izietu." << endl;
            }
        } while (atkal != 'J' && atkal != 'N');

    } while (atkal == 'J');

    cout << "Paldies par speli!" << endl;

    return 0;
}


