package samplePrograms;
import javax.swing.*;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;



public class studentss extends JFrame implements ActionListener {
	JLabel label1;
	JButton bt;
	JTextField tf;
	ArrayList<String> al = new ArrayList<String>();
	public studentss() {
		super("Student Detail");
		label1 = new JLabel("Name");
		tf = new JTextField(20);
		bt = new JButton("Submit");
		bt.setActionCommand("Button1");
		Container c=getContentPane();
		c.setLayout(new FlowLayout());
		c.add(label1);
		c.add(tf);
		c.add(bt);
		bt.addActionListener(this);
				
		setSize(250,250);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}

	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getActionCommand().equals("Button1"))
		{
			al.add(tf.getText());
		}
	}
	public static void main(String[] args) {
		studentss s = new studentss();
	}	

}
