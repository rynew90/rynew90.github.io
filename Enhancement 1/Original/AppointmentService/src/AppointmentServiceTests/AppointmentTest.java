package AppointmentServiceTests;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import AppointmentService.Appointment;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

class AppointmentTest {

	@Test
	void testAppointment() throws ParseException {
		Date date = new SimpleDateFormat("dd/MM/yyyy").parse("16/08/2023");
		Appointment appointment = new Appointment("8675309", date, "Birthday Party");
		System.out.print(date);
		
		assertTrue(appointment.getAppointmentId().equals("8675309"));
		assertTrue(appointment.getAppointmentDate().equals(date));
		assertTrue(appointment.getAppointmentDesc().equals("Birthday Party"));
	}
	
	@Test
	@DisplayName("Tests for Appointment ID")
	void testAppointmentIdTooLong() throws ParseException {
		Date date = new SimpleDateFormat("dd/MM/yyyy").parse("16/08/2023");
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Appointment("68419735085", date, "Birthday Party");
		});
	}
	
	@Test
	void testAppointmentIdNull() throws ParseException {
		Date date = new SimpleDateFormat("dd/MM/yyyy").parse("16/08/2023");
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Appointment(null, date, "Birthday Party");
		});
	}
	
	@Test
	@DisplayName("Tests for Appointment Date")
	void testAppointmentDatePast() throws ParseException {
		Date date = new SimpleDateFormat("dd/MM/yyyy").parse("16/08/1990");
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Appointment("8675309", date, "Birthday Party");		
		});
	}
	
	@Test
	void testAppointmentDateNull() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Appointment("8675309", null, "Birthday Party");
		});
	}
	
	@Test
	@DisplayName("Tests for Appointment Description")
	void testAppointmentDescTooLong() throws ParseException {
		Date date = new SimpleDateFormat("dd/MM/yyyy").parse("16/08/2023");
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Appointment("8675309", date, "Go to Birthday Party, take gifts purchased for friend who is having a birthday.");
		});
	}
	
	@Test
	void testAppointmentDescNull() throws ParseException {
		Date date = new SimpleDateFormat("dd/MM/yyyy").parse("16/08/2023");
		Assertions.assertThrows(IllegalArgumentException.class, ()-> {
			new Appointment("8675309", date, null);
		});
	}

}
