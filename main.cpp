#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

// Función para determinar los estados equivalentes
vector<pair<int, int>> encontrarEstadosEquivalentes(int estados, vector<int> finales, map<int, map<char, int>> transiciones, set<char> alfabeto) {
    vector<vector<bool>> tabla(estados, vector<bool>(estados, false));

    // Marcar estados que son finales y no finales
    for (int i = 0; i < estados; i++) {
        for (int j = i + 1; j < estados; j++) {
            bool esFinalI = (find(finales.begin(), finales.end(), i) != finales.end());
            bool esFinalJ = (find(finales.begin(), finales.end(), j) != finales.end());
            if (esFinalI != esFinalJ) {
                tabla[i][j] = true;
            }
        }
    }

    // Comparar transiciones y marcar diferencias
    bool cambios = true;
    while (cambios) {
        cambios = false;
        for (int i = 0; i < estados; i++) {
            for (int j = i + 1; j < estados; j++) {
                if (!tabla[i][j]) {
                    for (char simbolo : alfabeto) {
                        int transI = transiciones[i][simbolo];
                        int transJ = transiciones[j][simbolo];

                        // Depuración: Verificar las transiciones que se están comparando
                        cout << "Comparando estados " << i << " y " << j
                             << " para símbolo '" << simbolo << "': "
                             << transI << " -> " << transJ << endl;

                        if (tabla[min(transI, transJ)][max(transI, transJ)]) {
                            tabla[i][j] = true;
                            cambios = true;

                            // Depuración: Indicar cuándo se marca una diferencia
                            cout << "Marcando (" << i << ", " << j << ") como distinguibles debido a "
                                 << simbolo << endl;

                            break;
                        }
                    }
                }
            }
        }
    }

    // Obtener pares de estados equivalentes
    vector<pair<int, int>> equivalentes;
    for (int i = 0; i < estados; i++) {
        for (int j = i + 1; j < estados; j++) {
            if (!tabla[i][j]) {
                equivalentes.push_back({i, j});
            }
        }
    }
    return equivalentes;
}

int main() {
    int estados, numFinales;
    cout << "Ingrese el número total de estados: ";
    cin >> estados;

    cout << "Ingrese el número de estados finales: ";
    cin >> numFinales;

    vector<int> finales(numFinales);
    cout << "Ingrese los estados finales: ";
    for (int i = 0; i < numFinales; i++) {
        cin >> finales[i];
    }

    set<char> alfabeto;
    cout << "Ingrese los símbolos del alfabeto (ejemplo: a b c): ";
    string entradaAlfabeto;
    cin.ignore();  // Para limpiar el buffer antes de getline()
    getline(cin, entradaAlfabeto);

    // Leer caracteres del alfabeto
    for (char c : entradaAlfabeto) {
        if (c != ' ') {
            alfabeto.insert(c);
        }
    }

    // Verificar que el alfabeto no esté vacío
    if (alfabeto.empty()) {
        cout << "Error: El alfabeto no puede estar vacío.\n";
        return 1;
    }

    map<int, map<char, int>> transiciones;
    cout << "\nIngrese las transiciones de la siguiente forma (separando cada numero con espacios):\n";
    cout << "Para cada estado, ingrese el estado de destino para cada símbolo del alfabeto.\n\n";

    // Leer transiciones
    for (int i = 0; i < estados; i++) {
        cout << "Estado " << i << ":\n";
        for (char simbolo : alfabeto) {
            int destino;
            cout << "  Para símbolo '" << simbolo << "' -> Estado destino: ";
            cin >> destino;
            transiciones[i][simbolo] = destino;
        }
    }

    // Mostrar las transiciones ingresadas
    cout << "\nTransiciones ingresadas:\n";
    for (int i = 0; i < estados; i++) {
        cout << "Estado " << i << ": ";
        for (char simbolo : alfabeto) {
            cout << simbolo << "->" << transiciones[i][simbolo] << "  ";
        }
        cout << endl;
    }

    // Calcular y mostrar los estados equivalentes
    vector<pair<int, int>> equivalentes = encontrarEstadosEquivalentes(estados, finales, transiciones, alfabeto);

    cout << "\nEstados equivalentes encontrados: ";
    if (equivalentes.empty()) {
        cout << "Ninguno";
    } else {
        for (auto par : equivalentes) {
            cout << "(" << par.first << ", " << par.second << ") ";
        }
    }
    cout << endl;

    return 0;
}
