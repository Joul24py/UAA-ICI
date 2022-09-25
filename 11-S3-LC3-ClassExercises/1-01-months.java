import java.util.*;

public class mes 
{

	public static void main(String[] args) 
	{
		Scanner read = new Scanner(System.in);
		
		System.out.println("Otorga un número");
		int mes = read.nextInt();
		
		String season = "nada";
		
		switch(mes)
		{
		case 12:
		case 1:
		case 2:
		{
			season="invierno";
			break;
		}
		case 3:
		case 4:
		case 5:
		{
			season="primavera";
			break;
		}
		case 6:
		case 7:
		case 8:
		{
			season="verano";
			break;
		}
		case 9:
		case 10:
		case 11:
		{
			season="otoño";
			break;
		}
		}
		System.out.println("La estación es: "+ season);

	}

}