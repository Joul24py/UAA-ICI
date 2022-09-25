using System;

namespace switch_propuesto
{
    class Program
    {
        static void Main(string[] args)
        {
            int menu = 0;
            do
            {
                Console.WriteLine("Elija la operación a realizar:");
                Console.WriteLine("1) Suma");
                Console.WriteLine("2) Resta");
                Console.WriteLine("3) Multiplicación");
                Console.WriteLine("4) División");
                Console.WriteLine("5) Potencia");
                Console.Write("\n\n\n\n");
                menu = int.Parse(Console.ReadLine());
                if (menu < 1 || menu > 5)
                {
                    Console.WriteLine("Número inválido");
                }
            }
            while (menu < 1 || menu > 5);

            switch (menu)
            {
                case 1:
                    {
                        int a, b, c;
                        Console.WriteLine("Ingrese un número");
                        a = int.Parse(Console.ReadLine());
                        Console.WriteLine("Ingrese otro número");
                        b = int.Parse(Console.ReadLine());
                        c = a + b;
                        Console.WriteLine("La suma de {0} más {1} es {2}", a, b, c);
                        break;
                    }
                case 2:
                    {
                        int a, b, c;
                        Console.WriteLine("Ingrese un número");
                        a = int.Parse(Console.ReadLine());
                        Console.WriteLine("Ingrese otro número");
                        b = int.Parse(Console.ReadLine());
                        c = a - b;
                        Console.WriteLine("La resta de {0} menos {1} es {2}", a, b, c);
                        break;
                    }
                case 3:
                    {
                        int a, b, c;
                        Console.WriteLine("Ingrese un número");
                        a = int.Parse(Console.ReadLine());
                        Console.WriteLine("Ingrese otro número");
                        b = int.Parse(Console.ReadLine());
                        c = a * b;
                        Console.WriteLine("El producto de {0} por {1} es {2}", a, b, c);
                        break;
                    }
                case 4:
                    {
                        int a, b, c;
                        Console.WriteLine("Ingrese un número");
                        a = int.Parse(Console.ReadLine());
                        Console.WriteLine("Ingrese otro número");
                        b = int.Parse(Console.ReadLine());
                        c = a / b;
                        Console.WriteLine("El cociente de {0} entre {1} es {2}", a, b, c);
                        break;
                    }
                case 5:
                    {
                        int a, b, c = 1, cont = 0;
                        Console.WriteLine("Ingrese un número");
                        a = int.Parse(Console.ReadLine());
                        Console.WriteLine("Ingrese la potencia a elevar");
                        b = int.Parse(Console.ReadLine());
                        do
                        {
                            c = c * a;
                            cont++;
                        }
                        while (cont < b);
                        Console.WriteLine("Elevar {0} a la potencia {1} resulta {2}", a, b, c);
                        break;
                    }
            }
            Console.ReadKey();
        }
    }
}
