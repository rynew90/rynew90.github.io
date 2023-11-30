package TaskServiceTest;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.BeforeEach;

import com.TaskService.TaskService;

class TaskServiceTest {
	
	@BeforeEach
	void setUP() {
		TaskService.taskList.clear();
	}
	
	@Test
	@DisplayName("Tests getting and displaying Task Info")
	void TestDisplayTask() {
		TaskService.addTask("546897", "Create Report", "Generate report for budget management.");
		TaskService.displayTask("546897");
	}

	@Test
	@DisplayName("Tests adding Tasks")
	void testAddTask() {
		//Tests adding one task
		TaskService.addTask("546897", "Create Report", "Generate report for budget management.");
		Assertions.assertEquals(1, TaskService.taskList.size());
		
		//Tests adding multiple tasks
		TaskService.addTask("265742", "Complete Timesheet", "Review timesheets and submit timecards.");
		TaskService.addTask("398421", "Review Inventory", "Inventory stock and reorder needed items.");
		Assertions.assertEquals(3, TaskService.taskList.size());
		
		//Tests that task ID must be unique, PR == Purchase Requisition
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			TaskService.addTask("546897", "Generate PR", "Create Purchase Requisition for reorder items");
		});
	}
	
	@Test
	@DisplayName("Tests for deleting Tasks")
	void testDeleteTask() {
		TaskService.addTask("546897", "Create Report", "Generate report for budget management.");
		TaskService.addTask("265742", "Complete Timesheet", "Review timesheets and submit timecards.");
		
		TaskService.deleteTask("265742");
		Assertions.assertEquals(1, TaskService.taskList.size());
	}
	
	@Test
	@DisplayName("Tests for modifying a Task")
	void testModifyTask() {
		TaskService.addTask("546897", "Create Report", "Generate report for budget management.");
		
		TaskService.modifyTask("1", "Contact Customer");
		Assertions.assertEquals("Contact Customer", TaskService.taskList.get(0).getTaskName());
		
		TaskService.modifyTask("2", "Contact customer for clarification on product ordered");
		Assertions.assertEquals("Contact customer for clarification on product ordered", TaskService.taskList.get(0).getTaskDescription());
	}

}
