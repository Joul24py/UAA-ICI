import java.util.*;

public class vector1 
{

	public static void main(String[] args) 
	{
		int[] arr; //Declaración
		arr = new int[10]; //Instanciación
		Scanner read = new Scanner(System.in);
		
		System.out.println("Otorga el primer número");
		arr[0]=read.nextInt();
		System.out.println("Otorga el segundo número");
		arr[1]=read.nextInt();
		System.out.println("Otorga el tercer número");
		arr[2]=read.nextInt();
		System.out.println("Otorga el cuarto número");
		arr[3]=read.nextInt();
		System.out.println("Otorga el quinto número");
		arr[4]=read.nextInt();
		System.out.println("Otorga el sexto número");
		arr[5]=read.nextInt();
		System.out.println("Otorga el s�ptimo número");
		arr[6]=read.nextInt();
		System.out.println("Otorga el octavo número");
		arr[7]=read.nextInt();
		System.out.println("Otorga el noveno número");
		arr[8]=read.nextInt();
		System.out.println("Otorga el d�cimo número");
		arr[9]=read.nextInt();
		
		int mayor=-100;
		
		for(int i = 0; i<10; i++)
		{
			if(mayor<arr[i])
			{
				mayor=arr[i];
			}
		}
		System.out.println("El mayor es: "+ mayor);

	}

}