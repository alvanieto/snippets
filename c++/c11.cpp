#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

// namespace in template
// vector<list<int>>

// keyword nullptr
char *foo = nullptr;
void f(int);
void f(bool);
void f(void*);
f(0);
f(NULL);
f(nullptr);

// Inicialización uniforme
int x(0);
int y = 0;
int z {0};
int z = {0};

Widget w1(w2);
Widget w2 = w1;
w1 = w2;

vector<string> stadt {"Berlin", "München", "Dortmund"};

// Deducción automática de tipos
double f();
auto res = 0.0;

res += 12.2;

res = f();

auto res = f();
auto pos = stadt.begin();

for ( data::const_iterator i = data.begin(); i != data.end(); ++i )
    cout << *element << endl;


for ( const auto &element: data )
    cout << element << endl;

// Funciones Lambda
auto l = [] {
    cout << "Hola Lambda" << endl;
}
l();

auto l = [] (const string &s) -> string {
    cout << s << endl;
    return s;
}
l("Hola Lambda");

auto l = [=] {
    cout << res << endl;
}

auto l = [&] {
    res = 12;
}

// pair como retorno de función
// Notar que C++11 define como valores de inicialización de int, float, etc por 0
// página 60
typedef pair<int, string> Dict;
Dict pairs()
{
    Dict d(1, "Hola Mundo");

    cout << d.first << ", " << d.second << endl;

    //return make_pair(2, "Hola Pair");
    return {3, "Adios pairs"};
}


int main(int argc, char *argv[])
{
    vector<string> lista = {"uno", "dos", "tres"};

    // Fundamental el paso por referencia para evitar llamar constructor y destructor en cada
    // llamada
    for ( const string &x : lista )
        cout << x << endl;

    auto mi_funcion = [&lista] (const string &s) {
        cout << "Mi primera lambda: " << s << endl;
    };

    mi_funcion("mi_funcion");
    pairs();

    return 0;
}
