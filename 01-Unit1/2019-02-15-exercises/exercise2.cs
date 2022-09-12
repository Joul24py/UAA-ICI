//Ejercicio 2: Obtenga el área de un triángulo
using System;

namespace _5Ejercicios
{
    class Program
    {
        static void Main(string[] args)
        {

            int n = 0, m = 0, a = 0;

            Console.WriteLine("Otorga la base del triángulo");
            n = int.Parse(Console.ReadLine());
            Console.WriteLine("Otorga la altura del triángulo");
            m = int.Parse(Console.ReadLine());
            a = (m * n) / 2;
            Console.WriteLine("El área de su triángulo es: {0}",a);
            Console.ReadKey();
        }
    }
}
