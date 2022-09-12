//Control de Excepciones con try, catch y final
using System;

namespace ConsoleApp6
{
    public class Program
    {
        public static void Main(string[] args)
        {
            int n1, n2, res;

            try
            {
                Console.WriteLine("Introduzca el primer número:");
                n1 = int.Parse(Console.ReadLine());

                Console.WriteLine("Introduzca el segundo número:");
                n2 = int.Parse(Console.ReadLine());

                res = n1 / n2;
                Console.WriteLine("Su división es: {0}",res);
            }

            catch(FormatException)
            {
                Console.WriteLine("No es un número válido");
            }
            catch (DivideByZeroException)
            {
                Console.WriteLine("No se puede dividir entre cero");
            }

            Console.ReadLine();
        }
    }
}