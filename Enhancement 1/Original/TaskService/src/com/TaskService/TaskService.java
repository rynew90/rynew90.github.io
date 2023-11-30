package com.TaskService;

import java.util.*;

public class TaskService {
	public static ArrayList<Task> taskList = new ArrayList<Task>();
	
	public static void displayTask(String taskId) {
		
		for (Task task : taskList) {
			if (task.getTaskId().equals(taskId)) {
				System.out.println(task.getTaskId());
				System.out.println(task.getTaskName());
				System.out.println(task.getTaskDescription());
			}
		}
	}
	
	public static void addTask(String taskId, String taskName, String taskDesc) {
		
		for (Task task : taskList) {
			if (task.getTaskId().equals(taskId)) {
				throw new IllegalArgumentException ("Error: Task ID already in use.");
			}
		}
		
		Task task = new Task(taskId, taskName, taskDesc);
		taskList.add(task);
	}
	
	public static void deleteTask(String taskId) {
		
		for (int i = 0; i < taskList.size(); i++) {
			if (taskList.get(i).getTaskId() == taskId) {
				taskList.remove(i);
				return;
			}
		}
	}
	
	public static void modifyTask(String item, String input) {
		
		for (Task task : taskList) {
			if (item == "1") {
				task.setTaskName(input);
			}
			else if (item == "2") {
				task.setTaskDescription(input);
			}
			else {
				System.out.println("Invalid Input");
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner scnr = new Scanner(System.in);
		
		String taskId;
		String taskName;
		String taskDesc;
		
		int choice = 0;
		while (choice != 9) {
			//Print Menu
			System.out.println("--Menu--");
			System.out.println("1: Display Task");
			System.out.println("2: Add New Task");
			System.out.println("3: Delete Task");
			System.out.println("4: Update Task Info");
			System.out.println("9: Exit");
			System.out.print("Please select an option:");
			
			//Accept user input
			choice = scnr.nextInt();
			
			//Switch statement to handle user input
			switch (choice) {
			
			case 1:
				System.out.print("Enter Task ID: ");
				taskId = scnr.nextLine();
				
				displayTask(taskId);
				
				break;
			
			case 2:
				System.out.print("Enter New Task ID: ");
				taskId = scnr.nextLine();
				
				System.out.print("Enter Task Name: ");
				taskName = scnr.nextLine();
				
				System.out.print("Enter Task Description: ");
				taskDesc = scnr.nextLine();
				
				addTask(taskId, taskName, taskDesc);
				
				break;
				
			case 3:
				System.out.print("Enter task ID to delete: ");
				taskId = scnr.nextLine();
				
				deleteTask(taskId);
				
				break;
				
			case 4:
				System.out.print("Enter Task ID to modify: ");
				taskId = scnr.nextLine();
				
				for (Task task : taskList) {
					if (task.getTaskId().equals(taskId)) {
						System.out.println("--Enter Item to Update--");
						System.out.println("1. Task Name");
						System.out.println("2. Task Description");
						String item = scnr.nextLine();
						String input;
						
						if (item.equals("1")) {
							System.out.print("Enter new task name: ");
							input = scnr.nextLine();
							modifyTask(item, input);
						}
						
						else if (item.equals("2")) {
							System.out.print("Enter new task description: ");
							input = scnr.nextLine();
							modifyTask(item, input);
						}
					}
					
				}
				
				break;
				
			case 9:
				System.out.println("Closing Task Service App...");
				
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
