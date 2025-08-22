#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Menuitem {
private:
    int id;
    string name;
    double price;
public:
    Menuitem(int i, string n, double p) {
        id = i;
        name = n;
        price = p;
    }

    int getPrice() {
        return price;
    }

    string getName() {
        return name;
    }

    int getId() {
        return id;
    }

    void setName(string n) {
        name = n;
    }

    void setPrice(double p) {
        price = p;
    }
    void setID(int i){
    	id = i;
	}

    void displayitems() {
    
           cout << id << ". " << name  << price << "$"<< endl;
    }
};

class Food  {
public:
    virtual void Message() = 0; 
    
	virtual void help(){
		
		cout<<"hello"<<endl;
	}
};



class resturant : public Food {
protected:
    vector<Menuitem> menu;
    vector<Menuitem> order;

public:
    
    void Message() {
        cout << " Welcome to our restaurant system" << endl;
    }
    
   void help()override{
   cout << "How can I help you"<< endl;
   }

    void addmenuitem(int id, string name, double price) {
        menu.push_back(Menuitem(id, name, price));
    }

    void displaymenu() {
        for (int i = 0; i < menu.size(); i++) {
            menu[i].displayitems();
        }
    }

    void Takeorder() {
        int Itemid;
        
     
        
        while (true) {
            cout << "Enter Item ID to order (0 to finish): ";
            cin >> Itemid;

            if (Itemid == 0)
                break;

            bool found = false;
            for (int i = 0; i < menu.size(); i++) {
                if (menu[i].getId() == Itemid) {
                    order.push_back(menu[i]);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Item not found" << endl;
            }
        }

        double total = 0;
        
        cout << "Order Details:"<<endl;
        for (int i = 0; i < order.size(); i++) {
            order[i].displayitems();
            total += order[i].getPrice();
        }

        cout << "Total : $ " << total << endl;
     
		
    }
};
class Mangement : public resturant{
	
	private:
	
	   string password = "rest123";
	   
	   public:
	   	string entpass;
	   	bool security(){
		   
	   	cout <<"Enter password"<<endl;
	   	cin>> entpass;
	   	return entpass == password;
		   }
	 void deleteItem() {
        if (!security()) {
            cout << "Access Denied" << endl;
            
        }
      
        
        
        int id;
        cout << "Enter ID of item to delete: ";
        cin >> id;
        for(int i = 0; i < menu.size();i++){
        	if(menu[i].getId()==id){
        		menu.erase(menu.begin() +i);
        		cout<<"item deleted;"<<endl;
        		
			}
        	
		}
		cout<<"item not found"<<endl;
	}

      void clearmenu(){
      	
      	  if (!security()) {
            cout << "Access Denied" << endl;
        
        }
      menu.clear();
	  
      	cout <<"All items cleared"<<endl;
	  
	  }
};
int main() {
    Mangement r;

    
    Food* m = &r;
    
    m->Message();
    
    m->help();
  
    

    r.addmenuitem(1, "Burger", 3.45);
    r.addmenuitem(2, "Pizza", 7.99);
    r.addmenuitem(3, "Wrap", 3.00);
    r.addmenuitem(4, "Fried Chicken", 11.00);
    r.addmenuitem(5, "Salad", 2.15);
    r.addmenuitem(6, "Fries", 1.99);
    r.addmenuitem(7, "Cold Drink", 1.50);

    int choice;
    while (true) {
        cout << "=== RESTAURANT MENU ==="<<endl;
        cout << "1. Display Menu"<<endl;
        cout << "2. Add Menu Items"<<endl;
        cout << "3. Take Order"<<endl;
        cout << "4. Delete item"<<endl;
        cout << "5. Clear"<<endl;
        cout << "6. Exit"<<endl;
        
        cout << "Enter choice: "<<endl;
        cin >> choice;

        if (choice == 6)
            break;

        switch (choice) {
            case 1:
                r.displaymenu();
                break;

            case 2: {
                int id;
                double price;
                string name;
                cout << "Enter ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Price: ";
                cin >> price;
                r.addmenuitem(id, name, price);
                break;
            }
            

            case 3:
                r.Takeorder();
                break;

           
               
                case 4 :
                	r.deleteItem();
                	break;
                	
                case 5 :
				r.clearmenu();	
                	break;
                	default:
         cout << "Invalid Choice" << endl;


    cout << "Thank you for visiting" << endl;
}
}
    return 0;
}
    


