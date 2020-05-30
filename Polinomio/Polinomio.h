#include <iostream>
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
		/**
		* @brief 
		* @pre 
		* @param () 
		* @return 
		* @post 
		*/	
		Polinomio* SumaV4(const Polinomio *p4);
		/**
		* @brief 
		* @pre 
		* @param () 
		* @return 
		* @post 
		*/
		Polinomio operator+(const Polinomio &p5);
		/**
		* @brief 
		* @pre 
		* @param () 
		* @return 
		* @post 
		*/
		Polinomio& operator=(const Polinomio &p6);
		/**
		* @brief 
		* @pre 
		* @param () 
		* @return 
		* @post 
		*/
		friend ostream& operator << (ostream &flujo, const Polinomio &p);
		/**
		* @brief 
		* @pre 
		* @param () 
		* @return 
		* @post 
		*/
		friend istream& operator >> ( std::istream &flujo, Polinomio &p);
};
