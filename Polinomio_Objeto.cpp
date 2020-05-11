#include <iostream>
#include <string>
#include <stdlib.h>
#define RESTORE "\033[1;0m"
#define GREY "\033[1;30m"
#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
using namespace std;
/*************************************
** Definición del OBJETO Polinomio  **
**************************************/

class Polinomio {

	private:
		float *coef;		// Vector con los coeficientes
		int grado;			// Grado del polinomio
		int max_grado;	   	// Maximo grado permitido en este polinomio
		/**
		 * @brief Módulo que introduce un grado al miembro grado del OBJETO Polinomio
		 * @pre El valor que se le va a introducir a este miembro debe de ser mayor o igual que 0
		 * @param (int) g, variable de tipo entero, la cual usaremos para introducir el grado en el OBJETO Polinomio
		 * @post El valor del miembro grado del OBJETO Polinomio, será modificado.
		 */
		void setGrado(int g);
		/**
		* @brief Modulo de redimension para el vector de coeficientes del OBJETO Polinomio, este modulo crea un vector de coeficientes de dimension [i + 1], posteriormente se copia el 			contenido del antiguo vector en este nuevo y por ultimo se libera la memoria antigua, se sustituye la posicion de memoria a la cual apunta el puntero de coef del OBJETO 				Polinomio y se ponen a 0 los nuevos espacios generados en el vector de coeficientes
		* @pre El parametro i que se pasa a este modulo para ajustar la dimension, debe de ser mayor o igual a 0, no se debe de introducir un numero negativo
		* @return No devuelve nada, es un procedimiento
		* @post El vector de coeficientes del OBJETO Polinomio debe de haber cambiado por el nuevo vector generado, que será un vector cuya dimension es exacta para el momento en el cual 				se invoca 
		*/
		void resize(int i);		//Funcion privada para redimensionar el tamaño del vector de coeficientes de un objeto polinomio

