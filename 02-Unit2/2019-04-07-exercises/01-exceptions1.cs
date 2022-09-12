/*
Alumno: Espinoza Sánchez Joel Alejandro
Ejercicio propuesto 2.7.1: Crea un programa que pregunte al usuario su edad y su año de nacimiento
Si la edad que introduce no es un número válido, mostrará un mensaje de aviso
Lo mismo ocurrirá si el año de nacimiento no es un número válido
*/
using System;

namespace PolimorfismoFiguras
{
    public class Program
    {
        public static void Main(string[] args)
        {
            try
            {
                byte edad;
                ushort fecha;
                Console.WriteLine("Introduzca su edad:");
                edad = byte.Parse(Console.ReadLine());
                Console.WriteLine("Introduzca su a�o de nacimiento:");
                fecha = ushort.Parse(Console.ReadLine());

                Console.WriteLine("Su edad es: {0}", edad);
                Console.WriteLine("Su a�o de nacimiento es: {0}", fecha);
            }

            catch (ArithmeticException)
            {
                Console.WriteLine("No es un n�mero v�lido");
            }
            catch (FormatException)
            {
                Console.WriteLine("No es un valor permitido");
            }

            Console.ReadKey();
        }
    }
}
