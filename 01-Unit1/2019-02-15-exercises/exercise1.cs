//Ejercicio 1: Obtenga el cuadrado de un número dado
using System;

namespace _5Ejercicios
{
    class Program
    {
        static void Main(string[] args)
        {

            int n = 0, m = 0;

            Console.WriteLine("Otorga un número entero");
            n = int.Parse(Console.ReadLine());
            m = n * n;
            Console.WriteLine("Su número al cuadrado es: {0}",m);
            Console.ReadKey();
        }
    }
}
