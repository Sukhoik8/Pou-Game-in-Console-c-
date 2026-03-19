#include <iostream>
#include <conio.h>
#include <cstdlib> // Contiene rand() y srand()
#include <ctime> 

using namespace std;

//Declarar la clase 

class Mascota{ //Esto crea una Clase llamada Mascota
public:
        string nombre;
        int hambre;
        int cansancio;
        int salud;
        int monedas;
        int nivel;
        int xp;
		int inventario[5];
		/*
		0 = Hot Dogs
		recupera hambre, quita salud
		1 = Manzana
		Recupera hambre
		2 = Espagueti
		Recupera hambre, da cansancio
		3 = Pocion 
		Recupera salud, da hambre		
		4 Pocion estrella
		recupera todo el stats
		*/
};

void crearPou(Mascota &miPou){ // Función que siempre se hará al iniciar el juego

cout << "Bienvenido! como llamaras a tu Mascota?" << endl;
cin >> miPou.nombre;
miPou.hambre = 100;
miPou.cansancio = 100;
miPou.salud = 100;
miPou.monedas = 100;
miPou.nivel = 1;
miPou.xp = 0;

for (int i = 0; i < 5; i++){ //Le asigno 0 a cada item del inventario
	
miPou.inventario[i] = 0;	
	
}

cout << "Felicidades, Ahora cuidaras de " << miPou.nombre << endl;
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
        } else if (numero < 95){
         cout << "[#########-]" << endl;
         } else if (numero <= 100){
          cout << "[##########]" << endl;
          }




}

void mostrarStat(Mascota &miPou){ //Funcion para mostrar las stats del POU

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

void dibujarPou(Mascota &miPou){ //Funcion para Dibujar A Pou

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

void limpiarConsola(){ //Funcion para limpiar la Consola

for (int i = 0; i < 500; ++i) {
        std::cout << "\n";
}
}

void limitarStat(Mascota &miPou){ //Funcion para limitar las stats

if (miPou.hambre < 0) { miPou.hambre = 0;}
if (miPou.cansancio < 0) { miPou.cansancio = 0;}
if (miPou.salud < 0) { miPou.salud = 0;}

if (miPou.hambre > 100) { miPou.hambre = 100;}
if (miPou.cansancio > 100) { miPou.cansancio = 100;}
if (miPou.salud > 100) { miPou.salud = 100;}

}

void comer(Mascota &miPou){ 
    bool hayComida = false;
    limpiarConsola();
    
    // 1. Verificamos si hay ALGO en el inventario
    for (int i = 0; i < 5; i++){ // Cambiado a 5, tu array es de 5
        if (miPou.inventario[i] > 0){ 
            hayComida = true;
            break; 
        }
    }
    
    if (hayComida){ 
        int eleccion;
        cout << "--- BANQUETE DE " << miPou.nombre << " ---" << endl;
        cout << "1. Hot Dog (Cant: " << miPou.inventario[0] << ")" << endl;
        cout << "2. Manzana (Cant: " << miPou.inventario[1] << ")" << endl;
        cout << "3. Espagueti (Cant: " << miPou.inventario[2] << ")" << endl;
        cout << "4. Pocion (Cant: " << miPou.inventario[3] << ")" << endl;
        cout << "5. Pocion Estrella (Cant: " << miPou.inventario[4] << ")" << endl;
        cout << "6. Cancelar" << endl;
        cout << "Elige que darle: ";
        cin >> eleccion;

        // 2. Lógica de consumo
        if (eleccion >= 1 && eleccion <= 5) {
            if (miPou.inventario[eleccion - 1] > 0) {
                miPou.inventario[eleccion - 1]--; // Gastamos 1 item
                
                switch(eleccion - 1) {
                    case 0: // Hot Dog
                        miPou.hambre += 30;
                        miPou.salud -= 10;
                        cout << "Le encanto el Hot Dog, pero le dio acidez... (-10 Salud)" << endl;
                        break;
                    case 1: // Manzana
                        miPou.hambre += 15;
                        cout << "¡Que sano! Una manzana al dia..." << endl;
                        break;
                    case 2: // Espagueti
                        miPou.hambre += 40;
                        miPou.cansancio -= 20;
                        cout << "Muchos carbohidratos, ahora tiene sueño... (-20 Energia)" << endl;
                        break;
                    case 3: // Pocion
                        miPou.salud += 50;
                        miPou.hambre -= 10;
                        cout << "¡Salud recuperada! Pero tiene un poco de hambre." << endl;
                        break;
                    case 4: // Estrella
                        miPou.hambre = 100;
                        miPou.salud = 100;
                        miPou.cansancio = 100;
                        cout << "¡TU MASCOTA ESTA RADIANTE!" << endl;
                        break;
                }
            } else {
                cout << "No tienes de ese objeto. ¡Ve a la tienda!" << endl;
            }
        }
        esperar();
        
    } else {
        cout << "Lo siento, no hay comida u objetos en tu inventario." << endl;
        esperar();
    }
}

void tiendaPou(Mascota &miPou){ //Funcion para la tienda
	
	limpiarConsola();
	int eleccion;
	int precios[] = {25, 35, 30, 50, 200};
	string cosas[] = {"Hot Dogs", "Manzana", "Espagueti", "Pocion", "Pocion Estrella"};
	
	cout<<"Bienvenidos a la tienda!"<<endl;
	cout<<"1.Hot Dogs = 25$"<<endl;
	cout<<"2.Manzana = 35$"<<endl;
	cout<<"3.Espaguetti = 30$"<<endl;
	cout<<"4.Pocion = 50$"<<endl;
	cout<<"5.Pocion Estrella = 200$"<<endl;
	cout<<"6.Regresar"<<endl;
	cout<<"Cual deseas comprar?";
	cin>> eleccion;
	
	if (eleccion >= 1 && eleccion <= 5 && miPou.monedas >= precios[eleccion]){
		
		limpiarConsola();
		miPou.monedas -= precios[eleccion];
		miPou.inventario[eleccion - 1] += 1;
		cout<<"Has comprado un " << cosas[eleccion - 1]<< endl;
		esperar();
			
		}
		
	
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
case 2: //Utilizar objetos del inventario
comer(miPou);
break;
case 3: //Dormir, gastas 30 monedas

if (miPou.monedas > 30){ //Opcion 3, dormir profundamente para recuperar energia
	
	
	limpiarConsola();
	miPou.monedas -= 30;
	miPou.cansancio = 100;
	cout <<"Tu "  <<  miPou.nombre  <<  " Ha descansado correctamente!"<< endl;
	esperar();
	
} else {
	
	limpiarConsola();
	cout<<"No cuentas con las monedas suficientes"<< endl;
	esperar();
	
}

break;
case 4: //Tienda 
tiendaPou(miPou);
break;
case 5: //Mostrar Stats
limpiarConsola();
miPou.hambre -= 3;
miPou.cansancio -= 1;
miPou.salud -= 2;
mostrarStat(miPou);
esperar();
break;
case 6: //Cerrar y guardar Partida
Gameloop = false;
break;

}
} while (Gameloop); //Aquí termina el Gameloop

limpiarConsola();
cout << "Gracias por jugar"<< endl;
esperar();


return 0;
}