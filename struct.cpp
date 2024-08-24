#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
using namespace std;
// repeated function so many times
string validation_num(string s){
    bool ok=true;
    while (true)  {

        for (char c: s) {
            if (!isdigit(c)) {
                ok=false;
                break;
            }
        }
        if(!ok){
            cout<<"PLS Enter a vaild num: ";
            cin>>s;
            ok=true;
        }else{
            return s;
        }
    }

}

//ID, Name, Price, Description, and Units in Stock.
struct product{
    string id;
    string name;
    string price;
    string description;
    string units;
};

struct shops{
    map<string,int>validation;// avoid repeation
    vector<string>id;// same order to access the different products
    vector<product>shop;// the details of the products
    string vaild_id(string);
    void add (bool,long long );
    void update(string);//takes id
    void deletes (string);
    void view ();

};

string shops::vaild_id(string s) {
   s=validation_num(s);
    while (validation.count(s)==1){
        cout<<"That ID Exist!!\n\nTry another one!!\n\nEnter a new ID:";
        cin>>s;
        s=validation_num(s);
    }
    id.push_back(s);
    validation[s]==1;
    return s;
}

void shops::add( bool menu,long long i=0) {
    product new_pro;

    if(menu==0){
        cout << "PLS Enter the ID product: ";
        string s;
        cin >> s;
        // if(menu==0){ s = vaild_id(s); }
        s = vaild_id(s);//id entered
        new_pro.id = s;
        cout << "\n\n";
    }else{
        new_pro.id = shop[i].id;
    }


    cout<<"PLS Enter the name of the product: ";
    cin>>new_pro.name;
    cout<<"\n\n";


    cout<<"PLS Enter the price: ";
    string p;cin>>p;
    new_pro.price= validation_num(p);
    cout<<"\n\n";


    cout<<"PLS Enter the description: \n";
    cin.get();
   getline(cin, new_pro.description);
    cout<<"\n\n";



    cout<<"PLS Enter the number of units: ";
    string n;cin>>n;
    new_pro.units= validation_num(n);
    cout<<"\n\n";


    if(menu==0){
        shop.push_back(new_pro); }
    else{
        shop[i]=new_pro;
    }
}

void shops::update(string s) {
    long long  save_index;
    for (long long i = 0; i < id.size(); ++i) {
        if(id[i]==s){
            save_index=i;
            break;
        }
    }
 // the add part is repeated but the  difference is that there we push a new item
 //but here we update a value
 add(1,save_index);

}

void shops::deletes(string s) {
 auto it1= validation.find(s);
 auto it2= find(id.begin(),id.end(),s);
 validation.erase(it1);
 long long index=it2-id.begin();
 id.erase(it2);
 shop.erase(shop.begin()+index);
 cout<<"###Deleting is done###\n\n";

}

void shops::view() {
    for (int i = 0; i < shop.size(); ++i) {
        if(i!=0){
            cout<<"####################\n";
        }
        cout<<"Product "<<i+1<<" :\n";
        cout<<"Product ID : "<<shop[i].id<<'\n'<<'\n'
        <<"Product Name : "<<shop[i].name<<'\n'<<'\n'
        <<"Product Price : "<<shop[i].price<<'\n'<<'\n'
        <<"Product description : "<<shop[i].description<<'\n'<<'\n'
        <<"Number of Units in the Stock : "<<shop[i].units<<'\n'<<'\n';
    }

   cout<<"###These are all the products  that are on the system###\n\n\n";

}

int main() {


    shops shopping;
    cout<<"      ###Welcome to our management system###    \n";
    while (true){
        // the program

        cout<<"Choose any operation from the following Menu:\n";
        cout<<"1.Add product\n";
        if(!shopping.id.empty()){
          cout<<"2.Update product\n3.Delete product\n4.View All products\n";
        }
        cout<<"5.Exit\n####################\n"
        <<"Enter your choice: ";

        string choice;cin>>choice;
        //validation for input
        while(!shopping.id.empty() && choice!="1" && choice!="5"  && choice!="2" && choice!="3" && choice!="4"){
cout<<"Pls Enter a valid choice: ";cin>>choice;
        }

        while(shopping.id.empty()&& (choice!="1" && choice!="5")){
            cout<<"Pls Enter a valid choice: ";cin>>choice;
        }


        // the operations

       if(choice=="1"){// add
           shopping.add(0);
       }
       else if(choice=="2"){// update
           cout<<"PLS Enter the Targeted ID : ";
           string ID;cin>>ID;
           while (shopping.validation.count(ID)==0){
               cout<<"PLS Enter a vaild ID: ";
               cin>>ID;
           }
           shopping.update(ID);

       }
       else if(choice=="3"){
           // delete
           cout<<"PLS Enter the Targeted ID : ";
           string ID;cin>>ID;
           while (shopping.validation.count(ID)==0){
               cout<<"PLS Enter a vaild ID: ";
               cin>>ID;
           }
           shopping.deletes(ID);
       }
       else if(choice=="4"){
           shopping.view();
       }
       else if(choice== "5"){//exit
           cout<<"Thanks for using our application :^)";
           break;
       }

    }
    return 0;
}
