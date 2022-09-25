/*
Alumnos:
    Espinoza Sánchez Joel Alejandro
    González Arenas Fernando Frnacisco
Ejercicio 3
*/
using System;

namespace Ejercicio3
{
    public class Vehiculo
    {
        public Vehiculo()
        {
            Console.WriteLine("\nConstrucción del Vehículo...");
        }
    }
    public class Coche : Vehiculo
    {
        public Coche()
        {
            Console.WriteLine("Se ha construido un coche");
        }
    }
    public class Moto : Vehiculo
    {
        public Moto()
        {
            Console.WriteLine("Se ha construido una motocicleta");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Vehiculo V = new Vehiculo();
            Coche C = new Coche();
            Moto M = new Moto();

            Console.ReadKey();
        }
    }
}
