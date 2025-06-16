# include <iostream>
# include <fstream>
using namespace std;

const int MAX = 100;

struct Product {
    int Product_id;
    char Product_name[50];
    int Quantity;
    float Discount;
    float Price;
};

Product inventory[MAX];
int Prod_count= 0;

// Loading inventory.txt file
void loadInventory() {
    ifstream in("inventory.txt");
    while (in >> inventory[Prod_count].Product_id 
              >> inventory[Prod_count].Product_name
              >> inventory[Prod_count].Quantity 
              >> inventory[Prod_count].Discount 
              >> inventory[Prod_count].Price) {
        Prod_count++;
    }
    in.close();
}

// Save inventory to file
void saveInventory() {
    ofstream out("inventory.txt", ios::app);
    for (int i = 0; i < Prod_count; i++) {
        out << inventory[i].Product_id << " "
            << inventory[i].Product_name << " "
            << inventory[i].Quantity << " "
            << inventory[i].Discount << " "
            << inventory[i].Discount << endl;
    }
    out.close();
}

// Add product
void addProduct() {
    
    int id;
    cout << "Enter Product ID: ";
    cin >> id;
    bool exist = false;

    // TO check that Product_id is always unique
    for(int i = 0; i < Prod_count; i++){
        if(inventory[i].Product_id == id){
            exist = true;
            break;
        }
    }
    if(exist){
        cout << "Product id already exist. Please enter a unique id!" << endl;
        return;
    }

    //Assigning the values
    inventory[Prod_count].Product_id = id;
    cout << "Enter Product Name: ";
    cin >> inventory[Prod_count].Product_name;
    cout << "Enter Quantity: ";
    cin >> inventory[Prod_count].Quantity;
    cout << "Enter Discount: ";
    cin >> inventory[Prod_count].Discount;
    cout << "Enter Price: ";
    cin >> inventory[Prod_count].Price;
    Prod_count++;
    cout << "Product added.\n";
}

// View all products
void viewProducts() {
    cout << "\n Inventory Report \n";
    for (int i = 0; i < Prod_count; i++) {
        cout << "ID: " << inventory[i].Product_id
            << ", Name: " << inventory[i].Product_name
            << ", Quantity: " << inventory[i].Quantity
            << ", Discount: " << inventory[i].Discount
            << ", Price: " << inventory[i].Price << endl;
    }
}

int main() {
    loadInventory();
    int choice;
    do {
        cout << "\nInventory Menu:\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1) addProduct();
        else if (choice == 2) viewProducts();
        else if (choice == 3) {
            saveInventory();
            cout << "Inventory saved. Exiting...\n";
        }
        else cout << "Invalid choice.\n";
    } while (choice != 3);

    return 0;
}
