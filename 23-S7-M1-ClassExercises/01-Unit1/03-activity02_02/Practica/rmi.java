import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;

public class rmi extends UnicastRemoteObject implements calculadora {
	public rmi() throws RemoteException{
		int a,b;
	}

	@Override
	public int div(int a, int b) throws RemoteException {
		// TODO Auto-generated method stub
		return a/b;
	}

	@Override
	public int mul(int a, int b) throws RemoteException {
		// TODO Auto-generated method stub
		return a*b;
	}

	@Override
	public int res(int a, int b) throws RemoteException {
		// TODO Auto-generated method stub
		return a-b;
	}

	@Override
	public int sum(int a, int b) throws RemoteException {
		// TODO Auto-generated method stub
		return a+b;
	}

}
