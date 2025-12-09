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