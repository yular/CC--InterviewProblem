/*
*
* Tag: Hash, Design
* Time: O(n)
* Space: O(n)
*/

class Cashier {
private:
    unordered_map<int,int> priceOfProduct;
    int customerCnt, discountBnd;
    double discnt;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        customerCnt = 0, discountBnd = n;
        discnt = (100 - discount)/100.0;
        for(int i = 0; i < products.size(); ++ i) {
            priceOfProduct[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        customerCnt = (customerCnt + 1)%discountBnd;
        long long tot = 0;
        for(int i = 0; i < product.size(); ++ i) {
            tot += priceOfProduct[product[i]]*amount[i];
        }
        
        return customerCnt == 0? discnt*tot : tot;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
