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

public class ListaDeEspera extends JFrame
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
					ListaDeEspera frame = new ListaDeEspera();
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
	public ListaDeEspera()
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
		
		JLabel lblListaDeEspera = new JLabel("Lista");
		lblListaDeEspera.setHorizontalAlignment(SwingConstants.CENTER);
		lblListaDeEspera.setBounds(0, 125, 120, 125);
		contentPane.add(lblListaDeEspera);
		
		JPanel btnListaDeEspera = new JPanel();
		btnListaDeEspera.setBounds(0, 125, 120, 125);
		contentPane.add(btnListaDeEspera);
		
		JButton btnEstadisticas = new JButton("Estad\u00EDsticas");
		btnEstadisticas.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				dispose();
				Estadisticas stats = new Estadisticas();
				stats.setVisible(true);
			}
		});
		btnEstadisticas.setBounds(0, 252, 120, 125);
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
		
		JButton btnAgregar = new JButton("Agregar a lista");
		btnAgregar.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				AgregarALista agregar1 = new AgregarALista();
				agregar1.setVisible(true);
			}
		});
		btnAgregar.setBounds(544, 348, 150, 40);
		contentPane.add(btnAgregar);
		
		JButton btnEliminar = new JButton("Eliminar de lista");
		btnEliminar.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				EliminarDeLista eliminar1 = new EliminarDeLista();
				eliminar1.setVisible(true);
			}
		});
		btnEliminar.setBounds(544, 399, 150, 40);
		contentPane.add(btnEliminar);
		
		JButton btnModificar = new JButton("Modificar elemento");
		btnModificar.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				ModificarDeLista modificar1 = new ModificarDeLista();
				modificar1.setVisible(true);
			}
		});
		btnModificar.setBounds(544, 450, 150, 40);
		contentPane.add(btnModificar);
	}
}
