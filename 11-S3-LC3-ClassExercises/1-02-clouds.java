import java.util.*;

class testnube
{
	 public int tam;
	 public int den;
	 
	 int lluvia()
	 {
	 	return tam*den;
	 }
	 
	 public testnube(int tama, int dens)
	 {
	 	tam = tama;
	 	den = dens;
	 }
}

public class nube 
{
	public static void main(String[] args) 
	{
		Scanner read = new Scanner(System.in);
		
		testnube n1 = new testnube(15,21);
		testnube n2 = new testnube(17,19);
		
		if(n1.lluvia()==n2.lluvia())
		{
			System.out.println("Iguales");
		}
		if(n1.lluvia()>n2.lluvia())
		{
			System.out.println("Nube 1 es mayor");
		}
		if(n1.lluvia()<n2.lluvia())
		{
			System.out.println("Nube 2 es mayor");
		}

	}

}