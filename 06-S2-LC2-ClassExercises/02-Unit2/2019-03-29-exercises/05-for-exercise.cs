/*
 Instrucciones For:
 Hacer una matriz de 3x3, un vector en un switch. Te da la lista de n�meros del 1 al 4
 */
using System;

namespace Ejercicios_EstControl
{
    class Program
    {
        static void Main(string[] args)
        {
            int x, i = 0, j = 0;
            int[,] matriz = new int[2,2];
            int[] vector = new int[5];

            matriz[0, 0] = 0;
            matriz[0, 1] = 1;
            matriz[1, 0] = 2;
            matriz[1, 1] = 3;
            vector[0] = 0;
            vector[1] = 1;
            vector[2] = 2;
            vector[3] = 3;
            vector[4] = 4;
            Console.WriteLine("Elija la opción:");
            Console.WriteLine("1) Matriz");
            Console.WriteLine("2) Vector");
            x = int.Parse(Console.ReadLine());
            switch (x)
            {
                case 1:
                    {
                        for(i=0;i<2;i++)
                        {
                            for(j=0;j<2;j++)
                            {
                                Console.Write("[{0}] ", matriz[i, j]);
                            }
                            Console.Write("\n");
                            j = 0;
                        }
                        break;
                    }
                case 2:
                    {
                        for(i=0;i<4;i++)
                        {
                            Console.WriteLine("[{0}]", vector[i]);
                        }
                        break;
                    }
            }
            Console.ReadKey();
        }
    }
}