/*
Hacer un programa utilizando while en el que se ingrese una cantidad de piezas a evaluar y la medida de cada una para saber si es apta
Esto se debe llevar a cabo en una función "Evaluar"
La función será llamada desde el main, imprimir la cantidad de piezas que apliquen (Rango de medida: 1.2 - 1.4)
*/
using System;

namespace ejercicio_while
{
    public class Pieza
    {
        public int tam;

        public void Evaluar()
        {

        }
    }
    public class Program
    {
        static void Main(string[] args)
        {
            int num = 0, cont = 0;
            Console.WriteLine("Escriba la cantidad de piezas a evaluar");
            num = int.Parse(Console.ReadLine());
            
            while(cont<num)
            {
                Pieza p = new Pieza();
                cont++;
            }
        }
    }
}