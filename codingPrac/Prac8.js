'use strict';

// Simulated API - returns order data
const OrderAPI = {
    fetchOrders: async function(userId) {
        return new Promise(resolve => setTimeout(() => resolve([
            { id: 1, item: "hat", price: 25, status: "shipped", quantity: 2 },
            { id: 2, item: "scarf", price: 20, status: "pending", quantity: 1 },
            { id: 3, item: "bag", price: 30, status: "shipped", quantity: 3 },
            { id: 4, item: "shoes", price: 50, status: "cancelled", quantity: 1 },
            { id: 5, item: "gloves", price: 15, status: "pending", quantity: 2 }
        ]), 100));
    },

    // Bug 1: Should return only shipped orders
    getShippedOrders: async function(userId) {
        const orders = await this.fetchOrders(userId);
        return orders.filter(order => order.status === "shipped");
    },

    // Bug 2: Should return total revenue (price * quantity) for shipped orders only
    getShippedRevenue: async function(userId) {
        const orders = await this.fetchOrders(userId);
        const shipped = orders.filter(order => order.status === "shipped");
        return shipped.reduce((total, order) => total + order.price * order.quantity, 0);
    },

    // Bug 3: Should return the pending order with highest price
    getMostExpensivePending: async function(userId) {
        const orders = await this.fetchOrders(userId);
        const pending = orders.filter(order => order.status === "pending");
        return pending.reduce((max, order) => order.price > max.price ? order : max);
        //note to keep in mind reduce is only used for single values
    },

    // TODO 1: Return count of each status as an object
    // expected: { shipped: 2, pending: 2, cancelled: 1 }
    getStatusCounts: async function(userId) {
        const orders = await this.fetchOrders(userId);

        return orders.reduce((counts, order) => {
            const status = order.status; // grab this value
            //does not exits yet(this a map) saying counts[status] = 1 is pretty much shipped : 1
            counts[status] = (counts[status] || 0) + 1;
                              //if there is nohting then it might read as undefined
                              //which may cause an erro so by giving it an option to fall back to (0)
                              //if found just add plus one everytime is seen again
            return counts;
        }, {})
    },

    // TODO 2: Return all orders sorted by total value (price * quantity) high to low
    getOrdersByValue: async function(userId) {
        const orders = await this.fetchOrders(userId);
        return orders.sort((a, b) => (b.price * b.quantity) - (a.price * a.quantity));
    }
};

async function runTests() {
    console.log((await OrderAPI.getShippedOrders(1)).length === 2);
    console.log(await OrderAPI.getShippedRevenue(1) === 140);
    console.log((await OrderAPI.getMostExpensivePending(1)).item === 'scarf');
    
    const counts = await OrderAPI.getStatusCounts(1);
    console.log(counts.shipped === 2 && counts.pending === 2 && counts.cancelled === 1);
    
    const byValue = await OrderAPI.getOrdersByValue(1);
    console.log(byValue[0].item === 'bag'); // bag: 30 * 3 = 90, highest value
}

runTests();