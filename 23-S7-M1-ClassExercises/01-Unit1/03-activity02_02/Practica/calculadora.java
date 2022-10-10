import java.rmi.Remote;
import java.rmi.RemoteException;

public interface calculadora extends Remote{
	public int div(int a, int b) throws RemoteException;
	public int mul(int a, int b) throws RemoteException;
	public int res(int a, int b) throws RemoteException;
	public int sum(int a, int b) throws RemoteException;

}
