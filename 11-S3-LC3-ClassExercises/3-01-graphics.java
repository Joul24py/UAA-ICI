import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JLabel;
import javax.swing.JCheckBox;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.awt.event.ActionEvent;
import javax.swing.JTextArea;
import javax.swing.JTable;
import javax.swing.border.LineBorder;
import java.awt.Color;

public class TrabajoFinal
{

	private JFrame frame;
	private JTextField txt1;
	private JTextField txt2;
	private JTextField txt3;
	private JTextField txt4;
	private JTable table1;
	String [] dato = new String [5];

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
					TrabajoFinal window = new TrabajoFinal();
					window.frame.setVisible(true);
				}
				catch (Exception e)
				{
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public TrabajoFinal()
	{
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize()
	{
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 490);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JComboBox CBox1 = new JComboBox();
		CBox1.setModel(new DefaultComboBoxModel(new String[] {"Selecciona un tipo de gr\u00E1fica", "Circular", "Barras", "XY", "Lineas"}));
		CBox1.setBounds(110, 11, 210, 20);
		frame.getContentPane().add(CBox1);
		
		JLabel lbl1 = new JLabel("Sexo:");
		lbl1.setBounds(10, 39, 72, 14);
		frame.getContentPane().add(lbl1);
		
		JCheckBox chck1 = new JCheckBox("Todos");
		chck1.setBounds(10, 60, 79, 23);
		frame.getContentPane().add(chck1);
		
		JCheckBox chck2 = new JCheckBox("Mujer");
		chck2.setBounds(91, 60, 79, 23);
		frame.getContentPane().add(chck2);
		
		JCheckBox chck3 = new JCheckBox("Hombre");
		chck3.setBounds(172, 60, 89, 23);
		frame.getContentPane().add(chck3);
		
		JLabel lbl2 = new JLabel("Edad:");
		lbl2.setBounds(10, 90, 72, 14);
		frame.getContentPane().add(lbl2);
		
		JCheckBox chck4 = new JCheckBox("Todos");
		chck4.setBounds(10, 110, 97, 23);
		frame.getContentPane().add(chck4);
		
		JLabel lbl3 = new JLabel("O rango de ");
		lbl3.setBounds(116, 114, 72, 14);
		frame.getContentPane().add(lbl3);
		
		txt1 = new JTextField();
		txt1.setBounds(198, 111, 44, 20);
		frame.getContentPane().add(txt1);
		txt1.setColumns(10);
		
		JLabel lbl4 = new JLabel("a");
		lbl4.setBounds(248, 114, 24, 14);
		frame.getContentPane().add(lbl4);
		
		txt2 = new JTextField();
		txt2.setColumns(10);
		txt2.setBounds(276, 111, 44, 20);
		frame.getContentPane().add(txt2);
		
		JLabel lbl5 = new JLabel("Estado:");
		lbl5.setBounds(10, 140, 72, 14);
		frame.getContentPane().add(lbl5);
		
		JCheckBox chck5 = new JCheckBox("Todos");
		chck5.setBounds(10, 161, 97, 23);
		frame.getContentPane().add(chck5);
		
		JLabel lbl6 = new JLabel("O rango de ");
		lbl6.setBounds(116, 165, 72, 14);
		frame.getContentPane().add(lbl6);
		
		txt3 = new JTextField();
		txt3.setColumns(10);
		txt3.setBounds(198, 162, 44, 20);
		frame.getContentPane().add(txt3);
		
		JLabel lbl7 = new JLabel("a");
		lbl7.setBounds(248, 165, 24, 14);
		frame.getContentPane().add(lbl7);
		
		txt4 = new JTextField();
		txt4.setColumns(10);
		txt4.setBounds(276, 162, 44, 20);
		frame.getContentPane().add(txt4);
		
		table1 = new JTable();
		table1.setFillsViewportHeight(true);
		table1.setModel(new DefaultTableModel(
			new Object[][] {
				{null, null, null, null, null},
			},
			new String[] {
				"ID", "Nombre", "Edad", "Sexo", "Estado"
			}
		));
		table1.setBorder(new LineBorder(new Color(0, 0, 0)));
		table1.setBounds(10, 438, 414, -234);
		table1.setVisible(true);
		frame.getContentPane().add(table1);
		
		JButton btn1 = new JButton("Graficar");
		btn1.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent arg0)
			{
				Connection con = null;
				//text6.setText(null);
				try
				{
					Class.forName("com.mysql.jdbc.Driver"); //Cargar las librerías del conector
					con = DriverManager.getConnection("jdbc:mysql://localhost:3306/leeinsertajava","root","");
					Statement stmt = con.createStatement();
					
					//Primera gráfica
					if(chck1.isSelected()==true)
					{
						ResultSet rs = stmt.executeQuery("SELECT * FROM `table 4`");
						DefaultTableModel modelo = new DefaultTableModel();
						/*modelo.addColumn("Id");
						modelo.addColumn("Nombre");
						modelo.addColumn("Edad");
						modelo.addColumn("Sexo");
						modelo.addColumn("Estado");*/
						while(rs.next())
						{
							dato [0] = rs.getString(1);
							dato [1] = rs.getString(2);
							dato [2] = rs.getString(3);
							dato [3] = rs.getString(4);
							dato [4] = rs.getString(5);
							modelo.addRow(dato);
							//txt5.append(rs.getInt(1) + " " + rs.getString(2) + " " + rs.getInt(3) + " " + rs.getString(4) + " " + rs.getString(5) + "\n");
						}
						table1.setModel(modelo);
						
						System.out.println("Hola");
						
						con.close();
					}
					else
					{
						if(chck2.isSelected()==true)
						{
							
						}
						else
						{
							if(chck3.isSelected()==true)
							{
								
							}
						}
					}
					/*
					//Segunda gráfica
					
					//String inser = "INSERT INTO proyectoabc(id,nombre) VALUES (" + text1.getText() + ",\"" + text2.getText() + "\");";
					//stmt.executeUpdate(inser);
					
					ResultSet rs = stmt.executeQuery("SELECT * FROM proyectoabc");
					while(rs.next())
					{
						//text6.append(rs.getInt(1) + " " + rs.getString(2) + "\n");
					}
					
					con.close();
					//text1.setText(null);
					//text2.setText(null);*/
				}
				catch(ClassNotFoundException e)
				{
					//text6.setText("Error al cargar el controlador");
					e.printStackTrace();
				}
				catch(SQLException e)
				{
					//text6.setText("Error en la conexión");
					e.printStackTrace();
				}
				
				
				//GraficaTFinal g1 = new GraficaTFinal(this,false);
				//g1.setVisible(true);
			}
		});
		btn1.setBounds(335, 60, 89, 23);
		frame.getContentPane().add(btn1);
		
		JButton btn2 = new JButton("Graficar");
		btn2.setBounds(335, 110, 89, 23);
		frame.getContentPane().add(btn2);
		
		JButton btn3 = new JButton("Graficar");
		btn3.setBounds(335, 161, 89, 23);
		frame.getContentPane().add(btn3);
	}
}
