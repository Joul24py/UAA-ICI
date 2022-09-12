/*Ejercicio:
Declarar dos variables de tipo entero x, y respectivamente
Asignar el valor de 100 a x e imprimir su contenido
Dividir el valor de x entre 2 y asignárselo a y para imprimir su contenido igualmente
*/
using System;

class Wenas
{
    static void Main()
    {
        int x = 0, y = 0;
        x = 100;
        y = x / 2;
        Console.WriteLine("El Valor de Y es {0}",y);
        Console.ReadKey(); 
    }
}