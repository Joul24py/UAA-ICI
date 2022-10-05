import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.awt.Color;
import javax.swing.JButton;
import javax.swing.SwingConstants;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class ControlDeLanchas extends JFrame
{
	int l1 = 0;
	int l2 = 0;
	int l3 = 0;
	int l4 = 0;
	int l5 = 0;
	int l6 = 0;
	int l7 = 0;
	int l8 = 0;
	int l9 = 0;
	int l10 = 0;
	
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
					ControlDeLanchas control = new ControlDeLanchas();
					control.setVisible(true);
				}
				catch (Exception e)
				{
					e.printStackTrace();
				}
			}
		});
	}
	
	public ControlDeLanchas()
	{
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 720, 540);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblControlDeLanchas = new JLabel("Lanchas");
		lblControlDeLanchas.setHorizontalAlignment(SwingConstants.CENTER);
		lblControlDeLanchas.setBounds(0, 0, 120, 125);
		contentPane.add(lblControlDeLanchas);
		
		JPanel btnControlDeLanchas = new JPanel();
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
		btnEstadisticas.setBounds(0, 250, 120, 125);
		contentPane.add(btnEstadisticas);
		
		JButton btnSalir = new JButton("Salir");
		btnSalir.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				dispose();
			}
		});
		btnSalir.setBounds(0, 375, 120, 126);
		contentPane.add(btnSalir);
		
		JPanel panel1 = new JPanel();
		panel1.setBounds(130, 10, 277, 92);
		contentPane.add(panel1);
		panel1.setLayout(null);
		
		JLabel lancha1 = new JLabel("1");
		lancha1.setHorizontalAlignment(SwingConstants.CENTER);
		lancha1.setBounds(30, 11, 80, 14);
		panel1.add(lancha1);
		
		JLabel estado1 = new JLabel("Disponible");
		estado1.setForeground(Color.GREEN);
		estado1.setBounds(30, 36, 60, 14);
		panel1.add(estado1);
		
		JButton ocupar1 = new JButton("Ocupar");
		ocupar1.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent arg0)
			{
				if(l1==0)
				{
					l1=1;
					ocupar1.setText("Desocupar");
					estado1.setText("Ocupado");
					estado1.setForeground(Color.RED);
					OcuparLancha ocup1 = new OcuparLancha("1");
					ocup1.setVisible(true);
				}
				else
				{
					l1=0;
					ocupar1.setText("Ocupar");
					estado1.setText("Disponible");
					estado1.setForeground(Color.GREEN);
					DesocuparLancha desocup1 = new DesocuparLancha("1");
					desocup1.setVisible(true);
				}
			}
		});
		ocupar1.setBounds(10, 58, 130, 23);
		panel1.add(ocupar1);
		
		JLabel tres1 = new JLabel("");
		tres1.setHorizontalAlignment(SwingConstants.CENTER);
		tres1.setBounds(142, 11, 125, 14);
		panel1.add(tres1);
		
		JLabel tiempo1 = new JLabel("");
		tiempo1.setHorizontalAlignment(SwingConstants.CENTER);
		tiempo1.setBounds(142, 30, 125, 14);
		panel1.add(tiempo1);
		
		JLabel adultos1 = new JLabel("");
		adultos1.setBounds(142, 62, 69, 14);
		panel1.add(adultos1);
		
		JLabel ninos1 = new JLabel("");
		ninos1.setHorizontalAlignment(SwingConstants.RIGHT);
		ninos1.setBounds(198, 62, 69, 14);
		panel1.add(ninos1);
		
		JPanel panel2 = new JPanel();
		panel2.setBounds(130, 107, 277, 92);
		contentPane.add(panel2);
		panel2.setLayout(null);
		
		JLabel tres2 = new JLabel("");
		tres2.setHorizontalAlignment(SwingConstants.CENTER);
		tres2.setBounds(142, 11, 125, 14);
		panel2.add(tres2);
		
		JLabel tiempo2 = new JLabel("");
		tiempo2.setHorizontalAlignment(SwingConstants.CENTER);
		tiempo2.setBounds(142, 30, 125, 14);
		panel2.add(tiempo2);
		
		JLabel adultos2 = new JLabel("");
		adultos2.setBounds(142, 62, 69, 14);
		panel2.add(adultos2);
		
		JLabel ninos2 = new JLabel("");
		ninos2.setHorizontalAlignment(SwingConstants.RIGHT);
		ninos2.setBounds(198, 62, 69, 14);
		panel2.add(ninos2);
		
		JLabel estado2 = new JLabel("Disponible");
		estado2.setForeground(Color.GREEN);
		estado2.setBounds(30, 36, 60, 14);
		panel2.add(estado2);
		
		JButton ocupar2 = new JButton("Ocupar");
		ocupar2.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent arg0)
			{
				if(l2==0)
				{
					l2=1;
					ocupar2.setText("Desocupar");
					estado2.setText("Ocupado");
					estado2.setForeground(Color.RED);
					OcuparLancha ocup1 = new OcuparLancha("2");
					ocup1.setVisible(true);
				}
				else
				{
					l2=0;
					ocupar2.setText("Ocupar");
					estado2.setText("Disponible");
					estado2.setForeground(Color.GREEN);
					DesocuparLancha desocup1 = new DesocuparLancha("2");
					desocup1.setVisible(true);
				}
			}
		});
		ocupar2.setBounds(10, 58, 130, 23);
		panel2.add(ocupar2);
		
		JLabel lancha2 = new JLabel("2");
		lancha2.setHorizontalAlignment(SwingConstants.CENTER);
		lancha2.setBounds(30, 11, 80, 14);
		panel2.add(lancha2);
		
		JPanel panel3 = new JPanel();
		panel3.setLayout(null);
		panel3.setBounds(130, 204, 277, 92);
		contentPane.add(panel3);
		
		JLabel tres3 = new JLabel("");
		tres3.setHorizontalAlignment(SwingConstants.CENTER);
		tres3.setBounds(142, 11, 125, 14);
		panel3.add(tres3);
		
		JLabel tiempo3 = new JLabel("");
		tiempo3.setHorizontalAlignment(SwingConstants.CENTER);
		tiempo3.setBounds(142, 30, 125, 14);
		panel3.add(tiempo3);
		
		JLabel adultos3 = new JLabel("");
		adultos3.setBounds(142, 62, 69, 14);
		panel3.add(adultos3);
		
		JLabel ninos3 = new JLabel("");
		ninos3.setHorizontalAlignment(SwingConstants.RIGHT);
		ninos3.setBounds(198, 62, 69, 14);
		panel3.add(ninos3);
		
		JLabel estado3 = new JLabel("Disponible");
		estado3.setForeground(Color.GREEN);
		estado3.setBounds(30, 36, 60, 14);
		panel3.add(estado3);
		
		JButton ocupar3 = new JButton("Ocupar");
		ocupar3.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				if(l3==0)
				{
					l3=1;
					ocupar3.setText("Desocupar");
					estado3.setText("Ocupado");
					estado3.setForeground(Color.RED);
					OcuparLancha ocup1 = new OcuparLancha("3");
					ocup1.setVisible(true);
				}
				else
				{
					l3=0;
					ocupar3.setText("Ocupar");
					estado3.setText("Disponible");
					estado3.setForeground(Color.GREEN);
					DesocuparLancha desocup1 = new DesocuparLancha("3");
					desocup1.setVisible(true);
				}
			}
		});
		ocupar3.setBounds(10, 58, 130, 23);
		panel3.add(ocupar3);
		
		JLabel lancha3 = new JLabel("3");
		lancha3.setHorizontalAlignment(SwingConstants.CENTER);
		lancha3.setBounds(30, 11, 80, 14);
		panel3.add(lancha3);
		
		JPanel panel4 = new JPanel();
		panel4.setLayout(null);
		panel4.setBounds(130, 301, 277, 92);
		contentPane.add(panel4);
		
		JLabel tres4 = new JLabel("");
		tres4.setHorizontalAlignment(SwingConstants.CENTER);
		tres4.setBounds(142, 11, 125, 14);
		panel4.add(tres4);
		
		JLabel tiempo4 = new JLabel("");
		tiempo4.setHorizontalAlignment(SwingConstants.CENTER);
		tiempo4.setBounds(142, 30, 125, 14);
		panel4.add(tiempo4);
		
		JLabel adultos4 = new JLabel("");
		adultos4.setBounds(142, 62, 69, 14);
		panel4.add(adultos4);
		
		JLabel ninos4 = new JLabel("");
		ninos4.setHorizontalAlignment(SwingConstants.RIGHT);
		ninos4.setBounds(198, 62, 69, 14);
		panel4.add(ninos4);
		
		JLabel estado4 = new JLabel("Disponible");
		estado4.setForeground(Color.GREEN);
		estado4.setBounds(30, 36, 60, 14);
		panel4.add(estado4);
		
		JButton ocupar4 = new JButton("Ocupar");
		ocupar4.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				if(l4==0)
				{
					l4=1;
					ocupar4.setText("Desocupar");
					estado4.setText("Ocupado");
					estado4.setForeground(Color.RED);
					OcuparLancha ocup1 = new OcuparLancha("4");
					ocup1.setVisible(true);
				}
				else
				{
					l4=0;
					ocupar4.setText("Ocupar");
					estado4.setText("Disponible");
					estado4.setForeground(Color.GREEN);
					DesocuparLancha desocup1 = new DesocuparLancha("4");
					desocup1.setVisible(true);
				}
			}
		});
		ocupar4.setBounds(10, 58, 130, 23);
		panel4.add(ocupar4);
		
		JLabel lancha4 = new JLabel("4");
		lancha4.setHorizontalAlignment(SwingConstants.CENTER);
		lancha4.setBounds(30, 11, 80, 14);
		panel4.add(lancha4);
		
		JPanel panel5 = new JPanel();
		panel5.setLayout(null);
		panel5.setBounds(130, 398, 277, 92);
		contentPane.add(panel5);
		
		JLabel tres5 = new JLabel("");
		tres5.setHorizontalAlignment(SwingConstants.CENTER);
		tres5.setBounds(142, 11, 125, 14);
		panel5.add(tres5);
		
		JLabel tiempo5 = new JLabel("");
		tiempo5.setHorizontalAlignment(SwingConstants.CENTER);
		tiempo5.setBounds(142, 30, 125, 14);
		panel5.add(tiempo5);
		
		JLabel adultos5 = new JLabel("");
		adultos5.setBounds(142, 62, 69, 14);
		panel5.add(adultos5);
		
		JLabel ninos5 = new JLabel("");
		ninos5.setHorizontalAlignment(SwingConstants.RIGHT);
		ninos5.setBounds(198, 62, 69, 14);
		panel5.add(ninos5);
		
		JLabel estado5 = new JLabel("Disponible");
		estado5.setForeground(Color.GREEN);
		estado5.setBounds(30, 36, 60, 14);
		panel5.add(estado5);
		
		JButton ocupar5 = new JButton("Ocupar");
		ocupar5.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				if(l5==0)
				{
					l5=1;
					ocupar5.setText("Desocupar");
					estado5.setText("Ocupado");
					estado5.setForeground(Color.RED);
					OcuparLancha ocup1 = new OcuparLancha("5");
					ocup1.setVisible(true);
				}
				else
				{
					l5=0;
					ocupar5.setText("Ocupar");
					estado5.setText("Disponible");
					estado5.setForeground(Color.GREEN);
					DesocuparLancha desocup1 = new DesocuparLancha("5");
					desocup1.setVisible(true);
				}
			}
		});
		ocupar5.setBounds(10, 58, 130, 23);
		panel5.add(ocupar5);
		
		JLabel lancha5 = new JLabel("5");
		lancha5.setHorizontalAlignment(SwingConstants.CENTER);
		lancha5.setBounds(30, 11, 80, 14);
		panel5.add(lancha5);
		
		JPanel panel6 = new JPanel();
		panel6.setBounds(417, 11, 277, 92);
		contentPane.add(panel6);
		panel6.setLayout(null);
		
		JLabel tres6 = new JLabel("");
		tres6.setHorizontalAlignment(SwingConstants.CENTER);
		tres6.setBounds(142, 11, 125, 14);
		panel6.add(tres6);
		
		JLabel tiempo6 = new JLabel("");
		tiempo6.setHorizontalAlignment(SwingConstants.CENTER);
		tiempo6.setBounds(142, 30, 125, 14);
		panel6.add(tiempo6);
		
		JLabel adultos6 = new JLabel("");
		adultos6.setBounds(142, 62, 69, 14);
		panel6.add(adultos6);
		
		JLabel ninos6 = new JLabel("");
		ninos6.setHorizontalAlignment(SwingConstants.RIGHT);
		ninos6.setBounds(198, 62, 69, 14);
		panel6.add(ninos6);
		
		JLabel estado6 = new JLabel("Disponible");
		estado6.setForeground(Color.GREEN);
		estado6.setBounds(30, 36, 60, 14);
		panel6.add(estado6);
		
		JButton ocupar6 = new JButton("Ocupar");
		ocupar6.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				if(l6==0)
				{
					l6=1;
					ocupar6.setText("Desocupar");
					estado6.setText("Ocupado");
					estado6.setForeground(Color.RED);
					OcuparLancha ocup1 = new OcuparLancha("6");
					ocup1.setVisible(true);
				}
				else
				{
					l6=0;
					ocupar6.setText("Ocupar");
					estado6.setText("Disponible");
					estado6.setForeground(Color.GREEN);
					DesocuparLancha desocup1 = new DesocuparLancha("6");
					desocup1.setVisible(true);
				}
			}
		});
		ocupar6.setBounds(10, 58, 130, 23);
		panel6.add(ocupar6);
		
		JLabel lancha6 = new JLabel("6");
		lancha6.setHorizontalAlignment(SwingConstants.CENTER);
		lancha6.setBounds(30, 11, 80, 14);
		panel6.add(lancha6);
		
		JPanel panel7 = new JPanel();
		panel7.setBounds(417, 107, 277, 92);
		contentPane.add(panel7);
		panel7.setLayout(null);
		
		JLabel tres7 = new JLabel("");
		tres7.setHorizontalAlignment(SwingConstants.CENTER);
		tres7.setBounds(142, 11, 125, 14);
		panel7.add(tres7);
		
		JLabel tiempo7 = new JLabel("");
		tiempo7.setHorizontalAlignment(SwingConstants.CENTER);
		tiempo7.setBounds(142, 30, 125, 14);
		panel7.add(tiempo7);
		
		JLabel adultos7 = new JLabel("");
		adultos7.setBounds(142, 62, 69, 14);
		panel7.add(adultos7);
		
		JLabel ninos7 = new JLabel("");
		ninos7.setHorizontalAlignment(SwingConstants.RIGHT);
		ninos7.setBounds(198, 62, 69, 14);
		panel7.add(ninos7);
		
		JLabel estado7 = new JLabel("Disponible");
		estado7.setForeground(Color.GREEN);
		estado7.setBounds(30, 36, 60, 14);
		panel7.add(estado7);
		
		JButton ocupar7 = new JButton("Ocupar");
		ocupar7.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				if(l7==0)
				{
					l7=1;
					ocupar7.setText("Desocupar");
					estado7.setText("Ocupado");
					estado7.setForeground(Color.RED);
					OcuparLancha ocup1 = new OcuparLancha("7");
					ocup1.setVisible(true);
				}
				else
				{
					l7=0;
					ocupar7.setText("Ocupar");
					estado7.setText("Disponible");
					estado7.setForeground(Color.GREEN);
					DesocuparLancha desocup1 = new DesocuparLancha("7");
					desocup1.setVisible(true);
				}
			}
		});
		ocupar7.setBounds(10, 58, 130, 23);
		panel7.add(ocupar7);
		
		JLabel lancha7 = new JLabel("7");
		lancha7.setHorizontalAlignment(SwingConstants.CENTER);
		lancha7.setBounds(30, 11, 80, 14);
		panel7.add(lancha7);
		
		JPanel panel8 = new JPanel();
		panel8.setLayout(null);
		panel8.setBounds(417, 204, 277, 92);
		contentPane.add(panel8);
		
		JLabel tres8 = new JLabel("");
		tres8.setHorizontalAlignment(SwingConstants.CENTER);
		tres8.setBounds(142, 11, 125, 14);
		panel8.add(tres8);
		
		JLabel tiempo8 = new JLabel("");
		tiempo8.setHorizontalAlignment(SwingConstants.CENTER);
		tiempo8.setBounds(142, 30, 125, 14);
		panel8.add(tiempo8);
		
		JLabel adultos8 = new JLabel("");
		adultos8.setBounds(142, 62, 69, 14);
		panel8.add(adultos8);
		
		JLabel ninos8 = new JLabel("");
		ninos8.setHorizontalAlignment(SwingConstants.RIGHT);
		ninos8.setBounds(198, 62, 69, 14);
		panel8.add(ninos8);
		
		JLabel estado8 = new JLabel("Disponible");
		estado8.setForeground(Color.GREEN);
		estado8.setBounds(30, 36, 60, 14);
		panel8.add(estado8);
		
		JButton ocupar8 = new JButton("Ocupar");
		ocupar8.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				if(l8==0)
				{
					l8=1;
					ocupar8.setText("Desocupar");
					estado8.setText("Ocupado");
					estado8.setForeground(Color.RED);
					OcuparLancha ocup1 = new OcuparLancha("8");
					ocup1.setVisible(true);
				}
				else
				{
					l8=0;
					ocupar8.setText("Ocupar");
					estado8.setText("Disponible");
					estado8.setForeground(Color.GREEN);
					DesocuparLancha desocup1 = new DesocuparLancha("8");
					desocup1.setVisible(true);
				}
			}
		});
		ocupar8.setBounds(10, 58, 130, 23);
		panel8.add(ocupar8);
		
		JLabel lancha8 = new JLabel("8");
		lancha8.setHorizontalAlignment(SwingConstants.CENTER);
		lancha8.setBounds(30, 11, 80, 14);
		panel8.add(lancha8);
		
		JPanel panel9 = new JPanel();
		panel9.setLayout(null);
		panel9.setBounds(417, 301, 277, 92);
		contentPane.add(panel9);
		
		JLabel tres9 = new JLabel("");
		tres9.setHorizontalAlignment(SwingConstants.CENTER);
		tres9.setBounds(142, 11, 125, 14);
		panel9.add(tres9);
		
		JLabel tiempo9 = new JLabel("");
		tiempo9.setHorizontalAlignment(SwingConstants.CENTER);
		tiempo9.setBounds(142, 30, 125, 14);
		panel9.add(tiempo9);
		
		JLabel adultos9 = new JLabel("");
		adultos9.setBounds(142, 62, 69, 14);
		panel9.add(adultos9);
		
		JLabel ninos9 = new JLabel("");
		ninos9.setHorizontalAlignment(SwingConstants.RIGHT);
		ninos9.setBounds(198, 62, 69, 14);
		panel9.add(ninos9);
		
		JLabel estado9 = new JLabel("Disponible");
		estado9.setForeground(Color.GREEN);
		estado9.setBounds(30, 36, 60, 14);
		panel9.add(estado9);
		
		JButton ocupar9 = new JButton("Ocupar");
		ocupar9.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				if(l9==0)
				{
					l9=1;
					ocupar9.setText("Desocupar");
					estado9.setText("Ocupado");
					estado9.setForeground(Color.RED);
					OcuparLancha ocup1 = new OcuparLancha("9");
					ocup1.setVisible(true);
				}
				else
				{
					l9=0;
					ocupar9.setText("Ocupar");
					estado9.setText("Disponible");
					estado9.setForeground(Color.GREEN);
					DesocuparLancha desocup1 = new DesocuparLancha("9");
					desocup1.setVisible(true);
				}
			}
		});
		ocupar9.setBounds(10, 58, 130, 23);
		panel9.add(ocupar9);
		
		JLabel lancha9 = new JLabel("9");
		lancha9.setHorizontalAlignment(SwingConstants.CENTER);
		lancha9.setBounds(30, 11, 80, 14);
		panel9.add(lancha9);
		
		JPanel panel10 = new JPanel();
		panel10.setLayout(null);
		panel10.setBounds(417, 398, 277, 92);
		contentPane.add(panel10);
		
		JLabel tres10 = new JLabel("");
		tres10.setHorizontalAlignment(SwingConstants.CENTER);
		tres10.setBounds(142, 11, 125, 14);
		panel10.add(tres10);
		
		JLabel tiempo10 = new JLabel("");
		tiempo10.setHorizontalAlignment(SwingConstants.CENTER);
		tiempo10.setBounds(142, 30, 125, 14);
		panel10.add(tiempo10);
		
		JLabel adultos10 = new JLabel("");
		adultos10.setBounds(142, 62, 69, 14);
		panel10.add(adultos10);
		
		JLabel ninos10 = new JLabel("");
		ninos10.setHorizontalAlignment(SwingConstants.RIGHT);
		ninos10.setBounds(198, 62, 69, 14);
		panel10.add(ninos10);
		
		JLabel estado10 = new JLabel("Disponible");
		estado10.setForeground(Color.GREEN);
		estado10.setBounds(30, 36, 60, 14);
		
		JButton ocupar10 = new JButton("Ocupar");
		ocupar10.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				if(l10==0)
				{
					l10=1;
					ocupar10.setText("Desocupar");
					estado10.setText("Ocupado");
					estado10.setForeground(Color.RED);
					OcuparLancha ocup1 = new OcuparLancha("10");
					ocup1.setVisible(true);
				}
				else
				{
					l10=0;
					ocupar9.setText("Ocupar");
					estado9.setText("Disponible");
					estado9.setForeground(Color.GREEN);
					DesocuparLancha desocup1 = new DesocuparLancha("10");
					desocup1.setVisible(true);
				}
			}
		});
		ocupar10.setBounds(10, 58, 130, 23);
		panel10.add(ocupar10);
		panel10.add(estado10);
		
		JLabel lancha10 = new JLabel("10");
		lancha10.setHorizontalAlignment(SwingConstants.CENTER);
		lancha10.setBounds(30, 11, 80, 14);
		panel10.add(lancha10);
	}
}
