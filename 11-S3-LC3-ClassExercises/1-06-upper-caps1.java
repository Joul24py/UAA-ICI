package capitalizar;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class capitalizar extends JPanel implements ActionListener
{
	JButton confirma1;
	JTextField texto1, texto2;
	
	public capitalizar()
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
            String a = texto1.getText().toString();
            texto2.setText(a.substring(0, 1).toUpperCase()+a.substring(1));
	}
	
	public static void main(String[] args) 
	{
		JFrame.setDefaultLookAndFeelDecorated(true);
		
		JFrame frame = new JFrame("Dos textfield y un botón");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		capitalizar bot = new capitalizar();
		frame.getContentPane().add(bot,BorderLayout.CENTER);
		
		frame.setBounds(100,100,400,325);
		frame.setVisible(true);

	}

}