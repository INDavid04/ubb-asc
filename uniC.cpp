#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("test-lab-2024.in");

int main () {
    int numar_operatii, operatia, id, size, numar_adunari, capat = 0, v[1000] = { 0 };
    fin >> numar_operatii;
    // cout << "\nnumar operatii: " << numar_operatii;
    while (numar_operatii) {
        fin >> operatia;
        if (operatia == 1) {
            cout << "ADD";
            fin >> numar_adunari;
            // cout << "\nnumar adunari: " << numar_adunari;
            while (numar_adunari) {
                fin >> id >> size;
                for (int i = capat; i <= capat + size / 8; i++) {
                    v[i] = id;
                }
                // cout << "\ndescriptor si dimensiune: " << id << " si " << size;
                cout << "\n" << id << ": (" << capat << ", " << capat + size / 8 << ")";
                capat = capat + size / 8 + 1;
                numar_adunari--;
            }
        }
        if (operatia == 2) {
            cout << "\nGET";
            bool secventa = false;
            int id_get, capat_stang = 0, capat_drept = 0;
            fin >> id_get;
            for (int i = 0; i < 1000; i++) {
                if (v[i] == id_get && secventa == false) {
                    capat_stang = i;
                    secventa = true;
                }
                if (v[i] == id_get && v[i + 1] != id_get) {
                    capat_drept = i;
                }
            }
            cout << "\n(" << capat_stang << ", " << capat_drept << ")";
        }
        if (operatia == 3) {
            int id_delete, capat_stang = 0, capat_drept = 0;
            cout << "\nDELETE";
            fin >> id_delete;
            for (int i = 0; i <= capat; i++) {
                if (v[i] == id_delete) {
                    v[i] = 0;
                }
            }
            for (int i = 0; i <= capat; i++) {
                if ((i == 0 && v[i] != 0 && v[i] != v[i + 1]) || (v[i] != 0 && v[i] != v[i + 1] && v[i] != v[i - 1])) {
                    cout << "\n" << v[i] << ": (" << i << ", " << i << ")";
                }
                if (i == 0 || v[i] != 0 && v[i] == v[i + 1] && v[i] != v[i - 1]) {
                    capat_stang = i;
                    capat_drept = i;
                    while (i == 0 || (v[i] != 0 && v[i] == v[i + 1] && v[i] == v[i - 1]) || (v[i] != 0 && v[i] != v[i - 1] && v[i] == v[i + 1])) {
                        i++;
                        capat_drept = i;
                    }
                    cout << "\n" << v[i] << ": (" << capat_stang << ", " << capat_drept << ")";
                }
            }
        }
        if (operatia == 4) {
            cout << "\nDEFRAGMENTATION";
            int i = 0, capat_stang = 0, capat_drept = 0;
            while (v[i]) {
                i++;
            }
            while (v[i] == 0) {
                for (int j = i; j < capat; j++) {
                    v[j] = v[j + 1];
                }
            }
            for (i = 0; i < capat && v[i] != 0; i++) {
                if (v[i] != v[i + 1]) {
                    cout << "\n" << v[i] << ": (" << i << ", " << i << ")";
                } else {
                    capat_stang = i;
                    while (v[i] == v[i + 1]) {
                        i++;
                    }
                    capat_drept = i;
                    cout << "\n" << v[i] << ": (" << capat_stang << ", " << capat_drept << ")";
                }
            }
            if (capat_stang == 0 && capat_drept == 0) {
                cout << "\n(0, 0)";
            }
        }
        numar_operatii--;
    }
    
    // cout << "\n\nVectorul este: ";
    // for (int i = 0; i < 1000; i++) {
    //     cout << v[i] << " ";
    // }
    
    return 0;
}