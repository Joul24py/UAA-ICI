using System;

namespace ConsoleApp6
{
    class Program
    {
        public static void Main(string[] args)
        {
            Puerta p = new Puerta();

            Console.WriteLine("Valores iniciales:");
            p.MostrarEstado();

            Console.WriteLine();

            Console.WriteLine("Vamos a abrir:");
            p.Abrir();
            p.SetAncho(80);
            p.MostrarEstado();

            Console.WriteLine();

            Console.WriteLine("Ahora el portón:");
            Porton p2 = new Porton();
            p2.SetAncho(300);
            p2.Bloquear();
            p2.MostrarEstado();
            Console.ReadKey();
        }
    }

    public class Puerta
    {
        protected int ancho;
        protected int alto;
        protected int color;
        protected bool abierta;

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
            Console.WriteLine("Ancho: {0}", ancho);
            Console.WriteLine("Alto: {0}", alto);
            Console.WriteLine("Color: {0}", color);
            Console.WriteLine("Abierta: {0}", abierta);
        }
    }

    public class Porton : Puerta
    {
        bool bloqueada;

        public void Bloquear()
        {
            bloqueada = true;
        }
        public void Desbloquear()
        {
            bloqueada = false;
        }
        public new void MostrarEstado()
        {
            Console.WriteLine("Portón");
            Console.WriteLine("Ancho: {0}", ancho);
            Console.WriteLine("Alto: {0}",alto);
            Console.WriteLine("Color: {0}",color);
            Console.WriteLine("Abierta: {0}",abierta);
            Console.WriteLine("Bloqueada: {0}",bloqueada);
        }
    }
}
