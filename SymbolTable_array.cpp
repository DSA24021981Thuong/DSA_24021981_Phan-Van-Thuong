
#include <iostream>
#include <string>
using namespace std;

const int MAX_SYMBOLS = 100;

struct Symbol {
    string name;
    string type;
    string value;
};

struct SymbolTable {
    Symbol symbols[MAX_SYMBOLS];
    int count = 0;

    // Tim vi tri cua symbol
    int findIndex(const string& name) {
        for (int i = 0; i < count; i++) {
            if (symbols[i].name == name) {
                return i;
            }
        }
        return -1;
    }

    // Them symbol hoac cap nhat neu da ton tai
    void insert(const string& name, const string& type,
                const string& value) {
        int index = findIndex(name);

        if (index != -1) {
            symbols[index].type = type;
            symbols[index].value = value;
            return;
        }

        if (count == MAX_SYMBOLS) {
            cout << "Symbol Table is full!\n";
            return;
        }

        symbols[count].name = name;
        symbols[count].type = type;
        symbols[count].value = value;
        count++;
    }

    // Tim kiem symbol
    Symbol* search(const string& name) {
        int index = findIndex(name);

        if (index == -1) {
            return nullptr;
        }

        return &symbols[index];
    }

    // Xoa symbol
    bool remove(const string& name) {
        int index = findIndex(name);

        if (index == -1) {
            return false;
        }

        for (int i = index; i < count - 1; i++) {
            symbols[i] = symbols[i + 1];
        }

        count--;
        return true;
    }

    // Hien thi Symbol Table
    void display() {
        cout << "\n--- SYMBOL TABLE ---\n";
        cout << "Name\tType\tValue\n";

        for (int i = 0; i < count; i++) {
            cout << symbols[i].name << "\t"
                 << symbols[i].type << "\t"
                 << symbols[i].value << '\n';
        }
    }
};

int main() {
    SymbolTable st;

    // Insert
    st.insert("age", "int", "20");
    st.insert("salary", "float", "5000.5");
    st.insert("name", "string", "An");

    // Display
    st.display();

    // Search
    Symbol* s = st.search("age");

    if (s != nullptr) {
        cout << "\nFound: "
             << s->name << " "
             << s->type << " "
             << s->value << '\n';
    } else {
        cout << "\nSymbol not found!\n";
    }

    // Remove
    if (st.remove("salary")) {
        cout << "\nDeleted successfully!\n";
    } else {
        cout << "\nSymbol not found!\n";
    }

    // Display after deleting
    st.display();

    return 0;
}

