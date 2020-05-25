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

class Vista {
	private:
	TablaUsuarios t;
	public:
	void menu();
	void testing();
};
