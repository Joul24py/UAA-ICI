//Ejercicio 6: Dando el año de nacimiento de la persona, calcular su edad aproximada
using System;

namespace _5Ejercicios
{
    class Program
    {
        static void Main(string[] args)
        {


            double a = 0, e = 0;

            Console.WriteLine("Otorgue su año de nacimiento");
            a = int.Parse(Console.ReadLine());
            e = 2018 - a;
            Console.WriteLine("Aproximadamente, su edad es {0} años", e);
            Console.ReadKey();
        }
    }
}
