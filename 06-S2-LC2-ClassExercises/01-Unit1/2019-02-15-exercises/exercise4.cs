//Ejercicio 4: Leer una determinada temperatura en grados Celsius y convertirlo a grados Farenheit
using System;

namespace _5Ejercicios
{
    class Program
    {
        static void Main(string[] args)
        {


            double c = 0, f = 0;

            Console.WriteLine("Otorgue un número correspondiente a una temperatura en grados Celsius");
            c = int.Parse(Console.ReadLine());
            f = (c * (9 / 5)) + 32;
            Console.WriteLine("Su equivalente es: {0} grados Farenheit",f);
            Console.ReadKey();
        }
    }
}
