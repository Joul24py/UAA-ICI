/*
Ejercicio 1: Para guardar información sobre libros, vamos a comenzar por crear una clase "Libro"
Contendrá atributos "autor", "titulo", "ubicacion" (todos ellos strings) y métodos Get y Set adecuados para leer su valor y cambiarlo
Prepara también un Main, que cree un objeto de la clase Libro, dé valores a sus tres atributos y luego los muestre.
*/
using System;

namespace Libro
{
    public class Libro
    {
        string autor;      //texto
        string titulo;     //texto
        string ubicacion;     //texto


        public void SetDatos(string autornuevo, string titulonuevo, string ubicacionnuevo)
        {
            autor = autornuevo;
            titulo = titulonuevo;
            ubicacion = ubicacionnuevo;
        }
        public void Mostrar()
        {
            Console.WriteLine("El autor del libro es: {0}", autor);
            Console.WriteLine("El título es: {0}", titulo);
            Console.WriteLine("Su ubicación es: {0}", ubicacion);
        }
        public class Libro1
        {
            public static void Main()
            {
                Libro lib = new Libro();
                Console.WriteLine("Datos del libro: \n");
                lib.Mostrar();

                Console.WriteLine("\n\nDatos nuevos del libro: \n");
                Console.WriteLine("Ingrese el autor del libro: ");
                string autor1;
                autor1 = Console.ReadLine();
                Console.WriteLine("Ingrese el nombre del libro: ");
                string titulo1;
                titulo1 = Console.ReadLine();
                Console.WriteLine("Ingrese la ubicación del libro: ");
                string ubicacion1;
                ubicacion1 = Console.ReadLine();
                Console.WriteLine();

                lib.SetDatos(autor1, titulo1, ubicacion1);
                lib.Mostrar();
                Console.ReadKey();
            }
        }
    }
}
