// E-commerce shopping cart logic
// 6-7 bugs to fix!

class ShoppingCart {
    constructor() {
        this.items = [];
        this.taxRate = 0.08;
    }
    
    addItem(item) {
        //push since it is arr
        this.items.push(item);
    }
    
    removeItem(itemId) {
        this.items = this.items.filter(item => item.id !== itemId);
    }
    
    getSubtotal() {
       return this.items.reduce((sum, item) => sum + item.price, 0);
    }
    
    getTax() {
        return this.getSubtotal() * this.taxRate;
    }
    
    getTotal() {
        return this.getSubtotal() + this.getTax();
    }
    
    applyDiscount(code) {
        const discounts = {
            'SAVE10': 0.10,
            'SAVE20': 0.20
        };
        const discount = discounts.code || 0;
        const subtotal = this.getSubtotal();
        return subtotal *( 1 - discount);
    }
    
    getItemCount() {
        return this.items.length;
    }
}

// Tests
const cart = new ShoppingCart();
cart.addItem({id: 1, name: 'Vintage Mug', price: 15.00});
cart.addItem({id: 2, name: 'Handmade Scarf', price: 25.00});

console.log(cart.getSubtotal() === 40.00);
console.log(cart.getTax() === 3.20);
console.log(cart.getTotal() === 43.20);
console.log(cart.getItemCount() === 2);
console.log(cart.applyDiscount('SAVE10') === 36.00);
cart.removeItem(1);
console.log(cart.getItemCount() === 1);