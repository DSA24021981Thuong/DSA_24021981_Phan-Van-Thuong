
#include <iostream>
#include <string>
using namespace std;

struct Symbol {
    string name;
    string type;
    string value;
    Symbol* next;
};

struct SymbolTable {
    Symbol* head = nullptr;

    // Them symbol hoac cap nhat neu da ton tai
    void insert(const string& name, const string& type,
                const string& value) {
        Symbol* current = head;

        while (current != nullptr) {
            if (current->name == name) {
                current->type = type;
                current->value = value;
                return;
            }
            current = current->next;
        }

        Symbol* newSymbol = new Symbol{name, type, value, head};
        head = newSymbol;
    }

    // Tim kiem symbol
    Symbol* search(const string& name) {
        Symbol* current = head;

        while (current != nullptr) {
            if (current->name == name) {
                return current;
            }
            current = current->next;
        }

        return nullptr;
    }

    // Xoa symbol
    bool remove(const string& name) {
        Symbol* current = head;
        Symbol* previous = nullptr;

        while (current != nullptr && current->name != name) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            return false;
        }

        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;
        return true;
    }

    // Hien thi Symbol Table
    void display() {
        Symbol* current = head;

        cout << "\n--- SYMBOL TABLE ---\n";
        cout << "Name\tType\tValue\n";

        while (current != nullptr) {
            cout << current->name << "\t"
                 << current->type << "\t"
                 << current->value << '\n';

            current = current->next;
        }
    }

    // Giai phong bo nho
    void clear() {
        while (head != nullptr) {
            Symbol* temp = head;
            head = head->next;
            delete temp;
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

    // Free memory
    st.clear();

    return 0;
}

