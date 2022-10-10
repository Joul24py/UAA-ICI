import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;
import javax.swing.JOptionPane;

public class cliente {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		try
		{
			Registry miRegistro= LocateRegistry.getRegistry("localhost",1099);
			calculadora c= (calculadora) Naming.lookup("//localhost/calculadora");
			
			while(true)
			{
				String menu=JOptionPane.showInputDialog("Ejercicio calculadora \n "+
			    "1) Suma\n"+
						"2) Resta\n"+
			    "3) Multiplicación\n"+
						"4) División\n\n"+
			    "Cancelar para salir");
				switch(menu)
				{
				case "1":
				{
					int x=Integer.parseInt(JOptionPane.showInputDialog("Imgrese el primer numero a sumar"));
					int y=Integer.parseInt(JOptionPane.showInputDialog("Imgrese el segundo numero a sumar"));
					JOptionPane.showMessageDialog(null, "El resultado de la suma es "+c.sum(x, y), "Suma",JOptionPane.INFORMATION_MESSAGE);
				}	
					break;
				case "2":
				{
					int x=Integer.parseInt(JOptionPane.showInputDialog("Imgrese el primer numero a restar"));
					int y=Integer.parseInt(JOptionPane.showInputDialog("Imgrese el segundo numero a resar"));
					JOptionPane.showMessageDialog(null, "El resultado de la resta es "+c.res(x, y), "Resta",JOptionPane.INFORMATION_MESSAGE);
				}
					break;
				case "3":
				{
					int x=Integer.parseInt(JOptionPane.showInputDialog("Imgrese el primer numero a multiplicar"));
					int y=Integer.parseInt(JOptionPane.showInputDialog("Imgrese el segundo numero a multiplicar"));
					JOptionPane.showMessageDialog(null, "El resultado de la multiplicacion es "+c.mul(x, y), "Multiplicación",JOptionPane.INFORMATION_MESSAGE);
				}
					break;
				case "4":
				{
					int x=Integer.parseInt(JOptionPane.showInputDialog("Imgrese el divisor"));
					int y=Integer.parseInt(JOptionPane.showInputDialog("Imgrese el dividendo"));
					JOptionPane.showMessageDialog(null, "El resultado de la division es "+c.div(x, y), "División",JOptionPane.INFORMATION_MESSAGE);
				}
					break;
					default:
						JOptionPane.showMessageDialog(null, "opcion invalida");
						break;
					
				}
			}
		}catch(Exception e) {
			JOptionPane.showMessageDialog(null, "Servidor no conectado "+e);
		}
	}

}
