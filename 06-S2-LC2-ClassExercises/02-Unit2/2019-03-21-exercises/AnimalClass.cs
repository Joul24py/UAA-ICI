using System;

namespace ConsoleApp6
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Animal a1 = new Animal();
            Console.WriteLine();

            GatoSiames a2 = new GatoSiames();
            Console.WriteLine();

            Perro a3 = new Perro();
            Console.WriteLine();

            Gato a4 = new Gato();
            Console.ReadLine();
        }
    }

    public class Animal
    {
        public Animal()
        {
            Console.WriteLine("Ha nacido un animal");
        }
    }

    public class Perro : Animal
    {
        public Perro()
        {
            Console.WriteLine("Ha nacido un perro");
        }
    }

    public class Gato : Animal
    {
        public Gato()
        {
            Console.WriteLine("Ha nacido un gato");
        }
    }

    public class GatoSiames : Gato
    {
        public GatoSiames()
        {
            Console.WriteLine("ha nacido un Gato Siamés");
        }
    }
}
