# 📚 Study Management Application (SIMS)

A Qt-based desktop application developed in the 2nd semester to help students organize their study materials, manage class schedules, keep track of assignments and exams, and access essential academic resources from a unified platform.

---

## 🛠️ Technologies Used

* **Frontend/UI:** Qt (Qt Designer + C++)
* **Backend Logic:** C
* **Password Security:** Custom implementation of SHA-256

---

## ✨ Features

### 🏠 Home Page

* Greets the user by name.
* Displays **today’s class schedule**.
* Shows **upcoming exams and assignments** for the **next 7 days**.
* Includes a **button to add new study resources** quickly.

---

### 📁 Study Materials Organizer

* Materials are grouped under **course blocks** (e.g., `CSE 4402`, `CSE 4341`, `EEE 5569`).
* Clicking a block opens a submenu with categories:

  * **Books**
  * **Notes**
  * **Exam Papers**
* Each category stores relevant resources for the selected course.

---

### 🗓️ Routine Setup

* Students can **create and update** their class routine.
* Designed to reflect each day’s schedule in the home dashboard.

---

### 📆 Upcoming Events Tracker

* Students can add:

  * **Assignments**
  * **Exams**
* Automatically calculates and displays **days remaining**.
* Reminders for all events happening **within 7 days** are visible on the homepage.

---

### ☁️ Web & Cloud Access

* Access **Google Drive** directly from within the app.
* Provides shortcuts to **vital academic web resources** (e.g., LMS, university portals).

---

### 🔒 Security

* Password protection at startup.
* Secure hashing via a **custom SHA-256 implementation** ensures stored credentials remain encrypted.

---

## 📸 UI Preview



  
---

## 🚀 Getting Started

1. **Clone the repository**
2. Open the project in **Qt Creator**.
3. Make sure C and C++ compilers are configured.
4. Build and run.

---

## 📌 Notes

* The app was created during the **2nd semester** as a personal academic project.
* Although C++ is used for UI interaction with Qt, **all backend logic is written in C** as this was the prerequisite of the course. 

---
