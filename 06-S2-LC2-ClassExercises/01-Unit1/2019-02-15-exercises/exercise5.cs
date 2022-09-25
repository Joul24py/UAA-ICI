//Ejercicio 5: Teniendo como datos el radio y la altura de un cilindro, obtener su volumen y el área
using System;

namespace _5Ejercicios
{
    class Program
    {
        static void Main(string[] args)
        {


            double r = 0, h = 0, v = 0, a = 0;

            Console.WriteLine("Otorgue el radio de un círculo");
            r = int.Parse(Console.ReadLine());
            Console.WriteLine("Otorgue la altura del círculo");
            h = int.Parse(Console.ReadLine());
            v = (3.1416 * (r * r)) * h;
            a = (2 * (3.1416 * (r * r))) + ((3.1416 * (2 * r)) * h);
            Console.WriteLine("El volumen del círculo es: {0}", v);
            Console.WriteLine("El �rea del círculo es: {0}",a);
            Console.ReadKey();
        }
    }
}
