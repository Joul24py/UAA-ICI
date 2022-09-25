/*
Break: Elaborar un programa que en un método llamado "evaluación" pida al usuario ingresar 10 valores de dos cifras (en un bucle for)
Determine si son primos o no. La sentencia break romperá el ciclo si no se cumple que las cifras no sean mayores a 30

Continue: Pide 5 números entre 0 y 10. Si alguno es múltiplo de 5 muestra un mensaje que lo indique
No debe salir del bucle hasta que el número ingresado sea mayor a 10 o menor a 5

Label: Elabora un programa donde imprimas 4 instrucciones y con la etiqueta "goto" brincar la impresión de la segunda instrucción
*/
using System;

namespace BreakLabelContinue
{
    public class BREAK
    {
        int[] valores = new int[10];
        int i = 0;

        public void evaluacion()
        {
            for (i = 0; i < 10; i++)
            {
                Console.WriteLine("Otorgue el dato {0}:", i + 1);
                valores[i] = int.Parse(Console.ReadLine());
                if(valores[i]>30)
                {
                    break;
                }
                if (valores[i] == 2 || valores[i] == 3 || valores[i] == 5 || valores[i] == 7 || valores[i] == 11 || valores[i] == 13 || valores[i] == 17 || valores[i] == 19 || valores[i] == 23 || valores[i] == 29 )
                {
                    Console.WriteLine("El número otorgado es primo");
                }
                else
                {
                    Console.WriteLine("El número otorgado no es primo");
                }

            }
        }
    }
    public class CONTINUE
    {
        int[] valores = new int[5];
        int i = 0;

        public void evaluacion()
        {
            do
            {
                Console.WriteLine("Otorgue el dato {0}:", i + 1);
                valores[i] = int.Parse(Console.ReadLine());
                if(valores[i]>10)
                {
                    continue;
                }
                if (valores[i] == 0 || valores[i] == 5 || valores[i] == 10)
                {
                    Console.WriteLine("El número otorgado es múltiplo de 5");
                }
                if(valores[i]<5)
                {
                    continue;
                }
                i++;
            }
            while (i < 5);
        }
    }
    public class LABEL
    {
        public void label()
        {
            Console.WriteLine("INSTRUCCIONES:");
            Console.WriteLine("1.- Ingrese un número para accesar a diferentes partes del programa");
            goto etiqueta1;
            Console.WriteLine("2.- EJEMPLO GOTO");
        etiqueta1:
            Console.WriteLine("3.- Agregue números para conocer si son primos o múltiplos de 5");
            Console.ReadKey();
        }
    }
    public class Program
    {
        public static void Main(string[] args)
        {
            int menu;
            Console.WriteLine("Elija la opción:");
            Console.WriteLine("1) Break");
            Console.WriteLine("2) Continue");
            Console.WriteLine("3) Label");
            menu = int.Parse(Console.ReadLine());

            BREAK b = new BREAK();
            CONTINUE c = new CONTINUE();
            LABEL l = new LABEL();

            switch (menu)
            {
                case 1:
                    {
                        b.evaluacion();
                        break;
                    }
                case 2:
                    {
                        c.evaluacion();
                        break;
                    }
                case 3:
                    {
                        l.label();
                        break;
                    }
            }

        }
    }
}
