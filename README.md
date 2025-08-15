# 🏥 Hospital Management System in C++

**Author:** Fairuz Faiyaz  

### 🔧 Technologies
- **Language**: C++
- **Compiler**: Any standard C++ compiler (GCC, MSVC, or Clang)

### Standard Libraries: 
- **iostream**
- **stack**
- **string**
---

## 📌 Project Overview

This is a comprehensive **Hospital Management System** implemented in C++ using fundamental **data structures**:

- **Doubly Linked List** for managing patient records.
- **Stack** for undo operations.
- **Binary Search Tree (BST)** for doctor allocation.
- **Graph (Adjacency List)** for hospital department mapping.
- **Infix-to-Postfix conversion and evaluation** for billing calculations.

The project demonstrates practical applications of data structures in healthcare management.

---

## 🛠 Features

### 1. Patient Management (Doubly Linked List + Stack)
- Add new patients with **name, age, priority level, and arrival time**.
- Remove a patient by **name**.
- Display all patients in forward order.
- **Undo functionality** using stack: removes last added patient from both stack and list.

### 2. Doctor Allocation (Binary Search Tree)
- Add doctors with **ID, name, and specialization**.
- Search doctors by **ID**.
- Display doctors in **sorted order** using in-order traversal.

### 3. Hospital Department Map (Graph)
- Map hospital departments using **adjacency lists**.
- Add connections between departments.
- Display all department connections clearly.

### 4. Billing System
- Input **arithmetic expressions** in infix form.
- Convert infix to **postfix** expressions.
- Evaluate the expression to calculate the **final bill**.

---

## 💻 Example Usage

```cpp
PatientManager PatientManagement;

// Adding patients
PatientManagement.addPatient("Fairuz", 20, "High", "10:17 AM");
PatientManagement.addPatient("Faiyaz", 22, "Low", "8:41 PM");

// Removing patients
PatientManagement.removePatientByName("Fairuz");

// Undo last patient entry
PatientManagement.undoLastPatientEntry();

// Display patients
PatientManagement.displayPatientDetail();
