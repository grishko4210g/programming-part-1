# Lab 09 — Structs in C
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Arina Hryshko   
**Date:** November 27, 2025    
**Variant:** 11(eleven)  
 
---
 
## Task Description
 
**Retail Inventory Management**
  - Structs: Store, Product, Supplier
  - Fields: Store contains Product with details from Supplier.
  - Functions:
  1. addSupplier(Store*, Supplier): Adds a supplier to the store.
  2. addProduct(Store*, Product): Addsa product from a supplier.
  3. listProductsBySupplier(Store*, Supplier*): Lists products from a supplier.


## Structure
 
```
lab09/
├── main.c         # Main application file
└── Report.md      # Project documentation
```
 
## Lab Instructions
 
1. Define a primary struct that contains one or more structs as its fields.
2. Write functions to add, modify, delete and display data in these structs.
3. Implement error ha
 ndling where appropriat, such as checking for invalid input or ensuring array.
4. Test each function to ensure it operates correctly.


### How to Build main.c 
 
 
```bash
#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIER 10
#define MAX_PRODUCTS 120
#define MAX_NAME_LENGTH 30
#define MAX_PROD_NAME_LENGTH 70

// supplier
typedef struct {
    char name[MAX_NAME_LENGTH];
} Supplier;

// product
typedef struct {
    char name[MAX_PROD_NAME_LENGTH];
    float price;
    int stock;
    char supplier_name[MAX_NAME_LENGTH];
} Product;

// store
typedef struct {
    char name[MAX_NAME_LENGTH];
    Product products[MAX_PRODUCTS];
    int product_count;
    Supplier suppliers[MAX_SUPPLIER];
    int supplier_count;
} Store;

// Checking
int supplierCheck(const Store *store, const char *name) {
    for (int i = 0; i < store->supplier_count; i++) {
        if (strcmp(store->suppliers[i].name, name) == 0)
            return i;
    }
    return -1;
}

// initStore
void initStore(Store *store, const char *name) {
    strncpy(store->name, name, MAX_NAME_LENGTH);
    store->name[MAX_NAME_LENGTH - 1] = '\0';
    store->product_count = 0;
    store->supplier_count = 0;
}

// addSupplier
void addSupplier(Store *store, const char *name) {
    if (store->supplier_count >= MAX_SUPPLIER) {
        printf("Unable to add supplier: maximum reached!\n");
        return;
    }
    if (supplierCheck(store, name) == -1) {
        strncpy(store->suppliers[store->supplier_count].name, name, MAX_NAME_LENGTH);
        store->suppliers[store->supplier_count].name[MAX_NAME_LENGTH - 1] = '\0';
        store->supplier_count++;
        printf("Supplier attached. %s \n", name);
    }
}

// addProduct
void addProduct(Store *store, const char *name, float price, int stock, const char *supplier_name) {
    if (store->product_count >= MAX_PRODUCTS) {
        printf("The warehouse's full!\n");
        return;
    }

    // adding a Supplier that isn't available
    addSupplier(store, supplier_name);

    Product *product = &store->products[store->product_count++];
    strncpy(product->name, name, MAX_PROD_NAME_LENGTH);
    product->name[MAX_PROD_NAME_LENGTH - 1] = '\0';
    
    strncpy(product->supplier_name, supplier_name, MAX_NAME_LENGTH);
    product->supplier_name[MAX_NAME_LENGTH - 1] = '\0';
    
    product->price = price;
    product->stock = stock;
    printf("Product attached. %s \n", name);
}

// Store inventory
void displayInventory(const Store *store) {
    printf("Store inventory: %s \n", store->name);
    if (store->product_count == 0) {
        printf("The warehouse is empty.\n");
        return;
    }
    for (int i = 0; i < store->product_count; i++) {
        printf("%d. %s (Supplier: %s) - Price: %.2f UAH, Number: %d piece\n",
               i + 1,
               store->products[i].name,
               store->products[i].supplier_name,
               store->products[i].price,
               store->products[i].stock);
    }
}

// Calculate. Inventory
float calculateTotalValue(const Store *store) {
    float total = 0.0f;
    for (int i = 0; i < store->product_count; i++)
        total += store->products[i].price * store->products[i].stock;
    return total;
}

// Find Product
int findProduct(const Store *store, const char *name) {
    for (int i = 0; i < store->product_count; i++) {
        if (strcmp(store->products[i].name, name) == 0)
            return i;
    }
    return -1;
}

void modifyProduct(Store *store, const char *name, float newPrice, int newStock) {
    int idx = findProduct(store, name);
    if (idx == -1) {
        printf("Product  not found. %s \n", name);
        return;
    }
    store->products[idx].price = newPrice;
    store->products[idx].stock = newStock;
    printf("Product updated. %s \n", name);
}

void deleteProduct(Store *store, const char *name) {
    int idx = findProduct(store, name);
    if (idx == -1) {
        printf("Product not found.%s \n", name);
        return;
    }
    for (int i = idx; i < store->product_count - 1; i++)
        store->products[i] = store->products[i + 1];
    store->product_count--;
    printf("Product deleted. %s \n", name);
}

// main
int main() {
    Store retail_store;
    initStore(&retail_store, "Minimum inventory system");
    
    addProduct(&retail_store, "Banana", 24.99, 10, "Home");
    addProduct(&retail_store, "Decorative balls", 325.50, 20, "Home");
    addProduct(&retail_store, "Water bottle", 17.67, 70, "Home");
    addProduct(&retail_store, "Phone", 14499.99, 2, "Tech");


    displayInventory(&retail_store);

    printf("Total cost of inventory: %.2f UAH \n", calculateTotalValue(&retail_store));

    modifyProduct(&retail_store, "Decorative balls", 230.25, 30);
    deleteProduct(&retail_store, "Phone");

    displayInventory(&retail_store);
    printf("Total cost of inventory after changes: %.2f UAH\n", calculateTotalValue(&retail_store));

    return 0;
}

```
 
