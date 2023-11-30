package TaskServiceTest;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import com.TaskService.Task;

class TaskTest {

	@Test
	void testTask() {
		Task task = new Task("546897", "Create Report", "Generate report for budget management.");
		
		assertTrue(task.getTaskId().equals("546897"));
		assertTrue(task.getTaskName().equals("Create Report"));
		assertTrue(task.getTaskDescription().equals("Generate report for budget management."));
	}
	
	@Test
	@DisplayName ("Tests for Task ID")
	void TestTaskIdTooLong() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task("01234567890", "Create Report", "Generate report for budget management.");
			});
	}
	
	@Test
	void TestTaskIdNull() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task(null, "Create Report", "Generate report for budget management.");
			});
	}
	
	@Test
	@DisplayName ("Tests for Task Name")
	void TestTaskNameTooLong() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task("546897", "Create Monthly Budget Report", "Generate report for budget management.");
			});
	}
	
	@Test
	void TestTaskNameNull() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task("546897", null, "Generate report for budget management.");
			});
	}
	
	@Test
	@DisplayName ("Tests for Task Description")
	void TestTaskDescriptionTooLong() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task("546897", "Create Report", "Generate a monthly budget report and submit to budget management spreadsheet.");
			});
	}
	
	@Test
	void TestTaskDescriptionNull() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task("546897", "Create Report", null);
			});
	}

}
