//Ejercicio 7: Calcular el área de un círculo a partir del radio otorgado
using System;

namespace _5Ejercicios
{
    class Program
    {
        static void Main(string[] args)
        {


            double r = 0, a = 0;

            Console.WriteLine("Otorgue el radio de un círculo");
            r = double.Parse(Console.ReadLine());
            a = (r * r) * 3.1416;
            Console.WriteLine("El área del círculo es: {0}", a);
            Console.ReadKey();
        }
    }
}