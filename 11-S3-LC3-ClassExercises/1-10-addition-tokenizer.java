import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class sumatokenizer extends JPanel implements ActionListener
{
	JButton confirma1;
	JTextField texto1, texto2;
	
	public sumatokenizer()
	{
		texto1 = new JTextField(5);
		texto2 = new JTextField(15);
		confirma1 = new JButton("Sumar");
		confirma1.addActionListener(this);
		setLayout(new FlowLayout());
		add(texto1);
		add(texto2);
		add(confirma1);
	}
	
	@Override
	
	public void actionPerformed(ActionEvent ae)
	{
        Integer suma=0;    
		StringTokenizer st = new StringTokenizer(texto1.getText(),", ");
		String s3 = new String();
        while(st.hasMoreTokens())
        {
        	String s1 = st.nextToken();
        	Integer i = new Integer(s1);
        	suma=suma+i;
        }
        texto2.setText(suma.toString());
	}
	
	public static void main(String[] args) 
	{
		JFrame.setDefaultLookAndFeelDecorated(true);
		
		JFrame frame = new JFrame("Dos textfield y un botón");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		sumatokenizer bot = new sumatokenizer();
		frame.getContentPane().add(bot,BorderLayout.CENTER);
		
		frame.setBounds(100,100,400,325);
		frame.setVisible(true);

	}

}