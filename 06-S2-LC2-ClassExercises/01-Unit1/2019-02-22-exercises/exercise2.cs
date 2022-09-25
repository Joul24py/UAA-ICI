/*
Ejercicio 2: Crea una clase "Coche"
Atributos "marca" (texto), "modelo" (texto), "cilindrada" (número entero), potencia (número real) y métodos Get y Set adecuados para leer su valor y cambiarlo
Prepara también un Main, que cree un objeto de la clase coche, dé valores a sus cuatro atributos y luego los muestre.
*/
using System;

namespace Coche
{
    public class Coche
    {
        string marca;      //texto
        string modelo;     //texto
        int cilindrada; //num_entero
        float potencia;   //num_real

        public void SetDatos(string marcanuevo, string modelonuevo, int cilindradanuevo, float potencianuevo)
        {
            marca = marcanuevo;
            modelo = modelonuevo;
            cilindrada = cilindradanuevo;
            potencia = potencianuevo;
        }
        public void Mostrar()
        {
            Console.WriteLine("La marca del coche es {0}", marca);
            Console.WriteLine("El modelo es {0}", modelo);
            Console.WriteLine("El coche es de {0} cilindros", cilindrada);
            Console.WriteLine("La potencia del coche es de {0} caballos de fuerza", potencia);
        }
        public class Coche1
        {
            public static void Main()
            {
                Coche car = new Coche();
                Console.WriteLine("Datos del coche: \n");
                car.Mostrar();

                Console.WriteLine("\n\nDatos nuevos del coche: \n");
                Console.WriteLine("Ingrese la marca del coche: ");
                string marca1;
                marca1 = Console.ReadLine();
                Console.WriteLine("Ingrese el modelo del coche: ");
                string modelo1;
                modelo1 = Console.ReadLine();
                Console.WriteLine("Ingrese la cilindrada del coche: ");
                int cilindrada1;
                cilindrada1 = int.Parse(Console.ReadLine());
                Console.WriteLine("Ingrese la potencia del coche: ");
                float potencia1;
                potencia1 = float.Parse(Console.ReadLine());
                Console.WriteLine();

                car.SetDatos(marca1, modelo1, cilindrada1, potencia1);
                car.Mostrar();
                Console.ReadKey();
            }
        }
    }
}
