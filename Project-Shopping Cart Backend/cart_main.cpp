#include<iostream>
#include "data_model.h"
#include<vector>
#include<string>
vector<Product> all_products={Product(1, "apple",26), Product(2,"banana",10), Product(3,"mango",22),
Product(4,"pineapple",30), Product(5,"strawberry",60), Product(6,"guava",11)};
Product* choose_product()
{
    string product_list;
    cout<<"avaialble products "<<endl;
    for(auto product:all_products)
    {
        product_list.append(product.get_display_name());
    }
    cout<<product_list<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"select a product"<<endl;
    string choice;
    cin>>choice;
    for(int i=0;i<product_list.size();i++)
    {
        if(all_products[i].get_short_name()==choice)
        return &all_products[i];

    }
    cout<<"Product not found!"<<endl;
    return NULL;
}
bool checkout(Cart &cart){
    if(cart.is_empty()) return false;
    int total=cart.get_total();
    int paid;
    cout<<"Kindly pay Rs: "+ to_string(cart.get_total())<<endl;
    cin>>paid;
    if(paid>=total) {
        cout<<"change is Rs: "<<paid-total<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"Thakyou for shopping with us"<<endl;
        return true;
    }
    else{
        cout<<"not enough cash"<<endl;
        return false;
    }
}
int main()
{
    char action;
    Cart cart;
    while(true)
    {
        cout<<"select an action- (a)dd item (v)iew cart (c)heckout"<<endl;
        cin>>action;
        if(action=='a')
        {
            Product* product=choose_product();
            if(product!=NULL){
                cart.add_product(*product);
            cout<<"added to cart- "<<product->get_display_name()<<endl;
            }
        }
        else if(action=='v'){
            cout<<"------------------------------"<<endl;
            cout<<cart.view_cart()<<endl;
            cout<<"------------------------------"<<endl;
        }
        else{
            // checkout
            cout<<cart.view_cart()<<endl;
            if(checkout(cart)) break;

        }
    }
    return 0;
}