### How to Run Tests
 
 
```bash
gcc -o file09  main.c
./file09
```

 ### Test Results
 
```bash
./file09
Supplier attached. Home 
Product attached. Banana 
Product attached. Decorative balls 
Product attached. Water bottle 
Supplier attached. Tech 
Product attached. Phone 
Store inventory: Minimum inventory system 
1. Banana (Supplier: Home) - Price: 24.99 UAH, Number: 10 piece
2. Decorative balls (Supplier: Home) - Price: 325.50 UAH, Number: 20 piece
3. Water bottle (Supplier: Home) - Price: 17.67 UAH, Number: 70 piece
4. Phone (Supplier: Tech) - Price: 14499.99 UAH, Number: 2 piece
Total cost of inventory: 36996.78 UAH 
Product updated. Decorative balls 
Product deleted. Phone 
Store inventory: Minimum inventory system 
1. Banana (Supplier: Home) - Price: 24.99 UAH, Number: 10 piece
2. Decorative balls (Supplier: Home) - Price: 230.25 UAH, Number: 30 piece
3. Water bottle (Supplier: Home) - Price: 17.67 UAH, Number: 70 piece
Total cost of inventory after changes: 8394.30 UAH

```
**Next Example:**

```bash
./file09
Supplier attached. Home 
Product attached. Banana 
Product attached. Decorative balls 
Product attached. Water bottle 
Supplier attached. Tech 
Product attached. Phone 
Store inventory: Minimum inventory system 
1. Banana (Supplier: Home) - Price: 24.99 UAH, Number: 10 piece
2. Decorative balls (Supplier: Home) - Price: 325.50 UAH, Number: 20 piece
3. Water bottle (Supplier: Home) - Price: 17.67 UAH, Number: 70 piece
4. Phone (Supplier: Tech) - Price: 14499.99 UAH, Number: 2 piece
Total cost of inventory: 36996.78 UAH 
Product updated. Decorative balls 
Product deleted. Water bottle 
Store inventory: Minimum inventory system 
1. Banana (Supplier: Home) - Price: 24.99 UAH, Number: 10 piece
2. Decorative balls (Supplier: Home) - Price: 230.25 UAH, Number: 30 piece
3. Phone (Supplier: Tech) - Price: 14499.99 UAH, Number: 2 piece
Total cost of inventory after changes: 36157.38 UAH
```

---

## Report
 
The goal of this lab is to practice working with structures in the C. In this laboratory work, I learnes how to: create and use nested structures; organize data using arrays of structures; implement fuctions for adding, modifying, searching and deleting elements; and simulate a simple inventory management system.
 
In this lab, I completed the following tasks:
1. Implemented three structures: Supplier(store supplier information); Product(store product details); Store(contains information about the store, supplier and product);
2. Created functions to: initialize the store; check for existing suppliers; add new suppliers; add products to the store; display the inventory; calculate the total inventory value; find a product by name; modify product data(price and peice); delete a product from the list.
3. Wrote and tested the "main()" function that demonstrates system functionality.

---
 
### Observations and Conclusion
 
During this lab, I learned how to build a simple but functional inventory system using structures.
I practiced working with: arrays of structures; string operations (strcmp, strncpy); passing structures to functions; searching and modifying elements in structured data.

So, structures in C allow grouping related information together, making programs more organized, readable, and scalable. This lab improved my understanding of data organization and functional programming in C.
 
---