package AppointmentService;

import java.util.ArrayList;
import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Scanner;

public class AppointmentService {
	public static ArrayList<Appointment> appointmentList = new ArrayList<Appointment>();
	
	public static void displayAppointment(String appointmentId) {
		
		for (Appointment appointment : appointmentList) {
			if (appointment.getAppointmentId().equals(appointmentId)) {
				System.out.println(appointment.getAppointmentId());
				System.out.println(appointment.getAppointmentDate());
				System.out.println(appointment.getAppointmentDesc());
			}
		}
	}
	
	public static void addAppointment(String appointmentId, Date appointmentDate, String appointmentDesc) throws ParseException {
		
		for (Appointment appointment : appointmentList) {
			if (appointment.getAppointmentId().equals(appointmentId)) {
				throw new IllegalArgumentException ("Error: Appointment ID already in use.");
			}
		}
		
		Appointment appointment = new Appointment(appointmentId, appointmentDate, appointmentDesc);
		appointmentList.add(appointment);
	}
	
	public static void deleteAppointment(String appointmentId) {
		
		for (int i = 0; i < appointmentList.size(); i++) {
			if (appointmentList.get(i).getAppointmentId() == appointmentId) {
				appointmentList.remove(i);
				return;
			}
		}
	}
	
	public static void main(String[] args) throws ParseException {
		Scanner scnr = new Scanner(System.in);
		
		String appointmentId;
		Date appointmentDate;
		String appointmentDesc;
		
		SimpleDateFormat format = new SimpleDateFormat("DD/MM/YYYY");
		Date date;
		
		int choice = 0;
		while (choice != 9) {
			//Print Menu
			System.out.println("--Menu--");
			System.out.println("1: Display Appointment");
			System.out.println("2: Add New Appointment");
			System.out.println("3: Delete Appointment");
			System.out.println("9: Exit");
			System.out.print("Please select an option:");
			
			//Accept user input
			choice = scnr.nextInt();
			
			//Switch statement to handle user input
			switch (choice) {
			
			case 1:
				System.out.print("Enter Appointment ID: ");
				appointmentId = scnr.nextLine();
				
				displayAppointment(appointmentId);
				
				break;
			
			case 2:
				System.out.println("Enter New Appointment ID: ");
				appointmentId = scnr.nextLine();
				
				System.out.println("Enter Appointment Date (DD/MM/YYYY): ");
				String input = scnr.nextLine();
				date = format.parse(input);
				appointmentDate = date;
				
				System.out.println("Enter Appointment Description: ");
				appointmentDesc = scnr.nextLine();
				
				addAppointment(appointmentId, appointmentDate, appointmentDesc);
				
				break;
				
			case 3:
				System.out.print("Enter Appointment ID to delete: ");
				appointmentId = scnr.nextLine();
				
				deleteAppointment(appointmentId);
				
				break;
				
			case 9:
				System.out.println("Closing Appointment Service App...");
				
				break;
				
			default:
				System.out.println("Invalid Input Option.");
				
				break;
			}
			
			System.out.println();
			
			scnr.close();
		}
	}

}
