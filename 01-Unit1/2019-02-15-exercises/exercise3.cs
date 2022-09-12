//Ejercicio 3: Realice un ejercicio que permita ingresar una cantidad en metros y obtener su equivalente en centímetros, kilómetros, pies y pulgadas
using System;

namespace _5Ejercicios
{
    class Program
    {
        static void Main(string[] args)
        {


            double m = 0, cm = 0, inches = 0, ft = 0, km = 0;

            Console.WriteLine("Otorgue un número en metros");
            m = int.Parse(Console.ReadLine());
            cm = m * 100;
            inches = m * 39.3701;
            ft = m * 3.28084;
            km = m / 1000;
            Console.WriteLine("Su equivalente es: {0} centímetros",cm);
            Console.WriteLine("Su equivalente es: {0} pulgadas", inches);
            Console.WriteLine("Su equivalente es: {0} pies", ft);
            Console.WriteLine("Su equivalente es: {0} kilómetros", km);
            Console.ReadKey();
        }
    }
}