#include <iostream>
#include <string>
#include <map>

using namespace std;
class PhoneBook{
    private:
        map<string,string> contacts;
    public:
        void add(string contactName, string contactNumber){
            if (contactNumber.length() != 10) cout <<"Invalid Phone Number. "<<endl;
            else{
            contacts[contactName] = contactNumber;
            cout << "Contact Added Succesfully!" <<endl;
            }
        }
        
        void searchContact(string contactName){
            if(contacts.find(contactName) != contacts.end()){
                cout << "Name : " << contactName << "\t Phone Number : " << contacts[contactName] << endl;
            }
            else{
                cout << "Contact Not Found \n Check for any Spelling Mistakes" <<endl; 
            }
        }

        void deleteContact(string contactName){
            if(contacts.find(contactName) != contacts.end()){
                contacts.erase(contactName);
                cout << "Contact Deleted Successfully" <<endl;
            }
            else{
                cout<<"Contact Not Found \n Check For any spelling Mistakes"<<endl;
            }
        }

        void displayAllContacts(){
            for(auto contact : contacts){
                cout << "Name : " << contact.first << "\t Phone Number : " << contact.second <<endl;
            }
        }
};


int main(){
    int choice;
    PhoneBook phonebook;
    string contactName, contactNumber;
    cout << "Welcome to Phone Book \n";

    do{
        cout << "\n1 -  Add Contact" << endl;
        cout << "2 - Search Contact" << endl;
        cout << "3 - Delete Contact" << endl;
        cout << "4 - Display All Contacts" << endl;
        cout << "5 - Exit" << endl;
        cout<<endl;
        cout<<"Enter Your Choice: ";
        cin >> choice;
        cout<<endl;
        switch(choice){
            case 1:
                cout << "Enter Contacts First Name: ";
                cin >> contactName;
                cout<<endl;
                cout << "Enter Contact Number: ";
                cin >> contactNumber;
                cout<<endl;
                phonebook.add(contactName, contactNumber);
                break;
            case 2:
                cout << "Enter Contact Name: ";
                cin >> contactName;
                cout<<endl;
                phonebook.searchContact(contactName);
                break;
            case 3:
                cout << "Enter Contact Name to Delete: ";
                cin >> contactName;
                cout<<endl;
                phonebook.deleteContact(contactName);
                break;
            case 4:
                phonebook.displayAllContacts();
                break;
            case 5:
                cout << "Hope you Found Your Mate! \n Thank You :) " <<endl;
                break;
            default:
                cout << "Invalid Choice" <<endl;
        }
    }while(choice !=5 );

    return 0;
}