	public:
		/**
		* @brief Constructor por defecto del OBJETO Polinomio, se invoca solo.
		* @post Tras haberse ejecutado este modulo, se debe de haber creado un OBJETO Polinomio
		*/
		Polinomio();			 //Constructor por defecto
		/**
		* @brief Constructor del OBJETO Polinomio, este constructor pide un numero entero para generar la dimension del vector de coeficientes
		* @pre El numero introducido debe de ser mayor o igual a 0, es decir, no se puede introducir un numero negativo
		* @post Tras haberse ejecutado este modulo, se debe de haber creado un OBJETO Polinomio cuyo vector de coeficientes debe de tener una dimension igual al numero introducido en 				maxGrado y este miembro del OBJETO tambien debe de quedar actualizado
		*/
		Polinomio(int maxGrado); //Otro constructor
		/**
		* @brief Constructor por copia del OBJETO Polinomio, este constructor crea una copia exacta del Polinomio P que se le pasa como parametro a este modulo.
		* @pre El polinomio que se pasa por referencia para copiar debe de estar previamente filtrado para que este correctamente generado
		* @post Tras haberse ejecutado este modulo, se debe de haber creado un OBJETO Polinomio exactamente igual al OBJETO Polinomio que se le ha pasado como parametro.
		*/
		Polinomio(const Polinomio &p);
		/**
		* @brief 
		* @pre 
		* @param () 
		* @return 
		* @post 
		*/
		void setCoeficienteV1(int i, float c);
		/**
		* @brief 
		* @pre 
		* @param () 
		* @return 
		* @post 
		*/
		void setCoeficienteV2(int i, float c);
		/**
		* @brief 
		* @pre 
		* @param () 
		* @return 
		* @post 
		*/
		void setCoeficienteV3 (int i, float c);
		/**
 		* @brief Modulo que devuelve el valor de la posicion 'i' del vector de coeficientes del OBJETO Polinomio
 		* @return Devuelve el valor de la posicion 'i' del vector de coeficientes que es un valor de tipo float
		*/
		float getCoeficiente(int i) const;
		/**
 		* @brief Modulo que devuelve el valor del miembro grado del OBJETO Polinomio
 		* @return Devuelve el valor de la variable grado que es un valor de tipo int
		*/
		int getGrado() const;
		/**
 		* @brief Modulo que devuelve el valor del miembro maxGrado del OBJETO Polinomio
 		* @return Devuelve el valor de la variable maxGrado que es un valor de tipo int
		*/
		int getMaxGrado () const;
		/**
		* @brief Modulo que imprime por pantalla un polinomio(EJ: 2X^3 + 0.5X^1...)
		* @pre El polinomio debe de tener algun coeficiente relleno para ser mostrado por pantalla.
		* @return No devuelve nada, es un procedimiento.
		* @post El OBJETO Polinomio debe de quedar impreso por pantalla de manera correcta, tal y como se ve en el ejemplo
		*/
		void print() const;
		/**
		* @brief Destructor del OBJETO Polinomio, se invoca solo al finalizar la ejecuccion del programa.
		* @post Tras ejecutarse este modulo, el OBJETO Polinomio debe de haberse borrado correctamente.
		*/
		~Polinomio();    //Destructor
		/**
		* @brief 
		* @pre 
		* @param () 
		* @return 
		* @post 
		*/
		void SumaV1(const Polinomio &p);
		/**
		* @brief 
		* @pre 
		* @param () 
		* @return 
		* @post 
		*/
		void SumaV2(const Polinomio &p1, const Polinomio &p2);
		/**
		* @brief 
		* @pre 
		* @param () 
		* @return 
		* @post 
		*/
		Polinomio SumaV3(const Polinomio &p3);
};
Polinomio::Polinomio (){
	int dim_nueva = 0;
	
	coef = new float [dim_nueva];
	for (int i = 0; i < dim_nueva; i++){
		coef[i] = 0.0;
	}
	grado = 0;
	max_grado = 0;

}
Polinomio::Polinomio (int maxGrado){
	
	coef = new float [maxGrado + 1];
	if (coef == 0){
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);//Salida forzada del programa para terminar el proceso.
    }
	for (int i = 0; i < maxGrado + 1; i++){
		coef[i] = 0;
	}
	grado = 0;
	max_grado = maxGrado;
}
void Polinomio::setGrado (int g){
	if (g < 0){
		cout << RED << "DEBUG: No se puede introducir un numero negativo..." << RESTORE << endl;
	}
	else{
		grado = g;
	}
}
void Polinomio::setCoeficienteV1 (int i, float c) {
	if (i >= 0){
		coef[i] = c;
		if(c != 0.0 && i > grado){
			setGrado(i);
		}
	}
}
void Polinomio::setCoeficienteV2 (int i, float c) {
	if (i >= 0){ 
		if (i > getMaxGrado()){ //Si el indice del coeficiente es mayor que el maximo grado permitido en nuestro polinomio, necesitamos mas espacio
			cout << RED << "DEBUG : Ampliando espacio... " << RESTORE << endl;
			float *	v_aux = new float[i + 1];
			if (v_aux == 0){
        		cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        		exit(-1);//Salida forzada del programa para terminar el proceso.
    		}
			//Copiamos los coeficientes en el auxiliar
			for(int j = 0; j <= grado; j++){
				v_aux[j] = coef[j];
			}		
			cout << GREEN << "DEBUG : Espacio ampliado... " << RESTORE << endl;
			cout << RED << "DEBUG : Liberando memoria antigua... " << RESTORE << endl;
			delete [] coef; //Aqui libero la memoria 
			coef = v_aux; //Cambio los punteros de coeficientes	
			cout << GREEN << "DEBUG : Memoria antigua liberada correctamente... " << RESTORE << endl;
			//Pongo a 0.0 los nuevos coeficientes
			for(int k = getGrado() + 1; k <= i; k++){
				coef[k] = 0.0; 
			}
			max_grado = i; //Cambio el nuevo grado maximo del polinomio
		}
		coef[i] = c; //Aqui asigno el nuevo coeficiente
		//Aqui cambio el grado actual del polinomio
		if(c != 0.0 && i > grado){
			setGrado(i);
		}
		else if(c == 0.0 && i == getGrado()){//
			while(coef[getGrado()] == 0.0 && getGrado() > 0){//Aqui cambio el grado por el primer coeficiente que encuentre distinto de 0
				setGrado(getGrado() - 1);//Aqui he tenido problemas al poner el -- y no se porque me da fallo, al ponerlo asi si funciona
			}
		}
	}
	else{
		cout << RED << "No se puede introducir un monomio de grado negativo " << RESTORE << endl;
	}
}
void Polinomio::resize(int i){
		float *	v_aux = new float[i + 1];
			if (v_aux == 0){
        		cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        		exit(-1);//Salida forzada del programa para terminar el proceso.
    		}
			//Copiamos los coeficientes en el auxiliar
			for(int j = 0; j <= getGrado(); j++){
				v_aux[j] = coef[j];
			}		
			cout << GREEN << "DEBUG : Modificando espacio... " << RESTORE << endl;
			cout << RED << "DEBUG : Liberando memoria antigua... " << RESTORE << endl;
			delete [] coef; //Aqui libero la memoria 
			coef = v_aux; //Cambio los punteros de coeficientes	
			cout << GREEN << "DEBUG : Memoria antigua liberada correctamente... " << RESTORE << endl;
			//Pongo a 0.0 los nuevos coeficientes
			for(int k = getGrado() + 1; k <= i; k++){
				coef[k] = 0.0; 
			}
			max_grado = i; //Cambio el nuevo grado maximo del polinomio
}
void Polinomio::setCoeficienteV3 (int i, float c) {
	if (i >= 0){ 
		if (i > max_grado){ //Si el indice del coeficiente es mayor que el maximo grado permitido en nuestro polinomio, necesitamos mas espacio
			cout << RED << "DEBUG : Ampliando espacio... " << RESTORE << endl;
			resize(i);
		}
		coef[i] = c; //Aqui asigno el nuevo coeficiente
		//Aqui cambio el grado actual del polinomio
		if(c != 0.0 && i > getGrado()){
			setGrado(i);
		}
		else if(c == 0.0 && i == grado){//
			while(coef[getGrado()] == 0.0 && getGrado() > 0){//Aqui cambio el grado por el primer coeficiente que encuentre distinto de 0
				setGrado(getGrado() - 1);//Aqui he tenido problemas al poner el -- y no se porque me da fallo, al ponerlo asi si funciona
			}
			if (getGrado() < max_grado){
				cout << RED << "DEBUG : Disminuyendo espacio... " << RESTORE << endl;
				resize(getGrado());
			}
		}
	}
	else{
		cout << RED << "No se puede introducir un monomio de grado negativo " << RESTORE << endl;
	}
}
float Polinomio::getCoeficiente (int i) const {
/**
* @brief Metodo público del objeto polinomio, este metodo devuelve el valor del coeficiente de la posicion i del polinomio, esta definido como metodo constante para impedir que se pueda modificar algun dato miembro de polinomio
* @pre 
* @return Devuelve el coeficiente de la posicion i del vector de coeficientes del objeto polinomio
* @post 
*/
	if (i > grado){
		return 0.0;
	}
	else{
		return coef[i];	
	}
}
int Polinomio::getGrado () const {

/**
* @brief Metodo público del objeto polinomio, este metodo devuelve el valor del grado actual del polinomio, esta definido como metodo constante para impedir que se pueda modificar algun dato miembro de polinomio
* @pre 
* @param () 
* @return Devuelve el valor del grado actual del polinomio 
* @post 
*/
	return grado;

}
int Polinomio::getMaxGrado () const {

/**
* @brief Metodo público del objeto polinomio, este metodo devuelve el valor del grado actual del polinomio, esta definido como metodo constante para impedir que se pueda modificar algun dato miembro de polinomio
* @pre 
* @param () 
* @return Devuelve el valor del grado actual del polinomio 
* @post 
*/
	return max_grado;

}
void Polinomio::print () const {

/**
* @brief Modulo el cual imprime por pantalla un polinomio de la forma de 1.1 x^2 (+ o -) 1.1 x^1 (+ o -) 1.1 x (+ o -) 1
* @pre 
* @param () 
* @return 
* @post Se debera de mostrar por pantalla el polinomio de manera correcta y de la forma en la cual se especifica
*/

	cout << BLUE << getCoeficiente(getGrado());
	cout << BLUE << "x^" << getGrado();
	for ( int i = getGrado() - 1 ; i >= 0; i--){
		if (getCoeficiente(i) != 0.0){

			cout << " + " << getCoeficiente(i) << "x^" << i;
		}
	}
	cout << RESTORE << endl;
}
Polinomio::~Polinomio(){
	cout << RED << "DEBUG: Eliminando polinomio... " << RESTORE << endl;
		//1º)Pongo los coeficientes del polinomio a 0.0
		for(int i = 0; i < max_grado; i++){
			coef[i] = 0.0;
		}
		//2º) Pongo el grado actual del polinomio a 0
		grado = 0;
		//3º) Pongo el grado maximo permitido en este polinomio a 0
		max_grado = 0;
		//Libero el espacio en memoria dinamica
		delete [] coef;
		coef = 0;
	cout << RED << "DEBUG: Polinomio ELiminado... " << RESTORE << endl;
}
void Test_caso1(Polinomio *p){
/**
* @brief Modulo que ejecuta el caso de testing 1: Insertar un monomio de grado menor que el grado actual
* @pre 
* @param () 
* @return 
* @post 
*/

	cout << endl << CYAN << "***** Ejecutando el caso de testing 1 ***** " << RESTORE << endl;
	
	p->setCoeficienteV3(3,5.5);
	cout << GREEN << "Introducido el valor por defecto" << endl;
	p->print();
	cout << RED << "DEBUG : Introduciendo un valor menor al grado actual " << RESTORE << endl;
	p->setCoeficienteV3(2,3.3);
	cout << GREEN << "DEBUG : Introducido el valor correctamente, imprimiendo nuevo polinomio... " << RESTORE << endl;
	p->print();
}
void Test_caso2(Polinomio *p){
/**
* @brief Modulo que ejecuta el caso de testing 2: Insertar un monomio de grado negativo
* @pre 
* @param () 
* @return 
* @post 
*/	
	cout << endl << CYAN << "***** Ejecutando el caso de testing 2 ***** " << RESTORE << endl;
	
	cout << RED << "DEBUG : Introduciendo un monomio de grado negativo " << RESTORE << endl;
	p->setCoeficienteV3(-2,1.3);
	cout << GREEN << "DEBUG : Previamente a esta sentencia debe de haber salido un mensaje de error... " << RESTORE << endl;
	p->print();
}
void Test_caso3(Polinomio *p){
/**
* @brief Modulo que ejecuta el caso de testing 3: Insertar un monomio de grado mayor al grado actual pero menor que max_grado
* @pre 
* @post 
*/	
	cout << endl << CYAN << "***** Ejecutando el caso de testing 3 ***** " << RESTORE << endl;
	
	cout << RED << "DEBUG : Introduciendo un monomio de grado mayor que el actual pero menor que el maximo" << RESTORE << endl;
	cout << RED << "DEBUG : Grado actual --> " <<  p->getGrado() << RESTORE << endl;
	p->setCoeficienteV3(4,6.7);
	cout << GREEN << "DEBUG : Grado actual --> " <<  p->getGrado() << RESTORE << endl;
	p->print();
}
void Test_caso4(Polinomio *p){
/**
* @brief Modulo que ejecuta el caso de testing 4: Insertar un monomio de grado mayor al grado actual y mayor que max_grado
* @pre 
* @post 
*/	
	cout << endl << CYAN << "***** Ejecutando el caso de testing 4 ***** " << RESTORE << endl;
	
	cout << RED << "DEBUG : Introduciendo un monomio de grado mayor que el actual pero menor que el maximo" << RESTORE << endl;
	cout << RED << "DEBUG : Grado actual --> " <<  p->getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo base --> " <<  p->getMaxGrado() << RESTORE << endl;
	p->setCoeficienteV3(7,8.7);
	cout << GREEN << "DEBUG : Grado actual --> " <<  p->getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo ahora --> " <<  p->getMaxGrado() << RESTORE << endl;
	p->print();
}
void Test_caso5(Polinomio *p){
/**
* @brief Modulo que ejecuta el caso de testing 4: Insertar un monomio de grado igual al grado actual y cuyo coeficiente es 0
* @pre 
* @post 
*/	
	cout << endl << CYAN << "***** Ejecutando el caso de testing 5 ***** " << RESTORE << endl;
	
	cout << RED << "DEBUG : Introduciendo un monomio de grado igual al grado actual y cuyo coeficiente es 0" << RESTORE << endl;
	cout << RED << "DEBUG : Grado actual --> " <<  p->getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo base --> " <<  p->getMaxGrado() << RESTORE << endl;
	p->setCoeficienteV3(7,0.0);
	cout << GREEN << "DEBUG : Grado actual --> " <<  p->getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo ahora --> " <<  p->getMaxGrado() << RESTORE << endl;
	p->print();
}
void ModuloTesting(Polinomio *p){
	
	Test_caso1(p);
	Test_caso2(p);
	Test_caso3(p);
	Test_caso4(p);
	Test_caso5(p);
}
Polinomio::Polinomio(const Polinomio &p){
	cout << RED << "Iniciando el constructor por copia " << RESTORE << endl;
	this->max_grado = p.max_grado;
	this->grado = p.grado;
	this->coef = new float[max_grado + 1];
	if (coef == 0){
        		cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        		exit(-1);//Salida forzada del programa para terminar el proceso.
    }
	for(int i = 0; i <= max_grado; i++){
		this->coef[i] = p.coef[i];
	}
}
void Polinomio::SumaV1(const Polinomio &p){
	cout << RED << "DEBUG: Entrando en el modulo de sumaV1... " << RESTORE << endl;
	if (p.getMaxGrado() <= getMaxGrado()){
		for(int i = 0; i <= getMaxGrado(); i++){
			//cout << BLUE << coef[i] << RESTORE << endl;
			setCoeficienteV3(i,(getCoeficiente(i) + p.getCoeficiente(i)));
			//cout << PURPLE << coef[i] << RESTORE << endl;
		}
	}
	else{
		resize(p.getMaxGrado());
		for(int i = 0; i <= getMaxGrado(); i++){
			//cout << BLUE << coef[i] << RESTORE << endl;
			setCoeficienteV3(i,(getCoeficiente(i) + p.getCoeficiente(i)));
			//cout << PURPLE << coef[i] << RESTORE << endl;
		}	
	 }
}
void Polinomio::SumaV2(const Polinomio &p1, const Polinomio &p2){
	cout << RED << "DEBUG: Entrando en el modulo de sumaV2... " << RESTORE << endl;
	if (p1.getMaxGrado() <= p2.getMaxGrado()){
		
		for(int i = 0; i <= p2.getMaxGrado(); i++){
			//cout << BLUE << coef[i] << RESTORE << endl;
			setCoeficienteV3(i,(p1.getCoeficiente(i) + p2.getCoeficiente(i)));
			//cout << PURPLE << coef[i] << RESTORE << endl;
		}
	}
	else{
		
		for(int i = 0; i <= p1.getMaxGrado(); i++){
			//cout << BLUE << coef[i] << RESTORE << endl;
			setCoeficienteV3(i,(p1.getCoeficiente(i) + p2.getCoeficiente(i)));
			//cout << PURPLE << coef[i] << RESTORE << endl;
		}	
	 }
}
Polinomio Polinomio::SumaV3(const Polinomio &p3){
	Polinomio aux;
	
	cout << RED << "DEBUG: Entrando en el modulo de sumaV2... " << RESTORE << endl;
	if (getMaxGrado() <= p3.getMaxGrado()){
		
		for(int i = 0; i <= p3.getMaxGrado(); i++){
			//cout << BLUE << coef[i] << RESTORE << endl;
			aux.setCoeficienteV3(i,(getCoeficiente(i) + p3.coef[i]));
			//cout << PURPLE << coef[i] << RESTORE << endl;
		}
	}
	else{
		
		for(int i = 0; i <= getMaxGrado(); i++){
			//cout << BLUE << coef[i] << RESTORE << endl;
			aux.setCoeficienteV3(i,(getCoeficiente(i) + p3.coef[i]));
			//cout << PURPLE << coef[i] << RESTORE << endl;
		}	
	 }
	return aux;
}
int main (){

	Polinomio *Polinom = new Polinomio();
	Polinomio poli_est;
	
	/*Polinom.setCoeficienteV1(1,3);
	Polinom.setCoeficienteV1(2,4);
	Polinom.print();
	cout << GREEN << "DEBUG: Primera parte (setCoeficienteV1) listo... " << RESTORE << endl;*/
	/*Polinom.setCoeficienteV2(1,1);
	Polinom.setCoeficienteV2(9,3);
	Polinom.print();
	cout << GREEN << "DEBUG: Segunda parte (setCoeficienteV2) lista... " << RESTORE << endl;*/


	// ********************* Parte del testing ************************

	/*cout << GREEN << "DEBUG : Empezando el testing a poli_est(version estática)" << RESTORE << endl;
	ModuloTesting(&poli_est);
	cout << PURPLE << "DEBUG : Acabado el testing a poli_est(version estática)" << RESTORE << endl;
	cout << GREEN << "DEBUG : Empezando el testing a *Polinom(version dinámica)" << RESTORE << endl;
	ModuloTesting(Polinom);
	cout << RED << "DEBUG : Liberando memoria dinamica..." << RESTORE << endl;
	delete Polinom;
	cout << GREEN << "DEBUG : Memoria dinámica borrada correctamente" << RESTORE << endl;*/


	// ********************* Parte del constructor por copia ************************

		//Parte dinamica
	/*Polinom->setCoeficienteV3(2,5.5);
	Polinom->setCoeficienteV3(4,1.1);
	cout << GREEN << "DEBUG : Grado actual --> " <<  Polinom->getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo ahora --> " <<  Polinom->getMaxGrado() << RESTORE << endl;
	cout << RED << "A continuacion vamos a crear una copia del polinomio mostrado..." << RESTORE << endl;
	Polinom->print();
	Polinomio *Copia_pol = new Polinomio(*Polinom);
	cout << GREEN << "DEBUG : Grado actual --> " <<  Copia_pol->getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo ahora --> " <<  Copia_pol->getMaxGrado() << RESTORE << endl;
	Copia_pol->print();
	cout << endl;
	cout << BLUE << "CAMBIANDO A LA PARTE ESTATICA DEL TESTING " << RESTORE << endl;
	cout << endl;
		//Parte estatica
	poli_est.setCoeficienteV3(2,5.5);
	poli_est.setCoeficienteV3(4,1.1);
	cout << GREEN << "DEBUG : Grado actual --> " <<  poli_est.getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo ahora --> " <<  poli_est.getMaxGrado() << RESTORE << endl;
	cout << RED << "A continuacion vamos a crear una copia del polinomio mostrado..." << RESTORE << endl;
	poli_est.print();
	Polinomio Copia_est = Polinomio(poli_est);
	cout << GREEN << "DEBUG : Grado actual --> " <<  Copia_est.getGrado() << RESTORE << endl;
	cout << RED << "DEBUG : Grado máximo ahora --> " <<  Copia_est.getMaxGrado() << RESTORE << endl;
	Copia_est.print();*/

	/*Polinom->setGrado(9);//Tras ponerlo en privado no debe de dejar que esta sentencia se ejecute
	Polinom->setCoeficienteV3(1,1.1);
	Polinom->print();*/

	// ********************* Parte del modulo de suma de polinomios ************************
		
		//Version 1.0 del metodo de suma de polinomios.(Se almacena el resultado de la suma en el polinomio que llama al metodo)
	/*Polinomio p;
	
	Polinom->setCoeficienteV3(2,5.5);
	Polinom->setCoeficienteV3(3,4);
	p.setCoeficienteV3(2,1);
	p.setCoeficienteV3(1,7);
	p.print();
	cout << p.getMaxGrado() << endl;
	cout << Polinom->getMaxGrado() << endl;
	Polinom->print();
	Polinom->SumaV1(p);
	cout << p.getMaxGrado() << endl;
	cout << Polinom->getMaxGrado() << endl;
	Polinom->print();*/

		//Version 2.0 del metodo de suma de polinomios.(Se almacena el resultado de la suma de dos polinomios externos en el OBJETO Polinomio que llama al metodo)
	/*Polinomio p1;
	Polinomio p2;
		//RELLENAR EL POLINOMIO P1 Y LO MUESTRO POR PANTALLA
	p1.setCoeficienteV3(1,1);
	p1.setCoeficienteV3(3,7);
	p1.print();
		//RELLENAR EL POLINOMIO P2 Y LO MUESTRO POR PANTALLA
	p2.setCoeficienteV3(2,3);
	p2.setCoeficienteV3(4,5);
	p2.print();
		//LLAMO AL METODO DE SUMA DE POLINOMIO V2
	Polinom->SumaV2(p1, p2);
	Polinom->print();*/

		//Version 3.0 del metodo de suma de polinomios.(Se devuelve un OBJETO Polinomio que posteriormente se asigna a un Polinomio resultado)
	Polinomio p1;
	Polinomio p2;

		//RELLENAR EL POLINOMIO P1 Y LO MUESTRO POR PANTALLA
	p1.setCoeficienteV3(1,1);
	p1.setCoeficienteV3(3,7);
	p1.print();
		//RELLENAR EL POLINOMIO P2 Y LO MUESTRO POR PANTALLA
	p2.setCoeficienteV3(2,3);
	p2.setCoeficienteV3(6,5);
	p2.print();
		//LLAMO AL METODO DE SUMA DE POLINOMIO V3
	Polinomio resultado = p1.SumaV3(p2);
	resultado.print();


}
