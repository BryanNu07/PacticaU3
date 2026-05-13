#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    const int MAX = 40;

    string nombres[MAX];

    float nota1[MAX];
    float nota2[MAX];
    float nota3[MAX];
    float nota4[MAX];

    float promedio[MAX];

    int cantidad = 0;
    int opcion;

    float num1, num2;


    ifstream archivoNombres("../resultados/nombres.txt");

    if(!archivoNombres.is_open()) {

        cout << "No se pudo abrir nombres.txt" << endl;
        return 1;
    }

    while(cantidad < MAX &&
          getline(archivoNombres, nombres[cantidad])) {

        cantidad++;
    }

    archivoNombres.close();


    ifstream archivoNotas("../resultados/notas.txt");

    if(!archivoNotas.is_open()) {

        cout << "No se pudo abrir notas.txt" << endl;
        return 1;
    }

    for(int i = 0; i < cantidad; i++) {

        archivoNotas >> nota1[i]
                      >> nota2[i]
                      >> nota3[i]
                      >> nota4[i];

        promedio[i] =
        (nota1[i] +
         nota2[i] +
         nota3[i] +
         nota4[i]) / 4;
    }

    archivoNotas.close();


    do {

        cout << "\n========== MENU ==========" << endl;

        cout << "1. Mostrar lista actual" << endl;
        cout << "2. Ver aprobados" << endl;
        cout << "3. Ver reprobados" << endl;
        cout << "4. Buscar estudiante" << endl;
        cout << "5. Mostrar mejor promedio" << endl;
        cout << "6. Mostrar peor promedio" << endl;
        cout << "7. Añadir estudiante" << endl;
        cout << "8. Operaciones basicas" << endl;
        cout << "9. Salir" << endl;

        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1: {

                cout << "\n===== LISTA ACTUAL =====\n";

                for(int i = 0; i < cantidad; i++) {

                    cout << "\nNombre: "
                         << nombres[i]
                         << endl;

                    cout << "Nota 1: "
                         << nota1[i]
                         << endl;

                    cout << "Nota 2: "
                         << nota2[i]
                         << endl;

                    cout << "Nota 3: "
                         << nota3[i]
                         << endl;

                    cout << "Nota 4: "
                         << nota4[i]
                         << endl;

                    cout << "Promedio: "
                         << promedio[i]
                         << endl;

                    if(promedio[i] >= 7) {

                        cout << "Estado: APROBADO" << endl;

                    } else {

                        cout << "Estado: REPROBADO" << endl;
                    }

                    cout << "-------------------------" << endl;
                }

                break;
            }


            case 2: {

                cout << "\n===== APROBADOS =====\n";

                for(int i = 0; i < cantidad; i++) {

                    if(promedio[i] >= 7) {

                        cout << nombres[i]
                             << " -> "
                             << promedio[i]
                             << endl;
                    }
                }

                break;
            }


            case 3: {

                cout << "\n===== REPROBADOS =====\n";

                for(int i = 0; i < cantidad; i++) {

                    if(promedio[i] < 7) {

                        cout << nombres[i]
                             << " -> "
                             << promedio[i]
                             << endl;
                    }
                }

                break;
            }


            case 4: {

                cin.ignore();

                string buscar;
                bool encontrado = false;

                cout << "\nIngrese nombre del estudiante: ";
                getline(cin, buscar);

                for(int i = 0; i < cantidad; i++) {

                    if(nombres[i] == buscar) {

                        cout << "\n===== ESTUDIANTE =====" << endl;

                        cout << "Nombre: "
                             << nombres[i]
                             << endl;

                        cout << "Promedio: "
                             << promedio[i]
                             << endl;

                        if(promedio[i] >= 7) {

                            cout << "Estado: APROBADO" << endl;

                        } else {

                            cout << "Estado: REPROBADO" << endl;
                        }

                        encontrado = true;
                    }
                }

                if(!encontrado) {

                    cout << "\nEstudiante no encontrado." << endl;
                }

                break;
            }


            case 5: {

                int mejor = 0;

                for(int i = 1; i < cantidad; i++) {

                    if(promedio[i] > promedio[mejor]) {

                        mejor = i;
                    }
                }

                cout << "\n===== MEJOR PROMEDIO =====" << endl;

                cout << "Nombre: "
                     << nombres[mejor]
                     << endl;

                cout << "Promedio: "
                     << promedio[mejor]
                     << endl;

                break;
            }


            case 6: {

                int peor = 0;

                for(int i = 1; i < cantidad; i++) {

                    if(promedio[i] < promedio[peor]) {

                        peor = i;
                    }
                }

                cout << "\n===== PEOR PROMEDIO =====" << endl;

                cout << "Nombre: "
                     << nombres[peor]
                     << endl;

                cout << "Promedio: "
                     << promedio[peor]
                     << endl;

                break;
            }


            case 7: {

                if(cantidad >= MAX) {

                    cout << "\nNo se pueden agregar mas estudiantes." << endl;
                    break;
                }

                cin.ignore();

                cout << "\n===== NUEVO ESTUDIANTE =====" << endl;

                cout << "Nombre: ";
                getline(cin, nombres[cantidad]);

                cout << "Nota 1: ";
                cin >> nota1[cantidad];

                cout << "Nota 2: ";
                cin >> nota2[cantidad];

                cout << "Nota 3: ";
                cin >> nota3[cantidad];

                cout << "Nota 4: ";
                cin >> nota4[cantidad];

                promedio[cantidad] =
                (nota1[cantidad] +
                 nota2[cantidad] +
                 nota3[cantidad] +
                 nota4[cantidad]) / 4;

                ofstream agregarNombre(
                    "../resultados/nombres.txt",
                    ios::app
                );

                agregarNombre
                << nombres[cantidad]
                << endl;

                agregarNombre.close();

                ofstream agregarNotas(
                    "../resultados/notas.txt",
                    ios::app
                );

                agregarNotas
                << nota1[cantidad] << " "
                << nota2[cantidad] << " "
                << nota3[cantidad] << " "
                << nota4[cantidad]
                << endl;

                agregarNotas.close();

                cout << "\nEstudiante agregado correctamente." << endl;

                cantidad++;

                break;
            }

            case 8: {

                cout << "\n===== OPERACIONES BASICAS =====" << endl;

                cout << "Ingrese el primer numero: ";
                cin >> num1;

                cout << "Ingrese el segundo numero: ";
                cin >> num2;

                cout << "\nSuma: "
                     << num1 + num2
                     << endl;

                cout << "Resta: "
                     << num1 - num2
                     << endl;

                cout << "Multiplicacion: "
                     << num1 * num2
                     << endl;

                if(num2 != 0) {

                    cout << "Division: "
                         << num1 / num2
                         << endl;

                } else {

                    cout << "No se puede dividir para cero."
                         << endl;
                }

                break;
            }


            case 9: {

                cout << "\nSaliendo del programa..." << endl;

                break;
            }

            default: {

                cout << "\nOpcion invalida." << endl;
            }
        }

    } while(opcion != 9);

    return 0;
}