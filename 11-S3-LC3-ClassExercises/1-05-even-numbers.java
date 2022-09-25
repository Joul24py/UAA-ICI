import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class pares extends JPanel implements ActionListener
{
	JButton confirma1;
	JTextField texto1, texto2, texto3;
	
	public pares()
	{
		texto1 = new JTextField(5);
		texto2 = new JTextField(10);
		texto3 = new JTextField(10);
		confirma1 = new JButton("Calcular");
		confirma1.addActionListener(this);
		setLayout(new FlowLayout());
		add(texto1);
		add(texto2);
		add(texto3);
		add(confirma1);
		texto2.setText("Pares:");
		texto3.setText("Impares:");
	}
	
	@Override
	
	public void actionPerformed(ActionEvent ae)
	{
        StringTokenizer st = new StringTokenizer(texto1.getText(),", ");
		StringBuilder s3 = new StringBuilder();
		StringBuilder s4 = new StringBuilder();
		s3.append("Pares: ");
		s4.append("Impares: ");
        while(st.hasMoreTokens())
        {
        	String s1 = st.nextToken();
        	Integer i = new Integer(s1);
        	if(i%2==0)
        	{
        		s3.append(i.toString() + " ");
        	}
        	else
        	{
        		s4.append(i.toString() + " ");
        	}
        }
        texto2.setText(s3.toString());
        texto3.setText(s4.toString());
	}
	
	public static void main(String[] args) 
	{
		JFrame.setDefaultLookAndFeelDecorated(true);
		
		JFrame frame = new JFrame("Dos textfield y un botón");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		pares bot = new pares();
		frame.getContentPane().add(bot,BorderLayout.CENTER);
		
		frame.setBounds(100,100,400,325);
		frame.setVisible(true);

	}

}