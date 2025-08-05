#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

struct Product {
    int id;
    char name[30];
    int quantity;
    float discount;
    float price;
};

Product inventory[MAX];
int product_count = 0;

// Load inventory from file
void loadInventory() {
    ifstream in("inventory.txt");
    if (!in) return;
    while (in >> inventory[product_count].id >> inventory[product_count].name
              >> inventory[product_count].quantity >> inventory[product_count].discount
              >> inventory[product_count].price) {
        product_count++;
    }
    in.close();
}

// Save inventory to file (overwrite)
void saveInventory() {
    ofstream out("inventory.txt");
    for (int i = 0; i < product_count; i++) {
        out << inventory[i].id << ' ' << inventory[i].name << ' '
            << inventory[i].quantity << ' ' << inventory[i].discount << ' '
            << inventory[i].price << endl;
    }
    out.close();
}

// Add new product
void addProduct() {
    if (product_count >= MAX) {
        cout << "Inventory full!\n";
        return;
    }

    cout << "Enter Product ID: ";
    cin >> inventory[product_count].id;
    cout << "Enter Product name (no spaces): ";
    cin >> inventory[product_count].name;
    cout << "Enter Quantity: ";
    cin >> inventory[product_count].quantity;
    cout << "Enter Discount (%): ";
    cin >> inventory[product_count].discount;
    cout << "Enter Price: ";
    cin >> inventory[product_count].price;

    product_count++;
    cout << "Product added!\n";
}

// View all products
void viewProducts() {
    cout << "\n--- Inventory Report ---\n";
    if (product_count == 0) {
        cout << "No products in inventory.\n";
        return;
    }

    for (int i = 0; i < product_count; i++) {
        cout << "ID: " << inventory[i].id
             << ", Name: " << inventory[i].name
             << ", Qty: " << inventory[i].quantity
             << ", Discount: " << inventory[i].discount << "%"
             << ", Price: " << inventory[i].price << endl;
    }
}

int main() {
    loadInventory();
    int choice;

    do {
        cout << "\n=== INVENTORY MANAGEMENT SYSTEM ===\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Save & Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) {
            addProduct();
        }
        else if (choice == 2) {
            viewProducts();
        }
        else if (choice == 3) {
            saveInventory();
            cout << "Inventory saved. Exiting...\n";
        }
        else {
            cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}

