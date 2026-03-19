#include <iostream>
#include <conio.h>
#include <cstdlib> // Contiene rand() y srand()
#include <ctime> 
#include <fstream>

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
		int xpNecesaria;
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
		bool hayPartida;

};

void crearPou(Mascota &miPou){ // Función que siempre se hará al iniciar el juego

cout << "Bienvenido! como llamaras a tu Mascota?" << endl;
cin >> miPou.nombre;
miPou.hambre = 100;
miPou.cansancio = 100;
miPou.salud = 100;
miPou.monedas = 0;
miPou.nivel = 1;
miPou.xp = 0;
miPou.hayPartida = true;

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
cout << "Siguiente nivel al " << miPou.xpNecesaria << " de XP"<<endl;
}

void esperar(){ //Función de espera
cout <<"Presiona cualquier tecla"<<endl;
getch();
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
/*
for (int i = 0; i < 500; ++i) {
        std::cout << "\n";
}*/
system("cls");
}

void limitarStat(Mascota &miPou){ //Funcion para limitar las stats

if (miPou.hambre < 0) { miPou.hambre = 0;}
if (miPou.cansancio < 0) { miPou.cansancio = 0;}
if (miPou.salud < 0) { miPou.salud = 0;}

if (miPou.hambre > 100) { miPou.hambre = 100;}
if (miPou.cansancio > 100) { miPou.cansancio = 100;}
if (miPou.salud > 100) { miPou.salud = 100;}

miPou.xpNecesaria = miPou.nivel * 100;

if (miPou.xp >= miPou.xpNecesaria) {
        miPou.nivel++;
        miPou.xp = 0; // Reiniciamos XP para el siguiente nivel
        miPou.monedas += 50 * miPou.nivel; // ¡Más recompensa por niveles altos!
        
        limpiarConsola();
        cout << "***************************" << endl;
        cout << "¡SUBIDA DE NIVEL!" << endl;
        cout << miPou.nombre << " ahora es nivel " << miPou.nivel << endl;
        cout << "Siguiente nivel requiere: " << (miPou.nivel * 100) << " XP" << endl;
        cout << "***************************" << endl;
        esperar();
    }

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
						miPou.xp += 10;
                        cout << "Le encanto el Hot Dog, pero le dio acidez... (-10 Salud)" << endl;
                        break;
                    case 1: // Manzana
                        miPou.hambre += 15;
						miPou.xp += 15;
                        cout << "¡Que sano! Una manzana al dia..." << endl;
                        break;
                    case 2: // Espagueti
                        miPou.hambre += 40;
						miPou.xp += 10;
                        miPou.cansancio -= 20;
                        cout << "Muchos carbohidratos, ahora tiene sueño... (-20 Energia)" << endl;
                        break;
                    case 3: // Pocion
                        miPou.salud += 50;
						miPou.xp += 20;
                        miPou.hambre -= 10;
                        cout << "¡Salud recuperada! Pero tiene un poco de hambre." << endl;
                        break;
                    case 4: // Estrella
                        miPou.hambre = 100;
                        miPou.salud = 100;
                        miPou.cansancio = 100;
						miPou.xp += 50;
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
	
	if (eleccion >= 1 && eleccion <= 5 && miPou.monedas >= precios[eleccion - 1]){
		
		limpiarConsola();
		miPou.monedas -= precios[eleccion - 1];
		miPou.inventario[eleccion - 1] += 1;
		miPou.xp += 25;
		cout<<"Has comprado un " << cosas[eleccion - 1]<< endl;
		esperar();
			
		}
		
	
}

