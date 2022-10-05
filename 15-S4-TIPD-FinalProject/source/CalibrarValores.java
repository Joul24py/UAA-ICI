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

public class CalibrarValores extends JFrame
{

	private JPanel contentPane;
	private JTextField txtSueldos;
	private JTextField txtRenta;
	private JTextField txtMantenimiento;

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
					CalibrarValores frame = new CalibrarValores();
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
	public CalibrarValores()
	{
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 400, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel titulo = new JLabel("Calibrar valores");
		titulo.setHorizontalAlignment(SwingConstants.CENTER);
		titulo.setBounds(10, 11, 364, 14);
		contentPane.add(titulo);
		
		JButton calcular = new JButton("Calcular");
		calcular.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				dispose();
			}
		});
		calcular.setBounds(149, 227, 89, 23);
		contentPane.add(calcular);
		
		JLabel lblSueldos = new JLabel("Sueldos:");
		lblSueldos.setBounds(10, 83, 113, 14);
		contentPane.add(lblSueldos);
		
		JLabel lblRenta = new JLabel("Renta del parque:");
		lblRenta.setBounds(10, 108, 113, 14);
		contentPane.add(lblRenta);
		
		JLabel lblMantenimiento = new JLabel("Mantenimiento:");
		lblMantenimiento.setBounds(10, 133, 113, 14);
		contentPane.add(lblMantenimiento);
		
		txtSueldos = new JTextField();
		txtSueldos.setBounds(129, 80, 130, 20);
		contentPane.add(txtSueldos);
		txtSueldos.setColumns(10);
		
		txtRenta = new JTextField();
		txtRenta.setColumns(10);
		txtRenta.setBounds(129, 105, 130, 20);
		contentPane.add(txtRenta);
		
		txtMantenimiento = new JTextField();
		txtMantenimiento.setColumns(10);
		txtMantenimiento.setBounds(129, 130, 130, 20);
		contentPane.add(txtMantenimiento);
	}

}
