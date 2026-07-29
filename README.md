University Event Management System
Project Description

The University Event Management System is a C programming project developed to manage university events efficiently.

Features
Student Registration
Student Login
View Events
Event Registration
Payment Module
Coordinator Panel
Admin Panel
Reports
Project Structure

The project is modularized into separate header (.h) and source (.c) files, one set per team member's contribution, all linked together through main.c.

University Event Management System/
├── common.h        # Shared Student struct
├── student.h        
├── student.c        # Md Tahmid Uddin's module
├── event.h
├── event.c          # Marzia Fardous's module
├── panel.h
├── panel.c          # Omor Faruk Shariar's module
├── main.c           # Main menu & program entry point
├── student.txt
├── registration.txt
└── payment.txt
Team Members & Contributions

1. Md Tahmid Uddin

ID: 252-35-228 Files: student.h, student.c, main.c

Contribution

Main Menu
Student Registration
Student Login
Login Algorithm (MD5 Hashing)
Student File Management (Search / Update / Delete Student)

2. Marzia Fardous

ID: 252-35-198 Files: event.h, event.c

Contribution

View Events
Event Registration
Payment Module
Running Student Discount
Alumni Discount
Department Discount
Club Event Free Payment
Central Event Free Payment
Search Registration
Search Payment

3. Omor Faruk Shariar

ID: 252-35-381 Files: panel.h, panel.c

Contribution

Coordinator Panel
Admin Panel
Dashboard
Reports
Programming Language
C
IDE
Visual Studio Code
Compiler
GCC (MinGW)
How to Compile & Run
bash

gcc main.c student.c event.c panel.c
.\main.exe

Data Files
student.txt — stores registered student records
registration.txt — stores event registration records
payment.txt — stores payment records
