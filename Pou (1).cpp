#include <iostream>

using namespace std;

//Declarar la clase 

class Mascota{
public:
        string nombre;
        int hambre;
        int cansancio;
        int salud;
        int monedas;
        int nivel;
        int xp;
};

void crearPou(Mascota &miPou){ // Función que siempre se hará al iniciar el juego

cout << "Bienvenido! como llamaras a tu Mascota?" << endl;
cin >> miPou.nombre;
miPou.hambre = 100;
miPou.cansancio = 100;
miPou.salud = 100;
miPou.monedas = 3000;
miPou.nivel = 5;
miPou.xp = 27;
cout << "Felicidades, Ahora cuidarás de " << miPou.nombre << endl;
cout << "(^w^)/ " << miPou.nombre << " Te manda saludos" << endl;
}

void dibujarBarra(int numero){ //Es para dibujar la barra

if (numero <= 0){
 cout << "[----------]" << endl;
 } else if (numero < 20){
  cout << "[#---------]" << endl;
  } else if (numero < 30){
   cout << "[##--------]" << endl;
   } else if (numero < 40){
    cout << "[###-------]" << endl;
    } else if (numero < 50){
     cout << "[####------]" << endl;
     } else if (numero < 60){
     cout << "[#####-----]" << endl;
     } else if (numero < 70){
      cout << "[######----]" << endl;
      } else if (numero < 80){
       cout << "[#######---]" << endl;
       } else if (numero < 90){
        cout << "[########--]" << endl;
        } else if (numero < 100){
         cout << "[#########-]" << endl;
         } else if (numero == 100){
          cout << "[##########]" << endl;
          }




}

void mostrarStat(Mascota &miPou){

cout << miPou.nombre << endl;
cout << "Nivel " << miPou.nivel << endl;
cout << "XP " << miPou.xp << endl;
cout << "Hambre" << endl;
dibujarBarra(miPou.hambre);
cout << "Energia" << endl;
dibujarBarra(miPou.cansancio);
cout << "Salud" << endl;
dibujarBarra(miPou.salud);
cout << "Monedas: " << miPou.monedas << endl;
}

void esperar(){ //Función de espera
char s;
cout << "Escribe cualquier letra para continuar" << endl;
cin >> s;
}

void dibujarPou(Mascota &miPou){

if (miPou.hambre > 40 && miPou.salud > 40 && miPou.cansancio > 30){
cout << "(0w0)" << endl;
} else if (miPou.hambre < 40 && miPou.salud> 40 && miPou.cansancio > 30){
cout << "(○□○)/" << endl;
} else if (miPou.hambre > 40 && miPou.salud < 40 && miPou.cansancio > 30 || miPou.hambre > 40 && miPou.salud > 40 && miPou.cansancio < 30){
cout << "(_._)" << endl;
} else if (miPou.hambre < 40 && miPou.salud < 40 && miPou.cansancio < 30){
cout << "(X.x)" << endl;
}
}

void limpiarConsola(){

system("clear");
}

void limitarStat(Mascota &miPou){

if (miPou.hambre < 0) { miPou.hambre = 0;}
if (miPou.cansancio < 0) { miPou.cansancio = 0;}
if (miPou.salud < 0) { miPou.salud = 0;}

}

int main(){

int opcion;
bool Gameloop = true;

Mascota miPou;
crearPou(miPou);
esperar();
limpiarConsola();
mostrarStat(miPou);
dibujarPou(miPou);
esperar();
do{ //Empieza el juego
limpiarConsola();
limitarStat(miPou);
cout << "Que quieres hacer?" << endl;
cout << "1.Jugar" << endl;
cout << "2.Comer" << endl;
cout << "3.Dormir cuesta 30 monedas" << endl;
cout << "4.Tienda" << endl;
cout << "5.Stats" << endl;
cout << "6.Guardar y cerrar el juego" << endl;
dibujarPou(miPou);
cin >> opcion;
switch (opcion){ //comprueba que opcion escogiste
case 1:
break;
case 2:
break;
case 3:
break;
case 4:
break;
case 5:
limpiarConsola();
miPou.hambre -= 3;
miPou.cansancio -= 1;
miPou.salud -= 2;
mostrarStat(miPou);
esperar();
break;
case 6:
break;

}
} while (Gameloop); //Aquí termina el Gameloop




return 0;
}