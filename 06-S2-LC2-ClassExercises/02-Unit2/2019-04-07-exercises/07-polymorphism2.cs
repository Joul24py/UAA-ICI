/*
Alumnos:
    Espinoza Sánchez Joel Alejandro
    González Arenas Fernando Francisco
Ejercicio de Poliformismo por sobrecarga
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace calculadora
{

    public class Calculadora
    {
        public double Suma(double a, double b)
        {
            return a + b;
        }

        public double Suma(double a, double b, double c)
        {
            return a + b+c;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int n;
            double s1;
            double s2;
            double s3;
            double r;
            Calculadora o = new Calculadora();
            Console.WriteLine("cuantos numeros quieres sumar, dos o tres?");
            n = Convert.ToInt32(Console.ReadLine());
            if (n == 2)
            {
                Console.WriteLine("ingresa el primer numero");
                s1 = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine("ingresa el segundo numero");
                s2 = Convert.ToDouble(Console.ReadLine());
                r = o.Suma(s1, s2);
                Console.WriteLine("el resultado es "+r);
            }
            if (n == 3)
            {
                Console.WriteLine("ingresa el primer numero");
                s1 = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine("ingresa el segundo numero");
                s2 = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine("ingresa el tercer numero");
                s3 = Convert.ToDouble(Console.ReadLine());
                r = o.Suma(s1, s2, s3);
                Console.WriteLine("el resultado es " + r);
            }
            if(n<2||n>3) Console.WriteLine("lo sentimos, la opcion seleccionada no es correcta");
        }
    }
}
