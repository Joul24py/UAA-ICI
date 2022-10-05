import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Estadisticas extends JFrame
{

	private JPanel contentPane;

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
					Estadisticas frame = new Estadisticas();
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
	public Estadisticas()
	{
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 720, 540);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JButton btnControlDeLanchas = new JButton("Lanchas");
		btnControlDeLanchas.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				dispose();
				ControlDeLanchas control = new ControlDeLanchas();
				control.setVisible(true);
			}
		});
		btnControlDeLanchas.setBounds(0, 0, 120, 125);
		contentPane.add(btnControlDeLanchas);
		
		JButton btnListaDeEspera = new JButton("Lista");
		btnListaDeEspera.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				dispose();
				ListaDeEspera lista = new ListaDeEspera();
				lista.setVisible(true);
			}
		});
		btnListaDeEspera.setBounds(0, 123, 120, 125);
		contentPane.add(btnListaDeEspera);
		
		JLabel lblEstadisticas = new JLabel("Estad\u00EDsticas");
		lblEstadisticas.setHorizontalAlignment(SwingConstants.CENTER);
		lblEstadisticas.setBounds(0, 248, 120, 125);
		contentPane.add(lblEstadisticas);
		
		JPanel btnEstadisticas = new JPanel();
		btnEstadisticas.setBounds(0, 248, 120, 125);
		contentPane.add(btnEstadisticas);
		
		JButton btnSalir = new JButton("Salir");
		btnSalir.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				dispose();
			}
		});
		btnSalir.setBounds(0, 376, 120, 125);
		contentPane.add(btnSalir);
		
		JLabel titulo = new JLabel("Estad\u00EDsticas");
		titulo.setHorizontalAlignment(SwingConstants.CENTER);
		titulo.setBounds(118, 11, 586, 14);
		contentPane.add(titulo);
		
		JLabel lbl1 = new JLabel("Reporte Semanal");
		lbl1.setHorizontalAlignment(SwingConstants.CENTER);
		lbl1.setBounds(118, 70, 293, 14);
		contentPane.add(lbl1);
		
		JLabel lbl2 = new JLabel("Reporte de Utilidad");
		lbl2.setHorizontalAlignment(SwingConstants.CENTER);
		lbl2.setBounds(411, 70, 293, 14);
		contentPane.add(lbl2);
		
		JButton btnRevisarFecha = new JButton("Revisar una fecha");
		btnRevisarFecha.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				RevisarFecha revisar1 = new RevisarFecha();
				revisar1.setVisible(true);
			}
		});
		btnRevisarFecha.setBounds(181, 106, 150, 40);
		contentPane.add(btnRevisarFecha);
		
		JButton btnCalibrarValores = new JButton("Calibrar Valores");
		btnCalibrarValores.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				CalibrarValores calibrar1 = new CalibrarValores();
				calibrar1.setVisible(true);
			}
		});
		btnCalibrarValores.setBounds(482, 106, 150, 40);
		contentPane.add(btnCalibrarValores);
	}

}
