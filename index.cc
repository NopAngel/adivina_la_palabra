#include <iostream>
/* number random */
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <sstream>

void jugar(std::string palabra[], int numeroDePalabras, int indice_aleatorio, std::string randomPalabra, int vida);


int contarPalabras(const std::string& texto) {
    std::istringstream stream(texto);
    std::string palabra;
    int contador = 0;
    
    while (stream >> palabra) {
        contador++;
    }
    
    return contador;
}

void componenteReintentar(int vida) {

    std::string palabras_jugar[] = {"agua", "teclado", "mouse", "monitor", "telefono", "texto", "caliente", "audifonos", "mezcla"};
    int indice_aleatorio = std::rand() % 9;
    std::string randomPalabra = palabras_jugar[indice_aleatorio];
    int numeroDePalabras = contarPalabras(randomPalabra);
    jugar(palabras_jugar, numeroDePalabras, indice_aleatorio, randomPalabra, vida);
    std::string resPrincipal;
    std::cin >> resPrincipal;
    std::transform(resPrincipal.begin(), resPrincipal.end(), resPrincipal.begin(), ::tolower);
     if(resPrincipal == randomPalabra) {
        std::cout << "has ganado";
    } else if(vida >= 2) {
         vida--;
        componenteReintentar(vida);
    } else {
        std::cout << "Has perdido." << std::endl;
        std::cout << "=============================================" << std::endl;
        std::cout << "                                             " << std::endl;
        std::cout << "         Presione cualquier tecla            " << std::endl;
        std::cout << "         Para reintentar                     " << std::endl;
        std::cout << "                             " << std::endl;
        std::cout << "         /salir - Salir del juego                     " << std::endl;
        std::cout << "                                             " << std::endl;
        std::cout << "=============================================" << std::endl;

   std::string res;
    std::cin >> res;
    if(res == "/salir") {
        exit(0);
    }

    }

    
        
}



int main() {
    std::cout << "=============================================" << std::endl;
    std::cout << "               ADIVINA LA PALABRA            " << std::endl;
    std::cout << "         /salir - Salir del Juego            " << std::endl;
    std::cout << "         Presione cualquier tecla            " << std::endl;
    std::cout << "            para empezar el juego            " << std::endl;
    std::cout << "                                             " << std::endl;
    std::cout << "            made by NopAngel            " << std::endl;
    std::cout << "=============================================" << std::endl;

    std::string res;
    std::cin >> res;
    std::srand(std::time(0));
    while(res != "/salir"){
        int vida = 3;
        std::string palabras_jugar[] = {"agua", "teclado", "mouse", "monitor", "telefono", "texto", "caliente", "audifonos", "mezcla"};
        int indice_aleatorio = std::rand() % 9;
        std::string randomPalabra = palabras_jugar[indice_aleatorio];
        int numeroDePalabras = contarPalabras(randomPalabra);
        jugar(palabras_jugar, numeroDePalabras, indice_aleatorio, randomPalabra, vida);
        std::string resPrincipal;
        std::cin >> resPrincipal;
        std::transform(resPrincipal.begin(), resPrincipal.end(), resPrincipal.begin(), ::tolower);

       if(resPrincipal == randomPalabra) {
        std::cout << "Has acertado la palabra!" << std::endl << std::endl << std::endl;
       } else {
        vida--;
        componenteReintentar(vida);
       }

       if(vida == 0) {
        std::cout << "Has Perdido :(";
       }
        
    }
    return 0;
}


void jugar(std::string palabra[], int numeroDePalabras, int indice_aleatorio, std::string randomPalabra, int vida){
    std::cout << "\n\n\nDescubre la palabra!                   VIDA:" << vida << "\n";

   for (size_t i = 0; i < randomPalabra.length(); i++)
    {
        std::cout << "-";
    }
    
}