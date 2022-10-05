import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.JButton;
import javax.swing.JTextField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class ModificarDeLista extends JFrame
{

	private JPanel contentPane;
	private JTextField txtPosicion;
	private JTextField txtNombre;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args)
	{
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				try
				{
					ModificarDeLista frame = new ModificarDeLista();
					frame.setVisible(true);
				}
				catch (Exception e)
				{
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public ModificarDeLista()
	{
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 400, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel titulo = new JLabel("Modificar");
		titulo.setHorizontalAlignment(SwingConstants.CENTER);
		titulo.setBounds(10, 11, 364, 14);
		contentPane.add(titulo);
		
		JLabel lblPosicion = new JLabel("Modificar Posici\u00F3n:");
		lblPosicion.setBounds(10, 63, 113, 14);
		contentPane.add(lblPosicion);
		
		txtPosicion = new JTextField();
		txtPosicion.setColumns(10);
		txtPosicion.setBounds(123, 60, 135, 20);
		contentPane.add(txtPosicion);
		
		JLabel lblNombre = new JLabel("Nombre Nuevo:");
		lblNombre.setBounds(10, 139, 103, 14);
		contentPane.add(lblNombre);
		
		txtNombre = new JTextField();
		txtNombre.setColumns(10);
		txtNombre.setBounds(123, 136, 135, 20);
		contentPane.add(txtNombre);
		
		JButton ok = new JButton("Ok");
		ok.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				dispose();
			}
		});
		ok.setBounds(149, 227, 89, 23);
		contentPane.add(ok);
	}

}
