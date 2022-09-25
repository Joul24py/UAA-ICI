import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class capitalizar2 extends JPanel implements ActionListener
{
	JButton confirma1;
	JTextField texto1, texto2;
	
	public capitalizar2()
	{
		texto1 = new JTextField(5);
		texto2 = new JTextField(15);
		confirma1 = new JButton("Capitalizar");
		confirma1.addActionListener(this);
		setLayout(new FlowLayout());
		add(texto1);
		add(texto2);
		add(confirma1);
	}
	
	@Override
	
	public void actionPerformed(ActionEvent ae)
	{
            StringTokenizer st = new StringTokenizer(texto1.getText()," ");
            StringBuffer s3 = new StringBuffer();
            while(st.hasMoreTokens())
            {
            	String s1 = st.nextToken();
            	Character s2 = s1.charAt(0);
            	s3.append(" " + s1.substring(0,1).toUpperCase()+s1.substring(1));
            	
            }
            texto2.setText(s3.toString());
	}
	
	public static void main(String[] args) 
	{
		JFrame.setDefaultLookAndFeelDecorated(true);
		
		JFrame frame = new JFrame("Dos textfield y un botón");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		capitalizar2 bot = new capitalizar2();
		frame.getContentPane().add(bot,BorderLayout.CENTER);
		
		frame.setBounds(100,100,400,325);
		frame.setVisible(true);

	}

}