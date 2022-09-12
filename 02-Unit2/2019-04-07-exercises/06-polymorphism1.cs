/*
Alumnos:
    Espinoza Sánchez Joel Alejandro
    González Arenas Fernando Francisco
Ejercicio de Poliformismo: Programa que identifica diferentes marcas de automóviles y el modelo más accesible
*/
using System;

namespace Ejpoli1
{
    public class Coche
    {
        public Coche()
        {
            Console.WriteLine("\nAutomóviles:");
        }
    }
    public class Audi : Coche
    {
        public Audi()
        {
            Console.WriteLine("Audi: A4");
        }
    }
    public class Ford : Coche
    {
        public Ford()
        {
            Console.WriteLine("Ford: Mustang");
        }
    }
    public class Chevrolet : Coche
    {
        public Chevrolet()
        {
            Console.WriteLine("Chevrolet: Camaro");
        }
    }
    public class Honda : Coche
    {
        public Honda()
        {
            Console.WriteLine("Honda: CRV");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Audi audi = new Audi();
            Chevrolet chevrolet = new Chevrolet();
            Ford ford = new Ford();
            Honda honda = new Honda();

            Console.ReadKey();
        }
    }
}
