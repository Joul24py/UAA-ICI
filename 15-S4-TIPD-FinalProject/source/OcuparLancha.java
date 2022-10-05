import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class OcuparLancha extends JFrame
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
					OcuparLancha ocupar = new OcuparLancha("Lancha");
					ocupar.setVisible(true);
				}
				catch (Exception e)
				{
					e.printStackTrace();
				}
			}
		});
	}
	
	public OcuparLancha(String lanchanum)
	{
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 400, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel titulo = new JLabel(lanchanum);
		titulo.setHorizontalAlignment(SwingConstants.CENTER);
		titulo.setBounds(10, 11, 364, 14);
		contentPane.add(titulo);
		
		JLabel lbltiempo = new JLabel("Tiempo:");
		lbltiempo.setBounds(10, 63, 46, 14);
		contentPane.add(lbltiempo);
		
		JLabel lblpersonas = new JLabel("Personas:");
		lblpersonas.setBounds(10, 139, 89, 14);
		contentPane.add(lblpersonas);
		
		JComboBox comboadultos = new JComboBox();
		comboadultos.setModel(new DefaultComboBoxModel(new String[] {"0", "1", "2", "3", "4", "5"}));
		comboadultos.setBounds(123, 136, 105, 20);
		contentPane.add(comboadultos);
		
		JComboBox comboninos = new JComboBox();
		comboninos.setModel(new DefaultComboBoxModel(new String[] {"0", "1", "2", "3", "4", "5"}));
		comboninos.setBounds(123, 170, 105, 20);
		contentPane.add(comboninos);
		
		JLabel adultoslbl = new JLabel("adultos");
		adultoslbl.setBounds(248, 139, 105, 14);
		contentPane.add(adultoslbl);
		
		JLabel ninoslbl = new JLabel("ni\u00F1os");
		ninoslbl.setBounds(248, 173, 105, 14);
		contentPane.add(ninoslbl);
		
		JComboBox combotiempo = new JComboBox();
		combotiempo.setModel(new DefaultComboBoxModel(new String[] {"15", "30", "45", "60"}));
		combotiempo.setBounds(123, 57, 105, 20);
		contentPane.add(combotiempo);
		
		JLabel tiempolbl = new JLabel("minutos");
		tiempolbl.setBounds(248, 60, 105, 14);
		contentPane.add(tiempolbl);
		
		JButton ok = new JButton("Ok");
		ok.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				Object tiempo = combotiempo.getSelectedItem();
				Object adultos = comboadultos.getSelectedItem();
				Object ninos =comboninos.getSelectedItem();
				dispose();
			}
		});
		ok.setBounds(149, 227, 89, 23);
		contentPane.add(ok);
	}
}
