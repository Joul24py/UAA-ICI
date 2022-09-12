/*
Alumnos:
    Espinoza Sánchez Joel Alejandro
    González Arenas Fernando Francisco
 */
using System;

namespace Ejercicio1
{
    public class Trabajador
    {
        public Trabajador()
        {
            Console.WriteLine("\nSoy un trabajador");
        }
    }
    public class Programador
    {
        public Programador()
        {
            Console.WriteLine("\nSoy programador");
        }
    }
    public class Analista
    {
        public Analista()
        {
            Console.WriteLine("\nSoy analista");
        }
    }
    public class Ingeniero
    {
        public Ingeniero()
        {
            Console.WriteLine("\nSoy ingeniero");
        }
    }
    public class IngenieroInformatico : Ingeniero
    {
        public IngenieroInformatico()
        {
            Console.WriteLine("Soy ingeniero informático");
        }
    }
    public class PruebadeTrabajadores
    {
        public PruebadeTrabajadores()
        {
            Trabajador t = new Trabajador();
            Programador p = new Programador();
            Analista a = new Analista();
            Ingeniero i = new Ingeniero();
            IngenieroInformatico ii = new IngenieroInformatico();
        }
    }
    public class Program
    {
        static void Main(string[] args)
        {
            PruebadeTrabajadores PDT = new PruebadeTrabajadores();

            Console.ReadKey();
        }
    }
}