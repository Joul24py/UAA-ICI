using System;

namespace if_propuesto
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = 0;
            Console.WriteLine("Otorgue un número:");
            x = int.Parse(Console.ReadLine());
            if(x<10)
            {
                Console.WriteLine("El número ingresado es menor a diez");
            }
            if(x>10)
            {
                Console.WriteLine("El número ingresado es mayor a diez");
            }
            else
            {
                Console.WriteLine("El número ingresado es diez");
            }

            Console.ReadKey();
        }
    }
}
