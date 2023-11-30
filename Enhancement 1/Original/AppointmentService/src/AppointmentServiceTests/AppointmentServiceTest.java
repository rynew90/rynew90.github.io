package AppointmentServiceTests;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import AppointmentService.AppointmentService;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

class AppointmentServiceTest {
	
	SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy", Locale.ENGLISH);
	Date date;
	
	@BeforeEach
	void setUp() throws ParseException {
		AppointmentService.appointmentList.clear();		
	}

	@Test
	@DisplayName("Test for Displaying Appointment")
	void testDisplayAppointment() throws ParseException {
		date = format.parse("16/08/2023");
		AppointmentService.addAppointment("8675309", date, "Birthday Party");
		AppointmentService.displayAppointment("8675309");
	}
	
	@Test
	@DisplayName("Tests for Adding New Appointment")
	void testAddAppointment() throws ParseException {
		//Test adding one appointment
		date = format.parse("16/08/2023");
		AppointmentService.addAppointment("8675309", date, "Birthday Party");
		Assertions.assertEquals(1, AppointmentService.appointmentList.size());
		
		//Test adding multiple appointments
		date = format.parse("03/05/2023");
		AppointmentService.addAppointment("946327", date, "Attend Wedding");
		date = format.parse("22/12/2023");
		AppointmentService.addAppointment("4656231", date, "Office Christmas Party");
		Assertions.assertEquals(3,  AppointmentService.appointmentList.size());
		
		//Test that AppointmentId is unique
		date = format.parse("20/06/2023");
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			AppointmentService.addAppointment("8675309", date, "Attend Music Concert");
		});
	}
	
	@Test
	@DisplayName("Tests that Appointment is deleted")
	void testDeleteAppointment() throws ParseException {
		date = format.parse("16/08/2023");
		AppointmentService.addAppointment("8675309", date, "Birthday Party");
		date = format.parse("03/05/2023");
		AppointmentService.addAppointment("4656231", date, "Attend Wedding");
		
		AppointmentService.deleteAppointment("8675309");
		Assertions.assertEquals(1, AppointmentService.appointmentList.size());
	}

}
