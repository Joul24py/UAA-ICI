/*
Alumnos:
	Espinoza Sánchez Joel Alejandro
	González Arenas Fernando Francisco
Ejercicio 2:
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace libro_erencia
{
    class Program
    {
        static void Main(string[] args)
        {
            Libro o = new Libro();
            Console.WriteLine("Mostrando los datos inicialisados por el constructor... ");
            o.mostrar();
            Console.WriteLine("Ingresa el nombre del autor");
            o.SetAutor(Console.ReadLine());
            Console.WriteLine("Ingresa el titulo del libro");
            o.SetTitulo(Console.ReadLine());
            Console.WriteLine("Ingresa la ubicacion del libro");
            o.SetUbicacion(Console.ReadLine());
            Console.WriteLine("Mostrando los datos del libro... ");
            o.mostrar();
        }
    }

    public class documento
    {

        public documento()
        {
            Console.WriteLine("Creando documento...");

        }


    }

    public class Libro : documento
    {
        string autor;
        string titulo;
        string ubicacion;

        public Libro()
        {
            Console.WriteLine("Creando libro... ");
            autor = "Gabriel García Marquez";
            titulo = "100 años de soledad";
            ubicacion = "biblioteca nacional jose basconcelos";
        }

        public void mostrar()
        {
            Console.WriteLine("El nombre del autor es: " + autor);
            Console.WriteLine("El titulo del libro es: " + titulo);
            Console.WriteLine("Y la ubicacion del libro es: " + ubicacion);
        }

        public string GetAutor()
        {
            return autor;
        }

        public void SetAutor(string valor)
        {
            autor = valor;
        }

        public string GetTitulo()
        {
            return titulo;
        }

        public void SetTitulo(string valor)
        {
            titulo = valor;
        }
        public string GetUbicacion()
        {
            return ubicacion;
        }

        public void SetUbicacion(string valor)
        {
            ubicacion = valor;
        }
    }

}
