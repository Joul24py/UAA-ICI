import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class f_JPanel_01 extends JPanel implements ActionListener
{
	JButton confirma1;
	JTextField texto1, texto2;
	
	public f_JPanel_01()
	{
		texto1 = new JTextField(5);
		texto2 = new JTextField(15);
		confirma1 = new JButton("Cuadrado");
		confirma1.addActionListener(this);
		setLayout(new FlowLayout());
		add(texto1);
		add(texto2);
		add(confirma1);
	}
	
	@Override
	
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource() == confirma1)
		{
			Integer i = new Integer(texto1.getText().toString());
			int cua = i.intValue()*i.intValue();
			Integer ii= new Integer(cua);
			texto2.setText("Respuesta " + ii.toString());
		}
	}
	
	public static void main(String[] args) 
	{
		JFrame.setDefaultLookAndFeelDecorated(true);
		
		JFrame frame = new JFrame("Dos textfield y un botón");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		f_JPanel_01 bot = new f_JPanel_01();
		frame.getContentPane().add(bot,BorderLayout.CENTER);
		
		frame.setBounds(100,100,400,325);
		frame.setVisible(true);

	}

}