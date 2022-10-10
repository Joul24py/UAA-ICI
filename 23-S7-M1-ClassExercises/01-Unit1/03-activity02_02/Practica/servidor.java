import java.rmi.registry.Registry;
import javax.swing.JOptionPane;

public class servidor {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			Registry r = java.rmi.registry.LocateRegistry.createRegistry(1099);
			r.rebind("calculadora", new rmi());
			JOptionPane.showMessageDialog(null, "Servidor conectado");
		}catch (Exception e) {
			JOptionPane.showMessageDialog(null, "Servidor no conectado "+e);
		}
	}

}
