package com.TaskService;

public class Task {
	private String taskId;
	private String taskName;
	private String taskDescription;
	
	public Task (String taskId, String taskName, String taskDescription) {
		if (taskId == null || taskId.length() > 10) {
			throw new IllegalArgumentException("Invalid task ID.");
		}
		
		if (taskName == null || taskName.length() > 20) {
			throw new IllegalArgumentException("Invalid task name.");
		}
		
		if (taskDescription == null || taskDescription.length() > 50) {
			throw new IllegalArgumentException("Invalid task description.");
		}
		
		this.taskId = taskId;
		this.taskName = taskName;
		this.taskDescription = taskDescription;
	}
	
	public String getTaskId() {
		return taskId;
	}
	
	public String getTaskName() {
		return taskName;
	}
	
	public void setTaskName(String taskName) {
		this.taskName = taskName;
	}
	
	public String getTaskDescription() {
		return taskDescription;
	}
	
	public void setTaskDescription(String taskDescription) {
		this.taskDescription = taskDescription;
	}

}
