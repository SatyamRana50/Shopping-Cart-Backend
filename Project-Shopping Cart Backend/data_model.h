#include<string>
#include<bits/stdc++.h>
using namespace std;
class Item;
class Cart;
 class Product
 {
    private:
    int price;
    string name;
    int u_id;
    public:
    Product(){

    };
    Product(int u_id, string name, int price)
    {
        this->u_id=u_id;
        this->name=name;
        this->price=price;
    }
    string get_display_name()
    {
        return name+" : Rs "+ to_string(price)+"\n";
    }
    string get_short_name()
    {
        return name.substr(0,1);
    }
    friend class Item;
    friend class Cart;

 };
 class Item
 {
    private:
    Product product;
    int quantity;
    // constructor using init list
    public:
    Item(){}
    Item(Product p, int q): product(p), quantity(q){}
    int get_item_price()
    {
        return quantity*product.price;
    }
    string get_item_info()
    {
        return to_string(quantity) +" x " + product.name + " : Rs "+ to_string(quantity*product.price) +"\n";
    }
    friend class Cart;


 };
 
 class Cart
 {
    unordered_map<int, Item> items;
    public:
    void add_product(Product product)
    {
        if(items.find(product.u_id)==items.end())
        {
            Item new_item(product,1);
            items[product.u_id]=new_item;
        }
        else items[product.u_id].quantity+=1;
    }
    int get_total()
    {
        int total=0;
        for(auto item_pair:items)
            total+=item_pair.second.get_item_price();
        return total;    

    }
    string view_cart()
    {
        string itemized_list;
        if(items.empty()) return "cart is empty\n";
        for(auto item_pair:items)
        {
            auto item=item_pair.second;
            itemized_list.append(item.get_item_info());
        }
        return itemized_list+"\n" +"total is Rs: "+ to_string(get_total()) +"\n";
    }
    bool is_empty()
    {
        return items.empty();
    }

 };