void guardarPartida(Mascota &miPou) {
    ofstream archivo;
    archivo.open("partida.txt"); // Crea o sobrescribe el archivo

    if (archivo.is_open()) {
        // Guardamos las variables básicas
        archivo << miPou.nombre << endl;
        archivo << miPou.hambre << " " << miPou.cansancio << " " << miPou.salud << endl;
        archivo << miPou.monedas << " " << miPou.nivel << " " << miPou.xp << endl;
		archivo << miPou.hayPartida << " " << endl;

        // Guardamos el inventario con un bucle
        for (int i = 0; i < 5; i++) {
            archivo << miPou.inventario[i] << " ";
        }
		archivo << endl;
		archivo << miPou.xpNecesaria << endl;

        archivo.close();
        cout << "¡Partida guardada con exito!" << endl;
    } else {
        cout << "Error al abrir el archivo para guardar." << endl;
    }
    esperar();
}

void cargarPartida(Mascota &miPou) {
    ifstream archivo;
    archivo.open("partida.txt");

    if (archivo.is_open()) {
        // Leemos en el mismo orden en que guardamos
        archivo >> miPou.nombre;
        archivo >> miPou.hambre >> miPou.cansancio >> miPou.salud;
        archivo >> miPou.monedas >> miPou.nivel >> miPou.xp;
		archivo >> miPou.hayPartida;

        for (int i = 0; i < 5; i++) {
            archivo >> miPou.inventario[i];
        }
		archivo >> miPou.xpNecesaria;

        archivo.close();
        cout << "¡Partida cargada! Bienvenido de nuevo, " << miPou.nombre << endl;
    } else {
        cout << "No se encontro partida previa. Creando una nueva..." << endl;
		crearPou(miPou);
    }
    esperar();
}

void adivinaNumero(Mascota &miPou){
	
	int vidas = 5;
	int numeroAleatorio = rand();
    int numero = (rand() % 10) + 1;
	int intentar;
	int ganancias[2];
	bool hasGanado = false;
	
	limpiarConsola();
	cout<<"Bienvenido al juego de Adivina el numero del 1 al 10\nTienes "<<vidas<<" intentos para adivinar el numero\n"<< endl;
	
	
	while (vidas > 0 && !hasGanado){
		cout<<"Escribe un numero:";
		cin>>intentar;
		if (intentar == numero){
			limpiarConsola();
			cout<<"Felicidades, adivinaste!"<<endl;
			miPou.monedas += 30 * miPou.nivel;
			miPou.xp += 25 * miPou.nivel;
			ganancias[0] = 30 * miPou.nivel;
			ganancias[1] = 25 * miPou.nivel;
			hasGanado = true;
			cout<<"Has ganado "<< ganancias[0] << " de monedas y " << ganancias[1] << " de xp"<< endl;
			esperar();
			
		} else {
			limpiarConsola();
			cout<<"Mala ahi, has perdido una vida"<<endl;
			vidas -= 1;
			cout<<"Te quedan "<<vidas<<" intentos"<<endl;
			esperar();
		}
		
		
	}
	
	cout<<"El numero era "<<numero<<"!"<<endl;
	
	getch();
	
}

void jugarAlgo(Mascota &miPou){
	
	int eleccion;
	
	limpiarConsola();
	cout<< "Bienvenidos a la Zona de Juegos, elige que jugar" << endl;
	cout<< "1. Adivina el numero" << endl;
	cout<< "2.Regresar" << endl;
	cin>> eleccion;
	switch (eleccion){
		
		case 1:
		adivinaNumero(miPou);
		break;
		case 2:
		break;
	}
	
	
}

int main(){

Mascota miPou;
srand(time(0));
int opcion;
bool Gameloop = true;

ifstream archivoPrueba("partida.txt");

    if (archivoPrueba.good()) { 
        // Si el archivo existe, lo cerramos y llamamos a cargar
        archivoPrueba.close();
        cargarPartida(miPou);
    } else {
        // Si no existe, cerramos el intento y creamos mascota nueva
        archivoPrueba.close();
    }
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
jugarAlgo(miPou);
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
miPou.xp += 1;
mostrarStat(miPou);
esperar();
break;
case 6: //Cerrar y guardar Partida
Gameloop = false;
break;

}
} while (Gameloop); //Aquí termina el Gameloop

limpiarConsola();
guardarPartida(miPou);
cout << "Gracias por jugar"<< endl;
esperar();


return 0;
}