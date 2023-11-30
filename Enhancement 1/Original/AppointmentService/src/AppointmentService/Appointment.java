package AppointmentService;

import java.util.Date;
import java.text.ParseException;

public class Appointment {
	private String appointmentId;
	private Date appointmentDate;
	private String appointmentDesc;
	
	public Appointment (String appointmentId, Date appointmentDate, String appointmentDesc) throws ParseException {
		if (appointmentId == null || appointmentId.length() > 10) {
			throw new IllegalArgumentException("Invalid appointment ID.");
		}
		
		if (appointmentDate == null || appointmentDate.before(new Date())) {
			throw new IllegalArgumentException("Invalid appointment Date.");
		}
		
		if (appointmentDesc == null || appointmentDesc.length() > 50) {
			throw new IllegalArgumentException("Invalid appointment description.");
		}
		
		this.appointmentId = appointmentId;
		this.appointmentDate = appointmentDate;
		this.appointmentDesc = appointmentDesc;
	}
	
	public String getAppointmentId() {
		return appointmentId;
	}
	
	public Date getAppointmentDate() {
		return appointmentDate;
	}
	
	public void setAppointmentDate(Date appointmentDate) {
		this.appointmentDate = appointmentDate;
	}
	
	public String getAppointmentDesc() {
		return appointmentDesc;
	}
	
	public void setAppointmentDesc(String appointmentDesc) {
		this.appointmentDesc = appointmentDesc;
	}

}
