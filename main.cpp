#include <iostream>   // For input and output operations
#include <vector>     // For using vectors
#include <cstdlib>    // For srand() and rand()
#include <ctime>      // For time() to seed the random number generator
#include <algorithm>  // For using find()
#include <cctype>     // For using toupper() function
#include <string>     // For using string class

using namespace std;

// Funkcija, lai zîmçtu karatavas atkarîbâ no kïûdu skaita
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

    // Íermenis un rokas
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

    // Kâjas
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

// Funkcija, lai izvçlçtos nejauðu vârdu
string izveletiesNejausuVardu() {
    vector<string> vardi = {
        "PROGRAMME", "KARATAVAS", "DATORS", "STUDENTS", "SKOLA", "AUKSNE","AUKS", "PUTNS", "ZIEDS", "KALNS",
        "GAISMA", "TILTS", "MAJA", "GRAMATA", "PILSETA", "GADS", "GADIJUMS", "BALTS", "MELNS", "ZALS",
        "SARKANS", "DZELTENA", "LIELS", "MAZS", "GARS", "SKOLA", "CILVEKS", "PRIEKS", "KAKIS", "SUNS", "UGUNS",
        "JURA", "LAPA", "SNIEGS", "MEZS", "KRASTS", "PATS", "MATE", "TEVS", "BRALIS", "MASA", "BERNS",
        "DARBS", "SKATS", "PUTENIS", "VASARA", "ZIEMA", "RUDENS", "PAVASARIS", "ZVAIGZNE", "DEBESIS",
        "SAULAINS", "MENESS", "PEDAS", "CELS", "KOKS", "ZEME", "JAKA", "ZEKES", "KURPES", "DIENA", "NAKTIS",
        "MIERS", "DABA", "LAIME", "EDA", "DZIVIBA", "SIRDS", "GAISMA", "SAULE", "TUMSAS", "UGUNS", "RÎTS",
        "KRESLA", "KRASA", "LIELUMS", "MAZUMS", "STUNDAS", "BRIDIS", "MINUTE", "SKAITLIS", "PULSS",
        "STUNDA", "SKAITITAIS", "PLANOTS", "TRAKS", "MIERIGS", "EKSAMENS", "TESTS", "SKOLAS", "PRAKSE",
        "UZDEVUMS", "ATSKAITE", "DELS", "MEITA", "VECAKS", "RADINIEKS", "BRALA", "MATES", "DZIVE", "GADS",
        "NEPIECIESAMIBA", "PARBAUDE", "PILSETA", "PIENEMSANA", "NOTIKUMS"
    };

    srand(time(0));

    return vardi[rand() % vardi.size()];
}

void spelet() {
    int speletajuSkaits;
    string vards;

    cout << "Izvelaties speletaju skaitu (1 vai 2): ";
    cin >> speletajuSkaits;

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

        char burts;
        cout << "Ievadi burtu: ";
        cin >> burts;

        burts = toupper(burts);

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

        cout << "Spelet velreiz? (J/N): ";
        cin >> atkal;

        atkal = toupper(atkal);
    } while (atkal == 'J');

    cout << "Paldies par speli!" << endl;

    return 0;
}
