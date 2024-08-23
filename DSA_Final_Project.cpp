#include<iostream>
using namespace std;


////////////////////////////Sales Tracker//////////////////////////////
class SalesNode {
public:
    string itemName;
    string name;
    int pric; 
    SalesNode* next;

    SalesNode(string ItemName, int price, string name) {
        this->itemName = ItemName;
        this->pric = price;
        this->next = NULL;
    }
};

class SalesTracker {
public:
    SalesNode* head;


    SalesTracker(){
    	head=NULL;
	} 

    // Function to add sales 
    void addSalesData(const string& ItemName, int price, string& name) {
    SalesNode* newNode = new SalesNode(ItemName, price,name); // Use constructor
    if (head == NULL) {
        head = newNode;
    } else {
        SalesNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

    // Function to display sales 
    void displaySales(const string& period) {
    	cout<<"--------------------------------------------\n";
        cout << "Sales figures for " << period << ":\n";
        SalesNode* current = head;
        while (current != NULL) {
        	
            cout << "Item Name: " << current->itemName << ", Price: " << current->pric << endl; 
            current = current->next;
        }
         cout<<"-------------------------------------------------------";
    }

    // Function to delete sales data 
    void deleteSales() {
        cout << "\nWhich Name of item you want to delete: ";
        string date;
        cin >> date;

        if (head == NULL) {
            cout << "No sales data to delete." << endl;
            return;
        }

        if (head->itemName == date) {
            SalesNode* temp = head;
            head = head->next;
            delete temp;
            cout << "Sales data deleted successfully for " << date << "." << endl;
            return;
        }

        SalesNode* current = head;
        while (current->next != NULL) {
            if (current->next->itemName == date) {
                SalesNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
                cout << "Sales data deleted successfully for " << date << "." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Sales data not found for " << date << "." << endl;
    }

    // Destructor to free allocated memory
    ~SalesTracker() {
        while (head != NULL) {
            SalesNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


////////////////////////////Order Manager//////////////////////////////
class AddBakeryItem {
    public:
        string Name;
        float Price;

    AddBakeryItem(string name, float price) {
        Name = name;
        Price = price;
    }
};

class node1 {
    public:
        AddBakeryItem* item;
        node1* next;

        node1(string name, float price) {
            item = new AddBakeryItem(name, price);
            next = NULL;
        }
};

class BakeryList {
    public:
        node1* head;

   
        BakeryList() {
            head = NULL;
        }

        void Additem(string name, float price) {
            node1* n = new node1(name, price);

            if (head == NULL) {
                head = n;
                return;
            }

            n->next = head;
            head = n;
        }

        void display() {
            cout << "\n--------------- Bakery Item --------------";
            cout << endl;
            int p = 1;
            node1* temp = head;
            cout << "\n  Name      Price\n";
            cout << "-----------------------\n";
            while (temp != NULL) {
                cout << p << " - " << temp->item->Name << ":    " << temp->item->Price << "\n";
                temp = temp->next;
                p++;
            }
            cout<<"-------------------------------------------------------";
        }
        
        void deleteItem() {
    if (head == NULL) {
        cout << "\nList is empty." << endl;
        return;
    }

    cout << "\nWhich item do you want to delete? ";
    int pos;
    cin >> pos;

    if (pos <= 0) {
        cout << "\nInvalid position." << endl;
        return;
    }

    if (pos == 1) {
        node1* temp = head;
        head = head->next;
        delete temp;
        cout << "\nItem deleted." << endl;
        return;
    }

    int count = 1;
    node1* temp = head;
    while (temp->next != NULL && count != pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL || count != pos - 1) {
        cout << "\nInvalid position." << endl;
        return;
    }

    node1* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    cout << "\nItem deleted." << endl;
}

};
/////////////////////////Customer Dashboard///////////
class CustomerNode {
public:
    int id;
    string name;
    string email;
    CustomerNode* next;

    CustomerNode(int id, const string& name, const string& email) {
        this->id = id;
        this->name = name;
        this->email = email;
        this->next = NULL;
    }
};

class CustomerList {
public:
    CustomerNode* head;


    CustomerList(){
    	head=NULL;
	}

    // Add a new customer to the list
    void addCustomer(int id, const string& name, const string& email) {
        CustomerNode* newNode = new CustomerNode(id, name, email);
        newNode->next = head;
        head = newNode;
    }

    // View all customer details
    void viewCustomers() {
        CustomerNode* current = head;
        
        if (current == NULL) {
            cout << "No customers found." << endl;
            return;
        }
         cout<<"-------------------------------------------------------\n";
        while (current != NULL) {
            cout << "ID: " << current->id << ", Name: " << current->name << ", Email: " << current->email << endl;
            current = current->next;
        }
         cout<<"-------------------------------------------------------";
    }

    // Update a customer's details
    void updateCustomer(int id, const string& name, const string& email) {
        CustomerNode* current = head;
        while (current != NULL) {
            if (current->id == id) {
                current->name = name;
                current->email = email;
                cout << "Customer details updated successfully." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Customer with ID " << id << " not found." << endl;
    }

    
    void deleteCustomer(int id) {
        if (head == NULL) {
            cout << "No customers to delete." << endl;
            return;
        }

        if (head->id == id) {
            CustomerNode* temp = head;
            head = head->next;
            delete temp;
            cout << "Customer deleted successfully." << endl;
            return;
        }

        CustomerNode* current = head;
        while (current->next != NULL) {
            if (current->next->id == id) {
                CustomerNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
                cout << "Customer deleted successfully." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Customer with ID " << id << " not found." << endl;
    }

    // Destructor to free allocated memory
    ~CustomerList() {
        while (head != NULL) {
            CustomerNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
     void oldCustomer(BakeryList& bakeryList, SalesTracker& sales) {
        cout << "\nEnter your id: ";
        int Id;
        cin >> Id;
        CustomerNode* temp = head;
        while (temp != NULL) {
            if (temp->id == Id) {
                cout << "\n Your Id matched....";
                while (true) {
                    cout << "\n Press 1 to see all Bakery Items: ";
                    int press;
                    cin >> press;
                    if (press == 1) {
                        bakeryList.display();
                        int select;
                        node1* tempNode;
                        while (true) {
                            cout << "\nSelect Item which you want to order: ";
                            cin >> select;
                            tempNode = bakeryList.head;
                            int n = 1;
                            while (tempNode != NULL && n != select) {
                                tempNode = tempNode->next;
                                n++;
                            }
                            if (tempNode != NULL) {
                                cout << "\nEnter Quantity: ";
                                int qty;
                                cin >> qty;
                                
                                
                                int total = qty * tempNode->item->Price;
                                string na=tempNode->item->Name;
                                int pri=total;
                                cout << "\nYour ordered item is \n" << select << " - " << tempNode->item->Name << " : " << tempNode->item->Price;
                                cout << "\nTotal price: " << total;
                                cout << "\nPress 1 to confirm order or 2 to select another item: ";
                                int pre;
                                cin >> pre;
                                if (pre == 1) {
                                    cout << "\nSelect your payment method: \n1. Cash \n2. Credit: ";
                                    int met;
                                    cin >> met;
                                    if (met == 1 || met == 2) {
                                        cout << "\nYour Order has been placed successfully.";
                                        sales.addSalesData(na,pri, temp->name);
                                        return;
                                    } else {
                                        cout << "\nInvalid payment method. Please try again.";
                                    }
                                } else if (pre == 2) {
                                    break; // Go back to display the menu again
                                } else {
                                    cout << "\nInvalid selection.";
                                }
                            } else {
                                cout << "\nInvalid selection.";
                            }
                        }
                    } else {
                        cout << "\nInvalid selection.";
                    }
                }
                return; 
            }
            temp = temp->next;
        }
        cout << "Customer with ID " << Id << " not found." << endl;
    }
    
    void newCustomer(CustomerList& customers, BakeryList& bakeryList, SalesTracker& sales) {
    int id;
    string name, email;
    cout << "\nEnter id: ";
    cin >> id;
    cout << "\nEnter name: ";
    cin >> name;
    cout << "\nEnter email: ";
    cin >> email;
    customers.addCustomer(id, name, email);
    cout << "\nYour account has been created....";
    
    while (true) {
        cout << "\nPress 1 to see all Bakery Items: ";
        int press;
        cin >> press;
        if (press == 1) {
            bakeryList.display();
            int select;
            node1* tempNode;
            while (true) {
                cout << "\nSelect Item which you want to order: ";
                cin >> select;
                tempNode = bakeryList.head;
                int n = 1;
                while (tempNode != NULL && n != select) {
                    tempNode = tempNode->next;
                    n++;
                }
                if (tempNode != NULL) {
                    cout << "\nEnter Quantity: ";
                    int qty;
                    cin >> qty;
                    int total = qty * tempNode->item->Price;
                    string na = tempNode->item->Name;
                    int pri = total;
                    
                    cout << "\nYour ordered item is \n" << select << " - " << tempNode->item->Name << " : " << tempNode->item->Price;
                    cout << "\nTotal price: " << total;
                    cout << "\nPress 1 to confirm order or 2 to select another item: ";
                    
                    int pre;
                    cin >> pre;
                    if (pre == 1) {
                        cout << "\nSelect your payment method: \n1. Cash \n2. Credit: ";
                        int met;
                        cin >> met;
                        if (met == 1 || met == 2) {
                            cout << "\nYour Order has been placed successfully.";
                            sales.addSalesData(na, pri, name);
                            return;
                        } else {
                            cout << "\nInvalid payment method. Please try again.";
                        }
                    } else if (pre == 2) {
                        break; // Go back to display the menu again
                    } else {
                        cout << "\nInvalid selection.";
                    }
                } else {
                    cout << "\nInvalid selection.";
                }
            }
        } else {
            cout << "\nInvalid selection.";
        }
    }
}

};

////////////////All Bakeryss/////////////////
class BakeryData {
public:
    string name;
    int itemsAvailable;
    int itemsSold;
    double revenue;
    BakeryData* next;

    // Constructor
    BakeryData(const string& name, int itemsAvailable, int itemsSold, double revenue, BakeryData* next = NULL)
       {
		this->name=name;
		this->itemsAvailable=itemsAvailable;
		this->itemsSold=itemsSold;
		this->revenue=revenue;
		this->next=NULL;
		}
};

class BakeryDashboard {
public:
    BakeryData* head;

    // Constructor
    BakeryDashboard()  {
	head=NULL;
	}

    // Create and insert a new bakery data
    void create(const string& name, int itemsAvailable, int itemsSold, double revenue) {
    	
        BakeryData* n = new BakeryData(name, itemsAvailable, itemsSold, revenue, head);
        if(head==NULL){
    		head=n;
    		return;
		}
		BakeryData* temp=head;
		n->next=temp;
		head=n;
    }

    // Read and display all bakery information
    void read() {
        BakeryData* current = head;
         cout<<"-------------------------------------------------------\n";
        while (current != NULL) {
            cout << "Bakery Name: " << current->name << "\n";
            cout << "Items Available: " << current->itemsAvailable << "\n";
            cout << "Items Sold: " << current->itemsSold << "\n";
            cout << "Revenue: $" << current->revenue << "\n";
            cout << "-------------------\n";
            current = current->next;
        }
         cout<<"-------------------------------------------------------";
    }

    // Update bakery data by name
    void update() {
        string name;
    	int newItemsAvailable;
    	int newItemsSold;
    	double newRevenue;
    	
    	cout<<"\nEnter Name: ";
    	cin>>name;
    	cout<<"\nEnter Item Available: ";
    	cin>>newItemsAvailable;
    	cout<<"Enter Sold Item: ";
    	cin>>newItemsSold;
    	cout<<"\nEnter Revenew: ";
    	cin>>newRevenue;
    	
        BakeryData* current = head;
        while (current !=NULL) {
            if (current->name == name) {
            	
                current->itemsAvailable = newItemsAvailable;
                current->itemsSold = newItemsSold;
                current->revenue = newRevenue;
                return;
            }
            current = current->next;
        }
        cout << "Bakery not found.\n";
    }
    
    void deleteBakeryAtPosition() {
    	int position;
    	cout<<"which bakery you want to delete..?";
    	cin>>position;
        if (head == NULL) {
            cout << "No bakeries to delete.\n";
            return;
        }

        if (position <= 0) {
            cout << "Invalid position.\n";
            return;
        }

        if (position == 1) {
            BakeryData* temp = head;
            head = head->next;
            delete temp;
            cout << "Bakery deleted successfully.\n";
            return;
        }

        BakeryData* current = head;
        int count = 1;
        BakeryData* previous = NULL;

        while (current != NULL && count != position) {
            previous = current;
            current = current->next;
            count++;
        }

        if (current == NULL) {
            cout << "Invalid position.\n";
            return;
        }

        previous->next = current->next;
        delete current;
        cout << "Bakery deleted successfully.\n";
    }


    // Destructor to clean up the linked list
    ~BakeryDashboard() {
        while (head != NULL) {
            BakeryData* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


//////////////////////ALL CUSTOMER//////////////////////
class StaffData {
public:
    string name;
    int salary;
    string schedule;
    string tasks;
    string contact;
    StaffData* next;

    // Constructor
    StaffData(const string& name, int salary, const string& schedule, const string& tasks, const string& contact)
       {
		this->name=name;
		this->salary=salary;
		this->schedule=schedule;
		this->tasks=tasks;
		this->contact=contact;
		this->next=NULL;
		}
};

class StaffHelper {
public:
    StaffData* head;

    // Constructor
    StaffHelper() {
    	head=NULL;
	}

    // Create and add a new staff member
    void create(const string& name, int salary, const string& schedule, const string& tasks, const string& contact) {
    	
        StaffData* n = new StaffData(name, salary, schedule, tasks, contact);
        if(head==NULL){
        	head=n;
        	return;
		}
		
		StaffData* temp=head;
		n->next=temp;
		head=n;
		return;
    }

    // Read and display all staff information
    void read() {
        StaffData* current = head;
         cout<<"-------------------------------------------------------\n";
        while (current != NULL) {
            cout << "Staff Name: " << current->name << "\n";
            cout << "Salary: " << current->salary << "\n";
            cout << "Schedule: " << current->schedule << "\n";
            cout << "Tasks: " << current->tasks << "\n";
            cout << "Contact: " << current->contact << "\n";
            cout << "-------------------\n";
            current = current->next;
        }
         cout<<"-------------------------------------------------------";
    }

    // Update staff data by name
    void update() {
    	string name;
        int salary;
        string schedule;
        string tasks;
        string contact;
        cout<<"\nEnter Name , Salary, Schedule , tasks , contact";
        cin>>name>>salary>>schedule>>tasks>>contact;
        StaffData* current = head;
        while (current != NULL) {
            if (current->name == name) {
                current->salary = salary;
                current->schedule = schedule;
                current->tasks = tasks;
                return;
            }
            current = current->next;
        }
        cout << "Staff not found.\n";
    }

    // Delete a staff member by name
    void remove() {
    	string name;
    	cout<<"\nEnter name to delete: ";
    	cin>>name;
        StaffData* current = head;
        StaffData* previous = NULL;
        while (current != NULL) {
            if (current->name == name) {
                if (previous == NULL) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                cout << "Staff member removed.\n";
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Staff not found.\n";
    }

    // Destructor to clean up the linked list
    ~StaffHelper() {
        while (head != NULL) {
            StaffData* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    BakeryList bakeryList;
    CustomerList custom;
    SalesTracker  sales;
    BakeryDashboard dashboard;
    StaffHelper staffHelper;
    
    //Add Bakery Item
    bakeryList.Additem("Chocolate", 321);
    bakeryList.Additem("Ladoo", 200);
    bakeryList.Additem("pineapple cake", 300);
    
    //Add Customer
    custom.addCustomer(1,"Hafsa","haf@gmail.com");
    custom.addCustomer(2,"hifza","hafgfg");
    custom.addCustomer(3,"Momina","wwwwwwwwww");
    custom.addCustomer(4,"Areej","qqqqq");

    //Add Bakery
    dashboard.create("LAYERS SADDAR", 300, 100, 250.75);
    dashboard.create("LAYERS AIRPORT SOCIETY", 200, 150, 375.50);
    dashboard.create("LAYERS DHA", 400, 150, 478.50);
    
    //ADD STAFF
    staffHelper.create("Hassan", 700000, "9am-5pm", "Baking, Customer Service", "+9234523410");
    staffHelper.create("Ahad", 600000, "10am-6pm", "Inventory, Sales", "+92546789201");
    staffHelper.create("Salar", 900000, "7am-6pm", "Attend customer, Sales", "+9254654201");
    staffHelper.create("Abbas", 1000000, "5am-12pm", "Manage delivery, Sales", "+9254654201");
    
    cout << "---------------------Welcome To Bakery Management System---------------------";
    while(true){
	
    cout << "\nSelect Your Status..";
    cout << "\n1. Admin \n2. Customer\n3. exit";
    int pre;
    cin >> pre;

    if (pre == 1) {
        int pass = 123;
        string name = "Hafsa";
        cout << "\nEnter Password: ";
        int ps;
        cin >> ps;
        cout << "\nEnter Name:  ";
        string na;
        cin >> na;

        if (na == name && ps == pass) {
            cout << "\nPassword matched: ";
            cout << "\nPress 1 to see all dashboard...";
            int press;
            cin >> press;

            if (press == 1) {
                while (true) {
                    cout << "\n1. See all added Customers \n2. Bakery Detail \n3.Track Sales \n4.Manage All Bakerys \n5.Manage All StafMembers \n6.Exit\n";
                    int ch;
                    cin >> ch;

                    if (ch == 1) {
                        custom.viewCustomers();
                    } else if (ch == 2) {
                        while (true) {
                            cout << "\n1. Add item \n2. Delete Item \n3. See All items  \n4. Exit\n";
                            int cho;
                            cin >> cho;

                            if (cho == 1) {
                                 bakeryList.Additem("Pastery", 321);
                                 bakeryList.Additem("Simple Cake", 200);
                                 bakeryList.Additem("Chocolate Cake", 300);
                                 cout<<"\nEnter Name: ";
                                 string names;
                                 cin>>names;
                                 cout<<"\nEnter Price: ";
                                 int prices;
                                 cin>>prices;
                                 bakeryList.Additem(names,prices);
                            } else if (cho == 2) {
                                bakeryList.deleteItem();
                            } else if (cho == 3) {
                                bakeryList.display();
                            } else if (cho == 4) {
                                break; // Exit the inner loop
                            } else {
                                cout << "\nInvalid Choice.";
                            }
                        }
                    }
					else if(ch==3){
						while(true){
						cout<<"\n1. See All Sales \n2. Delete Sales \n3. Exit";
						int choic;
						cin>>choic;
						if(choic==1){
							sales.displaySales("May-29");
						}
						else if(choic==2){
							sales.deleteSales();
						}
						else if(choic==3){
							break;
						}
						else{
							cout<<"\nInvalid Choice";
						}
					}
					}
					else if(ch==4){
						while(true){
						
						cout<<"\n1.Add Bakery \n2.Delete Bakery \n3.Display Bakery  \n4.Exit";
						int choice;
						cin>>choice;
						if(choice==1){
							string names;
                            int itemsAvailable;
                            int itemsSold;
                            double revenue;
                            cout<<"\nEnter name, itemAvailable, itemsSold, Revenue";
                            cin>>names>>itemsAvailable>>itemsSold>>revenue;
                            
							dashboard.create(names,itemsAvailable,itemsSold,revenue);
						}
						else if(choice==2){
							dashboard.deleteBakeryAtPosition();
						}
						else if(choice==3){
							dashboard.read();
						}
						
						else if(choice==4){
							break;
						}
						else{
							cout<<"\nInvalid Choice ";
						}
					}
				}
				
				else if(ch==5){
						while(true){
						
						cout<<"\n1.Add Sales Member \n2.Delete Sales Member \n3.Display Sales Member  \n4.Exit";
						int choices;
						cin>>choices;
						if(choices==1){
							string name;
                              int salary;
                            string schedule;
                            string tasks;
                            string contact;
                          cout<<"\nEnter Name , Salary, Schedule , tasks , contact";
                          cin>>name>>salary>>schedule>>tasks>>contact;
							staffHelper.create(name,salary,schedule,tasks,contact);
						}
						else if(choices==2){
							staffHelper.remove();
						}
						else if(choices==3){
							staffHelper.read();
						}
						
						else if(choices==4){
							break;
						}
						else{
							cout<<"\nInvalid Choice ";
						}
					}
				}
				
	
					else if (ch == 6) {
                        break; // Exit the outer loop
                    } else {
                        cout << "\nInvalid Choice";
                    }
                }
            }
        } else {
            cout << "\nPassword does not match.";
        }
    
}

else if(pre==2){
	cout<<"\n1.New Customer \n2.Old Customer";
	int choi;
	cin>>choi;
	if(choi==1){
		custom.newCustomer(custom,bakeryList,sales);
	}
	else if(choi==2){
		custom.oldCustomer(bakeryList,sales);
	}
}

else{
	break;
}
    
}
return 0;
}
