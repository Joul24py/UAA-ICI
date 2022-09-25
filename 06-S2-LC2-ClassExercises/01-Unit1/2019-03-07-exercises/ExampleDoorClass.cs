using System;

// Ejemplo 2
// Ejemplo clases con métodos
namespace ejemplo_metodos
{
    public class Puerta
    {
        int ancho;
        int alto;
        int color;      // Color en formato RGB
        bool abierta;  // Abierta o cerrada

        public void Abrir()
        {
            abierta = true;
        }

        public void Cerrar()
        {
            abierta = false;
        }
        

        public int GetAncho()
        {
            return ancho;

        }

        public void SetAncho(int nuevoValor)
        {
            ancho = nuevoValor;
        }

        public void MostrarEstado()
        {
            Console.WriteLine("Ancho : {0}", ancho);
            Console.WriteLine("Alto : {0}", alto);
            Console.WriteLine("Color : {0}", color);
            Console.WriteLine("Abierta : {0}", abierta);

        }
    }
    // Final de la clase compuerta


    public class Ejemplo_02
    { 
        public static void Main()
    {
        Puerta p = new Puerta();
        Console.WriteLine("Los valores iniciales...");
        p.MostrarEstado();

        Console.WriteLine(); 
        
       Console.WriteLine("Vamos a abrir");
        p.Abrir();
        p.SetAncho(80);
        p.MostrarEstado();

       Console.ReadKey();
         }

    }
}




