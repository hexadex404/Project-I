// Description
// Data about sales in an e-commerce company (the e-commerce company has several shops) consists a sequence of lines, each line (represents an order) has the following information:
//             <CustomerID> <ProductID> <Price> <ShopID> <TimePoint>
// in which the customer <CustomerID> buys a product <ProductID> with price <Price> at the shop <ShopID> at the time-point <TimePoint>
// <CustomerID>: string of length from 3 to 10
// <ProductID>: string of length from 3 to 10
// <Price>: a positive integer from 1 to 1000
// <ShopID>: string of length from 3 to 10
// <TimePoint>: string representing time-point with the format HH:MM:SS (for example, 09:45:20 means the time-point 9 hour 45 minutes 20 seconds)


// Perform a sequence of queries of following types:
// ?total_number_orders: return the total number of orders
// ?total_revenue: return the total revenue the e-commerce company gets
// ?revenue_of_shop <ShopID>: return the total revenue the shop <ShopID> gets 
// ?total_consume_of_customer_shop <CustomerID> <ShopID>: return the total revenue the shop <ShopID> sells products to customer <CustomerID> 
// ?total_revenue_in_period <from_time> <to_time>: return the total revenue the e-commerce gets of the period from <from_time> to <to_time> (inclusive)

// Input
// The input consists of two blocks of data:
// The first block is the operational data, which is a sequence of lines (number of lines can be upto 100000), each line contains the information of a submission with above format 
// The first block is terminated with a line containing the character #
// The second block is the query block, which is a sequence of lines (number of lines can be upto 100000), each line is a query described above
// The second block is terminated with a line containing the character #

// Output
// Write in each line, the result of the corresponding query 

// Example
// Input
// C001 P001 10 SHOP001 10:30:10
// C001 P002 30 SHOP001 12:30:10
// C003 P001 40 SHOP002 10:15:20
// C001 P001 80 SHOP002 08:40:10
// C002 P001 130 SHOP001 10:30:10
// C002 P001 160 SHOP003 11:30:20
// #
// ?total_number_orders
// ?total_revenue
// ?revenue_of_shop SHOP001
// ?total_consume_of_customer_shop C001 SHOP001 
// ?total_revenue_in_period 10:00:00 18:40:45
// #


// Output 
// 6
// 450
// 170
// 40
// 370

#include <bits/stdc++.h>
using namespace std;

struct Order
{
    string customerID;
    string productID;
    int price;
    string shopID;
    string timePoint;
};

int PrefixSum(int from, int to, vector <int> &prefix_sum){
    if (from == 0){
        return prefix_sum[to];
    }
    return prefix_sum[to] - prefix_sum[from - 1];
}

vector <Order> orders;
map <string, int> total_revenue;
map <string, map <string, int>> total_revenue_of_customer_shop;
int total = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    while (getline(cin, line))
    {
        if (line == "#"){
            break;
        }
        stringstream ss(line);
        Order order;
        ss >> order.customerID >> order.productID >> order.price >> order.shopID >> order.timePoint;
        orders.push_back(order);
        total_revenue_of_customer_shop[order.customerID][order.shopID] += order.price;
    }

    std::sort(orders.begin(),orders.end(),[](const Order& a, const Order& b){
        return a.timePoint < b.timePoint;
    });
    vector <int> prefix_sum(orders.size());
    prefix_sum[0] = orders[0].price;
    for (int i = 1; i < orders.size(); i++){
        prefix_sum[i] = prefix_sum[i - 1] + orders[i].price;
    }

    for (auto order: orders){
        total += order.price;
        total_revenue[order.shopID] += order.price;
    }
    while(getline(cin, line)){
        if (line == "#"){
            break;
        }
        stringstream ss(line);
        string query;
        ss >> query;
        if (query == "?total_number_orders"){
            cout << orders.size() << "\n";
        }
        else if (query == "?total_revenue"){
            cout << total << "\n";
        }
        else if (query == "?revenue_of_shop"){
            string shopID;
            ss >> shopID;
            cout << total_revenue[shopID] << "\n";
        }
        else if (query == "?total_consume_of_customer_shop"){
            string customerID, shopID;
            ss >> customerID >> shopID;
            cout << total_revenue_of_customer_shop[customerID][shopID] << "\n";
        }
       else if (query == "?total_revenue_in_period"){
            string from_time, to_time;
            ss >> from_time >> to_time;
            int total_revenue_in_period = 0;

            Order from_order, to_order;
            from_order.timePoint = from_time;
            to_order.timePoint = to_time;

            auto compare = [](const Order& a, const Order& b) {
                return a.timePoint < b.timePoint;
            };

            auto first_order = std::lower_bound(orders.begin(), orders.end(), from_order, compare) - orders.begin();
            auto last_order = std::upper_bound(orders.begin(), orders.end(), to_order, compare) - orders.begin() - 1;

            total_revenue_in_period = PrefixSum(first_order, last_order, prefix_sum);
            cout << total_revenue_in_period << "\n";
        }
    }
}