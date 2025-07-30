# CANTILEVER
📁 Repository for all daily tasks and assignments completed during my internship at Cantilever.

# Task 1:
# 🎯 Number Guessing Game in C++

📋 Project Overview
This project implements a console-based two-digit number guessing game in C++. The game generates a random number between 01-99 (including single digits with leading zeros), and the player must guess it within a limited number of attempts. The project includes both traditional and modern C++ implementations.

🎯 Features
Core Gameplay
1. Random two-digit number generation (01-99 range)
2. 7 attempts to guess the correct number
3. Directional hints (higher/lower) after each guess
4. Score system with point deduction for wrong guesses
5. Input validation and error handling
6. Multiple rounds support
7. Game statistics tracking
8. NEW: Leading zero display for single digits (01, 02, 03...)

Enhanced Features
1. Proximity hints (very close, warm, cold)
2. Time tracking for each game
3. Performance rating system
4. Enhanced visual feedback with emojis
5. Exception handling  


# Task 2:
# 📦 Inventory Management System in C++

This is a basic console-based Inventory Management System built using C++. It allows users to manage a list of products by adding new items, viewing the current inventory, and saving the data to a text file using file handling.  

---  

## 📌 Features  

- Add new products (ID, name, quantity, discount, price)  
- View all product records in a formatted report  
- File handling using `inventory.txt` to save/load data  
- Uses static array and simple `struct` (no STL or classes)  

---  

## 📂 File Used  

- **inventory.txt**    
  Stores all product information in plain text format, one product per line:  
  101 Pen 50 0.1 10.5  
  102 Notebook 20 0.05 45.0

## 🧪 Sample Output  
Inventory Menu:  
1. Add Product  
2. View Products  
3. Save and Exit  
Enter your choice: 1  
Enter Product ID: 103  
Enter Product Name: Pencil  
Enter Quantity: 100  
Enter Discount: 0.05  
Enter Price: 5.0  
Product added.

## 📋 Sample Inventory Report  
-- Inventory Report --  
ID: 101, Name: Pen, Quantity: 50, Discount: 0.1, Price: 10.5  
ID: 102, Name: Notebook, Quantity: 20, Discount: 0.05, Price: 45.0  



