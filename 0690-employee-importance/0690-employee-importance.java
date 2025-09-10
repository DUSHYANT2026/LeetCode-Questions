/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};
*/
class Solution {
    private Map<Integer, Employee> employeeMap;

    public int getImportance(List<Employee> employees, int targetEmployeeId) {
        employeeMap = new HashMap<>();
        for (Employee employee : employees) {
            employeeMap.put(employee.id, employee);
        }

        return calculateTotalImportance(targetEmployeeId);
    }

    private int calculateTotalImportance(int employeeId) {
        Employee employee = employeeMap.get(employeeId);
        
        int totalImportance = employee.importance;

        for (int subordinateId : employee.subordinates) {
            totalImportance += calculateTotalImportance(subordinateId);
        }

        return totalImportance;
    }
}