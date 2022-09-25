/*
Alumno: Espinoza Sánchez Joel Alejandro
 Ejercicio propuesto 2.7.2: Crea un programa que pregunte al usuario su edad y su año de nacimiento
 Si la edad que introduce no es un número válido, mostrará un mensaje de aviso, pero aun así le preguntará su año de nacimiento
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
                Console.WriteLine("Introduzca su edad:");
                edad = byte.Parse(Console.ReadLine());

                Console.WriteLine("Su edad es: {0}", edad);
            }

            catch (ArithmeticException)
            {
                Console.WriteLine("No es un número válido");
            }
            catch (FormatException)
            {
                Console.WriteLine("No es un valor permitido");
            }

            try
            {
                ushort fecha;
                Console.WriteLine("Introduzca su año de nacimiento:");
                fecha = ushort.Parse(Console.ReadLine());
                Console.WriteLine("Su año de nacimiento es: {0}", fecha);
            }

            catch (ArithmeticException)
            {
                Console.WriteLine("No es un número válido");
            }
            catch (FormatException)
            {
                Console.WriteLine("No es un valor permitido");
            }

            Console.ReadKey();
        }
    }
}
