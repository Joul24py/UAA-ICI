import java.util.*;

public class prog1
{

	public static void main(String[] args) 
	{
		int a,b,c;
		
		Scanner read = new Scanner(System.in);
		System.out.println("Otorga A:");
		a=read.nextInt();
		System.out.println("Otorga B:");
		b=read.nextInt();
		System.out.println("Otorga C:");
		c=read.nextInt();
		
		if(a==b&&a==c)
		{
			System.out.println("El triángulo es equilátero");
		}
		else
		{
			if(a==b||a==c||b==c)
			{
				System.out.println("El triángulo es isósceles");
			}
			else
			{
				System.out.println("El triángulo es escaleno");
			}
		}
		

	}

}