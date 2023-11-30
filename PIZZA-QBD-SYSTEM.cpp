#include <windows.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Queue.h"
#include "Menu.h"


using namespace std;

void displayMenu() {
    cout << "------------\n";
    cout << "*** MENU ***" << endl;
    cout << "------------\n";

    cout << "1. Add new pizza" << endl;
    cout << "2. Add new promo" << endl;
    cout << "3. Remove pizza" << endl;
    cout << "4. Remove promo" << endl;
    cout << "5. Print menu" << endl;
    cout << "6. Back" << endl;
    cout << "7. Exit" << endl;
}

void displayOrderOptions() {
    cout << "---------------------\n";
    cout << "*** ORDER OPTIONS ***" << endl;
    cout << "---------------------\n";

    cout << "1. New order" << endl;
    cout << "2. Cancel order" << endl;
    cout << "3. Job done" << endl;
    cout << "4. Display the queue" << endl;
    cout << "5. Search for an order" << endl;
    cout << "6. Display the menu" << endl;
    cout << "7. Handle emergency situation" << endl;
    cout << "8. VIP customer" << endl;
    cout << "9. Back" << endl;
    cout << "10. Exit" << endl;

}


int main()
{
    Queue q;
    Menu m;

    /*
    Queue abc;
    abc.newOrderPlaced(5);
    abc.newOrderPlaced(6);
    abc.newOrderPlaced(7);
    abc.print();
    abc.jobDone();
    abc.newOrderPlaced(8);
    abc.newOrderPlaced(9);
    abc.print();
    abc.orderCancelled(2);
    abc.print();
    abc.newOrderPlaced(1);
    abc.newOrderPlaced(2);
    abc.newOrderPlaced(3);
    abc.print();
    abc.emergencySituation(5);
    abc.print();
    abc.insertVipCustomer(0);
    abc.print();

    Menu p;
    p.insertNewPizza(5);
    p.insertNewPizza(6);
    p.insertNewPizza(7);
    p.insertNewPizza(8);
    p.print();
    p.insertNewPizza(2,0);
    p.print();
    p.insertNewPromo(1);
    p.print();
    p.insertNewPromo(4, 4);
    p.print();
    p.insertNewPizza(3);
    p.print();
    p.insertPromo(2,3,5);
    p.print();
    p.insertPromo(4, 3);
    p.print();
    p.removePromoPizza();
    p.print();
    p.removePizza(5);
    p.print();
    */

    int choice, orderType, order, pizza, pos, code, userId = 1, sId;
    map<int, string> pizzas;
    vector<string> queuee;
    string name, sname;

    //Default Pizza
    m.insertNewPizza(100);
    pizzas[100] = "[O]\tDevilled Chicken Pizza";
    m.insertNewPizza(101);
    pizzas[101] = "[O]\tBlack Chicken Pizza";
    m.insertNewPizza(102);
    pizzas[102] = "[O]\tSausage Pizza";



    while (true) {

        Sleep(1500);
        system("CLS");
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << endl << "....WELCOME to PIZZA QBD SYSTEM...." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << endl;
        cout << "1. Manage menu" << endl;
        cout << "2. Manage orders" << endl;
        cout << "3. Exit" << endl;
        cout << endl;
        cout << ">>> Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            system("CLS");
            displayMenu();

            cout << "\n>>> Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "\n~~~~PIZZA MENU~~~\n" << endl;
                for (auto pair : pizzas) {
                    cout << pair.first << " : " << pair.second << endl;
                }
                cout << "\n>>> Enter the pizza code: ";
                cin >> code;
                cout << "\n>>> Enter the pizza name: ";
                cin >> name;
                pizzas[code] = "[O]\t" + name;
                m.insertNewPizza(code);
                cout << "\nPizza added successfully!!!" << endl;
                break;
            case 2:

                cout << "\n>>> Enter the pizza promo code: ";
                cin >> code;
                cout << "\n>>> Enter the promo pizza name: ";
                cin >> name;
                pizzas[code] = "[P]\t" + name;
                m.insertNewPromo(code);
                cout << "\nPromo Pizza added successfully!" << endl;
                break;
            case 3:
                cout << "\n~~~~PIZZA MENU~~~\n" << endl;
                for (auto pair : pizzas) {
                    cout << pair.first << " : " << pair.second << endl;
                }
                cout << "\n>>> Enter the pizza code which want to remove: ";
                cin >> code;
                pizzas.erase(code);
                m.removePizza(code);
                cout << "\nPizza removed successfully!!!" << endl;
                break;
            case 4:
                cout << "\n~~~~PIZZA MENU~~~\n" << endl;
                for (auto pair : pizzas) {
                    cout << pair.first << " : " << pair.second << endl;
                }
                cout << "\n>>> Enter the promo pizza code which want to remove: ";
                cin >> code;
                pizzas.erase(code);
                m.removePizza(code);
                cout << "\nPromo pizza removed successfully!!!" << endl;
                break;
            case 5:
                //m.print();
                cout << "\n~~~~PIZZA MENU~~~\n" << endl;
                for (auto pair : pizzas) {
                    cout << pair.first << " : " << pair.second << endl;
                }
                cin.ignore();
                cin.get();
                break;
            case 6:
                // Continue
                system("CLS");
                break;
            case 7:
                // Exit the program
                cout << "\nExiting the program..." << endl;
                exit(0);
                break;
            default:
                cout << "\nInvalid choice!" << endl;
            }
        }
        else if (choice == 2) {
            system("CLS");
            displayOrderOptions();
            cout << "\n>>> Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "1. Online order" << endl;
                cout << "2. Physical order" << endl;
                cout << "\n>>> Enter your choice: ";
                cin >> orderType;

                if (orderType == 2) {
                    cout << "1. Dine in" << endl;
                    cout << "2. Pick up" << endl;
                    cout << "\n>>> Enter your choice: ";
                    cin >> order;

                    if (order == 1) {
                        // Implement dine in order
                        //m.print();
                        cout << "\n~~~PIZZA MENU~~~\n" << endl;
                        for (auto pair : pizzas) {
                            cout << pair.first << " : " << pair.second << endl;
                        }
                        cout << "\n> Customer Id: " << userId << endl;
                        //userId++;
                        cout << "\n>>> Enter the pizza code: ";
                        cin >> code;
                        if (pizzas.count(code)) {
                            q.newOrderPlaced(code, userId);
                            cout << "\nOrder placed successfully!" << endl;
                            queuee.push_back(to_string(userId) + " \t:\t[Physical]\tDine in Order");
                            userId++;

                        }
                        else {
                            cout << "Try Again" << endl;
                        }

                    }
                    else if (order == 2) {
                        // Implement pick up order
                        //m.print();
                        cout << "\n~~~PIZZA MENU~~~\n" << endl;
                        for (auto pair : pizzas) {
                            cout << pair.first << " : " << pair.second << endl;
                        }
                        cout << "\n> Customer Id: " << userId << endl;
                        //userId++;
                        cout << "\n>>> Enter the pizza code: ";
                        cin >> code;
                        if (pizzas.count(code)) {
                            q.newOrderPlaced(code, userId);
                            cout << "\nOrder placed successfully!!!" << endl;
                            queuee.push_back(to_string(userId) + " \t:\t[Physical]\tPick up Order");
                            userId++;
                        }
                        else {
                            cout << "Try Again" << endl;
                        }
                    }
                    else {
                        cout << "Invalid choice!" << endl;
                    }
                }
                else if (orderType == 1) {
                    // Implement online order
                    cout << "1. Dine in" << endl;
                    cout << "2. Pick up" << endl;
                    cout << "3. Delivery" << endl;
                    cout << "\n>>> Enter your choice: ";
                    cin >> order;

                    if (order == 1) {
                        // Implement dine in order
                        //m.print();
                        cout << "\n~~~PIZZA MENU~~~\n" << endl;
                        for (auto pair : pizzas) {
                            cout << pair.first << " : " << pair.second << endl;
                        }
                        cout << "\n> Customer Id: " << userId << endl;
                        //userId++;
                        cout << "\n>>> Enter the pizza code: ";
                        cin >> code;
                        if (pizzas.count(code)) {
                            q.newOrderPlaced(code, userId);
                            cout << "\nOrder placed successfully!!!" << endl;
                            queuee.push_back(to_string(userId) + " \t:\t[Online]\tDine in Order");
                            userId++;
                        }
                        else {
                            cout << "Try Again" << endl;
                        }
                    }
                    else if (order == 2) {
                        // Implement pick up order
                        //m.print();
                        cout << "\n~~~PIZZA MENU~~~" << endl;
                        for (auto pair : pizzas) {
                            cout << pair.first << " : " << pair.second << endl;
                        }
                        cout << "> Customer Id: " << userId << endl;
                        //userId++;
                        cout << "\n>>> Enter the pizza code: ";
                        cin >> code;
                        if (pizzas.count(code)) {
                            q.newOrderPlaced(code, userId);
                            cout << "\nOrder placed successfully!!!" << endl;
                            queuee.push_back(to_string(userId) + " \t:\t[Online]\tPick up Order");
                            userId++;
                        }
                        else {
                            cout << "Try Again" << endl;
                        }
                    }
                    else if (order == 3) {
                        // Implement delivery order
                        //m.print();
                        cout << "\n~~~PIZZA MENU~~~" << endl;
                        for (auto pair : pizzas) {
                            cout << pair.first << " : " << pair.second << endl;
                        }
                        cout << "\n> Customer Id: " << userId << endl;
                        //userId++;
                        cout << "\n>>> Enter the pizza code: ";
                        cin >> code;
                        if (pizzas.count(code)) {
                            q.newOrderPlaced(code, userId);
                            cout << "\nOrder placed successfully!\nEstimated delivery time is 30 minutes." << endl;
                            queuee.push_back(to_string(userId) + " \t:\t[Online]\tDelivery Order");
                            userId++;
                        }
                        else {
                            cout << "Try Again" << endl;
                        }
                    }
                    else {
                        cout << "Invalid choice!" << endl;
                    }
                }
                else {
                    cout << "Invalid choice!" << endl;
                }
                break;
            case 2:
                // Cancel an order
                //q.print();
                for (string a : queuee) {
                    cout << a << endl;
                }
                cout << "\n>>> Enter the position of the order to be cancelled: ";
                cin >> pos;
                q.orderCancelled(pos);
                queuee.erase(queuee.begin() + pos - 1);
                cout << "\nOrder cancelled successfully!" << endl;
                break;
            case 3:
                // Mark an order as done
                q.jobDone();
                queuee.erase(queuee.begin());
                cout << "\nOrder marked as done successfully!" << endl;
                cout << "\nCurrent Queue :" << endl;
                for (string a : queuee) {
                    cout << a << endl;
                }
                cin.ignore();
                cin.get();
                break;
            case 4:
                // Display the current queue
                //q.print();
                for (string a : queuee) {
                    cout << a << endl;
                }
                cin.ignore();
                cin.get();
                break;
            case 5:
                // Search for an order
                cout << "\n>>> Enter user ID to search: ";
                cin >> sId;
                //q.print();
                q.search(sId);
                break;
            case 6:
                // Display the menu
                //m.print();
                cout << "\n~~~PIZZA MENU~~~\n" << endl;
                for (auto pair : pizzas) {
                    cout << pair.first << " : " << pair.second << endl;
                }
                break;
            case 7:
                // In an emergency situation
                for (string a : queuee) {
                    cout << a << endl;
                }
                cout << "\n>>> Enter the position: ";
                cin >> code;
                q.emergencySituation(code - 1);
                sname = queuee[code - 1];
                queuee.erase(queuee.begin() + code - 1);
                queuee.insert(queuee.begin() + 1, sname);

                cout << "\nSuccessfully managed the Emergency Situation!" << endl;
                break;
            case 8:
                // VIP customer
                //m.print();
                cout << "\n~~~PIZZA MENU~~~\n" << endl;
                for (auto pair : pizzas) {
                    cout << pair.first << " : " << pair.second << endl;
                }
                cout << "\n>>> Enter the position of the queue and the code of the pizza: ";
                cin >> pos >> code;
                q.insertVipCustomer(pos, code);
                sname = to_string(userId) + " \t:\t[VIP]\t\tVIP Order";
                queuee.insert(queuee.begin() + (pos - 1), sname);
                userId++;
                cout << "\nVIP customer added successfully!" << endl;
                break;
            case 9:
                // Continue
                system("CLS");
                break;
            case 10:
                // Exit the program
                cout << "\nExiting the program..." << endl;
                exit(0);
                break;
            default:
                cout << "\nInvalid choice!" << endl;
            }
        }
        else {
            cout << "\nExiting the program..." << endl;
            exit(0);
        }

    }
    return 0;
}




