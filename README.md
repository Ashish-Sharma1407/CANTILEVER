# CANTILEVER
📁 Repository for all daily tasks and assignments completed during my internship at Cantilever.

# Task 1:
# 🎯 Number Guessing Game in C++

This is a simple console-based number guessing game built using C++. It generates a random number between 0 and 99 and lets the user guess it. After every guess, it gives a hint (too high / too low) and records the total number of attempts taken.

## 📄 Features
- Random number generation
- Interactive hints (too low / too high)
- Keeps track of number of attempts
- Uses file handling to store results in `numberGuessingGame.txt`

## 🛠️ How It Works
- The program uses `rand()` seeded by the current time to generate a number
- The user is prompted to guess until they get the correct number
- Upon correct guess, result is stored in a file for future record

## 🧪 Sample Output
Welcome to the Number Guessing Game!  

I have selected a number between 0 to 99. Try to guess it!  
Enter your number:  
50  
Too low! Try again  
Enter your number:  
75  
Too high! Try again  
Enter your number:  
62  
🎉 Congratulations! You guessed the number in 3 attempts.  


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



